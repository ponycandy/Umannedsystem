#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <service/vehicle_2_communicationservice.h>
#include <service/vehicle_2_Datamanageservice.h>
#include <service/eventservice.h>
namespace Ui {
class inputwidget;
}

class inputwidget : public QWidget,public EventService
{
    Q_OBJECT

public:
    explicit inputwidget(QWidget *parent = nullptr);
    ~inputwidget();
    void EventTriggeres(XTLevent event) override;
    void execute_cmd(VEHICLE_2_DATA::MOTIONCOMMAND cmd);
    vehicle_2_Datamanageservice *m_datamanager;
    vehicle_2_communicationservice *m_communication;

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::inputwidget *ui;
};

#endif // INPUTWIDGET_H
