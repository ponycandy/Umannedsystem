#include "vehicle1_controlActivator.h"


vehicle1_controlActivator* vehicle1_controlActivator::m_instance=Q_NULLPTR;
PluginContext* vehicle1_controlActivator::m_CONTEXT=Q_NULLPTR;
vehicle1_controlActivator::vehicle1_controlActivator(QObject *parent) : QObject(parent),m_widget(NULL)
{
    m_instance=this;
}
void vehicle1_controlActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void vehicle1_controlActivator::start()
{
  //  m_widget=new vehicle1_control_widget;
}
void vehicle1_controlActivator::stop()
{
delete this;

}
