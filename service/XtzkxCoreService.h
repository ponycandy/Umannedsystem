#pragma once

#include <QtPlugin>
#include <QWidget>

#include "event/XtzkxEventContants.h"

#include "defines/XtzkxDefines.h"


struct XtzkxCoreService
{
public:
    virtual ~XtzkxCoreService() {}


    /**
     * @brief getCommandControlWidget
     * @return
     */
    virtual QWidget*  getCommandControlWidget() = 0;

    /**
     * @brief changeView
     * @param viewKide
     */
    virtual  void  changeView(XtzkxDefines::XtzkxViewKind  viewKide) = 0;
};

Q_DECLARE_INTERFACE(XtzkxCoreService, "XtzkxCoreService")
