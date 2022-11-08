#include "vehicle_2_controlActivator.h"


vehicle_2_controlActivator* vehicle_2_controlActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle_2_controlActivator::m_CONTEXT=Q_NULLPTR;
vehicle_2_controlActivator::vehicle_2_controlActivator(QObject *parent) : QObject(parent),m_main_widget(nullptr)
{
    m_instance=this;
}
void vehicle_2_controlActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle_2_controlActivator::start()
{
    m_main_widget=new control_main_widget;
}
void vehicle_2_controlActivator::stop()
{
    delete this;

}
