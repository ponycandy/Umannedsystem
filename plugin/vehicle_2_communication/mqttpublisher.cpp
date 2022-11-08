#include "mqttpublisher.h"
#include "vehicle_2_communicationActivator.h"
#include "QtDebug"
mqttpublisher::mqttpublisher(QObject *parent) : QObject(parent)
    ,topicname(NULL)
{
    m_thread=new pubthread;
    n_thread=new subthread;
    qRegisterMetaType<XTLevent>("XTLevent");

    connect(this,SIGNAL(sig_setNet(XTLevent)),m_thread,SLOT(slot_setNet(XTLevent)),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_start_node()),m_thread,SLOT(slot_start_node()),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_stop_node()),m_thread,SLOT(slot_stop_node()),Qt::QueuedConnection);

    connect(this,SIGNAL(sig_setNet(XTLevent)),n_thread,SLOT(slot_setNet(XTLevent)),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_start_node()),n_thread,SLOT(slot_start_node()),Qt::QueuedConnection);
    connect(this,SIGNAL(sig_stop_node()),n_thread,SLOT(slot_stop_node()),Qt::QueuedConnection);

    vehicle_2_communicationActivator::subscribevent(UCSEVENT::MQTTNETSET,this);
    vehicle_2_communicationActivator::subscribevent(UCSEVENT::MQTTSTART,this);
    vehicle_2_communicationActivator::subscribevent(UCSEVENT::MQTTSTOP,this);
}


void mqttpublisher::EventTriggeres(XTLevent event)
{
    if(event.eventname==UCSEVENT::MQTTNETSET)
    {
        if(event.m_dict.value("vehicle_num")=="vehicle2")
        {
            emit sig_setNet(event);
        }
    }
    if(event.eventname==UCSEVENT::MQTTSTART)
    {
        if(event.m_dict.value("vehicle_num")=="vehicle2")
        {
            emit sig_start_node();
        }

    }
    if(event.eventname==UCSEVENT::MQTTSTOP)
    {
        if(event.m_dict.value("vehicle_num")=="vehicle2")
        {
            emit sig_stop_node();
        }
    }
}

void mqttpublisher::slot_setNet(XTLevent event)
{
}
