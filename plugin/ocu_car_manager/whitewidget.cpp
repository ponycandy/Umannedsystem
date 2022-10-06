#include "whitewidget.h"
#include "ui_whitewidget.h"

whitewidget::whitewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::whitewidget)
{
    ui->setupUi(this);
}

whitewidget::~whitewidget()
{
    delete ui;
}
