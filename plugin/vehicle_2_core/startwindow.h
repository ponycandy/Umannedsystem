#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QToolButton>
#include <QMap>
#include "service/Coreservice.h"

#include "service/eventservice.h"
#include "service/vehicle_2_coreservice.h"
#include "whitewidget.h"
namespace Ui {
class startwindow;
}

class startwindow : public QWidget,public EventService,public vehicle_2_coreservice
{
    Q_OBJECT
    Q_INTERFACES(vehicle_2_coreservice)


public:
    explicit startwindow(QWidget *parent = nullptr);
    ~startwindow();
    void setupwidget();
    void EventTriggeres(XTLevent event) override;
    void buildMenu(int type);
    void clearMenu();
    void setButton(int index, const QString &text, const QString &topic, const QString &icon);

    void setConnectStatus(bool connectStatus) override;
     void setControlStatus(bool controlStatus) override;
    void addView(UcsDefines::UcsViewKind viewKind, QWidget *view)  override;
     void changeView(UcsDefines::UcsViewKind viewKind) override;
     UcsDefines::UcsViewKind getCurrentView() override;
    void changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text)  override;
     void changeMenu(const int num,const QString &newMenu,const QString &text) override;
    whitewidget *m_whitewidget;
private slots:
    void onMenuClicked();
private:
    Ui::startwindow *ui;
    QMap<int, int> widgetmap;

    /**
     * @brief m_leftWidget 左边按钮界面
     */
    QWidget *m_leftWidget;

    /**
     * @brief m_rightWidget 右边按钮界面
     */
    QWidget *m_rightWidget;

    /**
     * @brief m_leftLayout 左边按钮界面布局
     */
    QVBoxLayout *m_leftLayout;

    /**
     * @brief m_rightLayout 右边按钮界面布局
     */
    QVBoxLayout *m_rightLayout;

    /**
     * @brief m_buttons 按钮管理器
     */
    QMap<int, QToolButton *> m_buttons;
    Coreservice *m_service;

};

#endif // STARTWINDOW_H
