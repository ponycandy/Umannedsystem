#include "ros_rviz_widget.h"
#include "ui_ros_rviz_widget.h"

ros_rviz_widget::ros_rviz_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ros_rviz_widget)
{
    ui->setupUi(this);
}

ros_rviz_widget::~ros_rviz_widget()
{
    delete ui;
}
