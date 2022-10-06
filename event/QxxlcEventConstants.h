#pragma once

#include <QtGlobal>

namespace QxxlcEventConstants {
    // topics
    const char TOPIC_EXAMPLE[] = "topic/example";

    const char PROPERTY_ID[] = "qxxlc/id";    // properties

    const char TOPCI_QXXLC_MENU_CLICKED[] = "ocu/qxxlc/menu/clicked";  // topics
    const char QXXLC_PROPERTY_ID[] = "id";    // properties

    //! uncontrol
    const char MENU_EVENT_UNCONTROL_RETURN[] = "qxxlc/ocu/menu/event/uncontrol/return";
    const char MENU_EVENT_UNCONTROL_CONTROL[] = "qxxlc/ocu/menu/event/uncontrol/control";

    //! control manager
    const char MENU_EVENT_CONTROL_MANAGER_RETURN[] = "qxxlc/ocu/menu/event/control_manager/return";
    const char MENU_EVENT_CONTROL_AUTO_DRIVER_RETURN[] = "qxxlc/ocu/menu/event/control_manager/auto/driver/return";
    const char MENU_EVENT_CONTROL_RCS_RESTORATION[] = "qxxlc/ocu/menu/event/control/rcs/restoration";

    //! main widget
    const char MENU_EVENT_REMOTE_CONTROL_DRIVER[] = "qxxlc/ocu/menu/event/remote/control/driver";     //! 遥控驾驶
    const char MENU_EVENT_AUTONOMOUS_DRIVER[] = "qxxlc/ocu/menu/event/autonomous/driver";             //! 自主驾驶
    const char MENU_EVENT_VIDEO_MONITOR[] = "qxxlc/ocu/menu/event/video/monitor";                     //! 组合相机
    const char MENU_EVENT_VIDEO_STARLIGHT_CAMERA[] = "qxxlc/ocu/menu/event/video/starlight/camera";   //! 星光相机
    const char MENU_EVENT_ELECTRIC_UP[] = "qxxlc/ocu/menu/event/electric/up";                         //! 上电管理
    const char MENU_EVENT_ALTITUDE_CONTROL[] = "qxxlc/ocu/menu/event/altitude/control";               //! 上电管理
    const char MENU_EVENT_SYSTEM_SETTING[] = "qxxlc/ocu/menu/event/system/setting";                   //! 上电管理
    const char MENU_EVENT_ENABLE[] = "qxxlc/ocu/menu/event/enable";                                   //! 车辆使能
    const char MENU_EVENT_CANCEL_ENABLE[] = "qxxlc/ocu/menu/event/cancel/enable";                     //! 取消使能
    const char MENU_EVENT_CANCEL_CONNECTED[] = "qxxlc/ocu/menu/event/cancel/connected";               //!
    const char MENU_EVENT_TASK_MANAGER[] = "qxxlc/ocu/menu/event/task/manager";                       //!
    const char MENU_EVENT_FIRE_CONTROL_TASK_MANAGER[] = "qxxlc/ocu/menu/event/fire/control/task/manager";
    const char MENU_EVENT_FIRE_CONTROL_TASK_MANAGER_RETURN[] = "qxxlc/ocu/menu/event/fire/control/task/manager/return";

    const char MENU_EVENT_CAR_CONTROL_TASK[] = "qxxlc/ocu/menu/event/car/control/task";                 //!车控指控信息
    const char MENU_EVENT_FIRE_CONTROL_TASK[] = "qxxlc/ocu/menu/event/fire/control/task";                 //!火控指控信息
    const char MENU_EVENT_PORTABLE_CAR[] = "qxxlc/ocu/menu/event/portable/car";                       //!便携式車輛进入按钮
    const char MENU_EVENT_FIRE_CONTROL[] = "qxxlc/ocu/menu/event/fire/control";                       //!进入火控界面按钮
    const char MENU_EVENT_DRONE[] = "qxxlc/ocu/menu/event/drone";                                     //!无人机信息进入按钮

    const char MENU_EVENT_COMMAND_CONTROL_TASK_INFO[] = "qxxlc/ocu/menu/event/command/control/task/info";
    const char MENU_EVENT_COMMAND_CONTROL_TARGET_INFO[] = "qxxlc/ocu/menu/event/command/control/target/info";
    const char MENU_EVENT_COMMAND_CONTROL_TASK_EXECUTE_INFO[] = "qxxlc/ocu/menu/event/command/control/task/execute/info";
    const char MENU_EVENT_COMMAND_CONTROL_INVESTIGATION_INFO[] = "qxxlc/ocu/menu/event/command/control/investigation/info";
    const char MENU_EVENT_COMMAND_CONTROL_SITUATION_INFO[] = "qxxlc/ocu/menu/event/command/control/situation/info";
const char MENU_EVENT_COMMAND_CONTROL_PERMISSION_INFO[]="qxxlc/ocu/menu/event/command/control/permission/info";
    //! ***************************************portable car TOPIC************************************************/
    //! main widget
    const char MENU_EVENT_PORTABLE_CAR_ENABLE[] = "qxxlc/ocu/menu/event/portable/car/enable";                                   //! 车辆使能
    const char MENU_EVENT_PORTABLE_CAR_CANCEL_ENABLE[] = "qxxlc/ocu/menu/event/portable/car/cancel/enable";                     //! 取消使能
    const char MENU_EVENT_PORTABLE_CAR_CONNECTED[] = "qxxlc/ocu/menu/event/portable/car/connected";                             //! 连接界面
    const char MENU_EVENT_PORTABLE_CAR_CANCEL_CONNECTED[] = "qxxlc/ocu/menu/event/portable/car/cancel/connected";               //! 取消链接界面


    const char MENU_EVENT_PORTABLE_CAR_CHASSIS[] = "qxxlc/ocu/menu/event/portable/car/chassis";                                 //! 底盘控制界面
    const char MENU_EVENT_PORTABLE_CAR_DEVICE[] = "qxxlc/ocu/menu/event/portable/car/device";                                   //! 设备设置界面
    const char MENU_EVENT_PORTABLE_CAR_FIRE_CONTROL[] = "qxxlc/ocu/menu/event/portable/car/fire/control";                       //! 载荷控制界面

    const char MENU_EVENT_PORTABLE_CAR_GEAR_SETTING[] = "qxxlc/ocu/menu/event/portable/car/gear/setting";                       //! 档位设置界面
    const char MENU_EVENT_PORTABLE_CAR_OPERATION_MODE[] = "qxxlc/ocu/menu/event/portable/car/operation/mode";                   //! 操控模式界面
    const char MENU_EVENT_PORTABLE_CAR_VIDEO_CHANNEL[] = "qxxlc/ocu/menu/event/portable/car/video/channel";                     //! 视频通道界面
    const char MENU_EVENT_PORTABLE_CONTROL_RETURN[] = "qxxlc/ocu/menu/event/portable/car/control/return";                       //! 视频通道界面
    const char MENU_EVENT_PORTABLE_RETURN_QXXLC[] = "qxxlc/ocu/menu/event/portable/car/return/qxxlc";                           //! 返回到



    /** ***************************************************便携式车辆与OCU交互TOPIC**************************************/
    const char TOPIC_PORTABLE_CAR_REPORT_STATUS_INFO[] ="ucs/portable/car/report/status/info";/*便携式车辆上报的车辆信息*/
    const char TOPIC_PORTABLE_SWITCH_TO_QXXLC_WIDGET[] = "qxxlc/topic/switch/to/qxxlc/widget"; /*便携式车切换到巡逻车*/


    //! ***************************************COMMON ATTRIBUTE TOPIC************************************************/
    const char TOPIC_RCS_INIT_STATE[] = "qxxlc/ocu/rcs/init/state";                            //! RCS初始化状态
    const char TOPIC_LINK_CAR_TYPE[] = "qxxlc/ocu/link/car/type";                              //! 车辆连接

    const char TOPIC_QXXLC_CONNECTED_STATE[] = "qxxlc/ocu/connected/state";                    //! 车辆连接


    //! ***************************************SUPER CAR TOPIC*******************************************************/
    //! SUPER CAR 车辆状态量TOPIC
    const char TOPIC_CAR_STATE_ENABLE[] = "qxxlc/ocu/car/state/enable";                        //! 车辆使能
    const char TOPIC_CAR_STATE_CONNECT[] = "qxxlc/ocu/car/state/connect";                      //! 车辆链接

    const char TOPIC_CAR_STATE_DISCONNECT[] = "qxxlc/ocu/car/state/disconnect";                //! 车辆链接
    const char TOPIC_CENTER_WIDGET_SWITCH[] = "qxxlc/ocu/center/widget/switch";                //!
    const char TOPIC_START_REMOTE_DRIVER[] = "qxxlc/ocu/start/remote/driver";                  //!
    const char TOPIC_START_AUTOMONUS_DRIVER[] = "qxxlc/ocu/start/automonus/driver";            //!
    const char TOPIC_RCS_RESTORATION[] = "qxxlc/ocu/rcs/restoration";                          //!
    const char TOPIC_DRIVER_MODE_SWITCH[] = "qxxlc/ocu/driver/mode/switch";                    //!
    const char TOPIC_DRIVER_MODE_FEEDBACK[] = "qxxlc/ocu/driver/mode/feedback";                //!
    const char TOPIC_DRIVER_MODE_INTO_AUTO_DRIVER[] = "qxxlc/ocu/driver/mode/into/auto/driver";//!
    const char TOPIC_CANCEL_CONNETED[] = "qxxlc/ocu/cancel/connected";                         //!
    const char TOPIC_CAR_POSITON_INFO[] = "qxxlc/ocu/car/position/info";                       //!
    const char TOPIC_CHASSIS_INFO[] = "qxxlc/ocu/chassis/info";                                //! 车辆信息
    const char TOPIC_JSCK_HEART_INFO[] = "qxxlc/ocu/jsck/heart/info";                          //! 驾驶心跳
    const char TOPIC_STATUS_PARA_WIDGET[] = "qxxlc/ocu/status/para/widget";                    //!
    const char TOPIC_LOCATION_AND_DIRECTION_INFO[] = "qxxlc/ocu/location/and/direction/info";  //! 定位定向数据
    const char TOPIC_SYSTEM_MONITOR_INFO[] = "qxxlc/ocu/system/monitor/info";                  //! 系统监控信息
    const char TOPIC_SERIALPORT_ROCKER_DATA[] = "qxxlc/ocu/serilport/rocker/data/receive";     //! 摇杆数据接收topic
    const char TOPIC_VIDEO_DISPLAY_MODE[] = "qxxlc/ocu/video/display/mode";                    //! 视频显示模式
    const char TOPIC_CONTROL_WIDGET_RECORD_POINT[] = "qxxlc/ocu/control/widget/record/point";  //! 开始录点和结束录点
//    const char TOPIC_ADD_POINT_FROM_MAP_CONTROL[] = "qxxlc/ocu/add/point/from/map/control";    //! MAP TOPIC
    const char TOPIC_ADD_POINT_FROM_MAP_CONTROL[] = "ucs/add/point/from/map/control";    //! MAP TOPIC
    const char TOPIC_ADD_POINT_FROM_MAP[] = "qxxlc/ocu/add/point/from/map";                    //!
    const char TOPIC_ADD_POINT_FROM_MAP_COMPLETE[] = "qxxlc/ocu/add/point/from/map/complete";  //!
    const char TOPIC_DRAW_CAR_PATH[] = "qxxlc/ocu/draw/car/path";                              //!
    const char TOPIC_DRAW_TASK_PATH[] = "qxxlc/ocu/draw/task/path";                            //!
    const char TOPIC_DRAW_TASK_DRIVER_MODE_SWITCH[] = "qxxlc/ocu/draw/task/driver/mode/switch"; //!


    const char TOPIC_AUTO_TASK_MODE[] = "qxxlc/ocu/auto/task/mode";
    const char TOPIC_ALERT_VIDEOPARENT_WIDGET[] = "ucs/alert/videoparent/widget";
    const char TOPIC_FIRE_CONTROL_ACTION[] = "ucs/fire/control/action";
    const char TOPIC_TASK_FLAGS[] = "ucs/task/flags";


    const char TOPIC_QXXLC_CAR_RCS_TASK_STATE[] = "qxxlc/car/rcs/task/state";                  //! 自主任务状态



    /** *************************************Data reported by RWLJ TOPIC***************************************/
    const char TOPIC_COMMAND_TASK_TURN_AUTO_DRIVER[] = "qxxlc/ocu/command/task/turn/driver";


    /** *******************************************任务管理 TOPIC********************************************/
    const char TOPIC_TASK_POINT_DATA[] = "qxxlc/ocu/task/point/data";
    const char TOPIC_TASK_CHILD_WIDGET[] = "qxxlc/ocu/task/child/widget";
    const char TOPIC_TASK_CAR_INFO_REPORT[] = "qxxlc/ocu/task/car/info/report";

    /** **********************************Data reported by control software TOPIC*************************************/
    const char TOPIC_CONTROL_PAUSE_CUR_ACTION[] = "qxxlc/ocu/control/pause/current/action";
    const char TOPIC_CONTROL_CONTINUCE_CUR_ACTION[] = "qxxlc/ocu/control/continuce/current/action";
    const char TOPIC_CONTROL_TERMINATE_CUR_ACTION[] = "qxxlc/ocu/control/terminate/current/action";
    const char TOPIC_CONTROL_AFTER_PARK_ACTION[] = "qxxlc/ocu/control/after/park/action";
    const char TOPIC_CONTROL_LIFT_CAR[] = "qxxlc/ocu/control/lift/car";
    const char TOPIC_CONTROL_POWER_SWITCH[] = "qxxlc/ocu/control/power/switch";
    const char TOPIC_CONTROL_SELF_DESTRUCT[] = "qxxlc/ocu/control/self/destruct";
    const char TOPIC_CONTROL_TURN_IN_PLACE[] = "qxxlc/ocu/control/turn/in/place";
    const char TOPIC_CONTROL_FOLLOW[] = "qxxlc/ocu/control/follow";
    const char TOPIC_CONTROL_CONVENT_MANEUVER[] = "qxxlc/ocu/control/conventional/maneuver";
    const char TOPIC_CONTROL_MANY_TASK_POINT[] = "qxxlc/ocu/control/many/task/point";
    const char TOPIC_CONTROL_AUTO_PARAMETER_SET[] = "qxxlc/ocu/control/auto/parameter/set";
    const char TOPIC_CONTROL_AUTO_WORK_CONTROL[] = "qxxlc/ocu/control/auto/work/control";
    const char TOPIC_CONTROL_NO_FATAL_STRIKE[] = "qxxlc/ocu/control/no/fatal/strike";
    const char TOPIC_CONTROL_FATAL_STRIKE[] = "qxxlc/ocu/control/fatal/strike";


    /** ************************************************车辆控制界面菜单切换*********************************************/
    const char TOPIC_QXXLC_MENU_SHOW_SWITCH_TO_CORE[] = "qxxlc/ocu/control/menu/show/switch/to/core"; /*车辆控制界面菜单切换*/
    const char TOPIC_QXXLC_MENU_SHOW_SWITCH_TO_MAP[] = "qxxlc/ocu/control/menu/show/switch/to/map"; /*车辆控制界面菜单切换*/
    const char TOPIC_QXXLC_MENU_SHOW_SWITCH_TO_CONTROL[] = "qxxlc/ocu/control/menu/show/switch/to/control"; /*车辆控制界面菜单切换*/
    const char TOPIC_SCOUT_TARGET_INFO[] = "qxxlc/ocu/scout/target/info";
    /** ***************************************************图片接收**************************************/
    const char TOPIC_QXXLC_RECV_IMAGE_SHOW[] = "qxxlc/topic/recv/image/show"; /*图片接收显示*/
    /** ***************************************************加载任务文件**************************************/
    const char TOPIC_QXXLX_LOAD_TASK_TXT[] = "qxxlc/topic/load/task/txt";      /*加载任务文件*/
    /** ***************************************************车辆状态信息**************************************/
    const char TOPIC_QXXLC_CAR_STATE_INFO[] = "qxxlc/topic/car/state/info";
    const char TOPIC_QXXLC_CAR_STATE_GEAR_INFO[] = "qxxlc/topic/car/state/gear/info";




    const char TOPIC_OPERATION_PATH_RECORD_CONTROL[] = "qxxlc/topic/operation/path/record/control";/*路点记录控制*/


    //!*******************************************************************************************************************/
    //!* communication event super car                                                                                   */
    //!*******************************************************************************************************************/

    //! 通信链路路径管理
    const char COMMUNICATION_OCU_TO_COMMAND_CONTROL[] = "ucs/communication/ocu/to/control/command";//! 指控通信
    const char COMMUNICATION_OCU_TO_VIDEO_COMPONET[] = "ucs/communication/ocu/to/video/component"; //! ocu到视频端
    const char COMMUNICATION_OCU_TO_VIDEO_STARLIGHT[] = "ucs/communication/ocu/to/video/starlight";//! ocu到视频端
    const char COMMUNICATION_OCU_TO_CHASSIS[] = "ucs/communication/ocu/to/chassis";                //! ocu到底盘
    const char COMMUNICATION_OCU_TO_RADIO[] = "ucs/communication/ocu/to/radio";                    //! ocu到电台
    const char COMMUNICATION_OCU_TO_COMPUTER[] = "ucs/communication/ocu/to/computer";              //! ocu到自主计算机
    const char COMMUNICATION_OCU_TO_PORTABLE[] = "ucs/communication/ocu/to/portable";              //! ocu到便携端
    const char COMMUNICATION_OCU_TO_RWLJ[] = "ucs/communication/ocu/to/rwlj";                      //!ocu to RWLJ
    const char COMMUNICATION_OCU_TO_RWLJ_LISTEN[] = "ucs/communication/ocu/to/rwlj/listen";        //!ocu to RWLJ

    const char COMMUNICATION_OCU_TO_RWLJ_HEART_BEAT[] = "ucs/communication/ocu/to/rwlj/heart/beat";        //!ocu to RWLJ

    const char COMMUNICATION_OCU_TO_PERSON_CAR[] = "ucs/communication/ocu/to/person/car";        //!ocu to RWLJ




    const char COMMUNICATION_OCU_TO_CONTROL_LISTEN[] = "ucs/communication/ocu/to/control/listen";  //!ocu to control software listen
    const char COMMUNICATION_OCU_TO_CONTROL_SEND[] = "ucs/communication/ocu/to/control/send";      //!ocu to control software send
    const char COMMUNICATION_OCU_TO_AlERT_MONITOR[] = "ucs/communication/ocu/to/alert/monitor";    //!*ocu to the alert monitor

    const char COMMUNICATION_OCU_TO_PROTABLE_CAR_BACKGROUND_SERVICE[] = "ucs/communication/ocu/to/protable/car/background/service"; //! 操控终端应用到无人车后台服务

    const char COMMUNICATION_OCU_TO_INTERNAL[] = "ucs/communication/ocu/to/integrated/receiver";    //! 系统显控软件内部
    const char COMMUNICATION_OCU_TO_INTEGRATED_RECEIVER[] = "ucs/communication/ocu/to/integrated/receiver";    //! 系统显控软件到一体化接收机
    const char COMMUNICATION_OCU_TO_ZCGR_INTEGERATION[] = "usc/communication/ocu/to/zcgr/integeration";        //! 系统显控软件到ZCGR一体机
    const char COMMUNICATION_OCU_TO_SERVO_CONTROL_EXTENSION[] = "usc/communication/ocu/to/servo/control/extension"; //! 系统显控软件到伺服控制驱动分机
    const char COMMUNICATION_OCU_TO_POWER_MANAGER[] = "usc/communication/ocu/to/power/manager";            //! 系统显控软件到电源管理分机

    //! COMMUNICATION PATH MANAGER
    const char COMMUNICATION_OCU_TO_SUPER_CAR[] = "ucs/communication/ocu/to/super/car";            //!ocu to super car
    const char COMMUNICATION_OCU_TO_MIDDLE_CAR[] = "ucs/communication/ocu/to/middle/car";          //! ocu to middle car
    const char COMMUNICATION_OCU_TO_CRAWLER_CAR[] = "ucs/communication/ocu/to/crawler/car";        //! ocu to middle crawler car


    const char COMMUNICATION_OCU_TO_PORTABLE_CAR[100] = "ucs/communication/ocu/to/portable/car";              //! ocu到便携端式车辆*/
    const char COMMUNICATION_OCU_TO_PORTABLE_CAR_VIDEO[100] = "ucs/communication/ocu/to/portable/car/video";  //! 便携式车辆视频*/




    //! UAV message sending
    const char COMMUNICATION_OCU_TO_ALLIGN_DWDX_INFO[] = "ucs/communication/ocu/to/alling/dwdx/info";       //! alling定位信息
    const char COMMUNICATION_OCU_TO_ALLING_QYZXD_INFO[] = "ucs/communication/ocu/to/alling/qyzxd/info";     //! 区域中心点信息

    //! IMAGE RECV OR SEND
    const char COMMUNICATION_OCU_TO_IMAGE_RECV_OR_SEND[] = "ucs/communication/ocu/to/image/recv/or/send";   //! 图片收发


    //! ANIMATION_SWITCHING
    const bool ANIMATION_SWITCHING = false;

    const char COMMUNICATION_OCU_TO_VIDEO_LOCAL[] = "ucs/communication/ocu/to/video/local";     //!ocu到本地视频端
    //! ************* 车控-火控************************************

    const char COMMUNICATION_OCU_CARTL_TO_FIRECTL[] = "ucs/communication/ocu/carctl/firectl";     //! 车控火控
    const char COMMUNICATION_OCU_FIRECTL_TO_CARCTL[] = "ucs/communication/ocu/friectl/carctl";    //!火控到车控


     const char COMMUNICATION_OCU_TO_CHASSIS_CONTROL[] = "ucs/communication/ocu/to/chassis/control";


} // namespace EventConstants

