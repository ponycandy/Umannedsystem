#ifndef TASKTUPLE_H
#define TASKTUPLE_H

#include <QObject>

struct TaskTuple
{
    QObject *qobjk;
    const char *functorname;
    bool is_signal;
    bool is_slot;
    Qt::ConnectionType Type;
//    Qt::QueuedConnection

};

#endif // DECLAREINTERFACE_H

