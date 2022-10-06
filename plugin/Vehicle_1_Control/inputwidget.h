#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <service/vehicle1_communicationservice.h>
#include <service/vehicle_1_1Datamanageservice.h>
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
    void execute_cmd(V1DATA::MOTIONCOMMAND cmd);
    vehicle_1_1Datamanageservice *m_datamanager;
    vehicle1_communicationservice *m_communication;

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::inputwidget *ui;
};

#endif // INPUTWIDGET_H
