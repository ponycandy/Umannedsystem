#pragma once

#include <QWidget>
#include <QApplication>
#include <QCloseEvent>

#include "service/OperationCoreServices.h"

class TitleWidget;
class StatusWidget;
class MenuManager;
class ViewManager;
class soyFramelessHelper;

/**
 * @brief The MainWindow class
 */
class MainWindow : public QWidget, public OperationCoreServices
{
    Q_OBJECT
    Q_INTERFACES(OperationCoreServices)
public:
    /**
     * @brief MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


    /**
     * @brief setTitleHide
     * @param isHide
     */
    void setTitleHide(bool isHide);

    /**
     * @brief setConnectStatus
     * @param connectStatus
     */
    void setConnectStatus(bool connectStatus)override;

    /**
     * @brief setControlStatus
     * @param controlStatus
     */
    void setControlStatus(bool controlStatus)override;

    /**
     * @brief addView
     * @param viewKind
     * @param view
     */
    void addView(UcsDefines::UcsViewKind viewKind, QWidget *view) override;

    /**
     * @brief changeView
     * @param viewKind
     */
    void changeView(UcsDefines::UcsViewKind viewKind) override;

    /**
     * @brief changeView
     * @param viewKind
     */
    UcsDefines::UcsViewKind getCurrentView() override;

    /**
     * @brief changeMenu
     * @param oldMenu
     * @param newMenu
     * @param text
     */
    void changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text) override;

    /**
     * @brief changeMenu
     * @param num
     * @param newMenu
     * @param text
     */
    void changeMenu(const int num,const QString &newMenu,const QString &text) override;


protected:
    /**
     * @brief paintEvent
     * @param event
     */
    void paintEvent(QPaintEvent *event);

private:
    /**
     * @brief setupUi
     */
    void setupUi(void);

    /**
     * @brief releaseUi
     */
    void releaseUi(void);

private slots:
    /**
     * @brief slotCloseBtnClicked
     */
    void slotCloseBtnClicked();

    /**
     * @brief slotMiniBtnClicked
     */
    void slotMiniBtnClicked();

    /**
     * @brief slotMaxBtnClicked
     */
    void slotMaxBtnClicked();

protected:
    /**
     * @brief closeEvent
     * @param event
     */
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief resizeEvent
     * @param event
     */
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief showEvent
     * @param event
     */
    void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;

private:
    /**
     * @brief m_centralWidget
     */
    QWidget *m_centralWidget;

    /**
     * @brief m_framelessHelper
     */
    soyFramelessHelper *m_framelessHelper;

    /**
     * @brief m_titleWidget
     */
    TitleWidget *m_titleWidget;

    /**
     * @brief m_statusWidget
     */
    StatusWidget *m_statusWidget;

    /**
     * @brief m_menuManager
     */
    MenuManager *m_menuManager;

    /**
     * @brief m_viewManager
     */
    ViewManager *m_viewManager;

    /**
     * @brief m_isWidgetShowState
     */
    bool  m_isWidgetShowState;

    /**
     * @brief m_CurrentViewKind
     */
    UcsDefines::UcsViewKind  m_CurrentViewKind;
};
