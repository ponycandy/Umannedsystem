#pragma once
#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QCoreApplication>

//! 定义测试数据
#define Task_28_Data
#define Task_29_Data

//!Π值
const double PI   = 3.14159265358979323846;
const double PI_2 = 1.57079632679489661923;
const double PI_4 = 0.78539816339744830962;

//!赤道半径
const double WGS_84_RADIUS_EQUATOR = 6378137.0;
//!*极半径*/
const double WGS_84_RADIUS_POLAR = 6356752.3142;

//!***********************************操控角色定义*****************************************/
typedef  enum{
   OPERATOR_ROLE_NONE = 0,
   OPERATOR_ROLE_VEHCLE_CONTROL,
   OPERATOR_ROLE_FIRE_CONTROL,
}OperatorRole;
Q_DECLARE_METATYPE(OperatorRole)

typedef enum{
    MAP_WIDGET_NONE = 0,
    MAP_WIDGET_XXDZZ_FC
}MapWidgetType;
Q_DECLARE_METATYPE(MapWidgetType)

//!***********************************path point info*****************************************/
typedef struct  _globalPose{
    double          longtitude;
    double          latitude;
    double          altitude;
    int             time;
    unsigned char   attribute;      //! 0-起始点 1-途经点 2-作战点 3-结束点
    int             reserve1;
    double          reserve2;
    unsigned char   reserve3;
}globalPose;

Q_DECLARE_METATYPE(globalPose)


//!中型轮式车和履带车自主驾驶都用这个结构体
typedef struct  _globalPoseMidCar{
    double          longtitude;
    double          latitude;
    double          altitude;
    int             time;
    unsigned char   attribute;
    int             reserve1;
    double          reserve2;
    unsigned char   reserve3;       //! 属性，同路网文件，0-起点/1-终点/2-必经点/3-定点侦查点/4-定位打击点
                                    //! 5-机动打击入口点/6-机动打击出口点/7-shuoshi砾石路/8-涉水路/9-壕沟/10-弹坑/11-凸台/12-S路段/13-队形变换点
}globalPoseMidCar;

//!所有车通用的自主驾驶都用这个结构体
typedef struct  _globalPoseCommon{
    double          longtitude;
    double          latitude;
    double          altitude;
    int             time;
    unsigned char   attribute;
    int             reserve1;
    double          reserve2;
    unsigned char   reserve3;       //! 属性，同路网文件，0-起点/1-终点/2-必经点/3-定点侦查点/4-定位打击点
                                    //! 5-机动打击入口点/6-机动打击出口点/7-shuoshi砾石路/8-涉水路/9-壕沟/10-弹坑/11-凸台/12-S路段/13-队形变换点
}globalPoseCommon;

Q_DECLARE_METATYPE(globalPoseMidCar)


typedef  struct    _CarPositonInfo{
  double    longtitude;
  double    altitude;
  double    yaw;
  double    pitch;
  double    roll;
}CarPositonInfo;
Q_DECLARE_METATYPE(CarPositonInfo)



/** ****************************车辆共用结构体**********************************************************/
typedef  enum{
   VEHICLE_TYPE_NONE = 0,
   VEHICLE_TYPE_QXXLC,              //! 轻型巡逻车车控
   VEHICLE_TYPE_ZXLDC,              //! 中型履带车车控
   VEHICLE_TYPE_ZXLSC,              //! 中型轮式车车控
   VEHICLE_TYPE_XXDZZ,              //! 新型电子战车控
   VEHICLE_TYPE_DJXLC,
   VEHICLE_TYPE_QXXLC_FC,           //! 轻型巡逻车火控
   VEHICLE_TYPE_ZXLDC_FC,           //! 中型履带车火控
   VEHICLE_TYPE_ZXLSC_FC,           //! 中型轮式车火控
   VEHICLE_TYPE_XXDZZ_FC,           //! 新型电子战火控
   VEHICLE_TYPE_DJXLC_FC,

}VehicleType;
Q_DECLARE_METATYPE(VehicleType)

typedef  enum{
   LINK_CAR_TYPE_NONE = 0,
   LINK_CAR_TYPE_SUPER,
   LINK_CAR_TYPE_MIDDLE,
   LINK_CAR_TYPE_CRAWLER,
   LINK_CAR_TYPE_SUPER_AND_MIDDLE_SUPER_MAIN,
   LINK_CAR_TYPE_SUPER_AND_MIDDLE_MIDDLE_MAIN
}LinkCarType;
Q_DECLARE_METATYPE(LinkCarType)

typedef  enum{
   CURRENT_LINK_CAR_TYPE_NONE = 0,
   CURRENT_LINK_CAR_TYPE_SUPER,
   CURRENT_LINK_CAR_TYPE_MIDDLE,
   CURRENT_LINK_CAR_TYPE_CRAWLER,
   CURRENT_LINK_CAR_TYPE_SUPER_AND_MIDDLE_SUPER_MAIN,
   CURRENT_LINK_CAR_TYPE_SUPER_AND_MIDDLE_MIDDLE_MAIN
}CurrentLinkCarType;
Q_DECLARE_METATYPE(CurrentLinkCarType)


typedef  enum{
    CAR_MANAGER_WIDGET_BTN_TYPE_NONE = 0,
    CAR_MANAGER_WIDGET_BTN_TYPE_CONNECT = 1,
    CAR_MANAGER_WIDGET_BTN_TYPE_EDIT = 2,
    CAR_MANAGER_WIDGET_BTN_TYPE_DELETE = 3,
    CAR_MANAGER_WIDGET_BTN_TYPE_DELETE_SURE = 4,
    CAR_MANAGER_WIDGET_BTN_TYPE_DELETE_CANCEL = 5,
}CarManagerWidgetBtnType;
Q_DECLARE_METATYPE(CarManagerWidgetBtnType)



/*位置信息结构体*/
typedef struct _strPose
{
    double longtitude;/*经度*/
    double latitude;  /*纬度*/
    float  targetSpeed;
    qint8  obstacleAvoidFlag;
    qint8  externFlagOne;
    qint8  externFlagTwo;
    qint32 externFlagThree;
    qint32 externFlagFour;
}strPose;
Q_DECLARE_METATYPE(strPose)



/** *************************************** coordination task struct*****************************************/
typedef struct  _CoordinationTask{
    int       taskNum;
    qint16    pointCount;/*路径点数*/
    float     speedMax;  /*最大速度：-100~100单位m/s,系数0.1，精确度到0.1m/s,实际10m/s时需下发值=100*/
    QVector<strPose>   pathPoint;/*规划航迹点*/
    QDateTime reciveTime;
}CoordinationTask;
Q_DECLARE_METATYPE(CoordinationTask)



/** **************************************用户管理相关枚举*************************************************/
typedef  enum userGradeName{
   PRIMARY_GRADE = 1,                                 /*普通的初级用户*/
   MIDDLE_GRADE,                                      /*普通管理员*/
   SENIOR_GRADE,                                      /*超级管理员*/
   SPECIAL_GRADE                                      /*特级管理员*/
}userGradeName;

/*用户信息*/
typedef  struct _UserInfo{
     QString   userName;           /*用户名*/
     QString   password;           /*密码*/
     int       grade;              /*用户等级*/
     int       currentState;       /*0 表示没有锁定 大于1表示锁定*/
     int       checkTime;          /*大于三次锁定用户半小时*/
     QDateTime  lockTime;
}UserInfo;
Q_DECLARE_METATYPE(UserInfo)

/*用户信息*/
typedef  struct _UserInfoDatabase{
     QString   userName;           /*用户名*/
     QString   password;           /*密码*/
     int       grade;              /*用户等级*/
     int       currentState;       /*0 表示没有锁定 大于1表示锁定*/
     int       checkTime;          /*大于三次锁定用户半小时*/
     int       lockTime;
}UserInfoDatabase;
Q_DECLARE_METATYPE(UserInfoDatabase)



typedef struct _PlusUserInfo
{
    QString userName;
    QString password;
    int grade;//1 普通用户, 2 普通管理员, 3 超级管理员
}PlusUserInfo;
Q_DECLARE_METATYPE(PlusUserInfo);


typedef struct _StVehicleNmlCfgData
{
    QString name;
    QString rw;
    QString buffer;
    QString process;
}StVehicleNmlCfgData;
Q_DECLARE_METATYPE(StVehicleNmlCfgData)

typedef struct _StVideoMonitorParam {
    QString sdpPath;
    bool isDoubleScene;
    int x;
    int y;
    int width;
    int height;
    bool isFullScene;
}StVideoMonitorParam;
Q_DECLARE_METATYPE(StVideoMonitorParam)

typedef struct _StVehicleCfgData
{
    QString nmlpath;
    QString nmlfiletemplate;
    QString nmlfile;

    QString crawlerNmlfiletemplate;
    QString crawlerNmlfile;

    QString middleNmlfiletemplate;
    QString middleNmlfile;

    QMap<QString, StVehicleNmlCfgData> nmlmap;
    QMap<QString, StVehicleNmlCfgData> readnmlmap;
    QMap<QString, StVehicleNmlCfgData> writenmlmap;

    StVideoMonitorParam videoParam;
    QString taskFileDirpath;
}StVehicleCfgData;
Q_DECLARE_METATYPE(StVehicleCfgData)

/** Vertex Point Info*/
typedef struct _VertexPointTrans{
    float   latitude;
    float   longitude;
    float   elevation;
}VertexPointTrans;
Q_DECLARE_METATYPE(VertexPointTrans)

typedef  enum{
    TASK_POINT_ATRRIBUTE_START = 0,                     //! 0表示起点
    TASK_POINT_ATRRIBUTE_END,                           //! 1表示终点
    TASK_POINT_ATRRIBUTE_ESSENTIAL,                     //! 2表示必经点
    TASK_POINT_ATRRIBUTE_INVESTIGATION_POINT,           //! 3表示定点侦察任务点
    TASK_POINT_ATRRIBUTE_ATTACH_POINT,                  //! 4表示定点打击任务点
    TASK_POINT_ATRRIBUTE_ATTACH_INTO_POINT,             //! 5表示机动打击入口点
    TASK_POINT_ATRRIBUTE_ATTACH_EXIT_POINT,             //! 6表示机动打击出口点
    TASK_POINT_ATRRIBUTE_ATTACH_GRAVEL_ROAD,            //! 7表示砾石路
    TASK_POINT_ATRRIBUTE_ATTACH_WADE_ROAD,              //! 8表示涉水路
    TASK_POINT_ATRRIBUTE_ATTACH_DITCH,                  //! 9表示壕沟
    TASK_POINT_ATRRIBUTE_ATTACH_CRATER,                 //! 10表示弹坑
    TASK_POINT_ATRRIBUTE_ATTACH_LUG_BOSS,               //! 11表示凸台
    TASK_POINT_ATRRIBUTE_ATTACH_S_SECTION_ROAD,         //! 12表示S路段
    TASK_POINT_ATRRIBUTE_ATTACH_FORMATION_CHANGE_POINT_START,  //! 13表示队形变换起点
    TASK_POINT_ATRRIBUTE_ATTACH_FORMATION_CHANGE_POINT_END,   //! 14表示队形变换终点
    TASK_POINT_ATRRIBUTE_HIGH_SPEED_START,              //! 15 预留位
    TASK_POINT_ATRRIBUTE_HIGH_SPEED_END,                //! 16 预留位
    TASK_POINT_ATRRIBUTE_RESERVE1,                      //! 17 预留位
    TASK_POINT_ATRRIBUTE_RESERVE2,                      //! 18 预留位
    TASK_POINT_ATRRIBUTE_RESERVE3,                      //! 19 预留位
    TASK_POINT_ATRRIBUTE_RESERVE4,                      //! 20 预留位
    TASK_POINT_ATRRIBUTE_RESERVE5,                      //! 21 预留位
    TASK_POINT_ATRRIBUTE_RESERVE6,                      //! 22 预留位
    TASK_POINT_ATRRIBUTE_RESERVE7,                      //! 23 预留位
    TASK_POINT_ATRRIBUTE_RESERVE8,                      //! 24 预留位
    TASK_POINT_ATRRIBUTE_RESERVE9,                      //! 25 预留位
    TASK_POINT_ATRRIBUTE_RESERVE10                      //! 26 预留位
}TaskPointAtrribute;
Q_DECLARE_METATYPE(TaskPointAtrribute)

typedef  enum{
    FIRE_CONTROL_TASK_TYPE_ON_STAND_BY,                //! 待命
    FIRE_CONTROL_TASK_TYPE_ORIENTATION_INVESTIGATION,  //! 定向侦察
    FIRE_CONTROL_TASK_TYPE_FIXED_ZERO_INVESTIGATION,   //! 定域侦察
    FIRE_CONTROL_TASK_TYPE_FIXED_POINT_ATTACH,         //! 定点打击
    FIRE_CONTROL_TASK_TYPE_LASER_START,                //! 开始激光照射
    FIRE_CONTROL_TASK_TYPE_LASER_END,                  //! 结束激光照射
    FIRE_CONTROL_TASK_TYPE_AROUND_SCAN,                //! 周视侦察
    FIRE_CONTROL_TASK_TYPE_FIXED_POINT_ATTACH_AND_LASER_START,
    FIRE_CONTROL_TASK_TYPE_FIXED_ZERO_INVESTIGATION_AND_DICATION_FLAG, //! 定域侦察和打击指示
    FIRE_CONTROL_TASK_TYPE_FIRING_PERMISION_INDICATION //! 打击指示
}FireControlTaskType;
Q_DECLARE_METATYPE(FireControlTaskType)

typedef  enum{
   TASK_TARGET_ISSUE_NOT = 0,                         //! 0未下发
   TASK_TARGET_ISSUE_YES,                             //! 1已下发
}TaskTargetIssueState;
Q_DECLARE_METATYPE(TaskTargetIssueState)

typedef  enum{
   TASK_COMPLETION_STATE_PROCESSING,                  //! 0-正在前往
   TASK_COMPLETION_STATE_ARRIVE_POINT,                //! 1-到达任务点开始任务
   TASK_COMPLETION_STATE_TASK_PROSSING,               //! 2-任务执行中
   TASK_COMPLETION_STATE_TASK_COMPLETE,               //! 3-任务完成
   TASK_COMPLETION_STATE_OVER_CLOCK,                  //! 4-任务超时
   TASK_COMPLETION_STATE_ARRIVE_FORMATION_CHANGE_POINT//! 5-任务超时
}TaskCompletionState;
Q_DECLARE_METATYPE(TaskCompletionState)

typedef  enum{
   FIRE_CONTROL_TASK_COMPLETION_STATE_TO_PERFORM,     //! 0-待执行
   FIRE_CONTROL_TASK_COMPLETION_STATE_PROCESSING,     //! 1-执行中
   FIRE_CONTROL_TASK_COMPLETION_STATE_PAUSE,          //! 2-暂停中
   FIRE_CONTROL_TASK_COMPLETION_STATE_COMPLETE        //! 3-完成
}FireControlTaskCompletionState;
Q_DECLARE_METATYPE(FireControlTaskCompletionState)

typedef  enum{
   FIRE_CONTROL_TASK_ISSUE_STATE_TO_PERFORM,          //! 0-待执行
   FIRE_CONTROL_TASK_ISSUE_STATE_PROCESSING,          //! 1-执行中
   FIRE_CONTROL_TASK_ISSUE_STATE_PAUSE,               //! 2-暂停中
   FIRE_CONTROL_TASK_ISSUE_STATE_COMPLETE             //! 3-完成
}FireControlTaskIssueState;
Q_DECLARE_METATYPE(FireControlTaskIssueState)

typedef  enum{
   TASK_POINT_DISTTRIBUTE_NONE,                       //! 任务未分配
   TASK_POINT_DISTTRIBUTE_CAR,                        //! 分配为无人车
   TASK_POINT_DISTTRIBUTE_PERSON_CAR                  //! 分配为有人车
}TaskPointDisttributeState;
Q_DECLARE_METATYPE(TaskPointDisttributeState)

typedef  enum{
   AUTONOMUS_DRIVER_TASK_COMPLETION_STATE_TO_PERFORM, //! 0-待执行
   AUTONOMUS_DRIVER_COMPLETION_STATE_PROCESSING,      //! 1-执行中
   AUTONOMUS_DRIVER_COMPLETION_STATE_PAUSE,           //! 2-暂停中
   AUTONOMUS_DRIVER_COMPLETION_STATE_COMPLETE         //! 3-完成
}AutonomusDriverTaskCompletionState;
Q_DECLARE_METATYPE(AutonomusDriverTaskCompletionState)

typedef struct _MiddleCarComponentTask
{
    int                  pointIndex;                  //!
    VertexPointTrans     pointValue;                  //!
    TaskPointAtrribute   pointAttribute;              //!
    TaskCompletionState  completionState;
    FireControlTaskIssueState  fireControlIssueState;
    FireControlTaskCompletionState  fireControlcompletionState;

    AutonomusDriverTaskCompletionState  autonomusState;
    int                  timeLimit;                   //!
    int                  iExecutedNum;                //! 更新界面状态  重复性任务执行次数，每执行一次加1，无重复执行的任务置为0
    QVector<VertexPointTrans>  taskArea;              //!
}MiddleCarComponentTask;
Q_DECLARE_METATYPE(MiddleCarComponentTask)



//! ********************************地图标会结构体管理*************************************/
enum WayPointAttribute {
    WAY_POINT_ATTRIBUTE_NONE = 0,      //! 起始点
    WAY_POINT_ATTRIBUTE_START,         //! 结束点
    WAY_POINT_ATTRIBUTE_END,           //! 过程点
};
Q_DECLARE_METATYPE(WayPointAttribute)

enum WaySectionAttribute {
    WAY_SECTION_ATTRIBUTE_NONE = 0,    //! 起始点
    WAY_SECTION_ATTRIBUTE_START,       //! 结束点
    WAY_SECTION_ATTRIBUTE_END,         //! 过程点
};
Q_DECLARE_METATYPE(WaySectionAttribute)


enum PlottingAttribute {
    PLOTTING_ATTRIBUTE_NONE = 0,       //! 起始点
    PLOTTING_ATTRIBUTE_COMMAND,        //! 结束点
    PLOTTING_ATTRIBUTE_AUTO_DRIVER,    //! 过程点
    PLOTTING_ATTRIBUTE_MIDDLE_CAR_COMMAND,        //! 结束点
    PLOTTING_ATTRIBUTE_MIDDLE_CAR_AUTO_DRIVER,    //! 过程点
    PLOTTING_ATTRIBUTE_CRAWLER_CAR_COMMAND,        //! 结束点
    PLOTTING_ATTRIBUTE_CRAWLER_CAR_AUTO_DRIVER,    //! 过程点
};

Q_DECLARE_METATYPE(PlottingAttribute)

typedef struct _MapPlottingAttribute{
    int      iSerinum;
    int      iLineWidth;
    QColor   color;
    QPointF  pointValue;
    TaskPointAtrribute   taskPointAtrribute;
    PlottingAttribute    plottingAttribute;
    WayPointAttribute    wayPointAttribute;
    WaySectionAttribute  waySectionAttribute;
}MapPlottingAttribute;
Q_DECLARE_METATYPE(MapPlottingAttribute)


typedef struct _MapPlottingParaManager{
    int     iTaskId;
    QMap<int,MapPlottingAttribute>  mapPlottingAttribute;
}MapPlottingParaManager;
Q_DECLARE_METATYPE(MapPlottingParaManager)


//!************************************履带车和轮式车摇杆定义***********************************
//! xBox axis value
//! 两个摇杆值经过转换后皆为：上正下负；左正右负 值域： (-100) - 100
//! L2与R2值皆为： 值域：0-100, L2-急停; R2-急停;
//! 左边摇杆，上方向表示油门，下方向表示制动; 右边摇杆，左方向表示左转，右方向表示右转
//!***********************************************************************************
typedef struct _XBoxAxisValue{
    int     L2;
    int     R2;
    int     leftX;
    int     leftY;
    int     rightX;
    int     rightY;
}XBoxAxisValue;
Q_DECLARE_METATYPE(XBoxAxisValue)


//! ***********************************serialPort application data *******************************************/
//! 上层应用数据
typedef   struct _rockerData{
    qint16   directionalDeflection;          //! 方向转向量
    qint16   brake;                          //! 刹车
    qint16   accelerograph;                  //! 油门
    qint8    fourToggleSwitchLeftUp;
    qint8    fourToggleSwitchLeftDown;
    qint8    fourToggleSwitchLeftLeft;
    qint8    fourToggleSwitchLeftRight;
    qint8    fourToggleSwitchRightUp;
    qint8    fourToggleSwitchRightDown;
    qint8    fourToggleSwitchRightLeft;
    qint8    fourToggleSwitchRightRight;
    qint8    buttonSwitchLeft;
    qint8    buttonSwitchRight;
    qint8    twoToggleSwitchLeftUp;
    qint8    twoToggleSwitchLeftDown;
    qint8    twoToggleSwitchRightUp;
    qint8    twoToggleSwitchRightDown;
}rockerData;
Q_DECLARE_METATYPE(rockerData)

//! ***********************************任务数据***************************************************/


//! ***********************************合成营摇杆串口数据接口*******************************************/
//! 上层应用数据
//!
#define MAX_XXDZZ_CTL_VALUE   100
#define MAX_QXXLC_CTL_VALUE   100
#define MAX_ZXLDC_CTL_VALUE   100
#define MAX_ZXLSC_CTL_VALUE   100
typedef   struct _ControlRockerTrans{
    qint16   x_axis;                    //! 转向控制
    qint16   y_axis;                    //! 油门或者制动
    qint8    topButtonSwitchesLeft;     //! 近光灯
    qint8    topButtonSwitchesMiddle;   //! 底盘限速 -5km
    qint8    topButtonSwitchesRight;    //! 底盘限速 +5km
    qint8    leftButtonSwitch;          //! 紧急制动
    qint8    triggerSwitch;             //! 喇叭
}ControlRockerTrans;
Q_DECLARE_METATYPE(ControlRockerTrans)

typedef   struct _ControlLeftRockerTrans{
    qint16   x_axis;                    //! 方位伺服速度
    qint16   y_axis;                    //! 俯仰伺服速度
    qint8    topButtonSwitchesLeft;     //! 搜索模式  1:搜索模式 0:无操作
    qint8    topButtonSwitchesMiddle;   //! 跟踪模式  1:跟踪模式 0:无操作
    qint8    topButtonSwitchesRight;    //! 单杆标志    武器平台随动光电
    qint8    leftButtonSwitch;          //! 单杆标志    仅操控光电
    qint8    triggerSwitch;             //! 测距命令
}ControlLeftRockerTrans;
Q_DECLARE_METATYPE(ControlLeftRockerTrans)

/**
 * 插件集成时用于转发数据
 * */
typedef   struct _RockerTurntoThirdPartyTrans{
    quint16  head;                      //! 头为 0x为固定值0xbbaa
    qint8    type;                      //! 为固定值0x0a
    qint8    length;                    //! 是指整个帧的字节总数，为固定值19
    qint8    x_axis;                    //!
    qint8    y_axis;                    //!
    qint8    topButtonSwitchesLeft;     //!
    qint8    topButtonSwitchesMiddle;   //!
    qint8    topButtonSwitchesRight;    //!
    qint8    leftButtonSwitch;          //!
    qint8    triggerSwitch;             //!
    qint8    crc;                       //!
}RockerTurntoThirdPartyTrans;
Q_DECLARE_METATYPE(RockerTurntoThirdPartyTrans)


//! ********************************车辆管理结构体******************************************************
typedef struct _CarInfo {
    int     carNumber;                    //! 车辆编号
    QString carType;                      //! 车辆类型
    QString carName;                      //! 车辆名称

    QString localIpAddress;               //! 本地IP地址
    quint16 carCtrlPort;

    QString carIpAddress;
    QString chassisIpAdddress;            //! 底盘计算机IP地址
    QString autonomousComputerIpAddress;  //! 自主计算机IP地址

    QString videoIpAddress;               //! 相机控制远端IP
    quint16 videoCtrlPort;                //! 相机控制本地端口
    quint16 videoCtrlRemotePort;          //! 相机控制远端端口
    quint16 videoPlayPort;                //! 视频播放端口

    QString fireControlIpAddress;         //! 火控软件远端IP
    quint16 fireControlLocalPort;         //! 火控软件本地端口
    quint16 fireControlRemotePort;        //! 火控软件远端端口

    QString commandControlIpAddress;      //! 指控软件远端IP
    quint16 commandControlLocalPort;      //! 指控软件本地端口
    quint16 commandControlRemotePort;     //! 指控软件远端端口
} CarInfo;

Q_DECLARE_METATYPE(CarInfo)


enum ControlMsgType{
    CONTROL_MSG_NONE,
    CONTROL_MSG_PAUSE_CUR_ACTION,
    CONTROL_MSG_CONTINUCE_CUR_ACTION,
    CONTROL_MSG_TERMINATE_CUR_ACTION,
    CONTROL_MSG_CONVENT_MANEUVER,
    CONTROL_MSG_MANY_TASK_POINT,
    CONTROL_MSG_AFTER_PARK_ACTION,
    CONTROL_MSG_TURN_IN_PLACE,
    CONTROL_MSG_LIFT_CAR,
    CONTROL_MSG_POWER_SWITCH,
    CONTROL_MSG_FOLLOW,
    CONTROL_MSG_SELF_DESTRUCT,
    CONTROL_MSG_AUTO_PARAMETER_SET,
    CONTROL_MSG_AUTO_WORK_CONTROL,
    CONTROL_MSG_NO_FATAL_STRIKE,
    CONTROL_MSG_FATAL_STRIKE,
};
Q_DECLARE_METATYPE(ControlMsgType)

typedef struct _KeyPointInfoTrans{
    qint16  serialNum;                      //! Range 0-10000, current key point sequence number*/
    double  longitude;                      //! Scale 0.0000001 degrees, range -180~180 degrees factor=0.0000001 offset=0*/
    double  latitude;                       //! Scale 0.0000001 degrees, range -90~90 degrees factor=0.0000001 offset=0*/
    quint8  attribute;                      //! 1-起始点; 2-导航点; 3-结束点
}KeyPointInfoTrans;
Q_DECLARE_METATYPE(KeyPointInfoTrans)


/** 指控任务转自主任务*/
typedef struct _CommandTaskTurnToAutoDriverTrans
{
    ControlMsgType      type;
    int                 powerMode;
    float               referenceSpeed;
    int                 keyPointNum;
    QVector<KeyPointInfoTrans>    keyPoint;
}CommandTaskTurnToAutoDriverTrans;
Q_DECLARE_METATYPE(CommandTaskTurnToAutoDriverTrans)


typedef  struct   _AddPointFromMapControl{
     bool   control;
     int    taskNum;
}AddPointFromMapControl;
Q_DECLARE_METATYPE(AddPointFromMapControl)

//! ********************************网络配置结构体*************************************/
//! 网络配置参数
typedef struct  _NetWorkConfig{
    QString  carID;
    QString  localIP;                          //! 本地Ip
    int      toChassisPort;                    //! 对底盘端口
    int      toCommamdControlPort;             //! 对指控端口
    int      toComputerPort;                   //! 对自主计算机端口
    int      toVideoPort;                      //! 对视频端口
    int      toRadioPort;                      //! 对电台端口
    int      toPortablePort;                   //! 对便携端端口
    QString  commandControlIp;                 //! 指控IP
    int      commandControlPort;               //! 指控端口
    QString  chassisIp;                        //! 底盘IP
    int      chassisPort;                      //! 底盘端口
    QString  computerIp;                       //! 自主计算机IP
    int      computerPort;                     //! 自主计算机端口
    QString  videoIp;                          //! 视频IP
    int      videoPort;                        //! 视频端口
    QString  radioIp;                          //! 电台IP
    int      radioPort;                        //! 电台端口
    QString  portableIp;                       //! 便携端IP
    int      portablePort;                     //! 便携端端口
}NetWorkConfig;
Q_DECLARE_METATYPE(NetWorkConfig)


enum TaskPointFlag {
    TASK_POINT_NONE,
    TASK_POINT_START,
    TASK_POINT_WAY,
    TASK_POINT_END,
    TASK_POINT_RECONNAISSANCE,
    TASK_POINT_PATROL_START,
    TASK_POINT_PATROL_END,
    TASK_POINT_TRENCH,
    TASK_POINT_VERTICAL_WALL,
};

Q_DECLARE_METATYPE(TaskPointFlag)

enum TaskMode{
    TASK_MODE_NONE,
    TASK_MODE_ON_STANDBY,
    TASK_MODE_ORIENT_ZHENCHA,
    TASK_MODE_LOCAL_ZHENCHA,
    TASK_MODE_FIXED_ZHENCHA,
    TASK_MODE_ORIENT_STRIKE,
    TASK_MODE_LOCAL_STRIKE,
    TASK_MODE_FIXED_STRIKE,
    TASK_MODE_TURN_ON_LASER,
    TASK_MODE_END_LASER,
    TASK_MODE_LASER_RANG
};
Q_DECLARE_METATYPE(TaskMode)

enum TaskPointActionType {
    ACTION_TYPE_ADD = 0,
    ACTION_TYPE_REMOVE,
    ACTION_TYPE_MODIFICATION,
};

Q_DECLARE_METATYPE(TaskPointActionType)


typedef struct _TaskPointData {
    int     index;
    double  longitude;
    double  latitude;
    double  altitude;
    TaskPointFlag flag;
} TaskPointData;
Q_DECLARE_METATYPE(TaskPointData)

typedef struct _ChildTask{
    TaskPointData       firstPoint;
    TaskPointData       secondPoint;
}ChildTask;
Q_DECLARE_METATYPE(ChildTask)

typedef  struct    _TaskInfoManager{
    int             serialNum;
    QString     fileName;
    QString     reciceTime;
    bool          issuedState;
    QList<TaskPointData>   taskPoint;
}TaskInfoManager;
Q_DECLARE_METATYPE(TaskInfoManager)


typedef  struct   _TaskPathPointPara{
    TaskPointActionType   actionType;
    int     iTaskID;
    int     iPointSerialNum;
    QPointF pathPoint;
}TaskPathPointPara;
Q_DECLARE_METATYPE(TaskPathPointPara)



/** ******************************************************************************
 * *  按键对应表
 *********************************************************************************/
typedef enum{
    Screen_Button_None,
    Screen_Button_Left_One,              //!*左1*/
    Screen_Button_Left_Two,              //!*左2*/
    Screen_Button_Left_Three,            //!*左3*/
    Screen_Button_Left_Four,             //!*左4*/
    Screen_Button_Left_Five,             //!*左5*/
    Screen_Button_Left_Six,              //!*左6*/
    Screen_Button_Right_One,             //!*右1*/
    Screen_Button_Right_Two,             //!*右2*/
    Screen_Button_Right_Three,           //!*右3*/
    Screen_Button_Right_Four,            //!*右4*/
    Screen_Button_Right_Five,            //!*右5*/
    Screen_Button_Right_Six,             //!*右6*/
}ScreenButtonNum;

/** ******************************************************************************
 *
 *  屏幕按键数据
 *
 *********************************************************************************/
typedef struct _ScreenButtonSerialPortPacketTrans
{
    qint8    head;                       //!*开始标志:0xAA*/
    qint8    workCode;                   //!*功能码0x01*/
    qint8    dataLength;                 //!*结束标志：按键按下是为0x01，没有按键按下时为0x00*/
    ScreenButtonNum   buttonValue;       //!*按键数据*/
    qint8    crc;                        //!*校验：校验和=（功能码+数据长度+数据）%80*/
    qint8    end;                        //!*结束标志：0xBB*/
}ScreenButtonSerialPortPacketTrans;
Q_DECLARE_METATYPE(ScreenButtonSerialPortPacketTrans)

//!**************************************************ocu到本地视频端*******************************************************
typedef struct _OcuToLocalVideoTrans{
    quint32         cmd;            //! 10:底盘视频;11:火控视频
    quint32         image_width;
    quint32         image_height;
}OcuToLocalVideoTrans;
Q_DECLARE_METATYPE(OcuToLocalVideoTrans)

//! **************************************************jgyddj*******************************************************
typedef struct	_MsgJGYDTrans
{
    QString XXLSH;  //流水号
    QString ZZDYBH; //作战单元编号
    int YDLX;       //引导类型
    QString JD;     // 经度
    QString WD;     // 纬度
    QString GD;     // 高度
}MsgCommJGYDTrans;
Q_DECLARE_METATYPE(MsgCommJGYDTrans)

//! ************************************车实时位置**************************************************
typedef struct	_OcuCarPositionTrans
{
    double  lon;
    double  lat;
    double  yaw;
    double  pitch;
    double  roll;
    double  reserv;
}OcuCarPositionTrans;
Q_DECLARE_METATYPE(OcuCarPositionTrans)

//!载荷任务完成情况反馈 操控端下发给自主软件 关键字段： zhzt
typedef struct _OcuFireControlTaskStateTrans{
    int heart_beat;                          //! 心跳信号
    int task_excu_num;                       //! 任务执行次数（预留，判断任务是否重复执行）
    int task_num;                            //! 任务号
    int Pos_id;                              //! 位置序列号 0-第一个点;1-第二个点;  .... ;n- 第n+1个点
    unsigned char attribute;                 //! 任务属性，同路网文件
    unsigned char   zhzt;                    //! 载荷任务完成状态,0-未完成/1-完成
    int             reserve1;                //! 保留位1
    int             reserve2;                //! 保留位2
    int             reserve3;                //! 保留位3
    double          reserve4;                //! 保留位4
    double          reserve5;                //! 保留位5
    double          reserve6;                //! 保留位6
    unsigned char   reserve7;                //! 保留位7
    unsigned char   reserve8;                //! 保留位8
    unsigned char   reserve9;                //! 保留位9
}OcuFireControlTaskStateTrans;
Q_DECLARE_METATYPE(OcuFireControlTaskStateTrans)


/** *********************************软件运行日志***********************************************************/
//!*******************************************************日志相关枚举***************************************

typedef enum LogRecordingTableType{
    LOGTABLE_REMOTEDRIVING,                           //! 遥控驾驶
    LOGTABLE_AUTODRIVING,                             //! 自主驾驶
    LOGTABLE_APPRUNINFO,                              //! 软件运行
}LogRecordingTableType;

Q_DECLARE_METATYPE(LogRecordingTableType)

/*软件运行日志*/
enum AppRunRecordingType {
    APPRUN_INFO = 0,                       /*软件运行记录类型：信息*/
    APPRUN_WARNING,                        /*软件运行记录类型：警告*/
    APPRUN_ERROR,                          /*软件运行记录类型：错误*/
};
Q_DECLARE_METATYPE(AppRunRecordingType)


typedef struct _AppRunRecordingData {
    QDateTime recordingTime;               /*记录时间*/
    AppRunRecordingType recordingType;     /*记录类型*/
    QString infoText;                      /*记录文本*/
} AppRunRecordingData;

/*任务日志*/
typedef struct _ReceiveTaskLogData{
    QString            taskFileName;                  /*任务文件名称*/
    QDateTime      receiveTime;                       /*接收时间*/
    QString            TaskReading;                   /*任务阅读情况*/
    QString            TaskCompletion;                /* 任务完成情况*/
}ReceiveTaskLogData;
Q_DECLARE_METATYPE(ReceiveTaskLogData)

/*遥控驾驶任务*/
typedef struct _RemoteDrivingData{
    QDateTime   StartTime;                            /*任务开始时间*/
    QDateTime   FinishTime;                           /*任务结束时间*/
    strPose         startPoint;                       /*起点*/
    strPose         endPoint;                         /*终点*/
    double          drivenDistance;                   /*行驶里程*/
    double          maxSpeed;                         /*最大速度（km/h）*/
    double          aveSpeed;                         /*平均速度（km/h）*/
}RemoteDrivingData;
Q_DECLARE_METATYPE(RemoteDrivingData)

/*自主驾驶任务*/
typedef struct _AutoDrivingData{
    QString                 globalPath;                 /*全局路径*/
    QVector<strPose>        midPoint;                   /*中间过程点*/
    QDateTime               StartTime;                  /*任务开始时间*/
    QDateTime               FinishTime;                 /*终止时间*/
    double                  drivenDistance;             /*行驶里程*/
    double                  maxSpeed;                   /*最大速度（km/h）*/
    double                  aveSpeed;                   /*平均速度（km/h）*/
    strPose                 humanInterPoint;            /*人工干预位置点*/
    QString                 humanInterWay;              /*人工干预方式（制动、加速）*/
}AutoDrivingData;
Q_DECLARE_METATYPE(AutoDrivingData)

/*系统操作日志*/
typedef struct _SystemOperationData{
    QDateTime       operationTime;                     /*操作时间*/
    QString         devicePowerHistory;                /*设备上电/断电记录*/
    QString         inertialNavigationRecord;          /*惯导操作记录*/
}SystemOperationData;
Q_DECLARE_METATYPE(SystemOperationData)

/*车辆状态日志**/
typedef struct _VehicleStatusData{
    QDateTime         recordTime;                     /*记录时间*/
    QString           equipmentRunningStatus;         /*设备运行状态*/
    QString           warningInfo;                    /*异常告警信息*/
}VehicleStatusData;
Q_DECLARE_METATYPE(VehicleStatusData)

/*数据查询接口*/
enum DataQueryMode {
    DATAQUERY_STARTEDTIME = 0,                          /*根据起始时间查询*/
    DATAQUERY_FINISHEDTIME,                             /*根据结束时间查询*/
};

namespace LogDatabase {
const QString g_databaseDir     = QCoreApplication::applicationDirPath() + "/sql";
const QString g_databaseName    = QCoreApplication::applicationDirPath() + "/sql/ucs.db";
const QString g_remoteTableName = "remote_driving_data";
const QString g_autoTableName   = "auto_driving_data";
const QString g_appRunTableName = "app_run_data";
const QString g_userInfoTableName = "user_info_data";
const QString g_taskManageTableName = "task_manage_data";
const QString g_controlTaskTableName = "control_task_data";
const QString g_controlConventTableName = "control_convent_data";
const QString g_controlManyTaskTableName = "control_many_task_data";
const QString g_controlLoadTableName = "control_load_data";
const int     g_dataMaxCounts   = 10;

const QString g_plusUserInfoTableName = "plus_user_info_data";
}

namespace LogDrivingTrack {
const QString g_remoteDrivingTrackPath      = QCoreApplication::applicationDirPath() + "/sql/track/remote_track";
const QString g_planAutoDrivingTrackPath    = QCoreApplication::applicationDirPath() + "/sql/track/auto_plan_track";
const QString g_realityAutoDrivingTrackPath = QCoreApplication::applicationDirPath() + "/sql/track/auto_reality_track";
const QString g_controlTaskPath             = QCoreApplication::applicationDirPath() + "/sql/task/control_task";
const QString g_taskFilePath                = QCoreApplication::applicationDirPath() + "/sql/task";
}

typedef QPointF DrivingPos;                /*路径点（经纬度）*/
Q_DECLARE_METATYPE(QList<DrivingPos>)

/*遥控驾驶任务*/
typedef struct _RemoteDrivingTaskData {
    QDateTime taskStartedTime;             /*任务开始时间*/
    QDateTime taskFinishedTime;            /*任务结束时间*/
    QList<DrivingPos> drivingTrack;        /*行驶轨迹*/
    double speed;                          /*速度（km/h）*/
    double course;                         /*航向角*/
    double courseSpeed;                    /*航向角速度*/
    int accelerograph;                     /*油门控制量*/
    int braking;                           /*制动控制量*/
    int turn;                              /*转向控制量*/
} RemoteDrivingTaskData;

Q_DECLARE_METATYPE(RemoteDrivingTaskData);


/*自主驾驶任务*/
typedef struct _AutoDrivingTaskData {
    QDateTime taskStartedTime;             /*任务开始时间*/
    QDateTime taskFinishedTime;            /*任务结束时间*/
    QList<DrivingPos> planDrivingTrack;    /*任务路径点*/
    double distance;                       /*行驶里程（km）*/
    QList<DrivingPos> realityDrivingTrack; /*行驶轨迹*/
    double speed;                          /*速度（km/h）*/
} AutoDrivingTaskData;
Q_DECLARE_METATYPE(AutoDrivingTaskData);


typedef struct _exportLogSelectData
{
    int exportLocal;//导出的位置，0导出到本地，1导出到U盘
    int exportTimeType;//导出的时间选择，0以开始时间，1以结束时间
    QDateTime timeBegin;//选择的开始时间
    QDateTime timeEnd;//选择的结束时间
    LogRecordingTableType logType;//选择导出的日志类型
    //新添加的，因为在弹出框必须传一个父指针，不然在平板上面会有一个黑色的边框
    QWidget* parent;//发出导出信号页面的指针
}ExportLogSelectData;
Q_DECLARE_METATYPE(ExportLogSelectData);


//! *************************************************指控任务*********************************************/
typedef struct _ControlTaskTrans
{
    int                 taskNum;
    QString             receiveTime;
    quint8              status;           //!1：未执行；2：已执行
    ControlMsgType      type;
    int                 dataOne;
    int                 dataTwo;
}ControlTaskTrans;
Q_DECLARE_METATYPE(ControlTaskTrans)

typedef struct _ControlTaskConventManeuverTrans
{
    int                 taskNum;
    QString             receiveTime;
    quint8              status;           //!1：未执行；2：已执行
    ControlMsgType      type;
    int                 powerMode;
    float               referenceSpeed;
    int                 keyPointNum;
    QVector<KeyPointInfoTrans>  keyPoint;
}ControlTaskConventManeuverTrans;
Q_DECLARE_METATYPE(ControlTaskConventManeuverTrans)

typedef struct _ControlTaskManyTaskTrans
{
    int                 taskNum;
    QString             receiveTime;
    quint8              status;           //!1：未执行；2：已执行
    ControlMsgType      type;
    int                 maxInterval;
    int                 keyPointNum;
    QVector<KeyPointInfoTrans>  keyPoint;
}ControlTaskManyTaskTrans;
Q_DECLARE_METATYPE(ControlTaskManyTaskTrans)

typedef struct _ControlLoadTrans
{
    int                 taskNum;
    QString             receiveTime;
    quint8              status;             //!1：未执行；2：已执行
    ControlMsgType      type;
    quint8              autoWorkMode;       //! 自主工作模式;0x01: 巡线侦察监视;0x02: 定点侦察监视告警;0x03: 定点侦打一体
    quint16             targetDistance;     //! 目标大致距离; 米
    qint16              targetPitchRange;   //! 目标俯仰角范围;量纲90°/32768,范围（-90°-90°）
    quint16             scanPosition;       //! 扫描方位;【A,B】°（默认为周扫）（0°~360°）360/65536
    qint16              scanRange;          //! 扫描左极限=扫描方位-扫描范围/2;扫描右极限=扫描方位+扫描范围/2
    quint8              loadImagingSensor;  //! 载荷成像传感器选择;0x01 红外;0x02 电视
    quint8              autoTracking;       //! 是否自动跟踪;0x01 非自动跟踪;0x02 自动跟踪
    quint8              autoRanging;        //! 是否自动测距;0x01 非自动测距;0x02 自动测距
}ControlLoadTrans;
Q_DECLARE_METATYPE(ControlLoadTrans)


/** **************************************************************************
 *
 *  RCS初始化状态
 *
 ****************************************************************************/
typedef struct _RcsInnitStateTrans
{
    LinkCarType  linkCarType;
    bool         isRcsInnitState;
    QString      rcsReportInfo;
}RcsInnitStateTrans;
Q_DECLARE_METATYPE(RcsInnitStateTrans)





