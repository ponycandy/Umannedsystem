#include "messagecollector.h"
#include "vehicle1_datamanagerActivator.h"
#include <QDebug>
#include <defines/Vehicle1_data.h>

#define ASSERT_LEN_BREAK(x, y) if((x) > (y)){break;}

messagecollector::messagecollector(QObject *parent) : QObject(parent),m_Data(NULL)
{
    m_Data=new Datacollection;
    m_Data_Ptr.setpointee(m_Data);
    vehicle1_datamanagerActivator::registerservice(this,"vehicle_1_1Datamanageservice");
}

void messagecollector::store(QSharedPointer<QByteArray> sptba)
{
    if (sptba->length() <= 2) { return; }

    quint8 *ptCach = (quint8 *)sptba->data();
    if (ptCach[0] == 0xbb && ptCach[1] == 0xaa)
    {
        V1DATA::DOWNSTREAM_INFO  m_downstreaminfo;
        if (execute((const char*)sptba->data(), sptba->length(), m_downstreaminfo))
        {
            //            xtlDictionary  dict;
            //            dict.insert(XtzkxEventConstants::TOPIC_COMMAND_CONTROL_COORPERATIVE_TASK_ISSUED,QVariant::fromValue<Xtzkx::CoorperativeTaskIssuedTrans>(coorperativeTaskIssuedTrans));
            //            emit sigCoorperativeTaskIssuedTrans(dict);

        }
    }
    return;
}

void messagecollector::execute(V1DATA::PLUSED_SWITCH_DATA ptopic, QByteArray &sending_data)
{
    const char* ptData = m_protcols_data;
    int offset,size;

    size=0;
    offset=2;
    memcpy((void *)(ptData), (void *)&ptopic, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (V1DATA::PLUSED_SWITCH_DATA::m_mode);
    memcpy((void *)(ptData), (void *)&ptopic.m_mode, offset);
    ptData += offset;
    size+=offset;

    sending_data.setRawData(m_protcols_data,size);
}

void messagecollector::execute(V1DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data)
{
    const char* ptData = m_control_cmd;
    int offset,size;

    size=0;
    offset=2;
    memcpy((void *)(ptData), (void *)&ptopic, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (V1DATA::MOTIONCOMMAND::linear);
    memcpy((void *)(ptData), (void *)&ptopic.linear, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (V1DATA::MOTIONCOMMAND::angular);
    memcpy((void *)(ptData), (void *)&ptopic.angular, offset);
    ptData += offset;
    size+=offset;

    sending_data.setRawData(m_control_cmd,size);
}

bool messagecollector::execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO &ptTopic)
{
    bool rslt = false;
    V1DATA::DOWNSTREAM_INFO_ISSUED rawTopic;
    memset((void *)&rawTopic, 0x00, sizeof(V1DATA::DOWNSTREAM_INFO_ISSUED));
    if(rslt = execute(data, len, rawTopic))
    {
        m_Data_Ptr->setStream(&rawTopic);
        //decode  in application layer
    }

    //    }

    return rslt;

}

bool messagecollector::execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO_ISSUED &ptTopic)
{


    return 1;

}

void messagecollector::parse(const char *data, V1DATA::POINTCLOUD &PTtopic)
{
    //    const char* ptData = data;
    //    int offset;

    //    memcpy((void *)&PTtopic.header,(void *)(ptData),  2);
    //    offset =2;
    //    ptData += offset;

    //    memcpy((void *)&PTtopic.secquense,(void *)(ptData),  4);
    //    offset =4;
    //    ptData += offset;

    //    memcpy((void *)&PTtopic.time,(void *)(ptData),  sizeof(V1DATA::ROSTIMESTAMP));
    //    offset =sizeof(V1DATA::ROSTIMESTAMP);
    //    ptData += offset;

    //    memcpy((void *)&PTtopic.pointnum,(void *)(ptData),  4);
    //    offset =4;
    //    ptData += offset;

    //    offset=sizeof (V1DATA::SINGEPOINTDATA);
    //    for(int i=0;i<PTtopic.pointnum;i++)
    //    {
    //        V1DATA::SINGEPOINTDATA  m_point_s;
    //        memcpy((void *)&m_point_s,(void *)(ptData),  sizeof (V1DATA::SINGEPOINTDATA));
    //        ptData += offset;
    //        PTtopic.point_group.append(m_point_s);
    //    }

}
