#include "video_display_widget.h"
#include "ui_video_display_widget.h"

video_display_widget::video_display_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video_display_widget)
{
    ui->setupUi(this);
}

video_display_widget::~video_display_widget()
{
    delete ui;
}
