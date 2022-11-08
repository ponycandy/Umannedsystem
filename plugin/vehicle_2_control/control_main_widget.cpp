#include "control_main_widget.h"
#include "vehicle_2_controlActivator.h"
control_main_widget::control_main_widget(QObject *parent) : QObject(parent),m_widget(NULL)
{
    m_widget=new inputwidget;
    m_service=vehicle_2_controlActivator::getService<vehicle_2_coreservice>("vehicle_2_coreservice");
    m_service->addView(UcsDefines::VEHICLE2_CONTROL,m_widget);
}
