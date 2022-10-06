#include "paramsetting.h"
#include "ui_paramsetting.h"

Paramsetting::Paramsetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paramsetting)
{
    ui->setupUi(this);
}

Paramsetting::~Paramsetting()
{
    delete ui;
}
