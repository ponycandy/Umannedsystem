#ifndef MUTEXOBJ_H
#define MUTEXOBJ_H

#include <QMutex>
class mutexobj
{
public:
    QMutex mutex;
    void Lock()
    {
        mutex.lock();
    };
    void Unlock()
    {
        mutex.unlock();
    };
};

#endif // MUTEXOBJ_H
