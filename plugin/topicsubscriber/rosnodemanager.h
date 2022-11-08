#ifndef ROSNODEMANAGER_H
#define ROSNODEMANAGER_H

#include <QWidget>
#include <service/ocu_car_coreservice.h>
#include <service/ROSnodeservice.h>
namespace Ui {
class ROSnodemanager;
}

class ROSnodemanager : public QWidget,public ROSnodeservice
{
    Q_OBJECT

public:
    explicit ROSnodemanager(QWidget *parent = nullptr);
    ~ROSnodemanager();
    void destroyall() override;

private slots:
    void on_add_button_clicked();

    void on_del_button_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

public slots:
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();

private:
    Ui::ROSnodemanager *ui;
    QStringList m_list;
    ocu_car_coreservice *m_service;

};

#endif // ROSNODEMANAGER_H
