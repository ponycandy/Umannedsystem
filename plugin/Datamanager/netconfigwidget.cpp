#include "netconfigwidget.h"
#include "ui_netconfigwidget.h"
#include <QtDebug>
#include <QFile>
#include <xtlevent.h>
#include "event/eventype.h"
#include <DatamanagerActivator.h>
Netconfigwidget::Netconfigwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Netconfigwidget)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(13);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList header;
    header<<""<<"cilentID(S)"<<"host(S)"<<"port(S)"<<"topicname(S)"<<"username(S)"<<"password(S)"
         <<"cilentID(R)"<<"host(R)"<<"port(R)"<<"topicname(R)"<<"username(R)"<<"password(R)";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    readconfig();
}

Netconfigwidget::~Netconfigwidget()
{
    delete ui;
}

void Netconfigwidget::readconfig()
{
    QDir mydir("./config");
    qDebug()<<mydir.absoluteFilePath("vehiclenetconfig.xml");
    QFile file(mydir.absoluteFilePath("vehiclenetconfig.xml"));
    if (!file.open(QIODevice::ReadOnly ))
    {
        return;
    }
    QDomDocument pluginxml;

    pluginxml.setContent(&file);
    file.close();

    QDomElement root = pluginxml.documentElement();
    QDomElement node = root.firstChild().toElement();
    int i=1;
    while(node.tagName() == "vehicle")
    {

        QString cilentnum=node.attribute("cilentnum");
        QString username=node.attribute("username");
        QString password=node.attribute("password");
        QString topicname=node.attribute("topicname");
        QString port=node.attribute("port");
        QString host=node.attribute("host");
        QString cilentID=node.attribute("cilentID");

        QString cilentnum2=node.attribute("cilentnum2");
        QString username2=node.attribute("username2");
        QString password2=node.attribute("password2");
        QString topicname2=node.attribute("topicname2");
        QString port2=node.attribute("port2");
        QString host2=node.attribute("host2");
        QString cilentID2=node.attribute("cilentID2");

        availabe_row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(availabe_row);
        ui->tableWidget->setItem(availabe_row,0,new QTableWidgetItem(cilentnum));
        ui->tableWidget->setItem(availabe_row,1,new QTableWidgetItem(cilentID));
        ui->tableWidget->setItem(availabe_row,2,new QTableWidgetItem(host));
        ui->tableWidget->setItem(availabe_row,3,new QTableWidgetItem(port));
        ui->tableWidget->setItem(availabe_row,4,new QTableWidgetItem(topicname));
        ui->tableWidget->setItem(availabe_row,5,new QTableWidgetItem(username));
        ui->tableWidget->setItem(availabe_row,6,new QTableWidgetItem(password));

        ui->tableWidget->setItem(availabe_row,7,new QTableWidgetItem(cilentID2));
        ui->tableWidget->setItem(availabe_row,8,new QTableWidgetItem(host2));
        ui->tableWidget->setItem(availabe_row,9,new QTableWidgetItem(port2));
        ui->tableWidget->setItem(availabe_row,10,new QTableWidgetItem(topicname2));
        ui->tableWidget->setItem(availabe_row,11,new QTableWidgetItem(username2));
        ui->tableWidget->setItem(availabe_row,12,new QTableWidgetItem(password2));

        m_map.insert(cilentnum,availabe_row);
        node = node.nextSibling().toElement();
    }

}

void Netconfigwidget::on_pushButton_clicked()
{
    availabe_row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(availabe_row);
    QString host = ui->lineEdit_host->text();
    QString port = ui->lineEdit_port->text();
    QString topicname = ui->lineEdit_topiname->text();
    QString cilentID = ui->lineEdit_cilentid->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString cilentnum = ui->lineEdit->text();

    QString host2 = ui->lineEdit_host_2->text();
    QString port2 = ui->lineEdit_port_2->text();
    QString topicname2 = ui->lineEdit_topiname_2->text();
    QString cilentID2 = ui->lineEdit_cilentid_2->text();
    QString username2 = ui->lineEdit_username_2->text();
    QString password2 = ui->lineEdit_password_2->text();

    ui->tableWidget->setItem(availabe_row,0,new QTableWidgetItem(cilentnum));
    ui->tableWidget->setItem(availabe_row,1,new QTableWidgetItem(cilentID));
    ui->tableWidget->setItem(availabe_row,2,new QTableWidgetItem(host));
    ui->tableWidget->setItem(availabe_row,3,new QTableWidgetItem(port));
    ui->tableWidget->setItem(availabe_row,4,new QTableWidgetItem(topicname));
    ui->tableWidget->setItem(availabe_row,5,new QTableWidgetItem(username));
    ui->tableWidget->setItem(availabe_row,6,new QTableWidgetItem(password));
    ui->tableWidget->setItem(availabe_row,7,new QTableWidgetItem(cilentID2));
    ui->tableWidget->setItem(availabe_row,8,new QTableWidgetItem(host2));
    ui->tableWidget->setItem(availabe_row,9,new QTableWidgetItem(port2));
    ui->tableWidget->setItem(availabe_row,10,new QTableWidgetItem(topicname2));
    ui->tableWidget->setItem(availabe_row,11,new QTableWidgetItem(username2));
    ui->tableWidget->setItem(availabe_row,12,new QTableWidgetItem(password2));

    m_map.insert(cilentnum,availabe_row);
}

void Netconfigwidget::on_pushButton_3_clicked()
{
    int curow = ui->tableWidget->currentRow();
    QString asd=ui->tableWidget->item(curow,0)->text();
    m_map.remove(asd);
    ui->tableWidget->removeRow(curow);
}

void Netconfigwidget::on_pushButton_2_clicked()
{
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        XTLevent m_event;
        m_event.eventname=UCSEVENT::MQTTNETSET;
        m_event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
        m_event.m_dict.insert("cilentID(S)",ui->tableWidget->item(i,1)->text());
        m_event.m_dict.insert("host(S)",ui->tableWidget->item(i,2)->text());
        m_event.m_dict.insert("port(S)",ui->tableWidget->item(i,3)->text());
        m_event.m_dict.insert("topicname(S)",ui->tableWidget->item(i,4)->text());
        m_event.m_dict.insert("username(S)",ui->tableWidget->item(i,5)->text());    m_event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
        m_event.m_dict.insert("password(S)",ui->tableWidget->item(i,6)->text());
        m_event.m_dict.insert("cilentID(R)",ui->tableWidget->item(i,7)->text());    m_event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
        m_event.m_dict.insert("host(R)",ui->tableWidget->item(i,8)->text());
        m_event.m_dict.insert("port(R)",ui->tableWidget->item(i,9)->text());    m_event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
        m_event.m_dict.insert("topicname(R)",ui->tableWidget->item(i,10)->text());
        m_event.m_dict.insert("username(R)",ui->tableWidget->item(i,11)->text());
        m_event.m_dict.insert("password(R)",ui->tableWidget->item(i,12)->text());
        DatamanagerActivator::postevent(m_event);

    }
}

void Netconfigwidget::on_pushButton_4_clicked()
{
    QDir mydir("./config");
    QFile file(mydir.absoluteFilePath("vehiclenetconfig.xml"));
    if (!file.open(QIODevice::ReadOnly ))
    {
        return;
    }
    QDomDocument document;

    file.close();
    file.open(QIODevice::WriteOnly );
    QTextStream xmlstream(&file);
    QDomElement root = document.createElement("vehiclelist");
    //add it to document
    document.appendChild(root);


    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        QDomElement vehicle = document.createElement("vehicle");
        vehicle.setAttribute("cilentnum", ui->tableWidget->item(i,0)->text());
        vehicle.setAttribute("cilentID", ui->tableWidget->item(i,1)->text());
        vehicle.setAttribute("host", ui->tableWidget->item(i,2)->text());
        vehicle.setAttribute("port", ui->tableWidget->item(i,3)->text());
        vehicle.setAttribute("topicname", ui->tableWidget->item(i,4)->text());
        vehicle.setAttribute("username", ui->tableWidget->item(i,5)->text());
        vehicle.setAttribute("password", ui->tableWidget->item(i,6)->text());

        vehicle.setAttribute("cilentID2", ui->tableWidget->item(i,7)->text());
        vehicle.setAttribute("host2", ui->tableWidget->item(i,8)->text());
        vehicle.setAttribute("port2", ui->tableWidget->item(i,9)->text());
        vehicle.setAttribute("topicname2", ui->tableWidget->item(i,10)->text());
        vehicle.setAttribute("username2", ui->tableWidget->item(i,11)->text());
        vehicle.setAttribute("password2", ui->tableWidget->item(i,12)->text());

        root.appendChild(vehicle);
    }

    xmlstream<<document.toString();
    file.close();
}

void Netconfigwidget::on_horizontalSlider_valueChanged(int value)
{
    ui->label_17->setText(value ? "On" : "off");
    if(value==1)
    {
        XTLevent event;
        event.eventname=UCSEVENT::MQTTSTART;
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
            DatamanagerActivator::postevent(event);

        }
    }
    else
    {
        XTLevent event;
        event.eventname=UCSEVENT::MQTTSTOP;
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            event.m_dict.insert("vehicle_num",ui->tableWidget->item(i,0)->text());
            DatamanagerActivator::postevent(event);

        }
    }
}

void Netconfigwidget::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_19->setText(value ? "On" : "off");

    XTLevent event;
    event.eventname=UCSEVENT::STARTROSLOOP;
    event.m_dict.insert("property",value);
    DatamanagerActivator::postevent(event);
}
