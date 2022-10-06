#pragma once

namespace UcsEventConstants {


const char NETCONFIG[]="on_net_config_clicked";
const char MAPINTERFACE[]="on_MAPINTERFACE_clicked";
const char VEHICLE_1_ACTIVATED[]="VEHICLE_1_ACTIVATED";
const char SET_MQTT_NET[]="SET_MQTT_NET";
const char ROS_NODE_MANAGEMENT[]="ROS_NODE_MANAGEMENT";
const char STSTEMSHUTDOWN[]="STSTEMSHUTDOWN";
const char VEHICLE_1_CONTROL[]="VEHICLE_1_CONTROL";
const char EXITTOMAIN[]="EXITTOMAIN";
const char VEHICLE_1_MAIN[]="VEHICLE_1_MAIN";
const char VEHICLE_1_CONTROL_STATE_SWITCHED[]="VEHICLE_1_CONTROL_STATE_SWITCHED";











const char TOPCI_MENU_CLICKED[] = "ocu/menu/clicked";  // topics
const char PROPERTY_ID[] = "id";    // properties

//! ***************************************COMMON ATTRIBUTE TOPIC************************************************/
const char TOPIC_RCS_INIT_STATE[] = "ocu/rcs/init/state";                            //! RCS初始化状态
const char TOPIC_LINK_CAR_TYPE[] = "ocu/link/car/type";                              //! 车辆连接

//! ***************************************SUPER CAR TOPIC*******************************************************/
//! SUPER CAR 车辆状态量TOPIC
const char TOPIC_CAR_STATE_ENABLE[] = "ocu/car/state/enable";                        //! 车辆使能
const char TOPIC_CAR_STATE_CONNECT[] = "ocu/car/state/connect";                      //! 车辆链接
const char TOPIC_CAR_STATE_DISCONNECT[] = "ocu/car/state/disconnect";                //! 车辆链接
const char TOPIC_CENTER_WIDGET_SWITCH[] = "ocu/center/widget/switch";                //!
const char TOPIC_START_REMOTE_DRIVER[] = "ocu/start/remote/driver";                  //!
const char TOPIC_START_AUTOMONUS_DRIVER[] = "ocu/start/automonus/driver";            //!
const char TOPIC_RCS_RESTORATION[] = "ocu/rcs/restoration";                          //!
const char TOPIC_DRIVER_MODE_SWITCH[] = "ocu/driver/mode/switch";                    //!
const char TOPIC_DRIVER_MODE_FEEDBACK[] = "ocu/driver/mode/feedback";                //!
const char TOPIC_DRIVER_MODE_INTO_AUTO_DRIVER[] = "ocu/driver/mode/into/auto/driver";//!
const char TOPIC_CANCEL_CONNETED[] = "ocu/cancel/connected";                         //!
const char TOPIC_CAR_POSITON_INFO[] = "ocu/car/position/info";                       //!
const char TOPIC_CHASSIS_INFO[] = "ocu/chassis/info";                                //! 车辆信息
const char TOPIC_STATUS_PARA_WIDGET[] = "ocu/status/para/widget";                    //!
const char TOPIC_LOCATION_AND_DIRECTION_INFO[] = "ocu/location/and/direction/info";  //! 定位定向数据
const char TOPIC_SYSTEM_MONITOR_INFO[] = "ocu/system/monitor/info";                  //! 系统监控信息
const char TOPIC_VIDEO_DISPLAY_MODE[] = "ocu/video/display/mode";                    //! 视频显示模式
const char TOPIC_CONTROL_WIDGET_RECORD_POINT[] = "ocu/control/widget/record/point";  //! 开始录点和结束录点
const char TOPIC_ADD_POINT_FROM_MAP_CONTROL[] = "ocu/add/point/from/map/control";    //! MAP TOPIC
const char TOPIC_ADD_POINT_FROM_MAP[] = "ocu/add/point/from/map";                    //!
const char TOPIC_ADD_POINT_FROM_MAP_COMPLETE[] = "ocu/add/point/from/map/complete";  //!
const char TOPIC_DRAW_CAR_PATH[] = "ocu/draw/car/path";                              //!
const char TOPIC_DRAW_TASK_PATH[] = "ocu/draw/task/path";                            //!
const char TOPIC_DRAW_TASK_DRIVER_MODE_SWITCH[] = "ocu/draw/task/driver/mode/switch"; //!

/***************************************便携式车辆与OCU交互TOPIC**************************************/
const char TOPIC_PORTABLE_CAR_REPORT_STATUS_INFO[] ="ocu/portable/car/report/status/info";/*便携式车辆上报的车辆信息*/

/*********************************************任务管理 TOPIC********************************************/
const char TOPIC_TASK_POINT_DATA[] = "ocu/task/point/data";
const char TOPIC_TASK_CHILD_WIDGET[] = "ocu/task/child/widget";
const char TOPIC_TASK_CAR_INFO_REPORT[] = "ocu/task/car/info/report";
const char TOPIC_AUTO_TASK_MODE[] = "ocu/auto/task/mode";

/***************************************Data reported by RWLJ TOPIC***************************************/
const char TOPIC_RWLJ_SITUATION_REPORT[] = "ocu/rwlj/situation/report";
const char TOPIC_RWLJ_TASK_FEEDBACK[] = "ocu/rwlj/task/feedback";
const char TOPIC_RWLJ_EQUIPMENT_STATUS[] = "ocu/rwlj/equipment/status";
const char TOPIC_RWLJ_TO_OCU_RESPONSE[] = "ocu/rwlj/to/ocu/response";
const char TOPIC_RWLJ_TO_OCU_FIXED_POINT_ATTACH[] = "ocu/rwlj/to/ocu/fixed/point/attach";

const char TOPIC_RWLJ_TO_OCU_HEART_BEAT[] = "ocu/rwlj/to/ocu/heart/beat";

/***************************************Data reported by RWLJ TOPIC***************************************/
const char TOPIC_COMMAND_TASK_TURN_AUTO_DRIVER[] = "ocu/command/task/turn/driver";

/************************************Data reported by control software TOPIC*************************************/
const char TOPIC_CONTROL_PAUSE_CUR_ACTION[] = "ocu/control/pause/current/action";
const char TOPIC_CONTROL_CONTINUCE_CUR_ACTION[] = "ocu/control/continuce/current/action";
const char TOPIC_CONTROL_TERMINATE_CUR_ACTION[] = "ocu/control/terminate/current/action";
const char TOPIC_CONTROL_AFTER_PARK_ACTION[] = "ocu/control/after/park/action";
const char TOPIC_CONTROL_LIFT_CAR[] = "ocu/control/lift/car";
const char TOPIC_CONTROL_POWER_SWITCH[] = "ocu/control/power/switch";
const char TOPIC_CONTROL_SELF_DESTRUCT[] = "ocu/control/self/destruct";
const char TOPIC_CONTROL_TURN_IN_PLACE[] = "ocu/control/turn/in/place";
const char TOPIC_CONTROL_FOLLOW[] = "ocu/control/follow";
const char TOPIC_CONTROL_CONVENT_MANEUVER[] = "ocu/control/conventional/maneuver";
const char TOPIC_CONTROL_MANY_TASK_POINT[] = "ocu/control/many/task/point";
const char TOPIC_CONTROL_AUTO_PARAMETER_SET[] = "ocu/control/auto/parameter/set";
const char TOPIC_CONTROL_AUTO_WORK_CONTROL[] = "ocu/control/auto/work/control";
const char TOPIC_CONTROL_NO_FATAL_STRIKE[] = "ocu/control/no/fatal/strike";
const char TOPIC_CONTROL_FATAL_STRIKE[] = "ocu/control/fatal/strike";


//! ***************************************xBox value TOPIC*********************************************************/
const char TOPIC_XBOX_BTN_VALUE[] = "ocu/xbox/btn/value";
const char TOPIC_XBOX_AXIS_VALUE[] = "ocu/xbox/axis/value";

//! ***************************************radio value TOPIC*********************************************************/
const char TOPIC_RADIO_LINK_QUALITY[] = "ocu/radio/link/quality";
const char TOPIC_SEND_ADMIN_INFO[] = "ocu/send/admin/info";

//! ***************************************rocker value TOPIC*********************************************************/
const char TOPIC_ROCKER_LEFT_DATA[] = "ocu/roker/left/data";
const char TOPIC_ROCKER_RIGHT_DATA[] = "ocu/roker/right/data";



const char TOPIC_ALERT_DOA_LINGERING[] = "ocu/alert/doa/lingering";
const char TOPIC_ALERT_DOA_SECTOR_SCAN[] = "ocu/alert/doa/sector/scan";
const char TOPIC_ALERT_DOA_CIRCULAR_SCAN[] = "ocu/alert/doa/circular/scan";
const char TOPIC_ALERT_STEP_LINGER_SCOPE[] = "ocu/alert/step/linger/scope";
const char TOPIC_ALERT_DOA_ZERO_CALIBRATION[] = "ocu/alert/doa/zero/calibration";
const char TOPIC_ALERT_DOA_STOP_SCAN[] = "ocu/alert/doa/stop/scan";
const char TOPIC_ALERT_DOA_WIDTHDRAWAL[] = "ocu/alert/doa/widthdrawal";
const char TOPIC_ALERT_PITCH_LINGERING[] = "ocu/alert/pitch/lingering";
const char TOPIC_ALERT_PITCH_LEVELING[] = "ocu/alert/pitch/leveling";
const char TOPIC_ALERT_SELF_CHECK_RESULT[] = "ocu/alert/self/check/result";
const char TOPIC_ALERT_WORK_STATE_REPORT[] = "ocu/alert/work/state/report";
const char TOPIC_ALERT_CHECK_NORTH_POSITION_REPORT[] = "ocu/alert/check/north/positition/report";

/***********************************电源管理分机上报数据***************************/
const char TOPIC_ALERT_POEWR_MANAGER_COMMAND_RESPONSE[] = "ocu/alert/power/manager/command/response";
const char TOPIC_ALERT_POWER_MANAGER_WORK_STATE[] = "ocu/alert/power/manager/work/state";

/***********************************显控软件与LD信号模拟软件***************************/
const char TOPIC_ALERT_SELECT_STATE[] = "ocu/alert/select/state";
const char TOPIC_ALERT_WORK_MODEL_CONTROL[] = "ocu/alert/work/model/control";
const char TOPIC_ALERT_LD_SIGNAL_CONTENT[] = "ocu/alert/ld/signal/content";
const char TOPIC_ALERT_LD_SIGNAL_POWER_CONTROL[] = "ocu/alert/ld/signal/power/control";
const char TOPIC_ALERT_SIMULATOR_STATE[] = "ocu/alert/simulator/state";
const char TOPIC_ALERT_SELf_check[] = "ocu/alert/self/check";
const char TOPIC_ALERT_HEART_BEAT[] = "ocu/alert/heart/beat";

/***********************************本系统（同型装备）间接口设计***************************/
const char TOPIC_ALERT_EQUIPMENT_STATE_INFO[] = "ocu/alert/equipment/state/info";
const char TOPIC_ALERT_LD_CONFRONT_AND_COOPERATE_REQUEST[] = "ocu/alert/LD/confront/and/cooperate/request";
const char TOPIC_ALERT_COOPERATE_RELIEVE[] = "ocu/alert/cooperate/relieve";
const char TOPIC_ALERT_COOPERATE_REPONSE[] = "ocu/alert/cooperate/response";

/***********************************系统显控软件内部接口***************************/
const char TOPIC_ALERT_COMMAND_REPLY_TOPIC[] = "ocu/alert/command/reply/topic";
const char TOPIC_ALERT_POWER_CONTROL[] = "ocu/alert/power/control";
const char TOPIC_ALERT_OP_DATA_RESP[] = "ocu/alert/op/data/resp";
const char TOPIC_ALERT_DEV_STATUS[] = "ocu/alert/dev/status";
const char TOPIC_ALERT_NAV_INFO[] = "ocu/alert/nav/info";
const char TOPIC_ALERT_RD_PARAM_FUSE_RLT_TOPIC[] = "ocu/alert/rd/param/fuse/rlt/topic";
const char TOPIC_ALERT_PLAT_POS_SIG_ID_DOA_TOPIC[] = "ocu/alert/plat/pos/sig/id/doa/topic";
const char TOPIC_ALERT_IFF_SINGLE_PLT_PROC_TOPIC[] = "ocu/alert/iff/single/plt/proc/topic";
const char TOPIC_ALERT_IFF_CROSS_LOC_TRACK_TOPIC[] = "ocu/alert/iff/cross/loc/track/topic";
const char TOPIC_ALERT_PLAT_TARGET_SYNTH_TOPIC[] = "ocu/alert/plat/target/synth/topic";
const char TOPIC_ALERT_DZZC_TASK_TOPIC[] = "ocu/alert/dzzc/task/topic";
const char TOPIC_ALERT_DZGR_TASK_TOPIC[] = "ocu/alert/dzgr/task/topic";
const char TOPIC_ALERT_EM_SIMULARION_TASK_TOPIC[] = "ocu/alert/em/simulation/task/topic";
const char TOPIC_ALERT_TASK_IMPLEMENTATION_TOPIC[] = "ocu/alert/task/implementation/topic";
const char TOPIC_ALERT_ROUTE_TOPIC[] = "ocu/alert/route/topic";
const char TOPIC_ALERT_LOAD_WORK_MODE_TOPIC[] = "ocu/alert/load/work/mode/topic";

//! **
const char TOPIC_CENTER_BTN_CLOSE_CLICKED[] = "ocu/fc/center/btn/close/clicked";
const char TOPIC_SHOW_CENTER_BOTTOM[] = "ocu/fc/show/center/bottom";



const char TOPIC_ALERT_VIDEO_INFO[] = "ocu/alert/monitor/video/info";



/*****************************串口数据,上位机与下位机之间通信的信息 TOPIC*********************************/
const char TOPIC_SERIAL_PORT_JOYSTICK[] = "ocu/serial/port/joystick";           /*摇杆值*/
const char TOPIC_SERIAL_PORT_BATTERY[] = "ocu/serial/port/battery";             /*电池状态*/
const char TOPIC_SERIAL_PORT_KEY[] = "ocu/serial/port/key";                     /*按键值*/
const char TOPIC_SERIAL_PORT_GPS[] = "ocu/serial/port/gps";                     /*gps*/
const char TOPIC_SERIAL_PORT_SYSTEM_TIME[] = "ocu/serial/port/system/time";     /*系统时间*/
const char TOPIC_SERIAL_PORT_ACCELERATE[] = "ocu/serial/port/accelerate";       /*加速度*/
const char TOPIC_SERIAL_PORT_MAGNETOMETER[] = "ocu/serial/port/magnetometer";   /*磁力计*/


//!*********************************************************************************************************/
//!* Menu event super car                                                                                  */
//!*********************************************************************************************************/
//! login page
const char MENU_EVENT_LOGIN_SYSTEM_SETTING[] = "ocu/menu/event/login/system_setting";
const char MENU_EVENT_LOGIN[] = "ocu/menu/event/login";
const char MENU_EVENT_LOGIN_ADMIN[] = "ocu/menu/event/login/admin";

//! system setting
const char MENU_EVENT_SYSTEM_SETTING_RETURN[] = "ocu/menu/event/system_setting/return";
const char MENU_EVENT_SYSTEM_SETTING_SAVE[] = "ocu/menu/event/system_setting/save";
const char MENU_EVENT_SYSTEM_SETTING_POWER[] = "ocu/menu/event/system_setting/power";

//! car manager
const char MENU_EVENT_CAR_MANAGER_LOGMANAGER[] = "ocu/menu/event/car_manager/logmanager";
const char MENU_EVENT_CAR_MANAGER_RETURN[] = "ocu/menu/event/car_manager/return";
const char MENU_EVENT_CAR_MANAGER_ADD[] = "ocu/menu/event/car_manager/add";
const char MENU_EVENT_CAR_MANAGER_EDIT[] = "ocu/menu/event/car_manager/edit";
const char MENU_EVENT_CAR_MANAGER_DELETE[] = "ocu/menu/event/car_manager/delete";
const char MENU_EVENT_CAR_MANAGER_CONNECT[] = "ocu/menu/event/car_manager/connect";
const char MENU_EVENT_CAR_MANAGER_RADIO[] = "ocu/menu/event/car_manager/radio";
const char MENU_EVENT_RADIO_SETTING_LOCAL_PARA[] = "ocu/menu/radio/setting/local/para";
const char MENU_EVENT_RADIO_SETTING_REMOTE_PARA[] = "ocu/menu/radio/setting/remote/para";
const char MENU_EVENT_RADIO_SETTING_FREQUENCE_INFO[] = "ocu/menu/radio/setting/frequence/info";
const char MENU_EVENT_RADIO_SETTING_RRU_INFO[] = "ocu/menu/radio/setting/rru/info";
const char MENU_EVENT_RADIO_SETTING_NETWORK_INFO[] = "ocu/menu/radio/setting/network/info";

//! uncontrol
const char MENU_EVENT_UNCONTROL_RETURN[] = "ocu/menu/event/uncontrol/return";
const char MENU_EVENT_UNCONTROL_CONTROL[] = "ocu/menu/event/uncontrol/control";

//! control manager
const char MENU_EVENT_CONTROL_MANAGER_RETURN[] = "ocu/menu/event/control_manager/return";
const char MENU_EVENT_CONTROL_AUTO_DRIVER_RETURN[] = "ocu/menu/event/control_manager/auto/driver/return";
const char MENU_EVENT_CONTROL_RCS_RESTORATION[] = "ocu/menu/event/control/rcs/restoration";

//! account management
const char MENU_EVENT_ACCOUNT_MANAGEMENT_RETURN[] = "ocu/menu/event/account_management/return";
const char MENU_EVENT_ACCOUNT_MANAGEMENT_ADD[] = "ocu/menu/event/account_management/add";
const char MENU_EVENT_ACCOUNT_MANAGEMENT_DELETE[] = "ocu/menu/event/account_management/delete";
const char MENU_EVENT_ACCOUNT_MANAGEMENT_EDIT_PASSWORD[] = "ocu/menu/event/plus_account_management/edit_password";
const char MENU_EVENT_ACCOUNT_MANAGEMENT_EDIT_GRADE[] = "ocu/menu/event/plus_account_management/edit_grade";

//! 主界面系统设置按钮
const char MENU_EVENT_SYSTEM_SETTING_CONTROL_RETURN[] = "ocu/menu/event/system/setting/control/return";



/***************************************摇杆串口通信TOPIC*****************************************/
const char TOPIC_SERIALPORT_ROCKER_DATA[] = "ocu/serilport/rocker/data/receive";                       /** 摇杆数据接收topic*/
const char TOPIC_SERIALPORT_ROCKER_DATA_LEFT[] = "ocu/serilport/rocker/data/receive/left";             /** 左摇杆数据接收topic*/
const char TOPIC_SERIALPORT_ROCKER_PATH[] = "ocu/serilport/rocker/path/right";                         /** 右摇杆路径标识*/
const char TOPIC_SERIALPORT_ROCKER_PATH_RIGHT[] = "ocu/serilport/rocker/path/right";                   /** 右摇杆路径标识*/
const char TOPIC_SERIALPORT_ROCKER_PATH_LEFT[] = "ocu/serilport/rocker/path/left";                     /** 左摇杆路径标识*/
const char TOPIC_SERIALPORT_ROCKER_DATA_TO_FC[] = "ocu/serilport/rocker/data/to/fc/receive";           /** 摇杆数据转发给火控*/
const char TOPIC_SERIALPORT_ROCKER_DATA_TO_FC_LEFT[] = "ocu/serilport/rocker/data/to/fc/receive/left"; /** 左摇杆数据转发*/
}
