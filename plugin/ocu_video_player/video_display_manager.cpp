#include "video_display_manager.h"
#include "ui_video_display_manager.h"

video_display_manager::video_display_manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video_display_manager)
{
    ui->setupUi(this);
}

video_display_manager::~video_display_manager()
{
    delete ui;
}
