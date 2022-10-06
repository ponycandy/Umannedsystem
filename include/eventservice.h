#ifndef EVENTSERVICE_H
#define EVENTSERVICE_H

#include <QObject>
//定义接口,不能用struct代替，否则模板就失效了
#include <xtlevent.h>
class EventService
{
public:
    virtual ~EventService(){}
    virtual void  EventTriggeres(XTLevent event) = 0;
};
//一定是唯一的标识符
//#define Coreservice_iid "Coreservice"

//QT_BEGIN_NAMESPACE
//Q_DECLARE_INTERFACE(Coreservice,Coreservice_iid )
//QT_END_NAMESPACE

#endif // DECLAREINTERFACE_H

