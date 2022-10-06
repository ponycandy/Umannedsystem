#include "ocu_car_managerActivator.h"


ocu_car_managerActivator* ocu_car_managerActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_car_managerActivator::m_CONTEXT=Q_NULLPTR;
ocu_car_managerActivator::ocu_car_managerActivator(QObject *parent) : QObject(parent),m_startwindow(Q_NULLPTR)
{
    m_instance=this;
}
void ocu_car_managerActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_car_managerActivator::start()
{
    m_startwindow=new startwindow;
}
void ocu_car_managerActivator::stop()
{
delete this;

}
