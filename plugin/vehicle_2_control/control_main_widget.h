#ifndef CONTROL_MAIN_WIDGET_H
#define CONTROL_MAIN_WIDGET_H

#include <QObject>
#include <inputwidget.h>
#include <service/vehicle_2_coreservice.h>
class control_main_widget : public QObject
{
    Q_OBJECT
public:
    explicit control_main_widget(QObject *parent = nullptr);
    inputwidget *m_widget;
    vehicle_2_coreservice *m_service;
signals:

};

#endif // CONTROL_MAIN_WIDGET_H
