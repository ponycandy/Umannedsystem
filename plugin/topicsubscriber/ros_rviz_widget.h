#ifndef ROS_RVIZ_WIDGET_H
#define ROS_RVIZ_WIDGET_H

#include <QWidget>

namespace Ui {
class ros_rviz_widget;
}

class ros_rviz_widget : public QWidget
{
    Q_OBJECT

public:
    explicit ros_rviz_widget(QWidget *parent = nullptr);
    ~ros_rviz_widget();

private:
    Ui::ros_rviz_widget *ui;
};

#endif // ROS_RVIZ_WIDGET_H
