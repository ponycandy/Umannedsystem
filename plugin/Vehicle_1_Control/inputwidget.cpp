#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "defines/Vehicle1_data.h"
#include "Vehicle_1_ControlActivator.h"
#include "event/eventype.h"
inputwidget::inputwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputwidget)
{
    ui->setupUi(this);
    m_datamanager=Vehicle_1_ControlActivator::getService<vehicle_1_1Datamanageservice>("vehicle_1_1Datamanageservice");
    m_communication=Vehicle_1_ControlActivator::getService<vehicle1_communicationservice>("vehicle1_communicationservice");
    Vehicle_1_ControlActivator::subscribevent(UCSEVENT::CONTROLLER_CMD,this);
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
            V1DATA::MOTIONCOMMAND cmd=data.value<V1DATA::MOTIONCOMMAND>();
            execute_cmd(cmd);
        }

        return;
    }
}

void inputwidget::execute_cmd(V1DATA::MOTIONCOMMAND cmd)
{
    QByteArray sendingdata;
    m_datamanager->execute(cmd,sendingdata);
    m_communication->send(sendingdata);
}

void inputwidget::on_horizontalSlider_valueChanged(int value)
{
    V1DATA::PLUSED_SWITCH_DATA signal;
    signal.header=0xaadd;
    switch (value)
    {
    case 0:
    {
        ui->label_2->setText("stop");
        signal.m_mode=V1DATA::control_mode::stop;

        break;

    }
    case 1:
    {
        ui->label_2->setText("automation");
        signal.m_mode=V1DATA::control_mode::automatation;

        break;

    }
    case 2:
    {
        ui->label_2->setText("remote automation");
        signal.m_mode=V1DATA::control_mode::remote_automatation;

        break;

    }
    case 3:
    {
        ui->label_2->setText("remote control");
        signal.m_mode=V1DATA::control_mode::remote;

        break;

    }

    }

    QByteArray sendingdata;

    m_datamanager->execute(signal,sendingdata);
    m_communication->send(sendingdata);
}
