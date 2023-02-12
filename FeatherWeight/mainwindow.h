#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "f_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString editcpp(QString str,QString A);
    QString editall(QString str,QString origin,QString target);
    QString get_text_between(QString start,QString endtext,QString text);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


private:
    Ui::MainWindow *ui;
    QString depend_plugin_name;
    QString depend_plugin_name_pro_str;
    QString dependency_name;
};
#endif // MAINWINDOW_H
