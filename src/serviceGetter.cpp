#include <serviceGetter.h>
template<class S>
servicegetter<S>::servicegetter(PluginContext *context):m_CONTEXT(NULL)
{
    m_CONTEXT=context;
};
template<class S>
S* servicegetter<S>::getservice(QString name)
{
    QObject *servicehandle=m_CONTEXT->getservice(name);
    return (S*)servicehandle;
};
