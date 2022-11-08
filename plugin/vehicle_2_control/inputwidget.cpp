#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "defines/vehicle_2_data.h"
#include "vehicle_2_controlActivator.h"
#include "event/eventype.h"
inputwidget::inputwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputwidget)
{
    ui->setupUi(this);
    m_datamanager=vehicle_2_controlActivator::getService<vehicle_2_Datamanageservice>("vehicle_2_Datamanageservice");
    m_communication=vehicle_2_controlActivator::getService<vehicle_2_communicationservice>("vehicle_2_communicationservice");
    vehicle_2_controlActivator::subscribevent(UCSEVENT::CONTROLLER_CMD,this);
    vehicle_2_controlActivator::subscribevent(UCSEVENT::V2_AUTO,this);

}

inputwidget::~inputwidget()
{
    delete ui;
}

void inputwidget::EventTriggeres(XTLevent event)
{
    if(event.eventname==UCSEVENT::CONTROLLER_CMD)
    {
        if (this->ui->horizontalSlider->value()== 3)
        {
            QVariant data=event.m_dict.value("value");
            VEHICLE_2_DATA::MOTIONCOMMAND cmd=data.value<VEHICLE_2_DATA::MOTIONCOMMAND>();
            execute_cmd(cmd);
        }

        return;
    }
    if(event.eventname==UCSEVENT::V2_AUTO)
    {
        if (this->ui->horizontalSlider->value()== 2)
        {
            QVariant data=event.m_dict.value("value");
            VEHICLE_2_DATA::MOTIONCOMMAND cmd=data.value<VEHICLE_2_DATA::MOTIONCOMMAND>();
            execute_cmd(cmd);
        }

        return;
    }
}

void inputwidget::execute_cmd(VEHICLE_2_DATA::MOTIONCOMMAND cmd)
{
    QByteArray sendingdata;
    m_datamanager->execute(cmd,sendingdata);
    m_communication->send(sendingdata);
}

void inputwidget::on_horizontalSlider_valueChanged(int value)
{
    VEHICLE_2_DATA::PLUSED_SWITCH_DATA signal;
    signal.header=0xaadd;
    switch (value)
    {
    case 0:
    {
        ui->label_2->setText("stop");
        signal.m_mode=VEHICLE_2_DATA::control_mode::stop;

        break;

    }
    case 1:
    {
        ui->label_2->setText("automation");
        signal.m_mode=VEHICLE_2_DATA::control_mode::automatation;

        break;

    }
    case 2:
    {
        ui->label_2->setText("remote automation");
        signal.m_mode=VEHICLE_2_DATA::control_mode::remote_automatation;

        break;

    }
    case 3:
    {
        ui->label_2->setText("remote control");
        signal.m_mode=VEHICLE_2_DATA::control_mode::remote;

        break;

    }

    }

    QByteArray sendingdata;

    m_datamanager->execute(signal,sendingdata);
    m_communication->send(sendingdata);
}
