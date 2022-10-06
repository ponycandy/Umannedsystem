/******************************************************************************
* File:     statuswidget.h
* Author:   liziqiang
* Company:  xinchuanhui
* Time:     2021-07-02
******************************************************************************/
#pragma once

//! qt headers include
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QSpacerItem>

//! current file include
#include "ocu_operation_coreActivator.h"

#include "defines/OcuDefines.h"
#include "service/eventservice.h"

class BatteryWidget;

class StatusWidget : public QWidget,public EventService
{
    Q_OBJECT
public:
    /**
     * @brief StatusWidget
     * @param parent
     */
    explicit StatusWidget(QWidget *parent = nullptr);
    ~StatusWidget(void);


    /**
     * @brief changeView
     * @param viewKind
     */
    void  changeView(UcsDefines::UcsViewKind viewKind);

public slots:


    /**
     * @brief slotCloseBtnClicked
     * @param state
     */
    void  slotCloseBtnClicked(bool  state);

    /**
     * @brief slotLogoutBtnClicked
     * @param state
     */
    void  slotLogoutBtnClicked(bool state);

    /**
     * @brief slotMinimumBtnClicked
     * @param state
     */
    void  slotMinimumBtnClicked(bool  state);

    /**
     * @brief slotMaxmumBtnClicked
     * @param state
     */
    void  slotMaxmumBtnClicked(bool  state);

//以下函数均是event的响应函数，不要继续使用xtl的激发方式了
    void slotCrawlerCarChassisInfo(const XTLevent &event);
    void slotMiddleCarChassisInfo(const XTLevent &event);
    void slotCrawlerCarSpeedLimited(const XTLevent &event);
    void slotMiddleCarSpeedLimited(const XTLevent &event);
    void slotFireControLinkState(const XTLevent &event);
    void EventTriggeres(XTLevent event) override;

    /**
     * @brief slotUpDateTime
     */
    void  slotUpDateTime();


protected:
    /**
     * @brief paintEvent
     */
    void paintEvent(QPaintEvent *);

signals:
    /**
     * @brief sigMinimumBtnClicked
     */
    void   sigMinimumBtnClicked();

    /**
     * @brief sigMaxmumBtnClicked
     */
    void   sigMaxmumBtnClicked();

    /**
     * @brief sigCloseBtnClicked
     */
    void   sigCloseBtnClicked();

    /**
     * @brief sigLogoutBtnClicked
     */
    void   sigLogoutBtnClicked();

private:


    /**
     * @brief setupOtherWidget 设置状态界面
     */
    void setupOtherWidget(void);

    /**
     * @brief setupUi
     */
    void setupUi(void);

    /**
     * @brief setupEvent
     */
    void setupEvent(void);

    /**
     * @brief releaseMemberPointer
     */
    void releaseMemberPointer(void);

    /**
     * @brief setupTimer
     */
    void setupTimer(void);

    /**
     * @brief releaseTimer
     */
    void releaseTimer(void);

    /**
     * @brief setupLogo
     */
    void setupLogo(void);

    /**
     * @brief setExceptLogoWidget
     */
    void setExceptLogoWidget(void);

private:

    QWidget *m_logoWidget;

    QWidget *m_modeWidget;

    QWidget *m_statusWidget;

    QWidget *m_otherWidget;

    QWidget *m_statusAndOtherWidget;

    QWidget *m_exceptLogoWidget;

    //! 主控制布局
    QHBoxLayout *m_centralLayout;

    //! logo布局
    QHBoxLayout *m_logoLayout;


    QHBoxLayout *m_modeLayout;
    QHBoxLayout *m_statusLayout;
    QHBoxLayout *m_otherLayout;
    QHBoxLayout *m_statusAndOtherLayout;

    QVBoxLayout *m_exceptLogoLayout;


    QSpacerItem *m_verticalSpacer;



    QLabel *m_logoutIcon;

    QLabel *m_timeIcon;
    QTimer *timer;


};
