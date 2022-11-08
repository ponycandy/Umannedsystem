#pragma once
#include <stdint.h>
#include <QVector>

namespace Djxlc {




#pragma pack(1)

/** **************************OCU端与底盘通信结构体********************************/
/**
 * ocu端到底盘的消息报头
 */
typedef struct _OcuToChassisFrameHead
{
    quint32     head;                   /** 帧头            为固定值0x43544550（小端字节序）*/
    quint32     num;                    /** 帧序号           从0开始每帧递增（小端字节序）*/
    quint32     CAN_gatewaySerialNum;   /** 网关CAN接口序号   0（小端字节序）*/
    quint32     CAN_msgID;              /** CAN报文ID        根据具体icd而定（小端字节序）*/
    quint8      CAN_msgIDE;             /** CAN报文IDE位	    0 */
    quint8      reserve;                /** 预留             0 */
    quint8      CAN_msgRTR;             /** CAN报文RTR位     0 */
    quint8      CAN_msgDLC;             /** CAN报文DLC	    8 */
}OcuToChassisFrameHead;

/**
  * ocu与底盘交互的消息尾
  */
typedef struct _OcuToChassisEnd
{
    quint8      heartNum;        /** 心跳  从0递增 */
}OcuToChassisEnd;

/** ocu端到底盘的控制消息内容，
 * 发送周期：每50ms发送2种报文
 */
//! 报文1
typedef struct _OcuToChassisParaOne
{
    OcuToChassisFrameHead   frameHead;
    quint8 reserveOne;                /** 预留*/
    quint8 modeSwitch;                /** 操控模式切换 分为6种工况（具体工况待定）：
                                        * 00—停车
                                        * 02—遥控
                                        * 01—自主
                                        * 03—自主侦察（预留）
                                        * 04—预留
                                        */
    quint8 chassisSpeedLimit;         /** 底盘限速设定，0~80，单位为km/h，低位在前，高位在后*/
    qint8  rockerHorizontal;          /** 摇杆水平方向值：0~100（左转），0~-100（右转）*/
    qint8  rockerVertical;            /** 摇杆垂直方向值：0~100（向前，油门开度），0~-100（向后，制动量）*/
    quint8 gear;                      /** 驱动档位和负载档位(前进档和倒车档各3个，中心转向1个)
                                        * =0：空挡
                                        * =1：前进低档（26km/h）
                                        * =3：前进中档（52km/h）
                                        * =5：前进高档（80km/h）
                                        * =2：后退低档
                                        * =4：后退中档
                                        * =6：后退高档
                                        * =7：中心转向*/
    quint8 chassisControl;            /** 底盘控制：
                                        * Bit0：高压电池控制; 强电上电（=1） 强电下电（=0）；
                                        * Bit1：紧急停车按钮; 接通（=1） 断开（=0）；
                                        * Bit2：驻车控制; 驻车（=1） 无驻车（=0）
                                        * Bit3：人工退出 有效（=1）;无效（=0）
                                        * Bit4：底盘使能（=1）底盘不使能（=0）
                                        * Bit5：爬坡工况 有效（=1）; 无效（=0）
                                       **/

    OcuToChassisEnd  end;
}OcuToChassisParaOne;

//! 报文2
typedef struct _OcuToChassisParaTwo
{
    OcuToChassisFrameHead   frameHead;
    quint8 equipmentControl;          /** 设备控制+车辆工作模式切换：
                                       * bit0:自主计算机上电控制:上电（=1）,下电（=0）；
                                       * bit1:激光雷达:上电（=）,下点（=0）；
                                       * Bit2：垂直墙工况；；
                                       * bit3:惯导/卫星定位装置上电控制：上电（=1），下电（=0）
                                       * bit4:预留；
                                       * bit5:侦察系统上电：上电（=1），下电（=0）
                                       * bit6:预留；
                                       * bit7:车辆工作模式切换：0：转矩 1：转速
                                       **/

    quint8 subcontrol;                /** 辅助控制：
                                       * bit0:前大灯：点亮（=1），关闭（=0）
                                       * bit2:双闪灯：开（=1），关闭（=0）
                                       * bit3:喇叭：开（=1），关闭（=0）
                                       * bit4:接受车辆底盘详细信息：接收（=1），不接收（默认）（=0）
                                       **/

    quint8 dataDestroy;                /** 数据销毁（预留）：0xaa*/
    quint8 electricalManagementControl;/** 电气系统管理控制，对应底盘协议0x202：
                                        * bit0:故障复位控制：不复位（=0），复位所有故障（=1）
                                        * bit1:保护屏蔽命令：不屏蔽保护（=0），屏蔽所有保护（=1）
                                        **/
    quint8 reserve1;                   /** 预留*/
    quint8 reserve2;                   /** 预留*/
    quint8 reserve3;                   /** 预留*/
    OcuToChassisEnd  end;
}OcuToChassisParaTwo;


//!

/** 底盘上报到Ocu的车辆主要信息的消息内容,
 * 车辆主要状态信息
 * 此帧数据操控员需时刻关注，尽可能显示在主屏显示
 * 发送周期：发送周期：每200ms发送2种报文
 */
//! 报文1
typedef struct _CarMainStatusInfoOne
{
    OcuToChassisFrameHead   frameHead;
    quint8  platformMoblieState;        /** 平台机动状态：
                                         * Bit0：是否驻车 驻车（=1）;无驻车（=0）；
                                         * Bit3~ Bit1：当前档位 000：空档 001:前进低档 010:倒车低档 011:前进中档 100：倒车中档 101:前进高档 110：倒车高档111：中心转向
                                         * Bit4:紧急停车状态 1：紧急停车中 0：非紧急停车状态
                                         * Bit7~ Bit5：当前驾驶模式 000：停车 001：自主 010：遥控 011：自主侦察（预留） 100：预留
                                         */
    qint16 speed;                       /** 车速:-800.0~800.0 系数为0.1 回传的数据除以10即为真实速度。*/
    quint8 systemVoltage;               /** 系统电压 0-250，offset=150 实际电压值150-400V*/
    quint8 batterySoc;                  /** 0-100（%） 低于10%时告警显示*/
    qint16 batteryCurrent;              /** 电池电流 -600~600，(-250~250正常其他为故障，需报警）>0放电电流；<0，充电电流）*/
    OcuToChassisEnd  end;
}CarMainStatusInfoOne;

//! 报文2
typedef struct _CarMainStatusInfoTwo
{
    OcuToChassisFrameHead   frameHead;
    quint8 investigationInfoOne;        /** 侦查信息1*/
    quint8 investigationInfoTwo;        /** 侦查信息2*/

    quint8 powerUpStateOne;             /** 上电状态1：0：未上电；1：已上电
                                         *  Bit0：高压上电状态
                                         *  Bit1：12V设备上电
                                         *  Bit2：侦察系统
                                         *  Bit3：预留
                                         *  Bit4：自主计算机
                                         *  Bit5：激光雷达
                                         *  Bit6：
                                         *  Bit7：惯导/卫星定位装置
                                         **/
    quint8 powerUpStateTwo;             /** 上电状态2+车辆工作模式:  0：未上电；1：已上电
                                          * Bit0：前大灯
                                          * Bit1：
                                          * Bit2：双闪灯
                                          * Bit3：喇叭
                                          * Bit4：
                                          * Bit5：预留
                                          * Bit6：视频处理单元
                                          * Bit7：车辆工作模式 =0 转矩模式; =1转速模式
                                         **/
    quint8 underFrameLevel;             /** 底盘状态等级 0：系统正常
                                          * 1：1级故障（一般故障）
                                          * 2：2级故障（限速使用）
                                          * 3：3级故障（最为严重，自动停车并下高压电）*/
    quint8 underFramePartState;         /** 底盘各部分状态等级:0为正常，1异常；
                                         * Bit0：CAN总线通讯（含CAN1和CAN2的收发状态）
                                         * Bit1：BMS高压电池
                                         * Bit2：侦察分系统
                                         * Bit3：制动分系统
                                         * Bit4：驱动分系统
                                         * Bit5：Net网络通讯
                                         * Bit6：Ele电气状态（含低压电压、电气盒和DCDC）
                                         * Bit7：高压电池电量不足警示
                                         **/
    quint8 reserve;                     /** 预留*/
    OcuToChassisEnd  end;
}CarMainStatusInfoTwo;

#define ELE_STATUS_RPM_NUM   2

/** 底盘上报到Ocu的车辆详细信息的消息内容
 * 车辆详细状态信息
 * 发送周期 每1000ms发送7种报文
 * 为1hz,共61个字
 */
//! 报文1
typedef struct _CarDetailStatusInfoOne
{
    OcuToChassisFrameHead   frameHead;
    qint8   directionControlValue;      /** 方向控制量反馈 0~100（左转）；0~-100（右转）*/
    qint8   throttleBrakeValue;         /** 油门制动控制量反馈向前0~100（油门开度） 向后0~-100（制动量）*/
    quint16 drivingDistance;            /** 车辆行驶里程 0~65000，系数0.1 实际值为0~6500.0km*/
    quint8  minimumSinglePressure;      /** 最低单体总压 28~45（显示值=该值/10）实际值3.0~4.2正常其他为故障，需报警*/
    quint8  maximumSinglePressure;      /** 最高单体总压 28~45（显示值=该值/10）实际值3.0~4.2正常其他为故障，需报警*/
    quint8  batteryTemperature;         /** 电池温度 offset=-50, -20~60°为正常，其他需报警*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoOne;

//! 报文2
typedef struct _CarDetailStatusInfoTwo
{
    OcuToChassisFrameHead   frameHead;
    quint8  batteryState;               /** 电池状态信息:
                                         *  Bit0：电池组工作模式：0-正常工作；1-快速充电
                                         *  Bit1：预充继电器状态：0-断开；1-吸合
                                         *  Bit2：总正继电器状态：0-断开；1-吸合
                                         *  Bit3：快充继电器状态：0-断开；1-吸合
                                         *  Bit4：DC/DC继电器状态：0-断开；1-吸合
                                         *  Bit5：加热继电器状态：0-断开；1-吸合
                                         *  Bit6：备用
                                         *  Bit7：预充状态：0-正常；1-失败
                                         **/
    quint16 batteryWarningInfo;         /** 电池告警信息: 0-正常；1-1级报警；2-2级报警；3-3级报警
                                         * Bit1~0：总电压过充；
                                         * Bit3~2：总电压过放；
                                         * Bit5~4：单体电压过充
                                         * Bit7~6：单体电压过放
                                         * Bit9~8：最高温度过高
                                         * Bit11~10：最低温度过低
                                         **/

    quint8 reserveOne;                  /** 预留1*/
    quint8 reserveTwo;                  /** 预留2*/
    quint8 reserveThree;                /** 预留3*/
    quint8 reserveFour;                 /** 预留4*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoTwo;

//! 报文3
typedef struct _CarDetailStatusInfoThree
{
    OcuToChassisFrameHead   frameHead;
    quint32 generatorStatus_Speed;       /** 2个双字节数，低字节在前，高字节在后 单位rpm  offset=-15000
                                          * Byte0~byte1:左电机转速
                                          * Byte2~byte3:右电机转速
                                         **/
    quint16 leftMotorCurrent;           /** 左电机状态—电流  offset=-1000 **/
    quint8  reserve;
    OcuToChassisEnd  end;
}CarDetailStatusInfoThree;

//! 报文4
typedef struct _CarDetailStatusInfoFour
{
    OcuToChassisFrameHead   frameHead;
    quint16 rightMotorCurrent;           /** 右电机状态—电流  offset=-1000 **/
    quint8  leftDriveMotorState;         /** 驱动、电机状态—告警信息（左）
                                           * bit0：绕组过温错误，
                                           * bit1：绕组过温警告
                                           * bit2：can超时，
                                           * bit3：电机速度超限，
                                           * bit4：直流电流过流
                                           * bit5：直流电压过压，
                                           * bit6：旋变错误
                                           * bit7：绕组温度传感器错误 **/

    quint8  rightDriveMotorState;         /** 驱动、电机状态—告警信息（左）
                                           * bit0：绕组过温错误，
                                           * bit1：绕组过温警告
                                           * bit2：can超时，
                                           * bit3：电机速度超限，
                                           * bit4：直流电流过流
                                           * bit5：直流电压过压，
                                           * bit6：旋变错误
                                           * bit7：绕组温度传感器错误 **/

    quint8  generatorControlerTemperature;  /** 电机控制器温度（多个电机控制器的最高温度）  范围0~250，offset=-40 */
    quint8  generatorTemperature;           /** 电机温度（多个电机的最高温度） 范围0~250，offset=-40 */
    quint8  brakeFeedback;                  /** 制动量反馈 0~100*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoFour;

//! 报文5
typedef struct _CarDetailStatusInfoFive
{
    OcuToChassisFrameHead   frameHead;
    quint8  accumulatorPressure;        /** 蓄能器压力 范围0~200，factor=0.1，单位MPa,当实际压力值小于0.5或大于14应告警显示*/
    quint8  brakePressure;              /** 制动压力 范围0~200，factor=0.1，单位MPa*/
    quint8  brakeState;                 /** 制动系状态 0：正常，1：故障
                                          * Bit3~0：保留
                                          * Bit4：蓄能器传感器
                                          * Bit5：制动传感器
                                          * Bit7~6：保留*/
    quint16 DCDC_InputVoltage;          /** DCDC输入电压 输入电压：系数0.1 **/
    quint16 DCDC_OutputVoltage;         /** DCDC输出电压 0-34V，系数0.01*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoFive;

//! 报文6
typedef struct _CarDetailStatusInfoSix
{
    OcuToChassisFrameHead   frameHead;
    quint16 DCDC_OutputCurrent;          /** 范围0~220，系数0.1，单位A*/
    quint8  leftDriveMotorState3;        /** 驱动、电机状态—告警信息3（左）
                                            * bit0：逆变器过温错误，
                                            * bit1：IPME错误
                                            * bit2：欠压错误，
                                            * bit3：24V欠压错误
                                            * bit4：逆变器过温警告
                                            * bit5：欠压警告
                                            * bit6：过压警告 */

    quint8  rightDriveMotorState3;        /** 驱动、电机状态—告警信息3（右）
                                            * bit0：逆变器过温错误，
                                            * bit1：IPME错误
                                            * bit2：欠压错误，
                                            * bit3：24V欠压错误
                                            * bit4：逆变器过温警告
                                            * bit5：欠压警告
                                            * bit6：过压警告 */
    quint8  reserve1;                    /** 预留*/
    quint8  reserve2;                    /** 预留*/
    quint8  reserve3;                    /** 预留*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoSix;

//! 报文7
typedef struct _CarDetailStatusInfoSeven
{
    OcuToChassisFrameHead   frameHead;
    quint8  reserve1;                    /** 预留*/
    quint8  reserve2;                    /** 预留*/
    quint8  reserve3;                    /** 预留*/
    quint8  reserve4;                    /** 预留*/
    quint8  reserve5;                    /** 预留*/
    quint8  reserve6;                    /** 预留*/
    quint8  reserve7;                    /** 预留*/
    OcuToChassisEnd  end;
}CarDetailStatusInfoSeven;


/** *******************自主计算机回传给ocu的平台位置和姿态信息通信结构体**************************/
/** 自主计算机回传给ocu的平台位置和姿态信息消息报头
 * 发送周期：100ms
*/
typedef struct _ComputerToOcuStateFrameHead
{
    quint16   prop;   /*帧头*/
    quint16   type;   /*帧类型*/
    quint8    len;    /*帧长度*/
}ComputerToOcuStateFrameHead;

/**
 * ocu端到自主计算机的消息报头
 */
typedef struct _frameTail
{
    quint8 checksum;                  /** 前面所有字节累加之和（数据包固定长度，但不固定值！
                                       * 校验码是从0xffaa一直加到校验码之前的所有数据，和取一个字节）
                                       **/
}UCSFrameTail;

/**
 * 自主计算机回传给ocu的平台位置和姿态信息消息
 */
typedef struct _ComputerToOcuStateInfo
{
    ComputerToOcuStateFrameHead  frameHead;
    qint8 pitch;                         /** 俯仰角：角度：-90~90；精度1度；采用四舍五入*/
    qint8 roll;                          /** 侧倾角：角度：-90~90；精度1度；采用四舍五入*/
    quint16 yaw;                          /** 航向角：数据范围：0~360；精度1度；采用四舍五入（和正北方向的夹角，顺时针方向）*/
    quint32 longtitude;                   /** 当前位置的精度乘以10000000传送，精度到0.0000001，如经度116.1234567表示为
                                          ** 1161234567回传，低字节在前，高字节在后
                                          */
    quint32 latitude;                     /** 当前位置的精度乘以10000000传送，精度到0.0000001*/
    qint16 reserve;                      /** 保留*/
    quint16 decisionControlState;         /** 决策控制系统状态：定义 1-成功；0-失败
                                            * Bit0:远程操控模块状态（预留）
                                            * Bit1:激光雷达数据采集模块状态
                                            * Bit2:激光雷达数据建模模块状态（预留）
                                            * Bit3:惯导数据采集模块状态
                                            * Bit4:运行轨迹记录模块状态（预留）
                                            * Bit5:路径规划模块状态（预留）
                                            * Bit6:跟踪控制模块状态（预留）
                                            * Bit7:底盘控制模块状态（预留）
                                            * Bit8~Bit14:保留
                                            * Bit15:路径规划结果（预留）**/
    qint32 realTimeSpeed;                /** 实时速度  惯导测量实时速度，单位m/s，低字节在前;实际发送乘100，接收除100精确到0.01m/s*/
    quint8 heartBeatCount;               /** 心跳计数：从0开始累加到0Xff*/
    UCSFrameTail  frameTail;
}ComputerToOcuStateInfo;

/** ******************************OCU端与自主计算机通信结构体*************************************/
/**
 * ocu端到自主计算机的消息报头
 *                                            第一字节	第二字节
 * 路点记录（记录路点，用于地图上显示轨迹，和路径下发）	0x1	0x1
 * 路径跟踪行驶	                                0x2	0x1:普通模式（不降级、不绕圈）
 *                                                      0x2:纯降级模式（仅降级、不绕圈）
 *                                                      0x3:仅绕圈模式（不降级、仅绕圈）
 *                                                      0x4:降级绕圈模式（既降级、又绕圈）
 *                                                      注：降级=不避障、绕圈=终点不停车
 * 一键返航	                                0x3
 * 暂停	                                        0x8     0x1
 * 恢复自动驾驶功能                                0x9     0x1
 * 停止自动驾驶功能                                0xA     0x1
 **/
typedef struct _OcuToComputerFrameHead
{
    quint16   prop;                      /** 帧头*/
    quint16   type;                      /** 帧类型*/
    quint16   len;                       /** 帧长度*/
}OcuToComputerFrameHead;

/**
 * ocu到自主计算机的心跳帧
 * 心跳帧为自主状态下ocu与自主控制计算机之间的通信状态确认帧
 * 非自主状态下不发送
 * 发送周期：100ms
*/
typedef struct _OcuToComputerHeartBeatParaTopic
{
    OcuToComputerFrameHead   frameHead;
    quint16 heartBeatCount;/* 心跳计数：从0开始累加到0Xffff */
    qint8   checksum;      /* 前面所有字节累加之和 */
}OcuToComputerHeartBeatParaTopic;


typedef struct _PositionPoint
{
    quint32 lontitude;           /** 经度 */
    quint32 latitude;            /** 纬度 */
    qint32 targetSpeed;         /** 目标速度 */
    qint8  obstacleAvoidFlag;   /** 避障标志 */
    qint8  inspectionPointFlag; /** 是否巡检*/
    qint8  externFlagOne;       /** 预留位1 */
    qint32 externFlagTwo;       /** 预留位2 */
    qint32 externFlagThree;     /** 预留位3*/
}PositionPoint;

#define MSG_MAX_LEN  2000
/* ocu到自主计算机的任务帧
 * 任务帧为自主状态下OCU与自主计算机之间的数据传送帧
 * 非自主状态下不发送
 * ocu街道确认帧后不发送任务帧
*/
typedef struct _OcuToComputerTaskParaTopic
{
    OcuToComputerFrameHead   frameHead;
    qint16 targetNum;        /*任务号：从1开始累加到0Xffff*/
    qint16 speedMax;         /*最大速度：-100~100单位m/s,系数0.1，精确度到0.1m/s,实际10m/s时需下发值=100*/
    qint16 pointCount;       /*路径点数*/
    PositionPoint positionPoint[MSG_MAX_LEN];
    quint32 reserveByte;      /*预留位*/
    quint16 frameSeriNum;     /*分帧序号*/
    qint16 flagMsiion;       /*分帧标记 1: 表示中间帧; 0：结束帧（如果不分帧，固定置0）*/
    quint8  frameTail;        /*消息尾，校验和*/
}OcuToComputerTaskParaTopic;

/* 自主计算机上报到ocu的心跳帧回文
 * 心跳帧为自主状态下自主避障模块与ocu之间的通讯状态确认帧
 * 非自主状态下不发送
 * 发送周期：100ms
*/
typedef struct _ComputerToOcuHeartBeatInfo
{
    OcuToComputerFrameHead   frameHead;
    quint16 heartBeatCount;  /*心跳计数：从0开始累加到0Xffff*/
    quint64 time;            /*时间：单位毫秒，当前系统时间从1970-1-1开始*/
    UCSFrameTail  frameTail; /*消息尾，校验和*/
}ComputerToOcuHeartBeatInfo;

/** 自主计算机上报到ocu的任务帧回文
 * 任务回复帧为自主状态下自主避障模块与Ocu之间的任务信息确认帧
 * 非自住状态下不发送
 * 在自主避障模块接收到正确的任务帧后发送
 * 其余时间不发送，为保证可靠,任务回复帧连续发送两次，每次间隔100ms
 */
typedef struct _ComputerToOcuTaskInfo
{
    OcuToComputerFrameHead   frameHead;
    quint16 receiveTargetNum;/*接受的任务编号*/
    quint16 status;          /*状态：为固定值0x4f4b*/
    UCSFrameTail  frameTail; /*消息尾，校验和*/
}ComputerToOcuTaskInfo;

/** 自主计算机上报到ocu端的惯导对准指令
 *  界面点击惯导对准发送此命令，没有消息回复
 */
typedef struct  OcuToComputerInertialAligCommand
{
    OcuToComputerFrameHead   frameHead;
    qint8    aligmentCommand;   /*Bit0:
                                =1，自检
                                =0，停止
                                Bit1:
                                =1，开始发送图像
                                =0，停止发送图像
                                Bit2-Bit7:保留*/
    qint8   checksum;           /*消息尾，校验和:前面所有字节累加之和*/
}OcuToComputerInertialAligCommand;


/* 自主计算机到OCU的态势增强信息帧
 * 当坐标和宽度高度为200时，代表没有检测到相关目标
 * 静态障碍物：根据z和宽度和高度算出是不是负障碍物（Z+（高度/2））<0就是负障碍物
 * 只有坐标x，z有正负值，其他均为正值
*/
typedef struct  _ComputerToOcuSituationalEnhancementPlotting
{
    OcuToComputerFrameHead   frameHead;

    qint16  regionNum;
    qint32  personTarget_y;/*人员目标的坐标y*/
    qint32  personTarget_z;/*人员目标的坐标z*/
    qint32  personTarget_width;/*人员目标的宽度*/
    qint32  personTarget_height;/*人员目标的高度*/

    qint32  carTarget_x;/*车辆目标的坐标x*/
    qint32  carTarget_y;/*车辆目标的坐标y*/
    qint32  carTarget_z;/*车辆目标的坐标z*/
    qint32  carTarget_width;/*车辆目标的宽度*/
    qint32  carTarget_height;/*车辆目标的高度*/

    qint32  passableRegonCenterLineEquation_a;/*可通行区域中心线抛物线方程a值*/
    qint32  passableRegonCenterLineMarginWidth;/*可通行区域中心线距边缘宽度*/
    qint32  passableRegonLength;/*可通行区域长度*/

    qint32  staticObstaclesOneCeterPoint_x;/*静态障碍物中心点坐标1x*/
    qint32  staticObstaclesOneCeterPoint_y;/*静态障碍物中心点坐标1y*/
    qint32  staticObstaclesOneCeterPoint_z;/*静态障碍物中心点坐标1z*/
    qint32  staticObstaclesOneWidth;/*静态障碍1宽度*/
    qint32  staticObstaclesOneHeight;/*静态障碍1高度*/
    qint32  staticObstaclesTwoCeterPoint_x;/*静态障碍物中心点坐标2x*/
    qint32  staticObstaclesTwoCeterPoint_y;/*静态障碍物中心点坐标2y*/
    qint32  staticObstaclesTwoCeterPoint_z;/*静态障碍物中心点坐标2z*/
    qint32  staticObstaclesTwoWidth;/*静态障碍2宽度*/
    qint32  staticObstaclesTwoHeight;/*静态障碍2高度*/

    qint8    checksum;          /*消息尾，校验和:前面所有字节累加之和*/
}ComputerToOcuSituationalEnhancementPlotting;

/*自主任务控制帧*/
typedef struct _OcuToComputerTaskControlTopic
{
    OcuToComputerFrameHead   frameHead;   /*消息头*/
    quint32  maxSpeed;                    /*最大速度*/
    qint16   taskType;                    /*操控模式*/
    qint16   taskConunter;                /*任务计数*/
    qint8    checksum;                    /*消息尾，校验和:前面所有字节累加之和*/
}OcuToComputerTaskControlTopic;

#define IMAGE_VALUE_MAX 200000

/*自主计算机到远程操控系统的图像*/
typedef struct _OcuToComputerImage{
    quint16   prop;                         /** 帧头      为固定值0xee33*/
    quint16   type;                         /** 帧类型    为固定值0x000e*/
    quint32   len;                          /** 帧长度    为固定值0x00023B59*/
    quint16   imageLength;                  /** 图像长为固定值H=0x0145 (325)*/
    quint16   imageWidth;                   /** 图像宽度为固定值W=0x0096 (150)*/
    quint8    imageValue[IMAGE_VALUE_MAX];  /** 图像值0x00-0xff*/
    quint16   heart;                        /** 心跳，依次累加*/
    UCSFrameTail  frameTail;                /** 消息尾，校验和*/
}OcuToComputerImage;


/** ******************************OCU与火控操控软件通信结构体********************************/
/**
 *  火控目标识别信息上报
 */
typedef struct _FireControlSituationReport
{
    quint16   freamHead;                      /** 帧头 0xAA 0x55*/
    quint16   targetDistance;                 /** 跟踪目标激光测距 精度2m，0~6000m*/
    quint16   targetLongtitude;               /** 跟踪目标经度 精度到小数点后6位*/
    quint16   targetLatitude;                 /** 跟踪目标纬度 精度到小数点后6位*/
    quint16   targetAltitude;                 /** 跟踪目标高度 精度1m，-100~9999m*/
}FireControlSituationReport;

/**
  * 轴操纵杆 RS232 通信协议
  */
typedef struct _AxisJoystick
{
    quint8      head;
    quint8      address;
    quint8      x_high;
    quint8      x_low;
    quint8      y_high;
    quint8      y_low;
    quint8      z_high;
    quint8      z_low;
    quint8      btn;
    quint8      check;
}AxisJoystick;

/********************************OCU端与视频端通信结构体*************************************/
//! ocu到视频处理端协议的帧头
typedef struct _OcuToVideoFrameHead
{
    quint8     SYNC1;	//! 同步头1 固定值0x42
    quint8     SYNC2;	//! 同步头2 固定值0x56
    quint8     SRCID;	//! 0x00
    quint8     DSTID;	//! 0x00
    quint8     MSGID;	//! 消息ID号
    quint8     MSNUM;	//! 00H~FFH 递增 01H 累加，然后除余 FFH，不同类型 MSG 按自己顺序累加。响应序号等于请求序号加 1。
    quint16    PLLEN;	//! 数据段数据长度
}OcuToVideoFrameHead;

//! *********************************ocu--->视频处理端*******************************
//! 打开音视频编码 MSGID(参数 ID)：0x12
typedef struct _VideoOpen
{
    OcuToVideoFrameHead     head;
    quint32                 payLoad;    //! 填0即可
}VideoOpen;

//! 停止音视频编码 MSGID(参数 ID)：0x14
typedef struct _VideoStop
{
    OcuToVideoFrameHead     head;
    quint32                 payLoad;    //! 填0即可
}VideoStop;

typedef struct _VideoInfo
{
    quint8   ID;         //! 通道号 0
    quint8   FPS;        //! 帧率 默认 30帧
    quint16  Width;      //! 视频宽度 1920
    quint16  Height;     //! 视频高度 1080
    quint16  Bitrate;    //! 码率 (单位 kbps) 默认 3600
    quint16  Gop;        //! I帧间隔(GOP) 30(默认)
    quint16  Reserve;    //! 保留，默认填0 0
}VideoInfo;

//! 设置视频编码码率  MSGID(参数 ID)：0x30
typedef struct _VideoSetParameter
{
    OcuToVideoFrameHead     head;
    VideoInfo               videoInfo;
}VideoSetParameter;

//! 获取视频编码参数  MSGID(参数 ID)：0x32
typedef struct _VideoGetParameter
{
    OcuToVideoFrameHead     head;
}VideoGetParameter;

//! 设置视频显示(拼接)模式  MSGID(参数 ID)：0x20
typedef struct _VideoSetShowMode
{
    OcuToVideoFrameHead     head;
    quint32                 mode;   //! 01H = 单路1; 02H = 单路2; 03H = 画中画模式1; 04H = 画中画模式2
}VideoSetShowMode;

//! 获取视频显示(拼接)模式   MSGID(参数 ID)：0x22
typedef struct _VideoGetShowMode
{
    OcuToVideoFrameHead     head;
}VideoGetShowMode;

//! *********************************视频处理端---->ocu*******************************
//! 打开音视频编码响应消息 MSGID(参数 ID)：0x13
typedef struct _VideoOpenResponse
{
    OcuToVideoFrameHead     head;
    quint32                 payLoad;    //! 0：成功; 非0：失败
}VideoOpenResponse;

//! 停止音视频编码响应消息  MSGID(参数 ID)：0x15
typedef struct _VideoStopResponse
{
    OcuToVideoFrameHead     head;
    quint32                 payLoad;    //! 0：成功; 非0：失败
}VideoStopResponse;

//! 设置视频参数响应消息  MSGID(参数 ID)：0x31
typedef struct _VideoSetParameterResponse
{
    OcuToVideoFrameHead     head;
    quint32                 payLoad;    //! 0：成功; 非0：失败
}VideoSetParameterResponse;

//! 获取视频编码参数响应消息   MSGID(参数 ID)：0x33
typedef struct _VideoGetParameterResponse
{
    OcuToVideoFrameHead     head;
    VideoInfo               videoInfo;
}VideoGetParameterResponse;

//! 设置视频显示(拼接)模式响应消息   MSGID(参数 ID)：0x21
typedef struct _VideoSetShowModeResponse
{
    OcuToVideoFrameHead     head;
    quint32                 mode;   //! 0：成功; 非0：失败
}VideoSetShowModeResponse;

//! 获取视频显示(拼接)模式响应消息   MSGID(参数 ID)：0x23
typedef struct _VideoGetShowModeResponse
{
    OcuToVideoFrameHead     head;
    quint32                 mode;   //! 01H = 单路1; 02H = 单路2; 03H = 画中画模式1; 04H = 画中画模式2
}VideoGetShowModeResponse;



#pragma pack()

}
