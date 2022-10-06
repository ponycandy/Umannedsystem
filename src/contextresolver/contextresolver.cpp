#include "contextresolver.h"

ContextResolver::ContextResolver(QObject *parent) : QObject(parent)
{
}
QObject* ContextResolver::getservice(QString name)
{
    return service_map.value(name);
}
void ContextResolver::setupevent() {}
void ContextResolver::publishsignal() {}
void ContextResolver::postevent(XTLevent event)
{

    SlotPointer *m_eventservice=    event_map.value(event.eventname);
    if (m_eventservice!=NULL)
    {
    for (int i=0;i<m_eventservice->num;i++)
    {
        m_eventservice->m_event[i]->EventTriggeres(event);
    }
    }
    //当前版本暂时不支持优先级切换特性，敬请期待

}
void ContextResolver::subscribeslot(QString name,EventService *handle)
{
if(event_map.value(name)!=NULL)
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
void ContextResolver::registerservice(QObject *service,QString name)
{
    service_map.insert(name,service);
    //there are no protection,so do not have the same name
    //when service are called system will be blocked
}
