#pragma once

#include <stdint.h>
#include <QVector>
#include <QMap>
#include "DjxlcOcuControlICDStruct.h"
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>




#include <QString>

namespace LogDefines {

typedef struct _TaskLogData
{
    QString taskname;
    QString readstate;
    QString workstate;
}TaskLogData;

typedef struct _SystemHandleData
{
    QString equipname;
    QString power;
    QString operation;
}SystemHandleData;

typedef struct _CarStateData
{
    QString carip;
    QString cartype;
    QString warning;
}CarStateData;

typedef struct _CarRunData
{
    QString tasktype;
    QString starttime;
    QString endtime;
    float mile;//里程数
    float maxspeed;
    float avespeed;
    QString detail;
}CarRunData;

} // namespace LogDefines



namespace Djxlc {

/*Π值*/
const double PI   = 3.14159265358979323846;
const double PI_2 = 1.57079632679489661923;
const double PI_4 = 0.78539816339744830962;

/*赤道半径*/
const double WGS_84_RADIUS_EQUATOR = 6378137.0;
/*极半径*/
const double WGS_84_RADIUS_POLAR = 6356752.3142;

/***********************************状态枚举量定义*******************************************/
typedef  enum{
    Operation_Mode_None = 0,
    Operation_Mode_Patk_Point_Record,            /*0x1：路点记录（只记录路点，用于地图上显示轨迹，不进行下发）*/
    Operation_Mode_Path_Follow,                  /*0x2：路径跟踪行驶*/
    Operation_Mode_One_Key_Back,                 /*0x3：一键返航*/
    Operation_Mode_Low_Speed_Follow,             /*0x4：人员低速跟随（低速对应：引导员不超过3km/h前进速度）*/
    Operation_Mode_Around_Pile_Follow,           /*0x5：人员绕桩跟随*/
    Operation_Mode_Target_Remote_Detection,      /*0x6：人员目标远距离探测（对应静态：人员跟随最大距离测试）*/

    Operation_Mode_Car_Target_Follow,            /*0x7：车辆目标跟随*/
    Operation_Mode_Pause,                        /*0x8：暂停*/
    Operation_Mode_Restore_Autopilot,            /*0x9：恢复自动驾驶功能*/
    Operation_Mode_Stop_Autopilot,               /*0xA：停止自动驾驶功能*/
    Operation_Mode_Voice_Guide_Follow,           /*0xB：语音引导跟随*/
    Operation_Mode_Gesture_Guide_Follow,         /*0xC：手势引导跟随*/
    Operation_Mode_Situation_Enhancement_Replay, /*0xD：态势增强回复*/
}OperationMode;

typedef  enum{
    Sub_Opration_Mode_None = 0,
    Sub_Opration_Mode_Genarate,
    Sub_Opration_Mode_Down_Level,
    Sub_Opration_Mode_Around_Pile,
    Sub_Opration_Mode_Down_Level_And_Around_Pile,
    Sub_Opration_Mode_Record_Point_Start,
    Sub_Opration_Mode_Record_Point_End,
    Sub_Opration_Mode_Enhancement_Situation_Start,
    Sub_Opration_Mode_Enhancement_Situation_End,
}SubOprationMode;

typedef  enum{
    DRIVING_MODE_STOP_CAR = 0,      /*0：停车*/
    DRIVING_MODE_AUTO_CONTROL,      /*1：自主*/
    DRIVING_MODE_REMOTE_CONTROL     /*2：遥控*/
}DrivingMode;

typedef  enum{
    PATH_FOLLOW_TASK_TYPE_NONE,
    PATH_FOLLOW_TASK_TYPE_NEW_BUILDE,
    PATH_FOLLOW_TASK_TYPE_LOAD_FILE,
}PathFollowTaskType;

typedef  enum{
    PLOT_TYPE_NONE = 0,/**/
    PLOT_TYPE_PATH_FOLLOE,/**/
    PLOT_TYPE_COORDINATE_TASK,
    PLOT_TYPE_DISTANCE,  /**/
    PLOT_TYPE_AREA,/**/
    PLOT_TYPE_FIXED_POINT_INVESTIGATION,
}PlotType;

typedef  enum{
    PLOT_POINT_CHANGED_TYPE_NONE = 0,/**/
    PLOT_POINT_CHANGED_TYPE_MOVE,/**/
    PLOT_POINT_CHANGED_TYPE_REMOVE,
    PLOT_POINT_CHANGED_TYPE_EDIT,
    PLOT_POINT_CHANGED_TYPE_INSERT,
}PlotPointChangedType;

typedef  enum{
    CURRENT_CONNECTED_CAR_TYPE_NONE = 0,
    CURRENT_CONNECTED_CAR_TYPE_WHEELED,     /*轮式车辆*/
}CurrentConnectedCarType;

/*语言设置*/
enum InternationalizationLanguage
{
    ChineseLanguage = 0,
    EnglishLanguage,
    FrenchLanguage,
    ArabicLanguage,
};

/*******************************ocu端到底盘的控制量*****************************************/
typedef struct _CAN_Num
{
    quint32     frameSerialNum;  /** 帧序号 从0开始每帧递增（小端字节序）*/
    quint8      heartNum;        /** 心跳   从0递增 */
}CAN_Num;

// yx
typedef enum
{
    CAN_Para_None = -1,
    CAN_Para_One = 0,
    CAN_Para_Two,
    CAN_CarMainStatusInfoOne,
    CAN_CarMainStatusInfoTwo,
    CAN_CarDetailStatusInfoOne,
    CAN_CarDetailStatusInfoTwo,
    CAN_CarDetailStatusInfoThree,
    CAN_CarDetailStatusInfoFour,
    CAN_CarDetailStatusInfoFive,
    CAN_CarDetailStatusInfoSix,
    CAN_CarDetailStatusInfoSeven
}CAN_TYPE;

/*ocu端到底盘的控制消息内容-上层应用*/
//! 报文1
typedef struct _OcuToChassisParaOneTrans
{
    quint8 reserveOne;           /** 预留*/
    quint8 modeSwitch;           /** 操控模式切换 分为6种工况（具体工况待定）：
                                        * 00—停车
                                        * 02—遥控
                                        * 01—自主
                                        * 03—自主侦察
                                        * 04—预留
                                        */
    quint8 chassisSpeedLimit;   /*底盘限速设定，0~80，单位为km/h，低位在前，高位在后*/
    qint8  rockerHorizontal;    /*摇杆水平方向值：0~100（左转），0~-100（右转）*/
    qint8  rockerVertical;      /*摇杆垂直方向值：0~100（向前，油门开度），0~-100（向后，制动量）*/
    quint8 gear;                /** 驱动档位和负载档位(前进档和倒车档各3个，中心转向1个)
                                  * =0：空挡
                                  * =1：前进低档
                                  * =3：前进中档
                                  * =5：前进高档
                                  * =2：后退低档
                                  * =4：后退中档
                                  * =6：后退高档
                                  * =7：中心转向*/

    /*底盘控制*/
    quint8 batteryControl;      /*高压电池控制:强电上电（=1）,强电下电（=0）*/
    quint8 emergencyStopButton; /*紧急停车按钮:接通（=1）,断开（=0）*/
    quint8 parkingControl;	/*驻车控制:驻车（=1）,无驻车（=0）  底盘/输送模块功能切换；底盘（=0）默认发0，过渡托盘摇杆值不输出。输送模块（=1）*/
    quint8 manualExit;          /*Bit3：人工退出 有效（=1）;无效（=0）*/
    quint8 chassisEnableControl;/*底盘使能控制：底盘使能（=1），底盘不使能（=0）*/
    quint8 climbConditions;     /*Bit5：爬坡工况 有效（=1）; 无效（=0）*/
}OcuToChassisParaOneTrans;

//! 报文2
typedef struct _OcuToChassisParaTwoTrans
{
    /*设备控制+车辆工作模式切换*/
    quint8 autonomicComputerPowerUpControl; /*自主计算机上电状态 0：未上电；1：已上电*/
    quint8 LiDAR_PowerUpControl;    /*激光雷达上电状态 0：未上电；1：已上电*/
    quint8 verticalWallCondition;   /*Bit2：垂直墙工况；*/
    quint8 INS_PowerUpControl;      /*惯导/卫星定位装置上电状态 0：未上电；1：已上电*/
    quint8 chargerInterfacePowerUpControl; /*侦察系统上电 0：未上电；1：已上电  预留1*/
    quint8 carWorkModeSwitchControl;/*车辆工作模式 0：转矩 1：转速*/

    /*辅助控制*/
    quint8 highLampPowerUpControl;  /*前大灯上电状态 0：未上电；1：已上电*/
    quint8 alertLampPowerUpControl; /*双闪灯上电状态 0：未上电；1：已上电*/
    quint8 trumpetPowerUpControl;   /*喇叭上电状态 0：未上电；1：已上电*/
    quint8 receveCarInfoPowerUpControl; /*接收车辆底盘详细信息：开（=1），关（=0）*/

    quint8  dataDestroy;             /*数据销毁：0xaa*/

    /*电气管理系统控制*/
    quint8 faultResetControl;       /*故障复位控制:不复位（=0），复位所有故障（=1）*/
    quint8 guardMaskCommand;        /*保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/
}OcuToChassisParaTwoTrans;

/*********************************底盘上报到ocu的状态量*************************************************/
/*底盘上报到Ocu的车辆的主要信息的消息内容-上层应用*/
//! 报文1
typedef struct _CarMainStatusInfoOneTrans
{
    quint8  isParking;          /*是否驻车 1：驻车 0：无驻车*/
    quint8  gear;               /*当前档位 000：空档 001:前进低档 010:倒车低档 011:前进中档 100：倒车中档 101:前进高档 110：倒车高档111：中心转向*/
    quint8  emergencyStopState; /*紧急停车状态 0：非紧急停车状态 1：紧急停车中*/
    quint8  driveState;         /*当前驾驶模式 000：停车 001：自主 010：遥控 011：自主侦察（预留） 100：预留*/
    float  speed;               /*车速:-800.0~800.0 系数为0.1 回传的数据除以10即为真实速度。*/
    int    systemVoltage;       /*系统电压 0-250，offset=150 实际电压值150-400V*/
    quint8 batterySoc;          /*电池Soc 0-100（%） 低于10%时告警显示*/
    qint16 batteryCurrent;      /*电池电流 -600~600，(-250~250正常其他为故障，需报警）>0放电电流；<0，充电电流）*/
}CarMainStatusInfoOneTrans;


//! 报文2
typedef struct _CarMainStatusInfoTwoTrans
{
    quint8 investigationInfoOne;  /** 侦查信息1*/
    quint8 investigationInfoTwo;  /** 侦查信息2*/

    /*上电状态1*/
    quint8 highVoltagePowerUp;              /*高压上电状态 0：未上电；1：已上电*/
    quint8 V12boot;                         /*12V开机状态 0：未上电；1：已上电*/
    quint8 scoutSystemPowerUp;              /*侦察系统 0：未上电；1：已上电*/
    quint8 autonomicComputerPowerUp;        /*自主计算机上电状态 0：未上电；1：已上电*/
    quint8 LiDAR_PowerUp;                   /*激光雷达上电状态 0：未上电；1：已上电*/
    quint8 INS_PowerUp;                     /*惯导/卫星定位装置上电状态 0：未上电；1：已上电*/

    /*上电状态2+车辆工作模式*/
    quint8 highLampPowerUp;    /*前大灯上电状态 0：未上电；1：已上电*/
    quint8 alertLampPowerUp;   /*双闪灯上电状态 0：未上电；1：已上电*/
    quint8 trumpetPowerUp;     /*喇叭上电状态 0：未上电；1：已上电*/
    quint8 videoUnitPowerUp;   /*视频处理单元上电状态 0：未上电；1：已上电*/
    quint8 carWorkMode;        /*车辆工作模式 0：转速 1：转矩*/
    /*底盘状态等级*/
    quint8 underFrameLevel;     /** 底盘状态等级 0：系统正常
                                  * 1：1级故障（一般故障）
                                  * 2：2级故障（限速使用）
                                  * 3：3级故障（最为严重，自动停车并下高压电）*/
    /*底盘各部分状态等级*/
    quint8 CAN_State;          /* CAN总线通讯（含CAN1和CAN2的收发状态） 0：正常 1：异常*/
    quint8 BMS_State;          /* BMS高压电池 0：正常 1：异常*/
    quint8 scoutSystem;        /* 侦察分系统 0：正常 1：异常   侦察分系统*/
    quint8 brakeState;         /* 制动分系统 0：正常 1：异常*/
    quint8 motorState;         /* 驱动分系统 0：正常 1：异常*/
    quint8 netState;           /* Net网络通讯 0：正常 1：异常*/
    quint8 eletricalState;     /* Ele电气状态（含低压电压、电气盒和DCDC） 0：正常 1：异常*/
    quint8 highVoltageBatteryPower; /*高压电池电量不足警示*/
}CarMainStatusInfoTwoTrans;


/*底盘上报到Ocu的车辆详细信息的消息内容-上层应用*/
//! 报文1
typedef struct _CarDetailStatusInfoOneTrans
{
    qint8  directionControlValue; /*方向控制量反馈 0~100（左转）；0~-100（右转）*/
    qint8  throttleBrakeValue;    /* 油门制动控制量反馈向前0~100（油门开度） 向后0~-100（制动量）*/
    float  drivingDistance;       /* 车辆行驶里程 0~65000，系数0.1 实际值为0~6500.0km*/
    float  minimumSinglePressure; /*最低单体电压 28~45（显示值=该值/10）实际值3.0~4.2正常其他为故障，需报警）*/
    float  maximumSinglePressure; /*最高单体电压 28~45（显示值=该值/10）实际值3.0~4.2正常其他为故障，需报警）*/
    qint8  batteryTemperature;    /*电池温度 offset=-50, -20~60°为正常，其他需报警*/
}CarDetailStatusInfoOneTrans;


//! 报文2
typedef struct _CarDetailStatusInfoTwoTrans
{
    /*电池状态信息*/
    quint8 batteryGroupWorkMode;  /*电池组工作模式 0-正常工作；1-快速充电*/
    quint8 prechargeRelayState;   /*预充继电器状态 0-断开；1-吸合*/
    quint8 totalRelayState;       /*总正继电器状态 0-断开；1-吸合*/
    quint8 quickRelayState;       /*快充继电器状态 0-断开；1-吸合*/
    quint8 DC_RelayState;         /*DC继电器状态 0-断开；1-吸合*/
    quint8 heatingRelayState;     /*加热继电器状态 0-断开；1-吸合*/
    quint8 prechargeState;        /*预充状态 0-正常；1-失败*/

    /*电池告警信息*/
    quint8 totalVoltageOverCharge; /*总电压过充 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 totalVoltageOverDischarge; /*总电压过放 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 singleVoltageOverCharge; /*单体电压过充 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 singleVoltageOverDischarge; /*单体电压过放 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 maximumTemperatureOverTop; /*最高温度过高 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 minimumTemperatureOverDown; /*最低温度过低 0-正常；1-1级报警；2-2级报警；3-3级报警*/
}CarDetailStatusInfoTwoTrans;


//! 报文3
typedef struct _CarDetailStatusInfoThreeTrans
{
    /*电机状态——转速信息*/
    int leftElectricRpm;     /*左电机转速 低字节在前，高字节在后 单位rpm  offset=-15000*/
    int rightElectricRpm;    /*右电机转速 低字节在前，高字节在后 单位rpm  offset=-15000*/

    /*电机状态——左电流信息*/
    int leftMotorCurrent;   /*左电机电流 offset=-1000 */
}CarDetailStatusInfoThreeTrans;


//! 报文4
typedef struct _CarDetailStatusInfoFourTrans
{
    int rightMotorCurrent; /*右电机电流 offset=-1000 */

    /*左电机状态——告警信息*/
    quint8 L_electricOverTemp;       /*绕组过温错误 1：真；0：假*/
    quint8 L_DCSToltageOverLow;      /*绕组过温警告 1：真；0：假*/
    quint8 L_CANTimeout;             /*CAN超时 1：真；0：假*/
    quint8 L_electricSpeedOutRange;  /*电机速度超限 1：真；0：假*/
    quint8 L_DC_CurrentOvercurrent;  /*直流电流过流 1：真；0：假*/
    quint8 L_DC_VoltageOvervoltage;  /*直流电压过压 1：真；0：假*/
    quint8 L_rotationalFault;        /*旋变错误 1：真；0：假*/
    quint8 L_windTemSensorFault;     /*绕组温度传感器错误 1：真；0：假*/

    /*右电机状态——告警信息*/
    quint8 R_electricOverTemp;       /*绕组过温错误 1：真；0：假*/
    quint8 R_DCSToltageOverLow;      /*绕组过温警告 1：真；0：假*/
    quint8 R_CANTimeout;             /*CAN超时 1：真；0：假*/
    quint8 R_electricSpeedOutRange;  /*电机速度超限 1：真；0：假*/
    quint8 R_DC_CurrentOvercurrent;  /*直流电流过流 1：真；0：假*/
    quint8 R_DC_VoltageOvervoltage;  /*直流电压过压 1：真；0：假*/
    quint8 R_rotationalFault;        /*旋变错误 1：真；0：假*/
    quint8 R_windTemSensorFault;     /*绕组温度传感器错误 1：真；0：假*/

    int   generatorControlerTemperature;/*电机控制器温度（多个电机控制器的最高温度）  范围0~250，offset=-40*/

    int   generatorTemperature;      /*电机温度（多个电机的最高温度） 范围0~250，offset=-40*/
    quint8 brakeFeedback;            /*制动量反馈 0~100*/
}CarDetailStatusInfoFourTrans;


//! 报文5
typedef struct _CarDetailStatusInfoFiveTrans
{
    float accumulatorPressure;      /*蓄能器压力 范围0~200，factor=0.1，单位MPa,当实际压力值小于0.5或大于14应告警显示*/
    float brakePressure;            /*制动压力 范围0~200，factor=0.1，单位MPa*/
    quint8 accumulatorSensor;       /*Bit4：蓄能器传感器 0：正常，1：故障*/
    quint8 brakeSensor;             /*Bit5：制动传感器   0：正常，1：故障*/
    float DCDC_InputVoltage;        /*DCDC输入电压 系数0.1*/
    float DCDC_OutputVoltage;       /*DCDC输出电压 0-34V，系数0.01*/
}CarDetailStatusInfoFiveTrans;


//! 报文6
typedef struct _CarDetailStatusInfoSixTrans
{
    float DCDC_OutputCurrent;       /*DCDC输出电流 范围0~220，系数0.1，单位A*/
    /*驱动、电机状态—告警信息3（左）*/
    quint8 L_inverterOverTemError;/*bit0：逆变器过温错误，*/
    quint8 L_IPME_error;          /*bit1：IPME错误  */
    quint8 L_undervoltageError;   /*bit2：欠压错误  */
    quint8 L_24VUndervoltageError;/*bit3：24V欠压错误 */
    quint8 L_inverterOverTemWarn; /*bit4：逆变器过温警告 */
    quint8 L_undervoltageWarn;    /*bit5：欠压警告    */
    quint8 L_overvoltageWarn;     /*bit6：过压警告    */

    /*驱动、电机状态—告警信息3（右）*/
    quint8 R_inverterOverTemError;/*bit0：逆变器过温错误，*/
    quint8 R_IPME_error;          /*bit1：IPME错误  */
    quint8 R_undervoltageError;   /*bit2：欠压错误，   */
    quint8 R_24VUndervoltageError;/*bit3：24V欠压错误 */
    quint8 R_inverterOverTemWarn; /*bit4：逆变器过温警告 */
    quint8 R_undervoltageWarn;    /*bit5：欠压警告    */
    quint8 R_overvoltageWarn;     /*bit6：过压警告    */
}CarDetailStatusInfoSixTrans;


//! 报文7
typedef struct _CarDetailStatusInfoSevenTrans
{
}CarDetailStatusInfoSevenTrans;


/*topic界面关联*/
typedef  struct _StatusBarInfo{
    qint8  driveState;         /* 当前驾驶状态 0：待机 1：自主路径跟踪模式 2：远程遥控 3：自主目标跟踪模式 4：暂停 5：值守 6：近程遥控 7：自主返航中*/
    qint8  emergencyStopState; /*紧急停车状态 0：非紧急停车状态 1：紧急停车中*/

    int    hybridPowerReaction;/*混合动力模块*/
    qint8  isParking;          /*是否驻车 1：驻车 0：无驻车*/
    qint8  gear;               /*当前档位 0：空挡 1：前进低档 2：倒车低档 3：前进中档 4：倒车中档 5：前进高档 6：倒车高档*/
    quint8 powerModulePowerUp; /*动力模块上电状态 0：未上电；1：已上电*/
    float  speed;         /*剩余油量0~20L*/

    int    systemVoltage;      /*系统电压*/
    float  batterySoc;         /*电池soc: 0-100*/
    int    batteryCurrent;     /*电池电流 -600~600，(-250~250正常其他为故障，需报警）>0放电电流；<0，充电电流）*/
    int    generatorCurrent;   /*发电机电流 100~100A*/
    int    controlAuthority;   /*控制权*/
    
    OperationMode  computerBackOprationMode;    /*自主计算机反馈的操控模式*/
}StatusBarInfo;


typedef  struct ElectricalState{  
    quint8 highVoltagePowerUp;          /*高压上电状态 0：未上电；1：已上电*/
    qint8  isParking;                   /*是否驻车 1：驻车 0：无驻车*/
    qint8  emergencyStopState;          /*紧急停车状态 0：非紧急停车状态 1：紧急停车中*/
    quint8 autonomicComputerPowerUp;    /*自主计算机上电状态 0：未上电；1：已上电*/
    quint8 LiDAR_PowerUp;               /*激光雷达上电状态 0：未上电；1：已上电*/
    quint8 carWorkMode;                 /*车辆工作模式 0：转速 1：转矩*/
    quint8 INS_PowerUp;                 /*惯导/卫星定位装置上电状态 0：未上电；1：已上电*/
    quint8 scoutSystemPowerUp;          /*侦察系统 0：未上电；1：已上电*/
    quint8 V12boot;                     /*12V开机状态 0：未上电；1：已上电*/
    quint8 videoUnitPowerUp;            /*视频处理单元上电状态 0：未上电；1：已上电*/

    //No
    qint8  gear;                 /*当前档位 0：空挡 1：前进低档 2：倒车低档 3：前进中档 4：倒车中档 5：前进高档 6：倒车高档*/
    /*上电状态1*/
    quint8 actuatorPowerUp;      /*驱动器上电状态 0：未上电；1：已上电*/
    quint8 investigationEquipmnetPowerUp;   /*搭载模块上电状态 0：未上电；1：已上电*/
    quint8 weaponsSystemPowerUp; /*武器系统上电状态 0：未上电；1：已上电*/
    quint8 singleColorCameraPowerUp; /*单目彩色相机上电状态 0：未上电；1：已上电*/
    /*上电状态2+车辆工作模式*/
    quint8 megaphonePowerUp;         /*扩音器上电状态 0：未上电；1：已上电*/
    quint8 chargerInterfacePowerUp;  /*单兵充电接口上电状态 0：未上电；1：已上电*/
}ElectricalState;


/*******************************车辆状态故障和告警信息显示*****************************************/
/*告警信息*/
typedef  struct _WaringDetailInfo{
    int    systemVoltage;             /*系统电压，当低于250或者高于380时告警显示*/
    float  batterySoc;                /*电池soc: 0-100，低于10%时告警显示*/
    int    batteryCurrent;            /*电池电流 -600~600，(-250~250正常其他为故障，需报警）>0放电电流；<0，充电电流）*/
    float  minimumSinglePressure;     /*最低单体总压 3.0~4.2正常其他为故障，需报警*/
    float  maximumSinglePressure;     /*最高单体总压 3.0~4.2正常其他为故障，需报警*/
    quint8 batteryTemperature;        /*电池温度 -20~60°为正常，其他需报警*/
    quint8 totalVoltageOverCharge;    /*总电压过充 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 totalVoltageOverDischarge; /*总电压过放 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 singleVoltageOverCharge;   /*单体电压过充 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 singleVoltageOverDischarge;/*单体电压过放 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 maximumTemperatureOverTop; /*最高温度过高 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    quint8 minimumTemperatureOverDown;/*最低温度过低 0-正常；1-1级报警；2-2级报警；3-3级报警*/
    int    engineWaterTemperature;    /*发动机水温 -50~200℃ 高于100℃时告警显示*/
    int    generatorControlerTemperature; /*发电机控制器温度 -50~200℃ 高于100℃时告警显示*/
    int    generatorTemperature;      /*发电机温度 -50~200℃ 高于100℃时告警显示*/
    int    generatorDC_voltage;       /*发电机直流侧电压 0~500V，大于400V时告警显示*/
    float accumulatorPressure;        /*蓄能器压力 0~20 单位MPa 当实际压力值小于0.5或大于14应告警显示*/
    int   electricControlerTemperature; /*电机控制器温度 -50~90℃为正常，其他需告警显示*/
    int   electricTemperature;         /*电机温度 -50~150℃为正常，其他需告警显示*/
    float DCDC_OutputVoltage;          /*DCDC输出电压 0~50V，低于20V或高于30V时告警显示*/
    float DCDC_OutputCurrent;          /*DCDC输出电流 范围0~250，单位A 当大于200A时告警显示*/
}WaringDetailInfo;


/*********************自主计算机回传给ocu的平台位置和姿态信息通信结构体**************************/
/*自主计算机回传给ocu的平台位置和姿态信息消息*/
typedef struct _ComputerToOcuStateInfoTrans
{
    int       pitch;                             /*俯仰角：角度：-90~90；精度1度；采用四舍五入*/
    int       roll;                              /*侧倾角：角度：-90~90；精度1度；采用四舍五入*/
    int       yaw;                               /*航向角：数据范围：0~360；精度1度；采用四舍五入（和正北方向的夹角，顺时针方向）*/
    double    longtitude;                        /*当前位置的精度乘以10000000传送，精度到0.0000001，如经度116.123456表示为 116123456回传，低字节在前，高字节在后*/
    double    latitude;                          /*当前位置的精度乘以10000000传送，精度到0.0000001*/
    int       trackingDeviation;                 /*保留*/

    /*决策控制系统状态  1-成功；0-失败*/
    quint8    HMIModuleStatus;                   /*远程操控模块状态（预留）*/
    quint8    LIDARDataCollectionModuleStatus;   /*激光雷达数据采集模块状态*/
    quint8    LIDARDataModelingModuleStatus;     /*激光雷达数据建模模块状态（预留）*/
    quint8    inertialDataCollectionModuleStatus;/*惯导数据采集模块状态*/
    quint8    trackRecordModuleStatus;           /*运行轨迹记录模块状态（预留）*/
    quint8    pathPlanningModuleStatus;          /*路径规划模块状态（预留）*/
    quint8    trackControlModuleStatus;          /*跟踪控制模块状态（预留）*/
    quint8    chassisControlModuleStatus;        /*底盘控制模块状态（预留）*/
    quint8    pathPlanningResults;               /*路径规划结果（预留）*/

    float     realTimeSpeed;                     /*实时速度*/
    int       heartBeatCount;                    /*心跳计数：从0开始累加到0Xff*/
}ComputerToOcuStateInfoTrans;


/********************************OCU端与自主计算机通信结构体*************************************/
typedef  enum
{
    POINT_NO_INSPECTION = 0,    /*不巡检*/
    POINT_SCAN_LEFT_RIGHT,      /*左右扫描*/
    POINT_WEEKLY_SCAN,          /*周视扫描*/
    POINT_PARK_WAIT,            /*停车等待*/
    POINT_Vision_SCAN           /*远景扫描*/
}PointAttributes;


/*位置信息结构体*/
typedef struct _strPose
{
    double longtitude;          /** 经度*/
    double latitude;            /** 纬度*/
    float  targetSpeed;         /** 速度*/
    qint8  obstacleAvoidFlag;   /** 是否避障*/
    qint8  inspectionPointFlag; /** 0x0: 不巡检
                                    0x1: 左右扫描
                                    0x2: 周视扫描
                                    0x3: 停车等待
                                    0x4: 远景扫描*/
    qint8  externFlagOne;
    qint32 externFlagTwo;       /** 停车时长，单位为秒  在0x3:停车等待时有效*/
    qint32 externFlagThree;
}strPose;


/*ocu到自主计算机的心跳帧消息*/
typedef struct _OcuToComputerHeartBeatParaTransTopic
{
    int    heartBeatCount;     /*心跳计数：从0开始累加到0Xffff*/
    OperationMode  oprationMode;/*操作模式:
                                0x1：路点记录（只记录路点，用于地图上显示轨迹，不进行下发）
                                0x2：路径跟踪行驶
                                0x3：一键返航
                                0x4：人员低速跟随（低速对应：引导员不超过3km/h前进速度
                                0x5：人员绕桩跟随
                                0x6：人员目标远距离探测（对应静态：人员跟随最大距离测试)
                                0x7：车辆目标跟随
                                0x8：暂停
                                0x9：恢复自动驾驶功能
                                0xA：停止自动驾驶功能
                                0xB：语音引导跟随
                                0xC：手势引导跟随*/
    SubOprationMode  subOperationMode;
}OcuToComputerHeartBeatParaTransTopic;


/*ocu端到自主计算机的然任务帧消息*/
typedef struct _OcuToComputerTaskParaTransTopic
{
    qint16    targetNum; /*任务号：从1开始累加到0Xffff*/
    qint16    pointCount;/*路径点数*/
    float       speedMax;  /*最大速度：-100~100单位m/s,系数0.1，精确度到0.1m/s,实际10m/s时需下发值=100*/
    QVector<strPose>   pathPoint;/*规划航迹点*/
    qint32    reserveByte;  /*预留位*/
    qint16    frameSeriNum; /*分帧序号*/
    qint16    flagMsiion;   /*发送任务标记*/
}OcuToComputerTaskParaTransTopic;


typedef struct  _OcuToComputerInertialAligCommandTrans
{
    qint8    aligmentCommand;/*Bit0:
                                =1，自检
                                =0，停止*/
    qint8    imageOpen;     /*Bit1:
                                =1，开始发送图像
                                =0，停止发送图像*/

}OcuToComputerInertialAligCommandTrans;



/*自主计算机上报到ocu的心跳帧消息报头*/
typedef struct _ComputerToOcuHeartBeatInfoTransTopic
{
    OperationMode  oprationMode;/*操作模式:
                                0x1：路点记录（只记录路点，用于地图上显示轨迹，不进行下发）
                                0x2：路径跟踪行驶
                                0x3：一键返航
                                0x4：人员低速跟随（低速对应：引导员不超过3km/h前进速度
                                0x5：人员绕桩跟随
                                0x6：人员目标远距离探测（对应静态：人员跟随最大距离测试)
                                0x7：车辆目标跟随
                                0x8：暂停
                                0x9：恢复自动驾驶功能
                                0xA：停止自动驾驶功能
                                0xB：语音引导跟随
                                0xC：手势引导跟随*/
    SubOprationMode  subOperationMode;
    int heartBeatCount;/*心跳计数：从0开始累加到0Xffff*/
    uint64_t time;/*时间：单位毫秒，当前系统时间从1970-1-1开始*/
}ComputerToOcuHeartBeatInfoTransTopic;


/*自主计算机上报到ocu的任务帧消息内容*/
typedef struct _ComputerToOcuTaskInfoTransTopic
{
    quint16 taskSeriNum;      /** 接收到的任务编号 **/
}ComputerToOcuTaskInfoTransTopic;


/*进入自主模式控制量*/
typedef struct _IntoSelfDrivingModeControl
{
    bool   intoSelfDrivingMode;
    OperationMode  enumOperationMode;
}IntoSelfDrivingModeControl;


/*进入自主模式控制量*/
typedef struct _OcuToComputerTaskControlTransTopic
{
    qint16         taskConunter;/*任务计数*/
    float          maxSpeed;
    OperationMode  enumOperationMode;
}OcuToComputerTaskControlTransTopic;


/*自主计算机到远程操控系统的图像*/
typedef struct _OcuToComputerImageTrans{
    quint16   imageLength;          /** 图像长为固定值H=0x0145 (325)*/
    quint16   imageWidth;           /** 图像宽度为固定值W=0x0096 (150)*/
    QByteArray imageValue;          /** 图像值0x00-0xff*/
}OcuToComputerImageTrans;


/********************************路径点管理结构体*************************************/
/*路径跟踪任务管理*/
typedef  struct _PathFollowTask{
     PathFollowTaskType taskType;
     QString            taskName;
     int                taskNum;
     int                pathPointNum;
     double             speedMax;
     QVector<strPose>   pathPoint;
}PathFollowTask;


/*路径点修改*/
typedef  struct _PathPointModification{
     QString   taskName;           /*任务号*/
     int       pointSerialNum;     /*点序号*/
     strPose   pointValue;         /*路径点值*/
}PathPointModification;





/********************************网络配置结构体*************************************/
/*待确认各车型配置信息后，分别定义对应结构体信息*/
/*网络配置参数*/
typedef struct  _NetWorkConfig{
    QString  carType;               /*车辆类型：F1轻型轮式无人平台，F2便携式无人平台，F3小履带式无人平台*/
    int      carID;                 /*车辆编号：1起始*/
    QString  localIP;               /*本地Ip*/
    QString  localVideoIP;          /*操控端本地视频处理板ip*/
    int      toChassisPort;         /*对底盘端口*/
    int      toCommamdControlPort;  /*对指控端口*/
    int      toComputerPort;        /*对自主计算机端口*/
    int      toVideoPort;           /*对视频处理板端口*/
    int      toRadioPort;           /*对电台端口*/
    int      toPortablePort;        /*对便携端端口*/

    QString  commandControlIp;      /*指控IP*/
    int      commandControlPort;    /*指控端口*/
    QString  chassisIp;             /*底盘IP*/
    int      chassisPort;           /*底盘端口*/
    QString  computerIp;            /*自主计算机IP*/
    int      computerPort;          /*自主计算机端口*/
    QString  videoIp;               /*视频处理板ip*/
    int      videoPort;             /*视频处理板端口*/
    QString  radioIp;               /*电台IP*/
    int      radioPort;             /*电台端口*/
    QString  portableIp;            /*便携车辆IP*/
    int      portablePort;          /*便携车辆端口*/
}NetWorkConfig;


/*******************************plotting manager  struct*******************************/
typedef struct  _PlottingManager{
    int              iPlottingManagerIndex;
    PlotType         enumPlotType;
    int              pointsNum;
    QList<QPointF>   points;
    QColor           color;
    int              iLineWidth;
    bool             isShowState;
    bool             isEditState;
    int              extentOne;
    int              extentTwo;
    double           extentThree;        /*面积测量时为面积结果；距离测量时为距离结果*/
    double           extentFour;
}PlottingManager;


typedef struct  _PlottingPointValueChanged{
    PlotPointChangedType    changedType;
    int                     pointSerialNum;
    strPose                 point;
}PlottingPointValueChanged;


/*******************************car link manager struct*******************************/
typedef struct  _CarLinkManager{
    bool     linkState;
    NetWorkConfig     netPara;
}CarLinkManager;


/******************************* coordination task struct*******************************/
typedef struct  _CoordinationTask{
    int       taskNum;
    qint16    pointCount;/*路径点数*/
    float     speedMax;  /*最大速度：-100~100单位m/s,系数0.1，精确度到0.1m/s,实际10m/s时需下发值=100*/
    QVector<strPose>   pathPoint;/*规划航迹点*/
    QDateTime reciveTime;
}CoordinationTask;



/*******************************软件运行日志****************************************/
/*软件运行日志*/
typedef struct _AppRunRecordingData{
    QDateTime      recordingTime;                          /*记录时间*/
    QString        infoText;                          /*记录文本*/
}AppRunRecordingData;


/*任务日志*/
typedef struct _ReceiveTaskLogData{
    QString            taskFileName;                  /*任务文件名称*/
    QDateTime      receiveTime;                       /*接收时间*/
    QString            TaskReading;                   /*任务阅读情况*/
    QString            TaskCompletion;                /* 任务完成情况*/
}ReceiveTaskLogData;


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


/*系统操作日志*/
typedef struct _SystemOperationData{
    QDateTime       operationTime;                     /*操作时间*/
    QString         devicePowerHistory;                /*设备上电/断电记录*/
    QString         inertialNavigationRecord;          /*惯导操作记录*/
}SystemOperationData;


/*车辆状态日志**/
typedef struct _VehicleStatusData{
    QDateTime         recordTime;                     /*记录时间*/
    QString           equipmentRunningStatus;         /*设备运行状态*/
    QString           warningInfo;                    /*异常告警信息*/
}VehicleStatusData;


/*数据查询接口*/
enum DataQueryMode {
    DATAQUERY_STARTEDTIME = 0,                          /*根据起始时间查询*/
    DATAQUERY_FINISHEDTIME,                             /*根据结束时间查询*/
};

/*******************************驾驶模式管理****************************************/
typedef struct _DrivingModeManager{
    OperationMode  operationMode;
    SubOprationMode  subOperationMode;
}DrivingModeManager;


/** ******************************OCU与火控操控软件通信结构体********************************/
/**
 *  火控目标识别信息上报
 */
typedef struct _FireControlSituationReportTrans
{
    float  targetDistance;                 /** 目标距离*/
    double targetLongtitude;               /** 目标经度*/
    double targetLatitude;                 /** 目标纬度*/
    float  targetAltitude;                 /** 目标高度*/
}FireControlSituationReportTrans;


typedef struct _MapPlottingAttribute{
    int             iSerinum;
    int             iLineWidth;
    QColor          color;
    QPointF         pointValue;
    PointAttributes pointAttributes;
//    TargetIdentifiedType    targetType;
//    WayPointAttribute    wayPointAttribute;
//    WaySectionAttribute  waySectionAttribute;
}MapPlottingAttribute;


typedef struct _MapPlottingParaManager{
    int     iTaskId;
    QMap<int,MapPlottingAttribute>  mapPlottingAttribute;
}MapPlottingParaManager;


typedef  struct   _AddPointFromMapControl{
     bool   control;
     int    taskNum;
}AddPointFromMapControl;


/**
  * 轴操纵杆 RS232 通信协议
  */
typedef struct _AxisJoystickTrans
{
    qint8       horizontal;
    qint8       vertical;
    quint8      btnRed;         /*红色按钮*/
    quint8      btnGreen;       /*绿色按钮*/
    quint8      btnTop;         /*操控杆右边的上面按钮*/
    quint8      btnBelow;       /*操控杆右边的下面按钮*/
    quint8      btn5;           /*无此按钮*/
    quint8      btn6;           /*外部按钮 2 */  /*无此按钮*/
    quint8      btnBehind;      /*操控杆后面的按钮*/
    quint8      btn8;           /*外部按钮 1*/   /*无此按钮*/
}AxisJoystickTrans;


/************************************************OCU端与视频端通信结构体*****************************************************/
//! *********************************ocu--->视频处理端*******************************

typedef enum
{
    VIDEO_MSGNUM_None = -1,
    VIDEO_MSGNUM_Open = 0,
    VIDEO_MSGNUM_Stop,
    VIDEO_MSGNUM_SetParameter,
    VIDEO_MSGNUM_GetParameter,
    VIDEO_MSGNUM_SetShowMode,
    VIDEO_MSGNUM_GetShowMode
}VIDEO_MSGNUM;
//! 打开音视频编码 MSGID(参数 ID)：0x12
typedef struct _VideoOpenTrans
{
    quint32  payLoad;    //! 填0即可
}VideoOpenTrans;

//! 停止音视频编码 MSGID(参数 ID)：0x14
typedef struct _VideoStopTrans
{
    quint32   payLoad;    //! 填0即可
}VideoStopTrans;

typedef struct _VideoInfoTrans
{
    quint8   ID;         //! 通道号 0
    quint8   FPS;        //! 帧率 默认 30帧
    quint16  Width;      //! 视频宽度 1920
    quint16  Height;     //! 视频高度 1080
    quint16  Bitrate;    //! 码率 (单位 kbps) 默认 3600
    quint16  Gop;        //! I帧间隔(GOP) 30(默认)
    quint16  Reserve;    //! 保留，默认填0 0
}VideoInfoTrans;

//! 设置视频编码码率  MSGID(参数 ID)：0x30
typedef struct _VideoSetParameterTrans
{
    VideoInfoTrans          videoInfo;
}VideoSetParameterTrans;

//! 获取视频编码参数  MSGID(参数 ID)：0x32
typedef struct _VideoGetParameterTrans
{
}VideoGetParameterTrans;

//! 设置视频显示(拼接)模式  MSGID(参数 ID)：0x20
typedef struct _VideoSetShowModeTrans
{
    quint32   mode;   //! 01H = 单路1; 02H = 单路2; 03H = 画中画模式1; 04H = 画中画模式2
}VideoSetShowModeTrans;

//! 获取视频显示(拼接)模式   MSGID(参数 ID)：0x22
typedef struct _VideoGetShowModeTrans
{
}VideoGetShowModeTrans;

//! *********************************视频处理端---->ocu*******************************
//! 打开音视频编码响应消息 MSGID(参数 ID)：0x13
typedef struct _VideoOpenResponseTrans
{
    quint32  payLoad;    //! 0：成功; 非0：失败
}VideoOpenResponseTrans;


//! 停止音视频编码响应消息  MSGID(参数 ID)：0x15
typedef struct _VideoStopResponseTrans
{
    quint32  payLoad;    //! 0：成功; 非0：失败
}VideoStopResponseTrans;


//! 设置视频参数响应消息  MSGID(参数 ID)：0x31
typedef struct _VideoSetParameterResponseTrans
{
    quint32   payLoad;    //! 0：成功; 非0：失败
}VideoSetParameterResponseTrans;


//! 获取视频编码参数响应消息   MSGID(参数 ID)：0x33
typedef struct _VideoGetParameterResponseTrans
{
    VideoInfoTrans   videoInfo;
}VideoGetParameterResponseTrans;


//! 设置视频显示(拼接)模式响应消息   MSGID(参数 ID)：0x21
typedef struct _VideoSetShowModeResponseTrans
{
    quint32  mode;   //! 0：成功; 非0：失败
}VideoSetShowModeResponseTrans;


//! 获取视频显示(拼接)模式响应消息   MSGID(参数 ID)：0x23
typedef struct _VideoGetShowModeResponseTrans
{
    quint32  mode;   //! 01H = 单路1; 02H = 单路2; 03H = 画中画模式1; 04H = 画中画模式2
}VideoGetShowModeResponseTrans;


}

Q_DECLARE_METATYPE(Djxlc::CarMainStatusInfoOneTrans)
Q_DECLARE_METATYPE(Djxlc::CarMainStatusInfoTwoTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoOneTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoTwoTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoThreeTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoFourTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoFiveTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoSixTrans)
Q_DECLARE_METATYPE(Djxlc::CarDetailStatusInfoSevenTrans)
Q_DECLARE_METATYPE(Djxlc::ElectricalState)
Q_DECLARE_METATYPE(Djxlc::StatusBarInfo)
Q_DECLARE_METATYPE(Djxlc::WaringDetailInfo)
Q_DECLARE_METATYPE(Djxlc::ComputerToOcuStateInfoTrans)
Q_DECLARE_METATYPE(Djxlc::PointAttributes)
Q_DECLARE_METATYPE(Djxlc::strPose)
Q_DECLARE_METATYPE(Djxlc::OcuToComputerHeartBeatParaTransTopic)
Q_DECLARE_METATYPE(Djxlc::OcuToComputerTaskParaTransTopic)
Q_DECLARE_METATYPE(Djxlc::OcuToComputerInertialAligCommandTrans)
Q_DECLARE_METATYPE(Djxlc::ComputerToOcuHeartBeatInfoTransTopic)
Q_DECLARE_METATYPE(Djxlc::ComputerToOcuTaskInfoTransTopic)
Q_DECLARE_METATYPE(Djxlc::IntoSelfDrivingModeControl)
Q_DECLARE_METATYPE(Djxlc::OcuToComputerTaskControlTransTopic)
Q_DECLARE_METATYPE(Djxlc::OcuToComputerImageTrans)
Q_DECLARE_METATYPE(Djxlc::PathFollowTask)
Q_DECLARE_METATYPE(Djxlc::PathPointModification)
Q_DECLARE_METATYPE(Djxlc::NetWorkConfig)
Q_DECLARE_METATYPE(Djxlc::PlottingManager)
Q_DECLARE_METATYPE(Djxlc::PlottingPointValueChanged)
Q_DECLARE_METATYPE(Djxlc::CarLinkManager)
Q_DECLARE_METATYPE(Djxlc::CoordinationTask)
Q_DECLARE_METATYPE(Djxlc::AppRunRecordingData)
Q_DECLARE_METATYPE(Djxlc::ReceiveTaskLogData)
Q_DECLARE_METATYPE(Djxlc::RemoteDrivingData)
Q_DECLARE_METATYPE(Djxlc::AutoDrivingData)
Q_DECLARE_METATYPE(Djxlc::SystemOperationData)
Q_DECLARE_METATYPE(Djxlc::VehicleStatusData)
Q_DECLARE_METATYPE(Djxlc::DrivingModeManager)
Q_DECLARE_METATYPE(Djxlc::FireControlSituationReportTrans)
Q_DECLARE_METATYPE(Djxlc::MapPlottingAttribute)
Q_DECLARE_METATYPE(Djxlc::MapPlottingParaManager)
Q_DECLARE_METATYPE(Djxlc::AddPointFromMapControl)
Q_DECLARE_METATYPE(Djxlc::AxisJoystickTrans)
Q_DECLARE_METATYPE(Djxlc::VideoOpenResponseTrans)
Q_DECLARE_METATYPE(Djxlc::VideoStopResponseTrans)
Q_DECLARE_METATYPE(Djxlc::VideoSetParameterResponseTrans)
Q_DECLARE_METATYPE(Djxlc::VideoGetParameterResponseTrans)
Q_DECLARE_METATYPE(Djxlc::VideoSetShowModeResponseTrans)
Q_DECLARE_METATYPE(Djxlc::VideoGetShowModeResponseTrans)
