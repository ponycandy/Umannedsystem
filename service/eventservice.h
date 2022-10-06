#ifndef EVENTSERVICE_H
#define EVENTSERVICE_H

#include <QObject>
#include <xtlevent.h>
class EventService
{
public:
    virtual ~EventService(){}
    virtual void  EventTriggeres(XTLevent event) = 0;
};

#endif

