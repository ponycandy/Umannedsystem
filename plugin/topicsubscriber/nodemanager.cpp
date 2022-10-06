#include "nodemanager.h"
#include "topicsubscriberActivator.h"
#include "QtDebug"
#include "defines/Vehicle1_data.h"
nodemanager::nodemanager(QObject *parent) : QObject(parent),workingthread(NULL),
    m_datamanager(NULL),m_thread(NULL),nh_(NULL),  ros_timer(NULL),m_rosview(NULL)
{
    m_thread=new listen_thread;
    m_thread2=new pub_thread;
    m_pub_once=new Singleshot;
    m_rosview=new ROSnodemanager;
    state_Nokl="stop";
    qRegisterMetaType<XTLevent>("XTLevent");
    qRegisterMetaType<ros::NodeHandlePtr>("ros::NodeHandlePtr");

    m_datamanager=topicsubscriberActivator::getService<Datamanageservice>("Datamanageservice");
   // m_communication=topicsubscriberActivator::getService<communicationservice>("communicationservice");
    nh_.reset(new ros::NodeHandle("~"));
    //ros_timer = new QTimer(this);
    //for different publish frequence,use qtimer and timeout signal
    //to triggered a single thread call to pub.publish
    //a multithreaded method is available however publish frequence is restricted
    topicsubscriberActivator::subscribevent(UCSEVENT::STARTROSLOOP,this);
    topicsubscriberActivator::subscribevent(UCSEVENT::ROSPUBCONTROLSIG,this);


    connect(this,SIGNAL(start_node()),m_thread,SLOT(startlisten()));
    connect(this,SIGNAL(stop_node()),m_thread,SLOT(stoplisten()));
    connect(this,SIGNAL(start_node()),m_thread2,SLOT(startpub()));
    connect(this,SIGNAL(stop_node()),m_thread2,SLOT(stoppub()));
    connect(this,SIGNAL(sig_setHandle(ros::NodeHandlePtr)),m_thread2,SLOT(setHandle(ros::NodeHandlePtr)));
    connect(this,SIGNAL(sig_setservice()),m_thread2,SLOT(setservice()));
    //    connect(this,SIGNAL(sig_start_pubthread_remote()),m_thread2,SLOT(start_pubthread_remote()));
    //    connect(this,SIGNAL(sig_start_pubthread_local()),m_thread2,SLOT(start_pubthread_local()));
    //    connect(this,SIGNAL(sig_stop_pubthread()),m_thread2,SLOT(stop_pubthread()));

    connect(this,SIGNAL(sig_switch_control(XTLevent)),m_thread2,SLOT(switch_control(XTLevent)));
    //    connect(m_thread2,SIGNAL(start_m_remote()),this,SLOT(slotsig_start_pubthread_remote()));
    //    connect(m_thread2,SIGNAL(start_m_local()),this,SLOT(slotsig_start_pubthread_local()));

    //        start_m_remote();
    //            void start_m_local();
    //            void stop_control_stream();
    std::string listen_topic0;

    nh_->param<std::string>("listen_topic0",listen_topic0,"/joy");
    sub1=nh_->subscribe<sensor_msgs::Joy>(listen_topic0, 1, &nodemanager::chatterCallback1, this);
    ros_timer = new QTimer(this);
    connect(ros_timer, SIGNAL(timeout()), this, SLOT(spinOnce()));
    m_thread2->moveToThread(&workingthread2);
    workingthread2.start();
    emit sig_setservice();
    emit sig_setHandle(nh_);
}

void nodemanager::spinOnce()
{
    if(ros::ok()){
        ros::spinOnce();
    }

}

void nodemanager::slotsig_start_pubthread_remote()
{
    emit sig_start_pubthread_remote();

}

void nodemanager::slotsig_start_pubthread_local()
{
    emit sig_start_pubthread_local();

}
void nodemanager::chatterCallback(const sensor_msgs::PointCloud data)
{
//    V1DATA::POINTCLOUD pointcloud_data;
//    pointcloud_data.header=0xaacc;
//    pointcloud_data.secquense=data.header.seq;

//    pointcloud_data.time.secs=data.header.stamp.sec;

//    pointcloud_data.time.nsecs=data.header.stamp.nsec;
//    pointcloud_data.pointnum=data.points.size();
//    for(int i=0;i<pointcloud_data.pointnum;i++)
//    {
//        V1DATA::SINGEPOINTDATA new_point;
//        new_point.x=data.points[i].x;
//        new_point.y=data.points[i].y;
//        new_point.intensity=data.channels[0].values[i];
//        new_point.timestamp=data.channels[1].values[i];
//        pointcloud_data.point_group.append(new_point);
//    }

//    //protocol layer done
//    QByteArray sendingdata;

//     //   qDebug()<<"sizeof pointcloud data and  pointnum"<<sizeof (pointcloud_data)<<" "<< pointcloud_data.pointnum;
//    m_datamanager->execute(pointcloud_data,sendingdata);
//    m_communication->send(sendingdata);

}
void nodemanager::chatterCallback1(const sensor_msgs::Joy data)
{

    V1DATA::MOTIONCOMMAND m_cmd;
    m_cmd.header=0xaabb;
    m_cmd.linear=data.axes[1];
    m_cmd.angular=data.axes[3];
    XTLevent m_event;
    m_event.eventname=UCSEVENT::CONTROLLER_CMD;
    m_event.m_dict.insert("value",QVariant::fromValue<V1DATA::MOTIONCOMMAND>(m_cmd));
    topicsubscriberActivator::postevent(m_event);
}

void nodemanager::EventTriggeres(XTLevent event)
{
    if(event.eventname==UCSEVENT::STARTROSLOOP)
    {
        QVariant signals_s=event.m_dict.value("property");
        if(signals_s.toBool()==true)
        {
            emit start_node();
            ros_timer->start(100);
        }
        else
        {
            emit stop_node();
            ros_timer->stop();

        }
        return;
    }
    if(event.eventname==UCSEVENT::ROSPUBCONTROLSIG)
    {
        emit sig_switch_control(event);
    }

}


