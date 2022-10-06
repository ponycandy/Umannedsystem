#include "vehicle1_coreActivator.h"


vehicle1_coreActivator* vehicle1_coreActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle1_coreActivator::m_CONTEXT=Q_NULLPTR;
vehicle1_coreActivator::vehicle1_coreActivator(QObject *parent) : QObject(parent),m_startwindow(NULL)
{
    m_instance=this;
}
void vehicle1_coreActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle1_coreActivator::start()
{
    m_startwindow=new startwindow;

}
void vehicle1_coreActivator::stop()
{
delete this;

}
