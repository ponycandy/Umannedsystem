#pragma once

#include <QtPlugin>

#include "defines/QxxlcDefines.h"

struct QxxlcOcCoreService
{
public:
    virtual ~QxxlcOcCoreService() {}

    /**
     * @brief setConnectStatus
     * @param connectStatus
     */
    virtual void setConnectStatus(bool connectStatus)=0;

    /**
     * @brief setControlStatus
     * @param controlStatus
     */
    virtual void setControlStatus(bool controlStatus)=0;

    /**
     * @brief addView
     * @param viewKind
     * @param view
     */
    virtual void addView(OcuDefines::QxxlcViewKind viewKind, QWidget *view) = 0;

    /**
     * @brief changeView
     * @param viewKind
     */
    virtual void changeView(OcuDefines::QxxlcViewKind viewKind) = 0;

    /**
     * @brief changeView
     * @param viewKind
     */
    virtual OcuDefines::QxxlcViewKind getCurrentView() = 0;

    /**
     * @brief changeMenu
     * @param oldMenu
     * @param newMenu
     * @param text
     */
    virtual void changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text) = 0;

    /**
     * @brief changeMenu
     * @param num
     * @param newMenu
     * @param text
     */
    virtual void changeMenu(const int num,const QString &newMenu,const QString &text) = 0;

    /**
     * @brief menuShowAnimation
     */
    virtual void menuShowAnimation() = 0;


};

Q_DECLARE_INTERFACE(QxxlcOcCoreService, "QxxlcOcCoreService")
