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

/**
 *  core中实现的是一个StackWidget
 *  OCU 是整体控制相关的界面
 *  每型车车控是一个StackWidget，车控的界面切换需要在车型的中进行控制
 *  每型车火控是一个StackWidget，火控的界面切换需要在车型的中进行控制
 *  每型车指控是一个StackWidget，火控的界面切换需要在车型的中进行控制
 */

namespace UcsDefines {

//!************************************************************************
//!* ucs view kind                                                        *
//!************************************************************************

typedef enum {
    UCS_VIEW_KIND_NONE = 0,
    UCS_VIEW_KIND_MAIN,                               //! 主界面
    VEHICLE_1_WINDOW,                                   //!vehicle 1 interface
    NETCONFIG_INTERFACE,                                   //!NETCONFIG_INTERFACE 1 interface
    ROSNODEMANAGEMENT,                                   //ROSNODEMANAGEMENT
    VEHICLE1_CONTROL,                                   //ROSNODEMANAGEMENT



    UCS_VIEW_KIND_LOGIN,                               //! 登陆界面
    UCS_VIEW_KIND_USER_MANGER,                         //! user管理界面
    UCS_VIEW_KIND_SYSTEM_SETTING,                      //! 系统设置界面
    UCS_VIEW_KIND_CAR_MANAGER,                         //! 车辆管理界面
    UCS_VIEW_KIND_CAR_NET_PARA_CONFIG,                 //! 车辆网络参数配置界面
    UCS_VIEW_KIND_RADIO_MANAGER,                       //! 电台管理界面

    UCS_VIEW_KIND_ACCOUNT_MANAGEMENT,                  //! 账户管理界面
    UCS_VIEW_KIND_PLUS_ACCOUNT_MANAGEMENT,             //! 三级用户管理界面
    UCS_VIEW_KIND_LOG_MANAGER,                         //!
    UCS_VIEW_KIND_OUTPUR_INFO,                         //!
    UCS_VIEW_KIND_COMMAND_INFO,                        //!
    UCS_VIEW_KIND_MAP,                                 //! 地图界面
    UCS_VIEW_KIND_ENABLE,

    UCS_VIEW_KIND_SUB_CORE,                            //! 第二张界面主界面
    UCS_VIEW_KIND_SUB_CORE_MAP,                        //! 第二张界面地图界面
    UCS_VIEW_KIND_SUB_CORE_VIDEO,                      //! 第二张界面视频界面


    UCS_VIEW_KIND_MIANWIDOW_CORE,                      //!整体框架的主界面

    UCS_VIEW_KIND_QXXLC_OPERATION_CONTROL,             //!轻型巡逻车车辆操控
    UCS_VIEW_KIND_QXXLC_FIRE_CONTROL,                  //!轻型巡逻车火控操控
    UCS_VIEW_KIND_QXXLC_COMMAND_CONTROL,               //!轻型巡逻车指控界面

    UCS_VIEW_KIND_ZXLSC_OPERATION_CONTROL,             //!中型轮式车车辆操控
    UCS_VIEW_KIND_ZXLSC_FIRE_CONTROL,                  //!中型轮式车火控操控
    UCS_VIEW_KIND_ZXLSC_COMMAND_CONTROL,               //!中型轮式车指控界面

    UCS_VIEW_KIND_ZXLDC_OPERATION_CONTROL,             //!中型履带车车辆操控
    UCS_VIEW_KIND_ZXLDC_FIRE_CONTROL,                  //!中型履带车火控操控
    UCS_VIEW_KIND_ZXLDC_COMMAND_CONTROL,               //!中型履带车指控界面

    UCS_VIEW_KIND_XXDZZ_OPERATION_CONTROL,             //!新型电子战车辆操控
    UCS_VIEW_KIND_XXDZZ_FIRE_CONTROL,                  //!新型电子战火控操控
    UCS_VIEW_KIND_XXDZZ_COMMAND_CONTROL,               //!新型电子战指控界面

    UCS_VIEW_KIND_ZXBLG_OPERATION_CONTROL,             //!中型北理工车辆操控
    UCS_VIEW_KIND_ZXBLG_FIRE_CONTROL,                  //!中型北理工火控操控
    UCS_VIEW_KIND_ZXBLG_COMMAND_CONTROL,               //!中型北理工指控界面

    UCS_VIEW_KIND_XXFKC_OPERATION_CONTROL,             //!新型防空车车辆操控
    UCS_VIEW_KIND_XXFKC_FIRE_CONTROL,                  //!新型防空车火控操控
    UCS_VIEW_KIND_XXFKC_COMMAND_CONTROL,               //!新型防空车指控界面

    UCS_VIEW_KIND_JJLSC_OPERATION_CONTROL,             //!军交8*轮式车辆操控
    UCS_VIEW_KIND_JJLSC_FIRE_CONTROL,                  //!军交8*轮式火控操控
    UCS_VIEW_KIND_JJLSC_COMMAND_CONTROL,               //!军交8*轮式指控界面

    UCS_VIEW_KIND_BKLSC_OPERATION_CONTROL,             //!207所8*8轮式车辆操控
    UCS_VIEW_KIND_BKLSC_FIRE_CONTROL,                  //!207所8*8轮式火控操控
    UCS_VIEW_KIND_BKLSC_COMMAND_CONTROL,               //!207所8*8轮式指控界面

    UCS_VIEW_KINE_OCU_CC_CONTROL,                      //! 指控信息显示界面
    UCS_VIEW_KIND_DJXLC_OPERATION_CONTROL,             //! 岛礁巡逻车操控界面
    UCS_VIEW_KIND_DJXLC_FIRE_CONTROL,                  //! 岛礁巡逻车火控界面
} UcsViewKind;

typedef enum {
    UCS_VIEW_INDEX_NONE = 0,
    UCS_VIEW_INDEX_QXXLC,
    UCS_VIEW_INDEX_ZXLSC,
    UCS_VIEW_INDEX_ZXLDC,
    UCS_VIEW_INDEX_XXDZZ,
    UCS_VIEW_INDEX_ZXBLG,
    UCS_VIEW_INDEX_XXFKC,
    UCS_VIEW_INDEX_207LSC,
    UCS_VIEW_INDEX_QXXLC_FIRECONTROL,
    UCS_VIEW_INDEX_ZXLSC_FIRECONTROL,
    UCS_VIEW_INDEX_ZXLDC_FIRECONTROL,
    UCS_VIEW_INDEX_XXDZZ_FIRECONTROL,
    UCS_VIEW_INDEX_ZXBLG_FIRECONTROL,
    UCS_VIEW_INDEX_XXFKC_FIRECONTROL,
    UCS_VIEW_INDEX_207LSC_FIRECONTROL
}UcsViewIndex;

//!** **********************************************************************
//!* ucs data kind                                                         *
//!*************************************************************************
}

