#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("欢迎使用轻量化框架FeatherWeight");
    w.show();
    return a.exec();
}
