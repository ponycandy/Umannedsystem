#include "ocu_coreActivator.h"


ocu_coreActivator* ocu_coreActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_coreActivator::m_CONTEXT=Q_NULLPTR;
ocu_coreActivator::ocu_coreActivator(QObject *parent) : QObject(parent),m_mainWindow(NULL)
{
    m_instance=this;
}
void ocu_coreActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_coreActivator::start()
{
    if(m_mainWindow == NULL)
    {
        m_mainWindow = new coremainwindow;
        m_mainWindow->show();
    }
}
void ocu_coreActivator::stop()
{
delete this;

}
