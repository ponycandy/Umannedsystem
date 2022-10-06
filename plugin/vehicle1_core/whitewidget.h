#ifndef WHITEWIDGET_H
#define WHITEWIDGET_H

#include <QWidget>

namespace Ui {
class whitewidget;
}

class whitewidget : public QWidget
{
    Q_OBJECT

public:
    explicit whitewidget(QWidget *parent = nullptr);
    ~whitewidget();

private:
    Ui::whitewidget *ui;
};

#endif // WHITEWIDGET_H
