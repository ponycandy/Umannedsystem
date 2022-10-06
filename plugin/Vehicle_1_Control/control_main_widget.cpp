#include "control_main_widget.h"
#include "Vehicle_1_ControlActivator.h"
control_main_widget::control_main_widget(QObject *parent) : QObject(parent),m_widget(NULL)
{
    m_widget=new inputwidget;
    m_service=Vehicle_1_ControlActivator::getService<vehicle_1_coreservice>("vehicle_1_coreservice");
    m_service->addView(UcsDefines::VEHICLE1_CONTROL,m_widget);
}
