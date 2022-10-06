#include "vehicle1_control_widget.h"
#include "ui_vehicle1_control_widget.h"
#include "vehicle1_controlActivator.h"
#include "event/OcuEventContants.h"
#include "defines/Vehicle1_data.h"
#include "event/eventype.h"
vehicle1_control_widget::vehicle1_control_widget(QWidget *parent) :
    QWidget(parent),m_service(NULL),m_datamanager(NULL),m_communication(NULL),
    ui(new Ui::vehicle1_control_widget)
{
    ui->setupUi(this);
    m_service=vehicle1_controlActivator::getService<vehicle_1_coreservice>("vehicle_1_coreservice");
    m_service->addView(UcsDefines::VEHICLE1_CONTROL,this);
    m_datamanager=vehicle1_controlActivator::getService<vehicle_1_1Datamanageservice>("vehicle_1_1Datamanageservice");
    m_communication=vehicle1_controlActivator::getService<vehicle1_communicationservice>("vehicle1_communicationservice");
  //  _timer = new QTimer(this);
   // connect(_timer, SIGNAL(timeout()), this, SLOT(spinOnce()));
    vehicle1_controlActivator::subscribevent(UCSEVENT::MQTTSTART,this);
    vehicle1_controlActivator::subscribevent(UCSEVENT::MQTTSTOP,this);
//            vehicle1_communicationservice *m_communication;

}

vehicle1_control_widget::~vehicle1_control_widget()
{
    delete ui;
}

void vehicle1_control_widget::on_horizontalSlider_valueChanged(int value)
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

         //   qDebug()<<"sizeof pointcloud data and  pointnum"<<sizeof (pointcloud_data)<<" "<< pointcloud_data.pointnum;
        m_datamanager->execute(signal,sendingdata);
        m_communication->send(sendingdata);
}
