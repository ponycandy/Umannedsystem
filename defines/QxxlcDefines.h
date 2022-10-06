/******************************************************************************
* File:     OcuDefines.h
* Author:   liziqiang
* Company:  xinchuanhui
* Time      2021-07-01
******************************************************************************/
#pragma once

#include <QtGlobal>
#include <QMetaType>
#include <QByteArray>

namespace OcuDefines {

//!************************************************************************
//!* ucs view kind                                                        *
//!************************************************************************

typedef enum {
    OCU_VIEW_KIND_QXXLC_CAR_NONE = 0,
    OCU_VIEW_KIND_QXXLC_CAR_ENABLE,
    OCU_VIEW_KIND_QXXLC_CAR_CONTROL,                  //! 中型轮式车使能界面
    OCU_VIEW_KIND_QXXLC_CAR_UNCONTROLLED,             //! 中型轮式车取消使能界面
    OCU_VIEW_KIND_QXXLC_CAR_ELECTRICCONTROL,          //! 中型轮式车上电参数设置界面
    OCU_VIEW_KIND_QXXLC_CAR_ALTITUDE_CONTROL,
    OCU_VIEW_KIND_QXXLC_CAR_REMOTE_CONTROL_DRIVER,    //! 中型轮式车遥控驾驶模式
    OCU_VIEW_KIND_QXXLC_CAR_AUTONOMOUS_DRIVER,        //! 中型轮式车自主驾驶模式
    OCU_VIEW_KIND_QXXLC_CAR_VIDEO,                    //! 中型轮式车视频模式
    OCU_VIEW_KIND_QXXLC_CAR_TASK_MANAGER,             //! 中型轮式车任务管理
    OCU_VIEW_KIND_QXXLC_CAR_SYSTEM_SETTING_CONTROL,   //! 中型轮式车主控界面系统设置
    OCU_VIEW_KIND_QXXLC_CAR_FIRE_CONTROL_MANAGER,     //! 中型轮式车载荷任务界面
    OCU_VIEW_KIND_QXXLC_CAR_DRONEINFO,                //! 巡逻车无人机信息界面

    OCU_VIEW_KIND_QXXLC_CAR_COMMAND_CONTROL,                //! 巡逻车无人机信息界面





    /** ***************************便携式车辆操控界面**********************************/
    OCU_VIEW_KIND_PORTABLE_CAR_CONNECTED,             //! 便携式车连接界面
    OCU_VIEW_KIND_PORTABLE_CAR_ENABLE,                //! 便携式车使能界面
    OCU_VIEW_KIND_PORTABLE_CAR_CONTROL,               //! 便携式车使能界面

    OCU_VIEW_KIND_PORTABLE_CAR_CHASSIS,               //! 便携式车底盘设置界面
    OCU_VIEW_KIND_PORTABLE_CAR_DEVICE_SETTING,        //! 便携式车档位设置界面

    OCU_VIEW_KIND_PORTABLE_CAR_FIRE_CONTROL,          //! 便携式车上电参数设置界面
    OCU_VIEW_KIND_PORTABLE_CAR_GEAR_SETTING,          //! 便携式车档位设置界面
    OCU_VIEW_KIND_PORTABLE_CAR_OPERATION_MODE,        //! 便携式车操控模式界面
    OCU_VIEW_KIND_PORTABLE_CAR_VIDEO_CHANNEL,         //! 便携式车视频通道界面

    OCU_VIEW_KIND_SHARE_VIDEO,                        //! 便携视频界面
} QxxlcViewKind;


}

