#ifndef FUNCDUMMY_H
#define FUNCDUMMY_H

#include <QObject>
#include <tasktuple.h>
#include <QMap>
class FuncDummy
{
public:
    int num=0;
    QMap<int ,TaskTuple* > tuples;

};
//一定是唯一的标识符
//#define Coreservice_iid "Coreservice"

//QT_BEGIN_NAMESPACE
//Q_DECLARE_INTERFACE(Coreservice,Coreservice_iid )
//QT_END_NAMESPACE

#endif // DECLAREINTERFACE_H

