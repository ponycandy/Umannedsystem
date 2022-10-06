#pragma once

#include <QtGlobal>
#include <QMetaType>
#include <QByteArray>

namespace DjxlcDefines {

/************************************************************************/
/* ucs view kind                                                        */
/************************************************************************/

typedef enum {  
    UCS_VIEW_KIND_NONE = 0,
    UCS_VIEW_KIND_LOGIN,                              /*登陆界面*/
    UCS_VIEW_KIND_USER_MANGER,                        /*user管理界面*/
    UCS_VIEW_KIND_SYSTEM_SETTING,                     /*系统设置界面*/
    UCS_VIEW_KIND_CAR_MANAGER,                        /*车辆管理界面*/
    UCS_VIEW_KIND_CAR_NET_CONFIG,                     /*车辆网络参数界面*/
    UCS_VIEW_KIND_CAR_NET_CONFIG_ADD,                 /*ADD车辆网络参数界面*/
    UCS_VIEW_KIND_CAR_NET_CONFIG_EDIT,                /*EDIT车辆网络参数界面*/
    UCS_VIEW_KIND_ACCOUNT_MANAGEMENT,                 /*账户管理界面*/
    UCS_VIEW_KIND_LOG_MANAGER,                        /*登陆管理界面*/
    UCS_VIEW_KIND_MAP,                                /*地图界面*/

    /*轻型轮式无人平台*/
    UCS_VIEW_KIND_CONTROL,                            /*使能界面*/
    UCS_VIEW_KIND_UNCONTROLLED,                       /*取消使能界面-设置为地图界面，按钮策略不同*/
    UCS_VIEW_KIND_ELECTRICCONTROL,                    /*上电参数设置界面*/
    UCS_VIEW_KIND_OPERATION_MODE,                     /*操作模式界面*/
    UCS_VIEW_KIND_OPERATION_MODE_PATH_FOLLOE,         /*路径跟随界面*/
    UCS_VIEW_KIND_OPERATION_MODE_ONE_KEY_BACK,        /*一键返航界面*/
    UCS_VIEW_KIND_VIDEO_MODE,                         /*视频控制界面*/
    UCS_VIEW_KIND_LOAD_MAP,                           /*地图界面*/
    UCS_VIEW_KIND_CHARIOT_SET,                        /*战车设置界面*/
    UCS_VIEW_KIND_CHARIOT_CONTROL,                    /*战车控制界面*/
    UCS_VIEW_KIND_FC,                                 /*火控界面*/
    UCS_VIEW_KIND_VEHICLE_STATUS,                     /*车辆状态*/

    /*档位设置界面*/
    UCS_VIEW_KIND_GEAR_SET,                           /*档位设置界面*/
    UCS_VIEW_KIND_PLOTTING_MANAGER,                   /*标绘管理界面*/

    /*地图工具相关界面*/
    UCS_VIEW_KIND_MAP_TOOLS_WIDGET,                   /*地图工具界面*/
    UCS_VIEW_KIND_MAP_TOOLS_LAYER_MANAGER,            /*图层管理*/
    UCS_VIEW_KIND_MAP_TOOLS_DISTANCE_MEASURMENT,      /*距离测量界面*/
    UCS_VIEW_KIND_MAP_TOOLS_AREA_MEASURMENT,          /*面积测量界面*/
    UCS_VIEW_KIND_MAP_TOOLS_MAP_MOVE,                 /*面积测量界面*/

    /*联动任务*/
    UCS_VIEW_KIND_RADIO_SETTING,                      /*电台设置界面*/

    UCS_VIEW_KIND_VIDEO_PLAYBACK                      /*视频回放*/
}UcsViewKind;

} // namespace UcsDefines

