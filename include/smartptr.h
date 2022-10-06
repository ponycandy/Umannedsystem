#ifndef SMARTPTR_H
#define SMARTPTR_H
#include "lockingproxy.h"

template <class T>
class SmartPtr
{
public:
    void setpointee(T* in)
    {
        pointee_=in;
    }
    LockingProxy<T> operator->() const
    { return LockingProxy<T>(pointee_); }

private:
    T* pointee_;
};
#endif // SMARTPTR_H
