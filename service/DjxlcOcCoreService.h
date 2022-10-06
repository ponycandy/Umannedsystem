#pragma once

#include <QtPlugin>

#include <QWidget>

#include "defines/DjxlcDefines.h"

struct DjxlcOcCoreService
{
public:
    virtual ~DjxlcOcCoreService() {}
    /**
     * @brief getMainWindow
     * @return
     */
    virtual QWidget *getMainWindow() = 0;

    /**
     * @brief getCentralWidget
     * @return
     */
    virtual QWidget *getCentralWidget() = 0;

    /**
     * @brief addView
     * @param viewKind
     * @param view
     */
    virtual void addView(DjxlcDefines::UcsViewKind viewKind, QWidget *view) = 0;

    /**
     * @brief changeView
     * @param viewKind
     */
    virtual void changeView(DjxlcDefines::UcsViewKind viewKind) = 0;

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
     * @brief getCurrentUcsViewKind
     * @return
     */
    virtual DjxlcDefines::UcsViewKind getCurrentUcsViewKind() = 0;

    /**
     * @brief setStatusWidgetHide       ×´Ì¬À¸½çÃæÊÇ·ñÒþ²Ø
     */
    virtual void setStatusWidgetHide(bool isHide) = 0;
};

Q_DECLARE_INTERFACE(DjxlcOcCoreService, "Djxlc.service.CoreService")
