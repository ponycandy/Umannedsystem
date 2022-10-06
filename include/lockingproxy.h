#ifndef LOCKINGPROXY_H
#define LOCKINGPROXY_H

template <class T>
class LockingProxy
{
public:
   LockingProxy(T* pObj) : pointee_ (pObj)
   { pointee_->Lock(); }
   ~LockingProxy()
   { pointee_->Unlock(); }
   T* operator->() const
   { return pointee_; }
private:
   LockingProxy& operator=(const LockingProxy&);
   T* pointee_;
};

#endif // LOCKINGPROXY_H
