#include "rosnodemanager.h"
#include "ui_rosnodemanager.h"
#include  <QtXml>
#include <QDomDocument>
#include <service/ROSnodeservice.h>
#include <ros/ros.h>
#include "topicsubscriberActivator.h"
ROSnodemanager::ROSnodemanager(QWidget *parent) :
    QWidget(parent),m_service(NULL),
    ui(new Ui::ROSnodemanager)
{
    m_service=topicsubscriberActivator::getService<ocu_car_coreservice>("ocu_car_coreservice");
    ui->setupUi(this);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
    ui->listWidget_2->setDragDropMode(QAbstractItemView::InternalMove);

    QDir mydir("./config");
    QFile file(mydir.absoluteFilePath("Nodeconfig.xml"));
    //file.setFileName(sFileName);
    if (!file.open(QIODevice::ReadOnly ))
    {
        return;
    }
    QDomDocument pluginxml;

    pluginxml.setContent(&file);
    file.close();

    QDomElement root = pluginxml.documentElement();
    QDomElement node = root.firstChild().toElement();

    while(node.isNull() == false)
    {
        qDebug() << node.tagName();
        while(node.tagName() == "nodetolaunch")
        {

            QString launchfile=node.attribute("value");
            node = node.nextSibling().toElement();
            ui->listWidget->addItem(launchfile);
        }
        while(node.tagName() == "nodelaunched")
        {
            QString launchedfile=node.attribute("value");
            node = node.nextSibling().toElement();
            ui->listWidget_2->addItem(launchedfile);

        }
        node = node.nextSibling().toElement();
    }
    m_service->addView(UcsDefines::ROSNODEMANAGEMENT,this);

}

ROSnodemanager::~ROSnodemanager()
{
    delete ui;
}

void ROSnodemanager::on_add_button_clicked()
{
    int n = ui->listWidget->currentRow();
    if(n == -1) { return; }
    ui->listWidget_2->addItem(ui->listWidget->takeItem(n));
}

void ROSnodemanager::on_del_button_clicked()
{
    int n = ui->listWidget_2->currentRow();
    if(n == -1) { return; }
    ui->listWidget->addItem(ui->listWidget_2->takeItem(n));
}

void ROSnodemanager::on_pushButton_3_clicked()
{
    QString text;
    for(int i = 0; i < ui->listWidget_2->count(); i++) {
        text="roslaunch  "+ ui->listWidget_2->item(i)->text()+"&";
        std::system(text.toLatin1().data());
    }
}

void ROSnodemanager::on_pushButton_4_clicked()
{

    QDir mydir("./config");
    QFile file(mydir.absoluteFilePath("Nodeconfig.xml"));
    if (!file.open(QIODevice::ReadOnly ))
    {
        return;
    }
    QDomDocument pluginxml;

    pluginxml.setContent(&file);
    file.close();
    file.open(QIODevice::WriteOnly );
    QTextStream xmlstream(&file);

    QDomElement root = pluginxml.documentElement();
    QDomElement node = root.firstChild().toElement();

    for(int i=0;i<ui->listWidget->count();i++)
    {
        node.setAttribute("value",ui->listWidget->item(i)->text());
        node.setTagName("nodetolaunch");
        node = node.nextSibling().toElement();
    }
    for(int i=0;i<ui->listWidget_2->count();i++)
    {
        node.setAttribute("value",ui->listWidget_2->item(i)->text());
        node.setTagName("nodelaunched");
        node = node.nextSibling().toElement();
    }
    xmlstream<<pluginxml.toString();
    file.close();

}

void ROSnodemanager::on_pushButton_2_clicked()
{
    m_list.clear();
    ui->listWidget_4->clear();
    ui->listWidget_3->clear();
    ros::V_string v_nodes;
    ros::master::getNodes(v_nodes);
    for (std::string elem : v_nodes) {
        ui->listWidget_4->addItem(QString::fromStdString(elem));
        m_list.append(QString::fromStdString(elem));
    }

}

void ROSnodemanager::on_pushButton_6_clicked()
{
    int n = ui->listWidget_4->currentRow();
    if(n == -1) { return; }
    ui->listWidget_3->addItem(ui->listWidget_4->takeItem(n));
}

void ROSnodemanager::on_pushButton_5_clicked()
{
    int n = ui->listWidget_3->currentRow();
    if(n == -1) { return; }
    ui->listWidget_4->addItem(ui->listWidget_3->takeItem(n));
}

void ROSnodemanager::on_pushButton_7_clicked()
{
    QString text;
    for(int i = 0; i < ui->listWidget_3->count(); i++) {
        text="rosnode kill  "+ ui->listWidget_3->item(i)->text()+"&";
        std::system(text.toLatin1().data());
    }
}

void ROSnodemanager::on_pushButton_clicked()
{
    m_list.clear();
    ui->listWidget_5->clear();
    ros::master::V_TopicInfo master_topics;
    ros::master::getTopics(master_topics);

    for (ros::master::V_TopicInfo::iterator it = master_topics.begin() ; it != master_topics.end(); it++)
    {
      const ros::master::TopicInfo& info = *it;
      ui->listWidget_5->addItem(QString::fromStdString(info.name));
      m_list.append( QString::fromStdString(info.name)) ;
    }
}
