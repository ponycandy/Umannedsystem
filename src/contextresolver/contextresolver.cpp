#include "contextresolver.h"
ContextResolver::ContextResolver(QObject *parent) : QObject(parent)
{
}
QObject* ContextResolver::getservice(QString name)
{
    if(service_map.contains(name))
    {
        return service_map.value(name);
    }
    else
    {
        return  NULL;
    }
}
void ContextResolver::setupevent() {}

void ContextResolver::publishsignal(QObject *sender, const char *signal, QString eventname,Qt::ConnectionType type)
{
    TaskTuple *m_tuple=new TaskTuple;
    m_tuple->Type=type;
    m_tuple->qobjk=sender;
    m_tuple->is_slot=false;
    m_tuple->is_signal=true;
    m_tuple->functorname=signal;
    if(sender_map.contains(eventname))
    {
        FuncDummy *m_dum=sender_map.value(eventname);
        m_dum->num++;
        m_dum->tuples.insert(m_dum->num,m_tuple);
    }
    else
    {
        FuncDummy *m_dum=new FuncDummy;
        m_dum->num=1;
        m_dum->tuples.insert(m_dum->num,m_tuple);
        sender_map.insert(eventname,m_dum);
        //wrong! m_dum is destroyed!!
    }
    tryconnection_slot(eventname,sender,signal);
}
void ContextResolver::postevent(XTLevent event)
{

    if (event_map.contains(event.eventname))
    {
        SlotPointer *m_eventservice=    event_map.value(event.eventname);
        for (int i=0;i<m_eventservice->num;i++)
        {
            m_eventservice->m_event[i]->EventTriggeres(event);
        }
    }
    //当前版本暂时不支持优先级切换特性，敬请期待

}

void ContextResolver::subscribeslot(QObject *reciever, const char *method, QString eventname,Qt::ConnectionType type)
{

    TaskTuple *m_tuple=new TaskTuple;
    m_tuple->Type=type;
    m_tuple->qobjk=reciever;
    m_tuple->is_slot=true;
    m_tuple->is_signal=false;
    m_tuple->functorname=method;
    if(reciever_map.contains(eventname))
    {
        FuncDummy *m_dum=reciever_map.value(eventname);
        m_dum->num++;
        m_dum->tuples.insert(m_dum->num,m_tuple);
    }
    else
    {
        FuncDummy *m_dum=new FuncDummy;
        m_dum->num=1;
        m_dum->tuples.insert(m_dum->num,m_tuple);
        reciever_map.insert(eventname,m_dum);
    }
    tryconnection_sig(eventname,reciever,method);
}

void ContextResolver::registerservice(QObject *service,QString name)
{
    service_map.insert(name,service);
    //there are no protection,so do not have the same name
    //when service are called system will be blocked
}

void ContextResolver::subscribeslot(QString name, EventService *handle)
{
    if(event_map.contains(name))
    {
        SlotPointer *a_event=event_map.value(name);
        a_event->m_event[a_event->num]=handle;
        a_event->num++;
    }
    else
    {
        SlotPointer *a_event=new SlotPointer;
        a_event->num=1;
        a_event->m_event[0]=handle;
        event_map.insert(name,a_event);
    }

}

void ContextResolver::tryconnection_slot(QString eventname,QObject *sender,const char *signal)
{
    if(reciever_map.contains(eventname))
    {
        FuncDummy *slot_dummy=    reciever_map.value(eventname);
        QMap<int ,TaskTuple*>::const_iterator it = slot_dummy->tuples.constBegin();
        while (it != slot_dummy->tuples.constEnd())
        {
            QObject::connect(sender,signal,it.value()->qobjk,it.value()->functorname,it.value()->Type);
            ++it;
        }
    }
}

void ContextResolver::tryconnection_sig(QString eventname, QObject *reciever, const char *slot)
{
    FuncDummy *sig_dummy=    sender_map.value(eventname);
    if(sender_map.contains(eventname))
    {
        QMap<int ,TaskTuple*>::const_iterator it = sig_dummy->tuples.constBegin();
        while (it != sig_dummy->tuples.constEnd())
        {
            QObject::connect(it.value()->qobjk,it.value()->functorname,reciever,slot,it.value()->Type);
            ++it;
        }
    }
}

