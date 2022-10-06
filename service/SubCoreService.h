#pragma once

#include <QtPlugin>

#include "defines/OcuDefines.h"

struct SubCoreService
{
public:
    virtual ~SubCoreService() {}

    /**
        * @brief addView
        * @param viewKind
        * @param view
        */
    virtual void addView(UcsDefines::UcsViewKind viewKind, QWidget *view) = 0;

    /**
     * @brief removeView
     * @param viewKind
     */
    virtual void removeView(UcsDefines::UcsViewKind viewKind)= 0;

    /**
        * @brief changeView
        * @param viewKind
        */
    virtual void changeView(UcsDefines::UcsViewKind viewKind) = 0;

    /**
        * @brief changeView
        * @param viewKind
        */
    virtual UcsDefines::UcsViewKind getCurrentView() = 0;


    /**
     * @brief setWdigetSwitch
     * 0：标识视频界面是第一个屏，主控界面为第二个屏
     * 1：标识视频界面是第二个屏，主控界面为第一个屏
     */
    virtual void setWdigetSwitch(int type) = 0;
};

Q_DECLARE_INTERFACE(SubCoreService, "SubCoreService")
