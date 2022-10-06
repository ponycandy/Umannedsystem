#ifndef NETCONFIGWIDGET_H
#define NETCONFIGWIDGET_H

#include <QWidget>
#include <QMap>
#include  <QtXml>
#include <QDomDocument>
#include <QDir>
namespace Ui {
class Netconfigwidget;
}

class Netconfigwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Netconfigwidget(QWidget *parent = nullptr);
    ~Netconfigwidget();
    void readconfig();
    void setconfig();
    int availabe_row=0;
    QMap<QString,int> m_map;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::Netconfigwidget *ui;
};

#endif // NETCONFIGWIDGET_H
