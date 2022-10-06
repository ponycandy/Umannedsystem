#ifndef XTLEVENT_H
#define XTLEVENT_H

#include <QObject>
#include <eventdictionary.h>
//定义接口,不能用struct代替，否则模板就失效了
class XTLevent
{
public:
QString eventname;
Eventdictionary m_dict;

};
//一定是唯一的标识符
//#define Coreservice_iid "Coreservice"

//QT_BEGIN_NAMESPACE
//Q_DECLARE_INTERFACE(Coreservice,Coreservice_iid )
//QT_END_NAMESPACE

#endif // DECLAREINTERFACE_H

