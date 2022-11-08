#ifndef ROS_RVIZ_WIDGET_H
#define ROS_RVIZ_WIDGET_H
#include <QVBoxLayout>
#include <QWidget>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include<rviz/tool.h>
#include <rviz/default_plugin/view_controllers/orbit_view_controller.h>
#include <rviz/view_manager.h>
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
