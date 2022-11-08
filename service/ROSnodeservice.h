
#ifndef ROSNODESERVICE_H
#define ROSNODESERVICE_H

#include <QObject>
class ROSnodeservice
{
public:
    virtual ~ROSnodeservice(){}
    virtual void destroyall()=0;

};
#define ROSnodeservice_iid "ROSnodeservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(ROSnodeservice,ROSnodeservice_iid  )
QT_END_NAMESPACE

#endif

