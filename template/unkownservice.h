
#ifndef UNKOWNSERVICE_H
#define UNKOWNSERVICE_H

#include <QObject>
class unkownservice
{
public:
    virtual ~unkownservice(){}

};
#define unkownservice_iid "unkownservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(unkownservice,unkownservice_iid  )
QT_END_NAMESPACE

#endif

