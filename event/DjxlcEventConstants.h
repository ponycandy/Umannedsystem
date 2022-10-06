#pragma once

namespace DjxlcEventConstants {
    /************************************************************************/
    /* event TOPIC                                                          */
    /************************************************************************/
    const char TOPIC_LINK_CLICKED[] = "djxlc/link/clicked";  // link
    const char TOPCI_MENU_CLICKED[] = "djxlc/menu/clicked";  // topics
    const char TOPCI_TASK_RECEVIE[] = "djxlc/task/receive";  // topics
    const char TOPCI_Net_Data_RECEVIE[] = "djxlc/net/data/receive"; // topics
    const char PROPERTY_ID[] = "id";    // properties
    const char TOPCI_LOGIN_SUCCESS[] = "djxlc/login/success";
    const char TOPCI_LOGIN_EXIT[] = "djxlc/login/exit";
    const char TOPCI_ADMIN_LOGIN_SUCCESS[] = "djxlc/admin/login/success";

    /***************************************车辆状态量TOPIC**************************************/
    const char TOPIC_CAR_STATE_ENABLE[] = "djxlc/car/state/enable";/*车辆使能*/
    const char TOPIC_CAR_STATE_CONNECT[] = "djxlc/car/state/connect";/*车辆链接*/

    /***************************************通信状态量TOPIC**************************************/
    const char TOPIC_COMMUNICATION_STATE_CHASSIS[] = "djxlc/communication/state/chassis";/*底盘通信状态*/
    const char TOPIC_COMMUNICATION_STATE_COMPUTER[] = "djxlc/communication/state/computer";/*自主计算机通信状态*/

    /***************************************车辆状态量分发TOPIC**************************************/
    const char TOPIC_CAR_STATE_STATUS_BAR_INFO[] = "djxlc/car/state/status/bar/info";/*状态栏显示*/
    const char TOPIC_CAR_STATE_ELECTICAL_INFO[] = "djxlc/car/state/electrical/info";/*车辆上电状态*/
    const char TOPIC_CAR_STATE_WARING_INFO[] = "djxlc/car/state/waring/info";/*车辆告警信息*/
    const char TOPIC_CAR_STATE_GEAR_CHANGED[] = "djxlc/car/state/gear/changed";/*档位变化*/
    
    /***************************************底盘数据接收TOPIC****************************************/
    const char TOPIC_Chassis_Main_ONE[]     = "djxlc/net/chassis/main/one"; /*底盘主要信息1*/
    const char TOPIC_Chassis_Main_TWO[]     = "djxlc/net/chassis/main/two"; /*底盘主要信息2*/
    const char TOPIC_Chassis_Detail_ONE[]   ="djxlc/net/chassis/detail/one";/*底盘详细信息1*/
    const char TOPIC_Chassis_Detail_TWO[]   ="djxlc/net/chassis/detail/two";/*底盘详细信息2*/
    const char TOPIC_Chassis_Detail_THREE[] ="djxlc/net/chassis/detail/three";/*底盘详细信息3*/
    const char TOPIC_Chassis_Detail_FOUR[]  ="djxlc/net/chassis/detail/four";/*底盘详细信息4*/
    const char TOPIC_Chassis_Detail_FIVE[]  ="djxlc/net/chassis/detail/five";/*底盘详细信息5*/
    const char TOPIC_Chassis_Detail_SIX[]   ="djxlc/net/chassis/detail/six";/*底盘详细信息6*/
    const char TOPIC_Chassis_Detail_SEVEN[] ="djxlc/net/chassis/detail/seven";/*底盘详细信息7*/

    /***************************************便携端数据接收TOPIC**************************************/
    const char TOPIC_PORTABLE_TASK_ACK[] ="djxlc/portable/task/ack";/*便携端任务帧*/
    const char TOPIC_PORTABLE_TASK[] ="djxlc/portable/task/ack";/*便携端任务帧*/


    /***************************************操控模式设置TOPIC****************************************/  
    const char TOPIC_OPERATION_MODE[] = "djxlc/opration/mode";/*操控模式的topic*/
    const char TOPIC_OPERATION_MODE_PATH_FOLLOW[] = "djxlc/operation/mode/path/follow";/*路径跟随模式的topic*/
    const char TOPIC_OPERATION_MODE_ONE_KEY_BACK[] = "djxlc/operation/mode/one/key/back";/*一键返航模式的topic*/
    const char TOPIC_OPERATION_MODE_SWITCH[] = "djxlc/operation/mode/switch";/*操控模式切换*/
    const char TOPIC_OPERATION_PATH_RECORD_CONTROL[] = "djxlc/operation/path/record/control";/*路点记录控制*/
    const char TOPIC_OPERATION_WIDDGET_SWITCH_CONTROL_WIDGET[] = "djxlc/operation/widget/switch/control/widget";/*操控模式界面切换控制界面*/

    /************************************操控模式路径跟踪与地图交互TOPIC********************************/
    const char TOPCI_PATH_FOLLOW_ADD_POINT_FROM_MAP[] = "djxlc/operation/mode/path/follow/add/point/from/map";/*路径跟随模式下从地图选点*/
    const char TOPCI_PATH_FOLLOW_ADD_POINT_FROM_MAP_RECIVE[] = "djxlc/operation/mode/path/follow/add/point/from/map/recive";/*路径跟随模式下接收从地图选点*/

    const char TOPIC_PATH_FOLLOW_POINT_MODIFICATION[] = "djxlc/operation/mode/path/follow/point/modification";/*路径跟随模式路径点修改*/
    const char TOPIC_PATH_FOLLOW_REMOVE_POINT[] = "djxlc/operation/mode/path/follow/remove/point";/*删除地图选的点 单个*/
    const char TOPIC_REMOVE_SELECTION_POINT_LINE[] = "djxlc/remove/selection/point/line"; /*删除地图选的点 整条线*/

    /************************************操控模式一键返航与地图交互TOPIC********************************/
    const char TOPIC_ONE_KEY_BANCK_PATH_POINT_EDIT[] = "djxlc/operation/mode/one/key/banck/path/point/edit";/*进入一键返航路径修改*/
    const char TOPIC_ONE_KEY_BANCK_POINT_MODIFICATION[] = "djxlc/operation/mode/one/key/banck/point/modification";/*一键返航路径点修改*/

    /*******************************************************自主计算机通信TOPIC***************************************/
    const char TOPCI_Computer_Status[] ="djxlc/net/computer/status";              /*自主计算机状态量上报*/
    const char TOPCI_Computer_Heart_Beat[] ="djxlc/net/computer/heart/beat";      /*自主计算机心跳回复*/
    const char TOPCI_Computer_Task[] ="djxlc/net/computer/task";                  /*自主计算机任务帧回复*/
    const char TOPCI_Computer_IMAGE[] ="djxlc/net/computer/image";                /*自主计算机图像上传*/
    const char TOPIC_COMPUTER_IMAGE_IS_SHOW[] = "djxlc/computer/image/is/show";   /*自主图像信息是否显示*/
    const char TOPIC_ISSUE_ONE_KEY_BACK_TASK[] = "djxlc/issue/one/key/back/task"; /*下发一键返航任务 topic*/

    /*******************************************************视频处理版通信TOPIC***************************************/
    const char TOPIC_VIDEO_OPEN_RESPONSE[] = "djxlc/video/open/response";                     /*打开音视频编码响应消息*/
    const char TOPIC_VIDEO_STOP_RESPONSE[] = "djxlc/video/stop/response";                     /*停止音视频编码响应消息*/
    const char TOPIC_VIDEO_SET_PARAMETER_RESPONSE[] = "djxlc/video/set/parameter/response";   /*设置视频参数响应消息*/
    const char TOPIC_VIDEO_GET_PARAMETER_RESPONSE[] = "djxlc/video/get/parameter/response";   /*获取视频编码参数响应消息*/
    const char TOPIC_VIDEO_SET_SHOW_MODE_RESPONSE[] = "djxlc/video/set/show/mode/response";   /*设置视频显示(拼接)模式响应消息*/
    const char TOPIC_VIDEO_GET_SHOW_MODE_RESPONSE[] = "djxlc/video/get/show/mode/response";   /*获取视频显示(拼接)模式响应消息*/

    /***************************************摇杆串口通信TOPIC*****************************************/
    const char TOPIC_SET_ROCKER_SERIALPORT_NAME[] = "djxlc/set/rocker/serialport/name"; /*设置摇杆的串口名的topic*/

    const char TOPIC_AXIS_JOYSTICK[] = "djxlc/serialport/axis/joystick";/*轴操纵杆 RS232 通信协议*/

    /***************************************界面按钮串口通信TOPIC*************************************/
    const char TOPIC_SET_SCREEN_BTN_SERIALPORT_NAME[] = "djxlc/set/screen/button/serialport/name";/*设置界面按钮 topic*/

    /***************************************语言设置TOPIC*************************************/
    const char TOPIC_LANGUAGE_SCREEN_BUTTON[] = "djxlc/set/screen/button/language";/*屏幕按钮语言设置*/

    /***************************************地图工具事件TOPIC*****************************************/ 
    const char TOPIC_MAP_TOOLS_ENLARGE[] = "djxlc/map/tools/enlarge"; /*地图放大*/
    const char TOPIC_MAP_TOOLS_ENSMALL[] = "djxlc/map/tools/ensmall"; /*地图缩小*/
    const char TOPIC_MAP_TOOLS_MOVE[] = "djxlc/map/tools/move"; /*地图移动*/
    const char TOPIC_MAP_TOOLS_MOVE_UP[] = "djxlc/map/tools/move/up"; /*地图移动-向上*/
    const char TOPIC_MAP_TOOLS_MOVE_DOWN[] = "djxlc/map/tools/move/down"; /*地图移动-向下*/
    const char TOPIC_MAP_TOOLS_MOVE_RIGHT[] = "djxlc/map/tools/move/right"; /*地图移动-向右*/
    const char TOPIC_MAP_TOOLS_MOVE_LEFT[] = "djxlc/map/tools/move/left"; /*地图移动-向左*/
    const char TOPIC_MAP_TOOLS_DISTANCE_MEASURMENT[] = "djxlc/map/tools/distance/measurment"; /*距离测量*/
    const char TOPIC_MAP_TOOLS_AREA_MEASURMENT[] = "djxlc/map/tools/area/measurment";/*面积测量*/
    const char TOPIC_MAP_TOOLS_LAYER_MANAGER[] = "djxlc/map/tools/layer/manager";/*图层管理*/
    const char TOPIC_MAP_TOOLS_LAYER_MANAGER_RETURN[] = "djxlc/map/tools/layer/manager/return";/*图层管理返回*/
    const char TOPIC_MAP_TOOLS_MY_LOCATION[] = "djxlc/map/tools/my/location";/*我的位置*/
    /*distance measurment*/
    const char TOPIC_MAP_TOOLS_DISTANCE_ADD_POINT[] = "djxlc/map/tools/distance/add/point";/*测距选点*/
    const char TOPIC_MAP_TOOLS_DISTANCE_ADD_POINT_RESULT[] = "djxlc/map/tools/distance/add/point/result";/*距离测量结果*/
    const char TOPIC_MAP_TOOLS_DISTANCE_ADD_POINT_RECIVE[] = "djxlc/map/tools/distance/add/point/recive";
    /*area mesurment*/
    const char TOPIC_MAP_TOOLS_AREA_ADD_POINT[] = "djxlc/map/tools/area/add/point";    /*测面积选点*/
    const char TOPIC_MAP_TOOLS_AREA_ADD_POINT_RESULT[] = "djxlc/map/tools/area/add/point/result";    /*面积测量结果*/
    const char TOPIC_MAP_TOOLS_AREA_ADD_POINT_RECIVE[] = "djxlc/map/tools/area/add/point/recive";

    /***************************************告警信息显示TOPIC**************************************/
    const char TOPIC_WARING_INFO_WIDGET_STRETCH_CONTROL[] = "djxlc/waring/info/widget/stretch/control";/*告警界面伸张控制*/
    const char TOPIC_WARING_INFO_IMAGE_FLASH[] = "djxlc/waring/image/flash";/*告警图标闪烁*/

    /***************************************车辆网络参数配置TOPIC**************************************/
    const char TOPIC_CAR_NET_CONFIG_ADD[] = "djxlc/car/net/config/add";/*添加车辆网络参数配置*/
    const char TOPIC_CAR_NET_CONFIG_EDIT[] = "djxlc/car/net/config/edit";/*编辑车辆网络参数配置*/
    const char TOPIC_CAR_NET_CONFIG_REMOVE[] = "djxlc/car/net/config/remove";/*删除车辆网络参数配置*/
    const char TOPIC_CAR_NET_CONFIG_CHECK[] = "djxlc/car/net/config/check";/*查看车辆网络参数配置*/
    const char TOPIC_CAR_NET_CONFIG_SAVE[] = "djxlc/car/net/config/save";/*保存车辆网络参数配置*/

    /***************************************菜单键隐藏TOPIC**************************************/
    const char TOPIC_HIDE_MENU_KEY[] = "djxlc/hide/menu/key";/*隐藏左右按右键*/

    /***********************************MAP PLOTTING MANAGER TOPIC*************************************/
    const char TOPIC_MAP_PLOTTING_REMOVE_DISTANCE_PLOT[] = "djxlc/map/plotting/remove/distance/plot";/**/
    const char TOPIC_MAP_PLOTTING_REMOVE_AREA_PLOT[] = "djxlc/map/plotting/remove/area/plot";/**/
    const char TOPIC_MAP_PLOTTING_REMOVE_AUOTDRIVER_PLOT[] = "djxlc/map/plotting/remove/autodriver/plot";/**/
    const char TOPIC_MAP_AUTO_DRIVER_POINT_VALUE_CHANGED[] = "djxlc/map/auot/driver/point/value/changed";/**/

    /***************************************小履带车辆上报消息TOPIC**************************************/
    const char TOPIC_SLOT_REMOVE_LINE_AND_CLEAR_TABLE_DATE[] = "djxlc/slot/remove/line/and/clear/table/data";/*当地图上的线条删除时，情况tableView上的点位和数据*/

    /***************************************fc**************************************/
    const char TOPIC_FC_SITUATION_REPORT[] = "djxlc/fc/situation/report"; /*火控目标识别信息上报*/
    const char TOPIC_FC_GOAL_INFO_SHOW_MAP[] = "djxlc/fc/goal/info/show/map"; /*火控目标信息在地图标绘*/
    const char TOPIC_FC_REMOVE_GOAL_INFO_MAP[] = "djxlc/fc/remove/goal/info/map"; /*删除在地图上的火控目标信息*/

    const char TOPIC_OBSTACLE_AVOID_FLAG[] = "djxlc/obstacle/avoid/flag";/*避障标志*/
    const char TOPIC_CRATER_LOCTION[] = "djxlc/crater/loction";/*是否巡检*/
	
	


    /************************************************************************/
    /* Menu event                                                           */
    /************************************************************************/
    /** car net config*/
    const char MENU_EVENT_CAR_NET_CONFIG_CHECK_EDIT[100] = "djxlc/menu/event/car/net/config/check/edit";/*编辑参数*/
    const char MENU_EVENT_CAR_NET_CONFIG_CHECK_SAVE[100] = "djxlc/menu/event/car/net/config/check/save";/*保存参数*/
    const char MENU_EVENT_CAR_NET_CONFIG_ADD_SAVE[100] = "djxlc/menu/event/car/net/config/add/save";/*保存参数*/
    const char MENU_EVENT_CAR_NET_CONFIG_EDIT_SAVE[100] = "djxlc/menu/event/car/net/config/edit/save";/*保存参数*/
    const char MENU_EVENT_CAR_NET_CONFIG_RETURN[100] = "djxlc/menu/event/car/net/config/return";/*返回到上一界面*/

    /** uncontrol*/
    const char MENU_EVENT_UNCONTROL_RETURN[100] = "djxlc/menu/event/uncontrol/return";
    const char MENU_EVENT_UNCONTROL_CONTROL[100] = "djxlc/menu/event/uncontrol/control";  /*底盘使能*/
    /** control manager*/
    const char MENU_EVENT_MANAGER_QXSN[100] = "djxlc/menu/event/manager/qxsn";/*取消使能*/
    const char MENU_EVENT_MANAGER_SDKZ[100] = "djxlc/menu/event/manager/sdkz";
    const char MENU_EVENT_MANAGER_CKMS[100] = "djxlc/menu/event/manager/ckms";
    const char MENU_EVENT_MANAGER_CKMS_RETURN[100] = "djxlc/menu/event/manager/ckmsreturn";
    const char MENU_EVENT_MANAGER_SPQH[100] = "djxlc/menu/event/manager/spqh";
    const char MENU_EVENT_MANAGER_JZDT[100] = "djxlc/menu/event/manager/jzdt";
    const char MENU_EVENT_MANAGER_WZCX[100] = "djxlc/menu/event/manager/wzcx";
    const char MENU_EVENT_MANAGER_KSLD[100] = "djxlc/menu/event/manager/ksld";/*开始录点*/
    const char MENU_EVENT_MANAGER_JSLD[100] = "djxlc/menu/event/manager/jsld";/*结束录点*/
    const char MENU_EVENT_MANAGER_ZCKZ[100] = "djxlc/menu/event/manager/zckz";
    const char MENU_EVENT_MANAGER_SZ[100] = "djxlc/menu/event/manager/sz";
    const char MENU_EVENT_MANAGER_DWSZ[100] = "djxlc/menu/event/manager/dwsz";
    const char MENU_EVENT_MANAGER_LJBH[100] = "djxlc/menu/event/manager/ljbh";
    const char MENU_EVENT_MANAGER_DTGJ[100] = "djxlc/menu/event/manager/dtgj";
    const char MENU_EVENT_MANAGER_FC[100] = "djxlc/menu/event/manager/fc";    /*火控*/
    const char MENU_EVENT_MANAGER_CLZT[100] = "djxlc/menu/event/manager/clzt";/*车辆状态*/
    const char MENU_EVENT_MANAGER_DRIVE_STATE[100] = "djxlc/menu/event/manager/drive/state";/*qu dong状态*/
    const char MENU_EVENT_MANAGER_ENGRAY_STATE[100] = "djxlc/menu/event/manager/engray/state";/*neng yuan状态*/
    const char MENU_EVENT_MANAGER_ELECTRIC_STATE[100] = "djxlc/menu/event/manager/electric/state";/*dian qi状态*/
    const char MENU_EVENT_MANAGER_AUTO_STATE[100] = "djxlc/menu/event/manager/auto/state";/*zi zhu状态*/
    const char MENU_EVENT_MANAGER_RETURN[100] = "djxlc/menu/event/manager/return";
    /** fc*/
    const char MENU_EVENT_FC_CHECK_GOAL[100] = "djxlc/menu/event/manager/fc/check/goal";        /*查看火控目标信息*/
    const char MENU_EVENT_FC_REMOVE_GOAL[100] = "djxlc/menu/event/manager/fc/remove/goal";      /*删除火控目标信息*/
    const char MENU_EVENT_FC_NEW_FILE_FILE[100] = "djxlc/menu/event/manager/fc/new/goal/file";  /*新建火控目标文件*/
    /** account management*/
    const char MENU_EVENT_ACCOUNT_MANAGEMENT_RETURN[100] = "djxlc/menu/event/account_management/return";
    const char MENU_EVENT_ACCOUNT_MANAGEMENT_ADD[100] = "djxlc/menu/event/account_management/add/user";   /*增加新的用户*/
    const char MENU_EVENT_ACCOUNT_MANAGEMENT_EDIT[100] = "djxlc/menu/event/account_management/edit";      /*修改用户*/
    const char MENU_EVENT_ACCOUNT_MANAGEMENT_DELETE[100] = "djxlc/menu/event/account_management/delete";  /*删除用户*/
    /** log manager*/
    const char MENU_EVENT_LOG_RETURN[100] = "djxlc/menu/event/log_manager/return";
    const char MENU_EVENT_LOG_APP_RUN[100] = "djxlc/menu/event/log_manager/app_run";
    const char MENU_EVENT_LOG_TASK[100] = "djxlc/menu/event/log_manager/task";
    const char MENU_EVENT_LOG_SYSTEM_OPERATION[100] = "djxlc/menu/event/log_manager/sys_operation";
    const char MENU_EVENT_LOG_VEHICLE_RUN[100] = "djxlc/menu/event/log_manager/vehicle_run";
    const char MENU_EVENT_LOG_VEHICLE_STATUS[100] = "djxlc/menu/event/log_manager/vehicle_status";
    const char MENU_EVENT_LOG_DELETE[100] = "djxlc/menu/event/log_manager/delete";
    const char MENU_EVENT_LOG_EXPORT[100] = "djxlc/menu/event/log_manager/export";
    /** platform operation*/
    const char MENU_EVENT_PLATFORM_DISCONNECT[100] = "djxlc/menu/event/platform/disconnect";
    const char MENU_EVENT_PLATFORM_CHASIS_ENABLED[100] = "djxlc/menu/event/platform/chasis_enabled";
    /** 通信链路路径管理*/
    const char COMMUNICATION_OCU_TO_CHASSIS[100] = "djxlc/communication/ocu/to/chassis";/*ocu到底盘*/
    const char COMMUNICATION_OCU_TO_COMPUTER[100] = "djxlc/communication/ocu/to/computer";/*ocu到自主计算机*/
    const char COMMUNICATION_OCU_TO_FC[100] = "djxlc/communication/ocu/to/fc";/*ocu到火控*/
    const char COMMUNICATION_OCU_TO_VIDEO_PROCESS[100] = "djxlc/communication/ocu/to/video/process"; /*ocu到操控视频处理端*/
    /** 系统设置界面中串口应用按钮*/
    const char SERIALPORT_ACTUON_BARS[100] = "djxlc/serialport/action/bars";/*摇杆串口号*/
    /** 地图面积测量和距离测量屏幕按钮*/
    const char MEASURMENT_ADD_POINT_FROM_MAP_START[100] = "djxlc/map/tools/measurment/add/point/from/map/start";/*开始从地图选点*/
    const char MEASURMENT_ADD_POINT_FROM_MAP_END[100] = "djxlc/map/tools/measurment/add/point/from/map/end";/*结束从地图选点*/
    const char MEASURMENT_ADD_POINT_MANUAL[100] = "djxlc/map/tools/measurment/add/point/manual";/*手动添点*/
    const char MEASURMENT_REMOVE_POINT[100] = "djxlc/map/tools/measurment/remove/point";/*删除*/
    const char MEASURMENT_CALCUTE[100] = "djxlc/map/tools/measurment/calcute";/*计算结果*/
    const char MEASURMENT_RETURN[100] = "djxlc/map/tools/measurment/return";/*返回上级菜单*/

    /** 地图面积测量和距离测量屏幕按钮*/
    const char MEASURMENT_AREA_ADD_POINT_FROM_MAP_START[100] = "djxlc/map/tools/measurment/area/add/point/from/map/start";/*开始从地图选点*/
    const char MEASURMENT_AREA_ADD_POINT_FROM_MAP_END[100] = "djxlc/map/tools/measurment/area/add/point/from/map/end";/*结束从地图选点*/
    const char MEASURMENT_AREA_ADD_POINT_MANUAL[100] = "djxlc/map/tools/measurment/area/add/point/manual";/*手动添点*/
    const char MEASURMENT_AREA_REMOVE_POINT[100] = "djxlc/map/tools/measurment/area/remove/point";/*删除*/
    const char MEASURMENT_AREA_CALCUTE[100] = "djxlc/map/tools/measurment/area/calcute";/*计算结果*/
    const char MEASURMENT_AREA_RETURN[100] = "djxlc/map/tools/measurment/area/return";/*返回上级菜单*/
    /** 地图面积测量和距离测量屏幕按钮*/
    const char MEASURMENT_DISTANCE_ADD_POINT_FROM_MAP_START[100] = "djxlc/map/tools/measurment/distance/add/point/from/map/start";/*开始从地图选点*/
    const char MEASURMENT_DISTANCE_ADD_POINT_FROM_MAP_END[100] = "djxlc/map/tools/measurment/distance/add/point/from/map/end";/*结束从地图选点*/
    const char MEASURMENT_DISTANCE_ADD_POINT_MANUAL[100] = "djxlc/map/tools/measurment/distance/add/point/manual";/*手动添点*/
    const char MEASURMENT_DISTANCE_REMOVE_POINT[100] = "djxlc/map/tools/measurment/distance/remove/point";/*删除*/
    const char MEASURMENT_DISTANCE_CALCUTE[100] = "djxlc/map/tools/measurment/distance/calcute";/*计算结果*/
    const char MEASURMENT_DISTANCE_RETURN[100] = "djxlc/map/tools/measurment/distance/return";/*返回上级菜单*/
    /** 路径跟踪界面按钮设置*/
    const char OPERATION_PATH_FOLLOW_LOAD_TASK_FROM_FILE[100] = "djxlc/operation/path/follow/load/task/from/file";/*从文件加载任务*/
    const char OPERATION_PATH_FOLLOW_TASK_EDIT[100] = "djxlc/operation/path/follow/task/edit";/*编辑任务*/
    const char OPERATION_PATH_FOLLOW_REMOVE_TASK[100] = "djxlc/operation/path/follow/remove/task";/*删除任务*/
    const char OPERATION_PATH_FOLLOW_ADD_POINT_FROM_MAP_START[100] = "djxlc/operation/path/follow/add/point/from/map/start";/*开始从地图选点*/
    const char OPERATION_PATH_FOLLOW_ADD_POINT_FROM_MAP_END[100] = "djxlc/operation/path/follow/add/point/from/map/end";/*结束从地图选点*/
    const char OPERATION_PATH_FOLLOW_ADD_POINT_MANUAL[100] = "djxlc/operation/path/follow/add/point/manual";/*手动添点*/
    const char OPERATION_PATH_FOLLOW_REMOVE_POINT[100] = "djxlc/operation/path/follow/remove/point";/*删除地图点*/
    const char OPERATION_PATH_FOLLOW_ISSUE_TASK[100] = "djxlc/operation/path/follow/issue/task";/*下发任务*/
    const char OPERATION_PATH_FOLLOW_ROAD_NETWORK_FILE[100] = "djxlc/operation/path/follow/road/network/file";/*路网文件*/
    const char OPERATION_MODE_RETURN[100] = "djxlc/operation/mode/return";/*返回上级菜单—操控模式下通用*/
    /** 一键返航界面按钮设置*/
    const char OPERATION_ONE_KEY_BANCK_LOAD_TASK_POINT[100] = "djxlc/operation/one/key/banck/load/task/poit";/*加载路径点*/
    const char OPERATION_ONE_KEY_BANCK_LOAD_TASK_FROM_FILE[100] = "djxlc/operation/one/key/banck/load/task/from/file";/*从文件加载路径点*/
    const char OPERATION_ONE_KEY_BANCK_TASK_EDIT[100] = "djxlc/operation/one/key/banck/task/edit";/*编辑任务*/
    const char OPERATION_ONE_KEY_BANCK_SAVE_TASK[100] = "djxlc/operation/one/key/banck/save/task";/*保存任务*/
    const char OPERATION_ONE_KEY_BANCK_ISSUE_TASK[100] = "djxlc/operation/one/key/banck/issue/task";/*下发任务*/
    /** *视频*/
    const char MENU_EVENT_VIDEO_PLAYBACK[100]        = "djxlc/menu/event/video/playback";         /*视频回放*/
    const char MENU_EVENT_VIDEO_PLAYBACK_RETURN[100] = "djxlc/menu/event/video/playback/return";  /*return*/
    const char MENU_EVENT_VIDEO_LIST[100]            = "djxlc/menu/event/video/list";             /*视频列表*/
}
