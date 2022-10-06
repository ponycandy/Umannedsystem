#ifndef VEHICLE1_CONTROL_WIDGET_H
#define VEHICLE1_CONTROL_WIDGET_H

#include <QWidget>
#include <service/vehicle_1_coreservice.h>
#include "service/vehicle_1_1Datamanageservice.h"
#include "service/vehicle1_communicationservice.h"
#include <QTimer>
#include "service/eventservice.h"

namespace Ui {
class vehicle1_control_widget;
}

class vehicle1_control_widget : public QWidget,public EventService
{
    Q_OBJECT

public:
    explicit vehicle1_control_widget(QWidget *parent = nullptr);
    ~vehicle1_control_widget();
    vehicle_1_coreservice *m_service;
    vehicle_1_1Datamanageservice *m_datamanager;
    vehicle1_communicationservice *m_communication;
    void EventTriggeres(XTLevent event) override;
   // QTimer *_timer;


private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::vehicle1_control_widget *ui;
};

#endif // VEHICLE1_CONTROL_WIDGET_H
