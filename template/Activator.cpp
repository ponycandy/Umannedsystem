#include "pluginnameActivator.h"


pluginnameActivator* pluginnameActivator::m_instance=Q_NULLPTR;
PluginContext* pluginnameActivator::m_CONTEXT=Q_NULLPTR;
pluginnameActivator::pluginnameActivator(QObject *parent) : QObject(parent)
{
    m_instance=this;
}
void pluginnameActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void pluginnameActivator::start()
{

}
void pluginnameActivator::stop()
{
delete this;

}
