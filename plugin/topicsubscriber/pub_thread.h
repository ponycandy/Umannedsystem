#ifndef PUB_THREAD_H
#define PUB_THREAD_H

#include <QObject>
#include <xtlevent.h>
#include <ros/ros.h>
#include <service/Datamanageservice.h>
#include <service/eventservice.h>

class pub_thread : public QObject,public EventService
{
    Q_OBJECT
public:
    explicit pub_thread(QObject *parent = nullptr);
    ros::NodeHandlePtr nh_;
    Datamanageservice *servicehandle;
    int on_pub=0;
    int on_remote=0;
    int on_local=0;
    ros::Publisher pub_1;
    void EventTriggeres(XTLevent event) override;
signals:
private slots:
    void setservice();
    void setHandle(ros::NodeHandlePtr nh);
    void switch_control(XTLevent event);
    void startpub();
    void stoppub();



};

#endif // PUB_THREAD_H
