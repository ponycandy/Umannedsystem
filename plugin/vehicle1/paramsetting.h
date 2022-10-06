#ifndef PARAMSETTING_H
#define PARAMSETTING_H

#include <QWidget>

namespace Ui {
class Paramsetting;
}

class Paramsetting : public QWidget
{
    Q_OBJECT

public:
    explicit Paramsetting(QWidget *parent = nullptr);
    ~Paramsetting();

private:
    Ui::Paramsetting *ui;
};

#endif // PARAMSETTING_H
