#include "ros_rviz_widget.h"
#include "ui_ros_rviz_widget.h"

ros_rviz_widget::ros_rviz_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ros_rviz_widget)
{
    ui->setupUi(this);
    rviz::RenderPanel *render_panel_=new rviz::RenderPanel;

    //设置布局
    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    mainLayout->addWidget(render_panel_);
    //初始化rviz控制对象
    rviz::VisualizationManager* manager_=new rviz::VisualizationManager(render_panel_);
    //初始化camera 这行代码实现放大 缩小 平移等操作
    render_panel_->initialize(manager_->getSceneManager(),manager_);

    //显示
    manager_->initialize();
    manager_->removeAllDisplays();
    manager_->startUpdate();

    //设置rviz左测的参数设置
    manager_->setFixedFrame("/vehicle_link");

    //创建一个类型为rviz/PointCloud2的图层，用于接收topic为points_map的点云数据，就是我最终底图的图层
    rviz::Display *map_=manager_->createDisplay("rviz/PointCloud2","pointCloud2",true);

    map_->subProp("Topic")->setValue("/os_cloud_node/points");
    map_->subProp("Invert Rainbow")->setValue("true");
    map_->subProp("Style")->setValue("Flat Squares");
    map_->subProp("Size (m)")->setValue("0.1");
    map_->subProp("Color Transformer")->setValue("FlatColor");
    map_->subProp("Queue Size")->setValue("10");
    map_->subProp("Alpha")->setValue("1");

}

ros_rviz_widget::~ros_rviz_widget()
{
    delete ui;
}
