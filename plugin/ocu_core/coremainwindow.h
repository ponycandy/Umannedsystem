#ifndef COREMAINWINDOW_H
#define COREMAINWINDOW_H

#include <QWidget>
#include "service/Coreservice.h"
#include "defines/OcuDefines.h"
#include "coreviewmanager.h"
#include "QVBoxLayout"
#include <QCloseEvent>
#include <QApplication>
#include <QPainter>

class coremainwindow : public QWidget,public Coreservice
{
    Q_OBJECT
    Q_INTERFACES(Coreservice)

public:
    explicit coremainwindow(QWidget *parent = nullptr);
    ~coremainwindow();

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


    void setCurCarIndex(UcsDefines::UcsViewIndex index);

    UcsDefines::UcsViewIndex getCurCarIndex();

    /**
     * @brief setWdigetSwitch
     * 0：标识视频界面是第一个屏，主控界面为第二个屏
     * 1：标识视频界面是第二个屏，主控界面为第一个屏
     */
    void setWdigetSwitch(int type) override;

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
    void setupUi();

    /**
     * @brief releaseUi
     */
    void releaseUi();


private slots:

    /**
     * @brief slotCloseBtnClicked
     */
    void slotCloseBtnClicked();

protected:
    /**
     * @brief closeEvent
     * @param event
     */
    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;

    /**
     * @brief resizeEvent
     * @param event
     */
    void resizeEvent(QResizeEvent *event)Q_DECL_OVERRIDE;

    /**
     * @brief showEvent
     * @param event
     */
    void showEvent(QShowEvent* event)Q_DECL_OVERRIDE;

private:
    /**
     * @brief m_centralWidget
     */
    QWidget *m_centralWidget;
    CoreViewManager *m_viewManager;


   UcsDefines::UcsViewIndex m_CurrentCarIndex;

    /**
     * @brief m_CurrentViewKind
     */
    UcsDefines::UcsViewKind  m_CurrentViewKind;

};

#endif // COREMAINWINDOW_H
