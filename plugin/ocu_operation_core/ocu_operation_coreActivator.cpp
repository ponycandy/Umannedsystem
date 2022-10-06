#include "ocu_operation_coreActivator.h"


ocu_operation_coreActivator* ocu_operation_coreActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_operation_coreActivator::m_CONTEXT=Q_NULLPTR;
ocu_operation_coreActivator::ocu_operation_coreActivator(QObject *parent) : QObject(parent),m_MainWindow(NULL)
{
    m_instance=this;
}
void ocu_operation_coreActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_operation_coreActivator::start()
{
    if(m_MainWindow == NULL)
    {
        m_MainWindow = new MainWindow();
    }
}
void ocu_operation_coreActivator::stop()
{
delete this;

}
