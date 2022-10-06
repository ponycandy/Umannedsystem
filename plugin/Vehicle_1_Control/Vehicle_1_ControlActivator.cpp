#include "Vehicle_1_ControlActivator.h"


Vehicle_1_ControlActivator* Vehicle_1_ControlActivator::m_instance=Q_NULLPTR;
PluginContext* Vehicle_1_ControlActivator::m_CONTEXT=Q_NULLPTR;
Vehicle_1_ControlActivator::Vehicle_1_ControlActivator(QObject *parent) : QObject(parent),m_main_widget(NULL)
{
    m_instance=this;
}
void Vehicle_1_ControlActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void Vehicle_1_ControlActivator::start()
{
    m_main_widget=new control_main_widget;
}
void Vehicle_1_ControlActivator::stop()
{
delete this;

}
