#pragma once

#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QDateTime>

#include "icd/OcuControlICDTransStruct.h"


namespace Qxxlc {

#define RCSNML_IDLE  0
#define RCSNML_WAIT  1
#define RCSNML_WORK  2

typedef enum{
    BUTTON_VALUE_0x00 = 0,
    BUTTON_VALUE_0x01,
    BUTTON_VALUE_0x02,
    BUTTON_VALUE_0x03,
    BUTTON_VALUE_0x04,
    BUTTON_VALUE_0x05,
    BUTTON_VALUE_0x06,
    BUTTON_VALUE_0x07,
    BUTTON_VALUE_0x08,
    BUTTON_VALUE_0x09,
    BUTTON_VALUE_0x0A,
    BUTTON_VALUE_0x0B,
    BUTTON_VALUE_0x0C,
    BUTTON_VALUE_0x0D,
    BUTTON_VALUE_0x0E,
    BUTTON_VALUE_0x0F,
    BUTTON_VALUE_0x10
}ButtonValue;

//!***********************************RCS公用结构体*******************************************/

//!***********************************定位定向设备管理*******************************************/
//!定位定向设备状态
typedef struct _ICD_CZ_DWDX_STATUS_TRANS
{
    /**
     * 具体协议如下：
     * 1表示自检信息(zjxx)，2表示发送参数，3表示正在启动，4表示启动完毕，5表示正在对准，6表示导航，7写入或者读取超时
     */
    unsigned char sbzt;                //! 上报状态
    /**
     * 自检信息状态(sbzt==1时赋值），1表示正在启动，2表示启动完毕，3表示正在对准，4表示导航，0表示无值,
     */
    unsigned char zjxx;                //! 自检信息状态
    /**
     * 参数序号状态(sbzt==2时赋值），1表示航向安装误差，2表示里程系数，3表示里程计脉冲数，4表示俯仰安装误差
     */
    unsigned char csxh;                //! 参数序号状态
    float hxanwc;                      //! 航向安装误差，刻度值为0.01mil
    float lcxs;                        //! 里程系数，刻度值0.0001
    float lcjmcs;                      //! 里程计脉冲数，刻度值0.0001
    float fyazwc;                      //! 俯仰安装误差，刻度值0.01mil
}ICD_CZ_DWDX_STATUS_TRANS;



//!*定位定向参数读取命令消息*/
typedef struct _ICD_CZ_DWDX_CSDQ_CMD_TRANS
{
    unsigned char csid;                //! 读取参数序号，数值范围为1-8
}ICD_CZ_DWDX_CSDQ_CMD_TRANS;


//!*定位定向参数修改命令消息*/
typedef struct _ICD_CZ_DWDX_CSXG_CMD_TRANS
{
    unsigned char csid;                //! 修改参数序号，数值范围为1-8
    /** 对应序号参数值，参数值
     *  1.航向安装误差 单位0.01mil0、
     *  2.里程系数    单位0.0001
     *  3.里程计脉冲数 单位0.0001
     *  4.俯仰安装误差 单位0.01mil
     */
    unsigned int csvalue;
}ICD_CZ_DWDX_CSXG_CMD_TRANS;


//!*定位定向对准命令消息*/
typedef struct _ICD_CZ_DWDX_DZ_CMD_TRANS
{
    double time_label;                  //! 时间戳
}ICD_CZ_DWDX_DZ_CMD_TRANS;


//!*定位定向坐标装订命令消息*/
typedef struct _ICD_CZ_DWDX_ZBZD_CMD_TRANS
{
    float lng;                          //! 经度值，单位0.000001
    float lat;                          //! 维度值
    float h;                            //! 高程值
}ICD_CZ_DWDX_ZBZD_CMD_TRANS;


//! 定位定向自检命令消息
typedef struct _ICD_CZ_DWDX_ZJ_CMD_TRANS
{
    double time_label;                  //! 时间戳
}ICD_CZ_DWDX_ZJ_CMD_TRANS;


//! 定位定向初始化命令消息
typedef struct _ICD_CZ_DWDX_INIT_TRANS
{
    double time_label;                  //! 时间戳
}ICD_CZ_DWDX_INIT_TRANS;


//!*定位定向暂停命令消息
typedef struct _ICD_CZ_DWDX_HALT_TRANS
{
    double time_label;                  //! 时间戳
}ICD_CZ_DWDX_HALT_TRANS;



//!**************************************系统监控*********************************************/
/** 系统监控模块状态消息
  * 点击“连接”后，持续读取，点击“断开连接”时停止读取；
  * 服务器断开连接时，若不点击“取消”，仍继续读取。
  * 服务器断开连接时，点“取消”，视同为点击“断开连接”，停止读取。
  */
typedef struct _ICD_CZ_XTJK_STATUS_TRANS
{
    unsigned char rwzx_status; //! 任务执行状态，值域，00H-无任务、01H-执行中、02H-执行完毕
    /** 车载综合决策控制系统运行状态，值域，
      * 00H-等待(初始值)、
      * 01H-INIT、
      * 02H-HALT、
      * 03H-紧急停车、
      * 04H-遥控驾驶、
      * 05H-自主驾驶、
      * 06H-编队机动、
      * 07H-系统停车
      */
    unsigned char xtyx_status;
    /** 车载综合决策控制系统是否异常，值域，
                                00H-初始值，正常、
                                01H-算法异常、
                                02H-模块断开，
                                03H-断开且异常*/
    unsigned char xtyx_excpetion;
    /** 车载编队机动规划模块运行状态，值域,
                                00H-等待(初始值)、
                                01H-INIT，
                                02H-HALT，
                                03H-编队规划,
                                04H-断开，
                                05H-异常*/
    unsigned char bdjdghc_status;
    /** 车载编队机动规划算法状态，值域,
                                00H-初始值,
                                01H-速度异常，
                                02H-路径点数目，
                                03H-车辆ID号大于车辆总数量，
                                04H-给定的低速值大于中速值或者中速值大于高速值，
                                05H-安全距离大于正常距离，
                                06H-队形矩阵长度小于等于0，
                                07H-车辆状态数量小于等于0，
                                08H-当前位置超出取值范围，
                                09H-路径点的坐标值超出取值范围*/
    unsigned char bdjdghc_algorithm_status;

    /** 车载局部路径规划与跟踪模块运行状态，值域，
                                00H-等待(初始值)、
                                01H-INIT、
                                02H-HALT、
                                03H-编队、
                                04H-规划跟踪、
                                05H-降级使用、
                                06H-系统停车,
                                07H-断开，
                                08H-异常,
                                09H-到达任务点1,
                                10H-离开任务点1,
                                11H-到达任务点2,
                                12H-离开任务点2(离开巡逻区域),
                                13H-达到终点*/
    unsigned char ghgz_status;
    /** 局部路径规划跟踪算法状态，值域，
                                00H-正在初始化(正常)、
                                01H-没有全局路径点(异常)、
                                02H-没有可执行局部最优路径(异常)、
                                03H-规划跟踪(正常)、
                                04H-到达终点(正常)、
                                05H-系统停车(正常)、
                                06H-编队规划(正常)、
                                07H-全局的最高车速<=0(异常)、
                                08H-底盘参数不正确(异常)、
                                09H-底盘运动状态不正确(异常)、
                                10H-定位定向不正确(异常)
                                11H-地图参数出错(异常),
                                12H-编队状态时不编队，需要重新给入命令(异常)*/
    unsigned char ghgz_algorithm_status;

    /** 车载运动控制决策模块运行状态，值域，
                                00H等待(初始值)、
                                01H-INIT、02H-HALT、
                                03H-紧急停车、
                                04H-遥控驾驶、
                                05H-自主驾驶、
                                06H人工干预、
                                07H-断开，
                                08H-异常*/
    unsigned char ydkzjc_status;
    /** 紧急避险算法状态，值域，
                                00H-初始值(正常),
                                01H-正常(正常),
                                02H-盘参数异常(异常),
                                03H-地图信息出错(异常),
                                04H-运动状态异常(异常),
                                05H-定位信息错误(异常),
                                06H-规划跟踪控制命令异常(异常),
                                07H-遥控指令异常(异常),
                                08H-人工干预指令异常(异常),
                                09H-可调参数异常(异常),
                                10H-紧急避险停车(正常)*/
    unsigned char jjbx_algorithm_status;
    /** 驾驶操控连接状态，
                                00H-断开，
                                01H-未断开*/
    unsigned char jsck_status;
    /** 运动控制决策与与底盘管控模块是否断开的标识，
                                00H-断开，
                                01H-未断开*/
    unsigned char ydkzjc_dpgk_connect_status;
}ICD_CZ_XTJK_STATUS_TRANS;


//! 系统监控模块编队机动计划命令消息*/
typedef struct _ICD_CZ_XTJK_BDJD_PLAN_TRANS
{
    double time_label;              //! 时间戳
    //! 全局路径点,最大长度为QJLJD_ARRAY_LENGTH的GlobalPosition数组
    //! DECLARE_NML_DYNAMIC_LENGTH_ARRAY(GlobalPosition, qjljd, QJLJD_ARRAY_LENGTH);
    //! vector<GlobalPosition> qjljd;
    float vmax;//!自主导航最高速度，值域0.0~100.0,单位是m/s
    //! 队形矩阵，最大长度为DXJZ_ARRAY_LENGTH的Formation数组
    //! DECLARE_NML_DYNAMIC_LENGTH_ARRAY(Formation, dxjz, VEHICLE_AMOUNT);//vector<Formation> dxjz;
    unsigned char jjsn_flag;        //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;        //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险

}ICD_CZ_XTJK_BDJD_PLAN_TRANS;


//! 系统监控暂停命令消息*/
typedef struct _ICD_CZ_XTJK_HALT_TRANS
{
    double time_label;               //! 时间戳
}ICD_CZ_XTJK_HALT_TRANS;


/** 系统监控初始化命令消息
 * 点击“连接”后，单次发送；
 * 退出遥控驾驶模式或自主驾驶模式后，单次发送；
 * 点击“RCS复位”按钮，单次发送；
*/
typedef struct _ICD_CZ_XTJK_INIT_TRANS
{
    double time_label;               //! 时间戳
}ICD_CZ_XTJK_INIT_TRANS;


//! 系统监控计划命令消息*/
typedef struct _ICD_CZ_XTJK_XTTC_PLAN_TRANS
{
    double time_label;                //! 时间戳
}ICD_CZ_XTJK_XTTC_PLAN_TRANS;


/** 系统监控遥控驾驶计划命令消息
 * 点击“遥控驾驶”按钮，单次发送，进入遥控驾驶模式；
*/
typedef struct _ICD_CZ_XTJK_YKJS_PLAN_TRANS
{
    double time_label;                //! 时间戳
    unsigned char bxsn_flag;          //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_CZ_XTJK_YKJS_PLAN_TRANS;


/** 系统监控自主驾驶计划命令消息
 * 在自主驾驶界面点击“任务”按钮，单次发送，进入自主驾驶模式；
 * 在自主驾驶模式下，当出现服务器断开连接时，若不点击“取消”，当恢复连接后，先发一次系统监控初始化命令消息CZ_XTJK_INIT，然后再发送一次自主驾驶计划命令消息CZ_XTJK_ZZJS_PLAN；
*/
typedef struct _ICD_MIDDLE_CZ_XTJK_ZZJS_PLAN_TRANS          //!中型轮式车自主驾驶
{
    double time_label;                //! 时间戳
    int taskType;                     //! 任务类型
    int task_num;                     //! 任务号
    unsigned  int   pathPointNum;
    QVector<globalPoseMidCar>  pathPoint;
    unsigned char jsck_qjlj_flag;     //! 驾驶操控发送一次全局任务,加一,0-255循环,发一次加一
    float vmax;                       //! 自主导航最高速度，值域0.0~100.0,单位是m/s
    unsigned char jjsn_flag;          //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;          //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_MIDDLE_CZ_XTJK_ZZJS_PLAN_TRANS;


typedef struct _ICD_CRAWLER_CZ_XTJK_ZZJS_PLAN_TRANS          //!中型履带车自主驾驶
{
    double time_label;                //! 时间戳
    int    taskType;                  //! 任务类型
    int    task_num;                  //! 任务号
    unsigned  int   pathPointNum;
    QVector<globalPoseMidCar>  pathPoint;
    unsigned char jsck_qjlj_flag;     //! 驾驶操控发送一次全局任务,加一,0-255循环,发一次加一
    float  vmax;                      //! 自主导航最高速度，值域0.0~100.0,单位是m/s
    unsigned char jjsn_flag;          //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;          //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_CRAWLER_CZ_XTJK_ZZJS_PLAN_TRANS;


typedef struct _ICD_CZ_XTJK_ZZJS_PLAN_TRANS
{
    double time_label;                //! 时间戳
    int    taskType;                  //! 任务类型
    int    task_num;                  //! 任务号
    unsigned  int   pathPointNum;
    QVector<globalPose>  pathPoint;
    unsigned char jsck_qjlj_flag;     //! 驾驶操控发送一次全局任务,加一,0-255循环,发一次加一
    float  vmax;                      //! 自主导航最高速度，值域0.0~100.0,单位是m/s
    unsigned char jjsn_flag;          //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;          //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_CZ_XTJK_ZZJS_PLAN_TRANS;



typedef struct _ICD_COMMON_CZ_XTJK_ZZJS_PLAN_TRANS          //!通用的所有车的自主驾驶（复用中型的）
{
    double time_label;                //! 时间戳
    int    taskType;                  //! 任务类型
    int    task_num;                  //! 任务号
    unsigned  int   pathPointNum;
    QVector<globalPoseCommon>  pathPoint;
    unsigned char jsck_qjlj_flag;     //! 驾驶操控发送一次全局任务,加一,0-255循环,发一次加一
    float  vmax;                      //! 自主导航最高速度，值域0.0~100.0,单位是m/s
    unsigned char jjsn_flag;          //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;          //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_COMMON_CZ_XTJK_ZZJS_PLAN_TRANS;

//! 系统监控NOP命令*/
typedef struct _ICD_CZ_XTJK_NOP_TRANS
{
    double time_label;                //! 时间戳
}ICD_CZ_XTJK_NOP_TRANS;



//! ************************************遥控驾驶命令**********************************************/
//! 遥控驾驶命令消息(辅助通道)*/
typedef struct _ICD_P_YKJS_CMD_MSG_TRANS
{
    unsigned int throttle;           //! 油门控制量，值域，0~100%
    unsigned int braking;            //! 制动控制量，值域directionalDeflection,0~100%
    int steering;                    //! 转向控制量，值域-100%~100%
    unsigned char e_stop_flag;       //! 紧急停车标志，值域，00H-不紧急停车，01H-紧急停车
}ICD_P_YKJS_CMD_MSG_TRANS;


//! ************************************定位定向数据**********************************************/
//! 定位定向信息消息(辅助通道)
//! * 点击“连接”后，持续读取，点击“断开连接”时停止读取；
//! * 服务器断开连接时，若不点击“取消”，仍继续读取。
//! * 服务器断开连接时，点“取消”，视同为点击“断开连接”，停止读取。
//! */
typedef struct  _ICD_P_DWDX_INFO_MSG_TRANS
{
    float global_x;                   //! 无人车全局坐标X值(北)(GPS)，值域，0～99999999，坐标刻度为0.1m
    float global_y;                   //! 无人车全局坐标Y值(东)(GPS)，值域，0～99999999，坐标刻度为0.1m
    float global_h;                   //! 无人车全局高程H值(地)(GPS)，值域，0～99999999，坐标刻度为0.1m
    unsigned short int zone;          //! 区号(GPS)，值域，0～60
    int ilongitude;                   //! 经度坐标(GPS)，值域，刻度0.000001度,范围-180~180度;
    int ilatitude;                    //! 纬度坐标(GPS)，值域，刻度0.000001度,范围-90~90度;

    float longitude;                  //! 经度坐标(GPS)，值域，刻度0.000001度,范围-180~180度;
    float latitude;                   //! 纬度坐标(GPS)，值域，刻度0.000001度,范围-90~90度;
    float heading;                    //! 航向角值，值域，0～36000，角度刻度为0.01°
    float pitch;                      //! 俯仰角值，值域，-9000～9000，角度刻度为0.01°
    float roll;                       //! 倾斜角值，值域，-9000～9000，角度刻度为0.01°
    float global_vx;                  //! 无人车全局X轴向速度(东)，值域，-10000～10000，坐标刻度为0.01m/s
    float global_vy;                  //! 无人车全局Y轴向速度(北)，值域，-10000～10000，坐标刻度为0.01m/s
    float global_vz;                  //! 无人车全局H轴向速度(天)，值域，-10000～10000，坐标刻度为0.01m/s
    float global_wx;                  //! 航向角速度，值域，-10000～10000,坐标刻度为0.01°/s,对应陀螺仪x轴角速度
    float global_wy;                  //! 俯仰角速度，值域，-10000～10000,坐标刻度为0.01°/s，对应陀螺仪y轴角速度
    float global_wz;                  //! 倾斜角速度，值域，-10000～10000,坐标刻度为0.01°/s，陀螺仪对应z轴角速度
    float mileage;                    //! 本次里程，值域，0～99999999，坐标刻度为0.1m
    bool valid_sts;                   //! 1-valid, 0-non-valid
    float belief;                     //! 0~10000%, 坐标刻度为0.01%
    float baseline;                   //! 基线长度,单位米
    unsigned short int NSV1;          //! NSV1天线1收星数
    unsigned short int NSV2;          //! NSV2天线2收星数
    char status;                      //! 标志位
    short int accx;                   //! 加速度计x轴加速度，单位g×10000
    short int accy;                   //! 加速度计y轴加速度，单位g×10000
    short int accz;                   //! 加速度计z轴加速度，单位g×10000
    short int tpr;                    //! 温度计，单位度
    unsigned short int info_source; //info source
}ICD_P_DWDX_INFO_MSG_TRANS;



//! ************************************底盘工作状态**********************************************/
/** 底盘状态模块的状态消息(辅助通道)
 * 点击“连接”后，持续读取，点击“断开连接”时停止读取；
 * 服务器断开连接时，若不点击“取消”，仍继续读取。
 * 服务器断开连接时，点“取消”，视同为点击“断开连接”，停止读取。
*/
typedef struct _ICD_P_DPZT_STAT_MSG_TRANS
{
#if 0
    quint8   hydraulicSystemEnableState;//! 设备：液压系统使能状态；定义：0-未使能，1-已使能；
    quint8   hydraulicState;            //! 设备：液压；定义：0-等待，1-运行；
    quint8   vehicleAttitudeAdjustMode; //! 设备：车姿调节模式；定义：0-手动，1-自动；
    quint8   vehicleAttitudeAdjustState;/** **设备：车姿调节状态；定义：0x0-等待，0x1-稳升车姿调节中，0x2-自动高位车姿调节中，0x3-自动中位车姿调节中，0x4-自动低位车姿调节中，
                                            *             0x5-自动提轮调节中， 0x15-手动提轮调节中，0x6-自动弹簧环形腔充油中，0x16-自动弹簧环形腔充油中，
                                            *             0x7-自动中心转向状态调节中，0x17-手动中心转向状态调节中，0x8-自动前俯车姿调节中，0x9-自动后仰车姿调节中，0xa-自动左倾车姿调节中，
                                            *             0xb-自动右倾车姿调节中，0xc手动弹簧闭锁中，0xd-手动车姿调节中*/
    int           cz_oil_temp;      //! 车姿油液温度，值域-50~+150, 单位 ℃，精度：1
    float         cz_oil_pressure;  //! 车姿油液压力，值域，0~510，单位0.1Mpa，精度：0.1，显示0.0-51.9MPa
    unsigned int  cz_leftfront_dis; //! 左前角位移,值域，0~1023，单位：无，精度：1
    unsigned int  cz_rightfront_dis;//! 右前角位移,值域，0~1023，单位：无，精度：1
    unsigned int  cz_leftrear_dis;  //! 左后角位移,值域，0~1023，单位：无，精度：1
    unsigned int  cz_rightrear_dis; //! 右后角位移,值域，0~1023，单位：无，精度：1
    float         cz_left_press;    //! 左张紧油缸压力，值域，0~51，单位Mpa，精度：0.01   //暂时保留不用
    float         cz_right_press;   //! 右张紧油缸压力，值域，0~51，单位Mpa，精度：0.01   //暂时保留不用
    float         cz_press;         //! 蓄能器压力，值域，0~51，单位Mpa，精度：0.01           //暂时保留不用
    unsigned int  cz_left_dis;      //! 左张紧油缸位移，值域，0~1020，单位：无，精度：1   //暂时保留不用
    unsigned int  cz_right_dis;     //! 右张紧油缸位移，值域，0~1020，单位：无，精度：1  //暂时保留不用
    unsigned char cz_diag;          //! 故障码，以十六进制数形式显示

    //! 尾门控制状态反馈*/
    quint8   tailGatePutAwayState;   //! 尾门收放机构状态, 00-停止； 01-收回中； 10-放下中
    quint8   tailGateLockState;     //! 尾门锁紧机构状态, 0-停止； 01-锁紧中； 10-解锁中

    //! 无人机夹紧机构控制状态反馈*/
    quint8   airClampSystemState;   //! 无人机夹紧机构状态  00-停止； 01-夹紧中； 10-松开中

    unsigned char jmzhsh_stat;      //! 静默值守状态反馈：0-非静默值守状态， 1-静默值守状态（处于静默值守状态时 在解除静默值守状态前不能进行其他操作，不显示其他信息）

    quint16   outlineLampState;     //! 示廓灯状态  0-未打开； 1-已打开
    quint16   dippedHeadlightState; //! 大灯近光状态 0-未打开；1-已打开
    quint16   highBeamState;        //! 大灯远光状态 0-未打开；1-已打开
    quint16   turnLigtState;        //! 转向灯状态 00-未打开； 01-右转亮； 10-左转亮； 11-双闪
    quint16   turretPowerUpState;   //! 炮塔上电状态 0-未上电， 1-已上电；
    quint16   inertialPowerUpState; //! 惯导上电状态 0-未上电， 1-已上电；
    quint16   imageRadioPowerUpState;//! 图像电台上电状态  0-未上电， 1-已上电；
    quint16   laserRadarPowerUpState;//! 激光雷达上电状态  0-未上电， 1-已上电；
    quint16   navigationComputerPowerUpState;//!导航计算机上电状态  0-未上电， 1-已上电；

    float current_velocity;          //! 当前速度，值域：0.0~100.0，单位：m/s

    unsigned char current_jsms;	     //! 当前驾驶模式，值域三位二进制数，000-待机、001-紧急停车、010-近程遥控、
                                     //! 011-人工驾驶、100-无人就绪、101-自主驾驶、110-远程遥控、111-人工干预
    unsigned char dlms;              //! 动力模式，0-纯电动模式，1-混合动力模式
    unsigned int volt;               //! 高压电压，值域：0~500，单位是V，精度：1
    unsigned int oil ;               //! 剩余油量，值域：0~100，单位是L，精度：1
    unsigned int soc;                //! 电池soc，值域：0~100,单位：%，精度1
    int battery_amper;               //! 高压电池电流,-500~500,单位：A，精度：1
    int generator_amper;             //! 发电机电流,-500~500,单位：A，精度：1
    unsigned char current_gear;      //! 当前档位，00H-空档、01H-前进、02H-倒退,、03H-中心转向
    unsigned int engine_rpm;         //! 发动机转速，值域:0~4000，单位:rpm，精度：1
    double current_curvature;        //! 当前曲率，值域-∞~+∞，单位是1/m，满足右手规则
    unsigned char current_park;      //! 当前驻车制动状态，值域，00H-无驻车制动、01H-驻车制动;  预留，不使用。

    quint16 faultLevel;              //! 设备：整车故障,0~4级；定义：00-1级故障，01-2级故障，10-3级故障，11-4级故障；
    quint16 busOneWaring;            //! 设备：总线1告警；定义：0表示无告警，1表示告警；
    quint16 busTwoWaring;            //! 设备：总线2告警；定义：0表示无告警，1表示告警；
    quint16 brakingSystemWaring;     //! 设备：制动系告警；定义：0表示无告警，1表示告警；
    quint16 steeringSystemWaring;    //! 设备：转向系告警；定义：0表示无告警，1表示告警；
    quint16 mixturePowerWaring;      //! 设备：混合动力系告；定义：0表示无告警，1表示告警；
    quint16 shortRangeRemoteControlWaring;//! 设备：近程遥控状态告警；定义：0表示无告警，1表示告警；
    quint16 driverMotorWaring;       //! 设备：驱动电机告警；定义：0表示无告警，1表示告警；
    quint16 collingFanWaring;        //! 设备：散热风扇告警； 定义：0表示无告警，1表示告警；
    quint16 DC_DC_Waring;            //! 设备：DC/DC告警；定义：0表示无告警，1表示告警；
    quint16 fireAlarm;               //! 设备：火警；定义：0表示无告警，1表示告警；
    unsigned char need_jmzhsh_cmd;   //! revised by shfli 20190617

#endif



    unsigned int czkz_stat;

    unsigned char cz_Enable_Sts;  /// 3、液压系统控制使能，0：未使能，1：已使能
    unsigned char cz_Work_Sts;    /// 4、液压动力单元状态，0：等待，1：运行
    unsigned char cz_Work_Mode;   /// 5、车姿调节模式，0：手动，1：自动

    float cz_oil_pressure;         /// 6、车姿油液压力，值域，0~510，单位0.1Mpa，精度：0.1，显示0.0-51.9MPa  精度：0.2，物理范围：0-51MPa（40）
    unsigned int cz_left1_dis;     /// 7、左1距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_left2_dis;     /// 8、左2距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_left3_dis;     /// 9、左3距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_left4_dis;     /// 10、左3距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_right1_dis;    /// 11、右1距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_right2_dis;    /// 12、右2距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_right3_dis;    /// 13、右3距地高,值域，0~1023，单位：无，精度：1
    unsigned int cz_right4_dis;    /// 14、右3距地高,值域，0~1023，单位：无，精度：1
    unsigned char cz_diag;         /// 15、故障码，以十六进制数形式显示
    unsigned int cz_dy;            /// 16、车姿油源电机电压
    unsigned char jmzhsh_stat;     /// 17、静默值守状态反馈：0-非静默值守状态， 1-静默值守状态（处于静默值守状态时 在解除静默值守状态前不能进行其他操作，不显示其他信息）
    unsigned char need_jmzhsh_stat;//revised by shfli 20190617（轮式）---疑问？？？？？？？？？？？为啥有cmd

    quint16   generatorControllerState;       //! 设备：发电机控制器；定义：1表示开启，0表示关闭；
    quint16   decisionPerceptionComputers; //! 设备：决策与感知计算机；定义：1表示开启，0表示关闭；
    quint16   remoteDriverState;      //! 遥控驾驶上电状态  0-未上电， 1-已上电；
    quint16   autonomous_12V_state;   //! 自主驾驶12V上电状态  0-未上电， 1-已上电；
    quint16   imageRadioPowerUpState;//! 图像电台上电状态  0-未上电， 1-已上电；
    quint16   inertialPowerUpState; //! 惯导上电状态 0-未上电， 1-已上电；
    quint16   emergence_switch;     //! 车体急停开关状态 0-未上电， 1-已上电；
    quint16   high_battery_switch_onoff;   //! 高压开关状态 0-未上电， 1-已上电；
    quint16   cz_control;           //! 车姿控制器上电状态 0-未上电， 1-已上电；
    quint16   highBeamState;        //! 大灯远光状态 0-未打开；1-已打开
    quint16   dippedHeadlightState; //! 大灯近光状态 0-未打开；1-已打开
    quint16   outlineLampState;     //! 示廓灯状态  0-未打开； 1-已打开



    ///------------------------ 车姿控制状态反馈-----------------------------------///
    float L1_Oil_Pump_Pressure;///19、左1
    float L2_Oil_Pump_Pressure;///20、左2
    float L3_Oil_Pump_Pressure;///21、左3
    float L4_Oil_Pump_Pressure;///22、左4
    float R1_Oil_Pump_Pressure;///23、右1
    float R2_Oil_Pump_Pressure;///24、右2
    float R3_Oil_Pump_Pressure;///25、右3
    float R4_Oil_Pump_Pressure;///26、右4

    float Total_Pressure;///27、油压
    unsigned char Oil_Position_Alarm;///29、
    unsigned char Oil_Filter_Alarm;///30、
    float Temperature_Sensor;///31、
    float Oil_Position_Sensor;///32、

    float current_velocity;/// 33、当前速度，值域：0.0~100.0，单位：km/h
    float current_dpxs;/// 34、当前实际限速，值域：0.0~100.0，单位：m/s
    double current_curvature;///35、当前曲率（履带），值域-∞~+∞，单位是1/m，满足右手规则
    unsigned char current_gear;///49、当前档位，值域，00H-空档、01H-前进档、02H-倒档、03H-中心转向(履带)
    unsigned char current_park;/// 当前驻车制动状态，值域，00H-无驻车制动、01H-驻车制动;  预留，不使用。
    unsigned char current_jsms;///38、当前驾驶模式，值域三位二进制数，000-待机、001-紧急停车、010-近程遥控、011-人工驾驶、100-自主驾驶、101-远程遥控、110-人工干预
    unsigned char current_MotorSts;/// 39、当前电机状态，值域，00H-待机模式、01H-正常运行（转矩模式）、02H-正常运行（转速模式）、03H-故障停止
    bool current_dlms;///40、   0纯电动,1混合动力
    float Total_Miles;///总里程，精度1km
    float One_Miles;///单次里程，精度0.1km

    unsigned char high_battery_onoff;/// 36、高压状态，0-高压未上电，1-高压已上电 BMS
    unsigned char cHVDeviceSwitchSts;///37、高压设备用电状态 00=高压设备没有上电 01=高压设备上电正常 10=高压供电短路保护

    float hybrid_water_temperature;/// 混合动力冷却水水温，单位是℃（轮式）
    float oil;/// 43、剩余油量，值域：0~100，单位是L
    float soc;/// 42、电池电量（轮式），值域：0-100，单位%

    float volt;/// 41、高压电压，值域：0~600，单位是V
    float battery_amper_H;/// 49、高压电池电流,-500~500,单位：A
    float battery_volt_H; /// 动力母线电压,（从高压配电盒采集此数据），0~500,单位：V
    unsigned char cLow_Volt_Battery_Sts;///50、低压电池状态
    float Low_Volt;///51、低压电压
    float Low_amper;///52、低压电流
    float battery_temperature;///53、动力电池温度，单位是℃

    //===发动机
    float current_water_temperature;///44、发动机水温，单位是℃
    float current_ISGCTRLer_temperature;///45、发电机控制器温度，单位是℃
    float current_engine_oil_pressure;///48、发动机机油压力（履带），单位是Kpa
    unsigned int engine_rpm; /// 发动机转速，值域:-1~4000，单位:rpm，精度：1(-1是初始值)
    float generator_power;///发电功率
    unsigned char EngineOutputPower;/// 发动机输出功率
    unsigned int generator_amper;/// 发电机电流,0~1000,单位：A
    //====驱动电机
    float current_Motor_temperature;///46、驱动电机冷却水温度，单位是℃
    float current_MotorCTRLer_temperature;///47、驱动电机控制器温度，单位是℃
    unsigned int left_motor_rpm;///前（左侧电机转速），值域，0~65535，单位rpm
    unsigned int right_motor_rpm;///后（右侧电机转速），值域，0~65535，单位rpm
    float current_front_brake_pressure;//当前前制动压力（轮式）
    float current_rear_brake_pressure;//当前后制动压力（轮式）

    quint16 faultLevel;              //! 设备：整车故障,0~4级；定义：00-1级故障，01-2级故障，10-3级故障，11-4级故障；
    quint16 busOneWaring;            //! 设备：总线1告警；定义：0表示无告警，1表示告警；
    quint16 busTwoWaring;            //! 设备：总线2告警；定义：0表示无告警，1表示告警；
    quint16 brakingSystemWaring;     //! 设备：制动系告警；定义：0表示无告警，1表示告警；
    quint16 driverMotorWaring;       //! 设备：驱动电机告警；定义：0表示无告警，1表示告警；
    quint16 DC_DC_Waring;            //! 设备：DC/DC告警；定义：0表示无告警，1表示告警；
    quint16 shortRangeRemoteControlWaring;//! 设备：近程遥控状态告警；定义：0表示无告警，1表示告警；
    quint16 steeringSystemWaring;    //! 设备：转向系告警；定义：0表示无告警，1表示告警；
    quint16 collingFanWaring;        //! 设备：散热风扇告警； 定义：0表示无告警，1表示告警；
    quint16 mixturePowerWaring;      //! 设备：混合动力系告；定义：0表示无告警，1表示告警；
    quint16 GPH_fault;               //! 设备：GPH高压配电盒告警（轮式）；
    quint16 powerBatteryFault;      //!  设备：动力电池故障（履带）；
    quint16 driverFanWaring;        //! 驱动风扇故障（履带） 定义：0表示无告警，1表示告警；
    quint16 APU_fault;               //!  设备：APU故障（履带）
    quint16 gerneratorFanWaring;        //! 设备：发动机风扇故障； 定义：0表示无告警，1表示告警；

    unsigned char cHeart201;
    unsigned char cHeart202;
    unsigned char cHeart203;
    unsigned char cHeart204;
    unsigned char cHeart205;
    unsigned char cHeart12F0F012;///28、
}ICD_P_DPZT_STAT_MSG_TRANS;


/** **********************************底盘操作命令**********************************************/
/** 底盘操作命令消息
 * 点击“连接”后，持续发送，点击“断开连接”时停止发送；
 * 服务器断开连接时，若不点击“取消”，仍继续发送。
 * 服务器断开连接时，点“取消”，视同为点击“断开连接”，停止发送。
 * 巡逻车界面切换至警戒监视载荷、小履带车和无人机时，停止发送；切换回巡逻车界面后恢复发送。
 * 底盘操作命令消息中的所有内容只能通过界面操作变更，程序不做自动处理。
*/
typedef struct _ICD_P_DPCZ_CMD_MSG_TRANS
{
    float dpxs;                        //! 底盘限速，值域，0.0～100.0，单位是m/s
    unsigned char dpsn_flag;           //! 底盘使能标志，值域，00H-底盘使能为假、01H-底盘使能为真
    unsigned char gear;                //! 档位命令，值域，00H-空档、 01H-前进档,02H-倒档，03H-中心转向
    unsigned char dlms;                //! 动力模式，值域，00H-纯电动模式，01H-混合动力模式

    unsigned char djms;                //! 电机模式，值域，00H-转矩模式，01H-转速模式
    unsigned char cEnginePower;        //! 发动机发电功率,值域，0-80KW

    unsigned char jmzhsh;              //! 静默值守模式,值域，00H-非值守模式，01H-值守模式   （值守模式后不能进行其他操作，直到启动非值守模式
    unsigned char parking;             //! 驻车命令，值域，00H-无驻车制动，01H-驻车制动，预留，不使用。

    unsigned char czsn;                //! 车姿使能，值域，00H-下使能，01H-上使能
    unsigned char czms;                //! 车姿控制模式（轮式），值域，00H-手动模式，01H-自动模式
    unsigned char czgysd;              //! 车姿高压上电命令（轮式），值域，00H-高压下电，01H-高压上电

    quint16 generatorController;       //! 设备：发电机控制器；定义：1表示开启，0表示关闭；
    quint16 vehicleAttitudeController; //! 设备：车姿控制器； 定义：1表示开启，0表示关闭；
    quint16 imageRadio;                //! 设备：电台；定义：1表示开启，0表示关闭；
    quint16 remoteDriving12V;          //! 设备：遥控驾驶12V；定义：1表示开启，0表示关闭；
    quint16 autonomousDriving12V;      //! 设备：自主驾驶12V；定义：1表示开启，0表示关闭；
    quint16 surveillanceCameraAssembly;//! 设备：监视相机组件;定义：1表示开启，0表示关闭；
    quint16 decisionPerceptionComputers; //! 设备：决策与感知计算机；定义：1表示开启，0表示关闭；
    quint16 inertialNavigation;        //! 设备：惯导；定义：1表示开启，0表示关闭；
    quint16 trumpet;                   //! 设备：喇叭；定义：1表示开启，0表示关闭；
    quint16 outlineMarkerLamps;        //! 设备：示廓灯；定义：1表示开启，0表示关闭；
    quint16 dippedHeadlight;           //! 设备：近光灯；定义：1表示开启，0表示关闭；
    quint16 highBeam;                  //! 设备：远光灯；定义：1表示开启，0表示关闭；

    quint16 vehicleAttitudeManualRightThree;//! 设备：手动右3调节指令; 定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualRightTwo;//! 设备：手动右2调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualRightOne;//! 设备：手动右1调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualLeftThree;//! 设备：手动左3调节指令; 定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualLeftTwo;//! 设备：手动左2调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualLeftOne;//! 设备：手动左1调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
    quint16 vehicleAttitudeManualBackWheel;  //! 设备：手动后轴提轮；定义：1-提轮，0-停止；
    quint16 vehicleAttitudeManualMiddleWheel;//! 设备：手动中轴提轮；定义：1-提轮，0-停止；
    quint16 vehicleAttitudeManualFrontWheel; //! 设备：手动前轴提轮；定义：1-提轮，0-停止；
    quint16 vehicleAttitudeManualSpringLatching;//! 设备：手动弹簧闭锁；定义：1-手动弹簧闭锁，0-开锁；

    /** 自动调节命令，值域，(注:发送0x01至0x11的命令时，按一下按钮发送10次（约1秒钟），后自动改为发送0x00等待命令。无操作时均发送等待命令)
                0x00-等待、
                0x01-稳升、
                0x02-高位、
                0x03-中位、
                0x04-低位、
                0x05-自动提轮、
                0x06-自动弹簧闭锁、
                0x07-自动中心转向状态、
                0x08-前倾、
                0x09-后仰、
                0x0a-左倾、
                0x0b-右倾、
                0x11-终止当前动作*/
    unsigned int czkz_auto_cmd;

    unsigned char OilPumpCmd;/// 16 油缸动作指令，值域，00H-等待，01H-缩短，02H-伸长

    quint8     oilPumpSelectLeftOne;           //! 设备：油缸伸缩选择-左1 定义：1＝选中；0=未选中
    quint8     oilPumpSelectLeftTwo;           //! 设备：油缸伸缩选择-左2 定义：1＝选中；0=未选中
    quint8     oilPumpSelectLeftThree;         //! 设备：油缸伸缩选择-左3 定义：1＝选中；0=未选中
    quint8     oilPumpSelectRightOne;          //! 设备：油缸伸缩选择-右1 定义：1＝选中；0=未选中
    quint8     oilPumpSelectRightTwo;          //! 设备：油缸伸缩选择-右2 定义：1＝选中；0=未选中
    quint8     oilPumpSelectRightThree;        //! 设备：油缸伸缩选择-右3 定义：1＝选中；0=未选中

    /** 底盘考核越野特殊车姿控制命令
        0 standby ;1 Center turn;2 Climb;3 trench;4 wall;5 stop;
        0 等待 01自动调节至中心转向车姿 02自动调节至爬陡坡车姿 03自动调节至越壕沟车姿 04自动调节至爬垂直墙车姿 05停止
        */
    unsigned char czkz_tsms_cmd;

    unsigned char cross;                 //! 19 垂直墙模式，值域，00H-正常模式，01H-垂直墙模式
}ICD_P_DPCZ_CMD_MSG_TRANS;



typedef   struct  _ICD_P_YCKZ_INFO_MSG_TRANS
{
    ///坐标装订状态位; 默认0表示不使能，驾驶操控发送一次,加1,0-255循环,发一次加1。以下标志位作用类同
    ///
    unsigned char zbzd_flag;
    int lon;///经度×1000000
    int lat;///纬度×1000000
    int height;
    int heading;

    unsigned char navigation_flag;    ///导航模式;默认0,驾驶操控发送一次,加1,0-255循环,发一次加1
    int navigationMode;   // 0 星网宇达；1 无卫星航迹推算；2融合输出模式；3 导控所

    unsigned char positiveObs_flag; ///正障碍; 默认0，驾驶操控发送一次,加一,0-255循环,发一次加一
    int positiveObs_enable;	       // 1 表示触发正障碍避障模式 ，0 表示非正障碍物避障模式，下同，默认0

    unsigned char negativeObs_flag;///负障碍
    int negativeObs_enable;         //默认0,非负障碍模式；1表示触发负障碍模式

    unsigned char dynamicObs_flag;///动态障碍
    int dynamicObs_enable;          //默认0,无动态障碍物; 表示进入动态障碍物区域

    unsigned char replan_flag;///重规划
    int replan_enable;          //默认0,正常行车模式; 1表示进入重规划区域

    unsigned char verticalWall_flag;///垂直墙
    int verticalWall_enable;        //默认0,正常路段; 1表示进入垂直墙区域

    unsigned char trench_flag;///濠沟
    int trench_enable;          //默认0,非濠沟模式; 1表示进入濠沟模式

    unsigned char reconnoitre_flag;///侦查区
    int reconnoitre_enable;         //默认0,非侦查区;1表示进入侦查区

    unsigned char patrol_flag;///沿途寻线
    int patrol_enable;    // 默认0，非巡线点。1表示巡线侦查起点；2表示巡线侦查终点


    unsigned char slowdownPts_flag;	///默认0，驾驶操控发送一次减速点,加一,0-255循环,发一次加一
    // 减速点队列 参考JSCK发给GHGZ的路点序列格式 经度，纬度，attribute赋值2表示减速点

    QVector<globalPoseMidCar>   slowdownPts;

    unsigned char task_property; // 默认0, 静态目标0x01;动态目标0x02;行为识别0x03;
    double target_longtitude;//原始经度
    double target_latitude;//原始纬度
    unsigned char task_confirmation_flag;//默认0,功能开始确认0x01;功能完成确认0x10;
    unsigned char platform_small_state;//默认0,小平台开始0x01;小平台搜寻完成0x10;
    unsigned char UAV_state;//默认0;无人机起飞状态0x01;无人机降落完成0x10
    unsigned char full_function_done_flag;//初始化0x00,全功能完成0x01，无人车前往终点

    ///预留
    unsigned char tpr1;
    unsigned char tpr2;
    int reserve1;
    int reserve2;
    int reserve3;
    int reserve4;
    double temp1;
    double temp2;
    double temp3;
    double temp4;
}ICD_P_YCKZ_INFO_MSG_TRANS;

//! ***********************************驾驶操控心跳消息*******************************************/
//! 驾驶操控心跳消息*/
typedef struct _ICD_P_JSCK_HEART_INFO_MSG_TRANS
{
    double time_label;                //! 时间戳
}ICD_P_JSCK_HEART_INFO_MSG_TRANS;

//! ***********************************car  driver para  link widget*******************************************/
typedef  struct  _DriverWidgetPara{
    qint8   directionalDeflection; //! 方向转向量
    qint8   brake;                 //! 刹车
    qint8   accelerograph;         //! 油门
    qint16  speed;
}DriverWidgetPara;

typedef  struct  _StatusParaWidget{
    int     driverMode;
    float   limitSpeed;
    float   planLimitSpeed;
    int     powerMode;
}StatusParaWidget;

typedef struct _ICD_P_RWZT_INFO_CAR_MSG_TRANS{
    int heart_beat;                          //! 心跳信号 从0开始，每发一次加一
    int task_excu_num;                       //! 任务执行次数（预留，判断任务是否重复执行）
    int task_num;                            //! 任务号 整个任务的序号，由操控软件下发；自主软件原值返回
    int Pos_id;                              //! 位置序列号 0-第一个点;1-第二个点;  .... ;n- 第n+1个点
    unsigned char attribute;                 //! 任务属性，同路网文件
                                             //! 0表示起点
                                             //! 1表示终点
                                             //! 2表示必经点
                                             //! 3表示定点侦察任务点
                                             //! 4表示定点打击任务点
                                             //! 5表示机动打击入口点
                                             //! 6表示机动打击出口点
                                             //! 7表示砾石路
                                             //! 8表示涉水路
                                             //! 9表示壕沟
                                             //! 10表示弹坑
                                             //! 11表示凸台
                                             //! 12表示S路段
                                             //! 13表示队形变换点*/
    unsigned char task_status;               //! 任务执行状态
                                             //! 0-正在前往
                                             //! 1-到达任务点开始任务
                                             //! 2-任务执行中
                                             //! 3-任务完成
                                             //! 4-任务超时
                                             //! 5---*/
    unsigned char zhzt_reply;                //! 定点侦查点与定点打击点任务完成信号收到时置1，未收到时置0。
                                             //! 置1后，到达下一个任务点时间内置0*/
    int           reserve1;                  //! 保留位1
    int           reserve2;                  //! 保留位2
    int           reserve3;                  //! 保留位3
    double        reserve4;                  //! 保留位4
    double        reserve5;                  //! 保留位5
    double        reserve6;                  //! 保留位6
    unsigned char reserve7;                  //! 保留位7
    unsigned char reserve8;                  //! 保留位8
    unsigned char reserve9;                  //! 保留位9
}ICD_P_RWZT_INFO_CAR_MSG_TRANS;


//!载荷任务完成情况反馈 操控端下发给自主软件
typedef struct _ICD_P_ZHZT_INFO_CAR_MSG_TRANS{
    int heart_beat;                          //! 心跳信号
    int task_excu_num;                       //! 任务执行次数（预留，判断任务是否重复执行）
    int task_num;                            //! 任务号
    int Pos_id;                              //! 位置序列号 0-第一个点;1-第二个点;  .... ;n- 第n+1个点
    unsigned char attribute;                 //! 任务属性，同路网文件
                                             //! *0表示起点
                                             //! *1表示终点
                                             //! *2表示必经点
                                             //! *3表示定点侦察任务点
                                             //! *4表示定点打击任务点
                                             //! *5表示机动打击入口点
                                             //! *6表示机动打击出口点
                                             //! *7表示砾石路
                                             //! *8表示涉水路
                                             //! *9表示壕沟
                                             //! *10表示弹坑
                                             //! *11表示凸台
                                             //! *12表示S路段
                                             //! *13表示队形变换点*/
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
}ICD_P_ZHZT_INFO_CAR_MSG_TRANS;

//! *********************************** super car 视频控制协议命令*******************************************/
//! 视频控制ack*/
typedef struct _ICD_VIDEO_ACK_TRANS
{
    qint8   Ack;
}ICD_VIDEO_ACK_TRANS;


//! 视频流切换*/
typedef struct _ICD_VIDEO_CHANNEL_TRANS
{
    qint8   VideoChannel;
}ICD_VIDEO_CHANNEL_TRANS;


//! 调节分辨率*/
typedef struct _ICD_VIDEO_ADJUST_RESOLUTION_TRANS
{
    quint16 x;
    quint16 y;
    quint16 crop_width;
    quint16 crop_height;             //! (x, y)为裁剪起始点，如0x00000000_05000320表示从(0, 0)开始裁剪1280x800大小的图像
    quint16 scale_width;
    quint16 scale_height;            //! scale_width为前两个字节，scale_height为后两个字节，均为无符号整数。如0x0A000320表示分辨率设置为2560x800。
}ICD_VIDEO_ADJUST_RESOLUTION_TRANS;


//! 调节码率*/
typedef struct _ICD_VIDEO_ADJUST_CODE_RATE_TRANS
{
    qint8   controlMode;
    qint32  codeRate;
}ICD_VIDEO_ADJUST_CODE_RATE_TRANS;


//! 调节帧率*/
typedef struct _ICD_VIDEO_ADJUST_FRAM_RATE_TRANS
{
    qint8   FPS;
}ICD_VIDEO_ADJUST_FRAM_RATE_TRANS;


//! 调节播放控制*/
typedef struct _ICD_VIDEO_PLAY_CONTROL_TRANS
{
    qint8   playControl;
    qint8   ipFistWord;
    qint8   ipSecondWord;
    qint8   ipThreeWord;
    qint8   ipFourWord;
    qint16  port;
}ICD_VIDEO_PLAY_CONTROL_TRANS;

typedef   struct _rockerMomentCOntrolDataTrnas{
    qint16   momentControlData;              //! 方向转向量
}rockerMomentControlDataTrnas;

//! 管理者信息
typedef struct _AdminInfo{
    QString adminName;
    QString adminPassWord;
}AdminInfo;

/** ******************************************************************************
 *
 *  操作杆数据翻译
 *
 *********************************************************************************/
typedef struct _ActionBarsSerialPortPacketTrans
{
    qint8    head;
    qint8    left_rightangellow;           //! 左右角度低字节*/
    qint8    left_rightangelheight;        //! 左右角度高子节*/
    qint8    up_downangellow;              //! 上下角度低字节*/
    qint8    up_downangelheight;           //! 上下角度高子节*/
                                           //! 控制开关:每一位表示一个开关量，开关闭合为 1，断开为 0， 其
                                           //! 中启动、熄火、喇叭、锁定为自复位开关，前进、倒退、
                                           //! 中心转向为两位开关。
                                           //!
    qint8    trumpSwitch;                  //! 按键信号字节 b0:开关 S1:喇叭(打击模式, 测距)*/
    qint8    centerTurn;                   //! b1:开关 S2: 中心转向*/
    qint8    forword;                      //! b2:开关 S3: 前进*/
    qint8    engineMisses;                 //! b3:开关 S4: 发动机熄火， S4 和 S5 同是 0 或 1，表示动力*/
    qint8    engineStart;                  //! b4:开关 S5: 发动机启动(打击模式,击发)*/
    qint8    backword;                     //! b5:开关 S6：倒退*/
    qint8    topSwitch;                    //! b6:开关 S7：顶部开关:大灯,近光灯双闪控制*/
    qint8    securityKey;                  //! b7:开关 S8：安全键,用于锁定和解锁*/

    qint8    workstate;                    //! 工作状态*/
    qint8    checkcode;                    //! 校验码*/
    qint8    end;                          //! 结束标志*/
}ActionBarsSerialPortPacketTrans;


/** ***********************Communication between driving control software and ocu*****************************/
//! Definition rules for msgID
typedef struct _OcuToControlMsgIDTrans{
    quint8      infoType;                  //! 1- Receive information; 2- send information*/
    quint8      vehicleNumber;             //! 10- Default vehicle; 11-ZC car; 12-DJ car; 13-XL car; 14-YS car*/
    quint8      mobilePlatform;            //! 30-default platform; 31-Universal Mobile Platform*/
    quint8      msgFlag;                   //! 40-default load; 42-ZC guide load; 43-HLDJ payload; 50-default communication;60-default protection; 70-empty*/
                                           //! For example: 1113171, namely receiving 1, ZC car 11, general mobile platform 31, message identification 71;
                                           //! 2113171, which is to issue 2, ZC car 11, general mobile platform 31, message identification 71;*/
}OcuToControlMsgIDTrans;


//! Data header definition*/
typedef struct _OcuToControlFrameHeadTrans{
    OcuToControlMsgIDTrans     msgID;      //! Distinguish between different commands and messages
    QDateTime                  timeStamp;  //! current tim(Structure day-hour-minute-second)
}OcuToControlFrameHeadTrans;


/** control software report information
  *Mobile platform status
  */
typedef struct _MobilePlatStatusTrans{
    OcuToControlFrameHeadTrans frameHead;   //!Message ID 1113171
                                            //! Message length 79 (104 in the original document, please confirm)*/
    quint8 platformHealth;                  //! 0x01-normal; 0x02-fault*/
    quint8 communicationStatus;             //! 0x01-normal; 0x02-disconnection*/
    quint8 taskStatus;                      //! 0x01-executing; 0x02-Pause;0x03 not executed*/
    quint8 controlMode;                     //! 0x01-Autonomous mode; 0x02-Remote control mode*/
    quint8 powerMode;                       //! 0x01-hybrid; 0x02 pure electric*/
    quint8 parkingState;                    //! 0x01-parking; 0x02-No parking*/
    quint8 currentGear;                     //! 0x01-forward gear;0x02-Neutral; 0x03-reverse gear*/
    quint8 vehicleHeightStatus;             //! 0x01-mid position; 0x02-low bit;0x03-high*/
    quint8 steeringMode;                    //! 0x01-forward steering; 0x02-rear steering; 0x03-full steering*/
    qint16 oilVolume;                       //! Value range is 0～100, scale is 1, factor=1, offset=0*/
    qint16 electricVolume;                  //! Value range is 0～100, scale is 1, factor=1, offset=0*/
    qint32 hybridDrivingRange;              //! Value range is 0～500000, scale is 1m, factor=1, offset=0*/
    qint32 pureElectricDrivingRange;        //! Value range is 0～500000, scale is 1m, factor=1, offset=0*/
    double longitude;                       //! Scale 0.0000001 degrees, range -180~180 degrees factor=0.0000001 offset=0*/
    double latitude;                        //! Scale 0.0000001 degrees, range -90~90 degrees factor=0.0000001 offset=0*/
    float  elevation;                       //! Scale 0.1m, range -100000~100000 degrees factor=0.1 offset=0*/
    float  globalCoord_X_north;             //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    float  globalCoord_Y_east;              //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    float  globalCoordHeight_H;             //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    float  global_X_axisEastSpeed;          //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    float  global_Y_axisNorthSpeed;         //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    float  global_H_axisSpeed;              //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    float  heading;                         //! The value range is 0～36000, the angle scale is 0.01°, factor=0.01, offset=0*/
    float  pitchAngle;                      //! Value range -9000～9000, angle scale is 0.01°, factor=0.01, offset=0*/
    float  rollAngle;                       //! Value range -9000～9000, angle scale is 0.01°, factor=0.01, offset=0*/
    float  headingSpeed;                    //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
    float  pitchAngleSpeed;                 //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
    float  rollAngleSpeed;                  //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
}MobilePlatStatusTrans;


/** control software report information
 * Platform environment awareness status (reserved and not uploaded)
 */
typedef struct _PlatEnvirStatusTrans{
    OcuToControlFrameHeadTrans  frameHead;  //! *Message ID 1113172
                                            //! Message length 19 (24 in the original document, please confirm)*/
    qint8       roadFeatures;
    qint8       obstacleFeatures;
    qint8       terrainFeatures;
}PlatEnvirStatusTrans;


//! The struct is just a data frame header*/
typedef struct _CarActionTrans{
    OcuToControlFrameHeadTrans  frameHead;  //! msgID:2113171 Pause the current action
                                            //! 2113172 Continue the current action temporarily
                                            //! 2113173 Terminate current action
                                            //! 2113176 Stop + action after parking
}CarActionTrans;


//! The structure is a data frame header and a byte*/
typedef struct _CarControlTrans{
    OcuToControlFrameHeadTrans   frameHead; //! msgID:2113178 Lifting body
                                            //! 2113179 Power switch
                                            //! 2113181 self-destruct and self-destruct
    qint8  dataOne;
}CarControlTrans;


typedef struct _TurnInPlaceTrans{
    OcuToControlFrameHeadTrans   frameHead; //! msgID:2113177*/
    float               turnAngle;          //! The value range is 0～36000, the angle scale is 0.01°, factor=0.01, offset=0*/
    qint8               turnMode;           //! 0x01-forward steering; 0x02-rear steering; 0x03-full steering*/
}TurnInPlaceTrans;


typedef struct _VerticalAndFormationFollowTrans{
    OcuToControlFrameHeadTrans  frameHead;  //! msgID:2113180*/
    quint8  powerMode;
    float   followDistance;                 //! Range 0-200 meters, scale 1 meter, factor=0.01, offset=0*/
}VerticalAndFormationFollowTrans;


//! Conventional maneuver instructions*/
typedef struct _ConventionalManeuverTrans{
    OcuToControlFrameHeadTrans frameHead;   //! *msgID:2113174*/
    qint8    powerMode;                     //! *0x01-hybrid 0x02-pure electric*/
    float    referenceSpeed;                //! *Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0;*/
    qint16   keyPointNum;                   //! *Value 0-10000*/
    QVector<KeyPointInfoTrans> keyPointInfo;
}ConventionalManeuverTrans;


/*many task point message*/
typedef struct _ManyTaskPointTrans{
    OcuToControlFrameHeadTrans  frameHead; //! *msgID:2113175*/
    qint16   maxInterval;                  //! *Unit: second*/
    qint16   keyPointNum;                  //! *Value 0-10000*/
    QVector<KeyPointInfoTrans>  keyPointInfo;
}ManyTaskPointTrans;


typedef struct _ControlMsgData{
    int                 num;              //!任务序号
    QDateTime           time;             //!当前时间
    ControlMsgType      type;             //!任务类型
    int                 status;           //!任务状态 0-未执行；1-已执行
    KeyPointInfoTrans   point;            //!类型为常规机动指令和多任务点指令才保存点
}ControlMsgData;



//! yx
//! **************************************The alert monitor******************************************/
//! *****************ocu send information to the alert monitor*****************/
//!自主参数设置报文
typedef struct _DC_IC_01Trans{
    quint8   autoWorkMode;                      //! 自主工作模式;0x01: 巡线侦察监视;0x02: 定点侦察监视告警;0x03: 定点侦打一体
    quint16  targetDistance;                    //! 目标大致距离; 米
    qint16   targetPitchRange;                  //! 目标俯仰角范围;量纲90°/32768,范围（-90°-90°）
    quint16  scanPosition;                      //! 扫描方位;【A,B】°（默认为周扫）（0°~360°）360/65536
    qint16   scanRange;                         //! 扫描左极限=扫描方位-扫描范围/2;扫描右极限=扫描方位+扫描范围/2
    quint8   loadImagingSensor;                 //! 载荷成像传感器选择;0x01 红外;0x02 电视
    quint8   autoTracking;                      //! 是否自动跟踪;0x01 非自动跟踪;0x02 自动跟踪
    quint8   autoRanging;                       //! 是否自动测距;0x01 非自动测距;0x02 自动测距
}DC_IC_01Trans;


//! 自主工作开始/结束控制
typedef struct _DC_IC_02Trans{
    quint8      autoWorkMode;                    //!0x01: 开始自主工作（光电自主）;0x02: 停止自主工作（待命状态）
}DC_IC_02Trans;


//! 允许打击（非致命武器）指令
typedef struct _DC_IC_03Trans{
    quint8      autoWorkMode;                    //!0x01: 不允许自动打击（非致命武器）;0x02: 允许自动打击（非致命武器）
}DC_IC_03Trans;


//! 允许打击（致命武器）指令
typedef struct _DC_IC_04Trans{
    quint8      autoWorkMode;                    //!0x01: 不允许自动打击（致命武器）;0x02: 允许自动打击（致命武器）
}DC_IC_04Trans;


//!****************the alert monitor send information to ocu*****************/
//!打击请求报文
typedef struct _IC_DC_01Trans{
    quint8      msgID;                            //!0x9A
}IC_DC_01Trans;


//!光电状态上报报文
typedef struct _IC_DC_02Trans{
    quint8      equipWorkMode;                     //!设备工作模式;0x00 值更;0x01 搜索;0x02 跟踪;0x03 拒止
    quint16     photoelectricAzimuth;              //!光电方位角;量纲360°/65536，范围（0-360°）（大地坐标系）
    qint16      photoelectricPitchAngle;           //!光电俯仰角;量纲360°/65536,范围（-90°-90°）
    quint16     weaponAzimuth;                     //!武器方位角;量纲360°/65536，范围（0-360°）
    qint16      weaponPitchAngle;                  //!武器俯仰角;量纲360°/65536,范围（-90°-90°）
    qint16      strongPitchAngle;                  //!强声俯仰角度;量纲360°/65536,范围（-90°-90°）
    quint16     azimuthInertialAngle;              //!惯性方位角惯导角;量纲360°/65536，范围（0-360°）
    qint16      pitchAngleInertialAngle;           //!惯性俯仰角惯导角;量纲360°/65536,范围（-90°-90°）
    quint16     rangDistance;                      //!测距距离;M(100~6000m)
    quint8      currentChannel;                    //!当前通道;0x02  红外;0x01  电视（默认）
    quint8      infraredFocalLength;               //!红外焦距;红外通道短焦 0x01;红外通道长焦 0x02
    float       TVFieldView;                       //!电视视场;量纲0.1°，范围（0-3600）
    quint8      powerState;                        //!健康状态;0x00 ：正常;0x01 ：异常
}IC_DC_02Trans;


typedef struct _TargetInfoTrans{
    quint16     num;                               //! 批次号
    float       longitude;
    float       latitude;
    float       height;
    quint8      type;                              //!0x01轻质装甲;0x02重型装甲;0x03 无人机 ;0x04 直升机;0x05武装人员;0x06卡车;0x07汽车
    quint8      confidence;                        //!0-100
    quint8      threatLevel;                       //!1-5（1为最高等级）
    quint8      alertSign;                         //!0x01:告警；0x10:不告警
}TargetInfoTrans;


//! Report message of detection and recognition results
typedef struct _AI_DC_O1Trans{
    quint16                      targetNum;
    QVector<TargetInfoTrans>     targetInfo;
}AI_DC_O1Trans;


//!*************************************************************************************************//
//! 电台链路质量
typedef struct _RadioLinkQualityTrans
{
    qint8 nodeOne;
    qint8 nodeOneQuality;
    qint8 nodeTwo;
    qint8 nodeTwoQuality;
    qint8 nodeThree;
    qint8 nodeThreeQuality;
    qint8 nodeFour;
    qint8 nodeFourQuality;
}RadioLinkQualityTrans;



//! *************************************************警戒监视模块向遥控端发送的信息报文**********************************
//! 上报设备状态报文	   报文标识 61H

typedef struct _DeviceStatusTrans
{
    quint8    equWorkMode;            //! 设备工作模式 0x00 值更 0x01 搜索 0x02 跟踪 0x03 拒止
    quint16   photoelectricAzimuth;   //! 光电方位角 量纲360°/65536，范围（0-360°）
    qint16    photoelectricPitch;     //! 光电俯仰角 量纲90°/32768,范围（-90°-90°）
    quint16   weaponAzimuth;          //! 武器方位角 量纲360°/65536，范围（0-360°）
    qint16    weaponPitch;            //! 武器俯仰角 量纲90°/32768,范围（-90°-90°）
    qint16    strongPitchAngle;       //! 强声俯仰角度 量纲360°/65536,范围（-90°-90°）
    quint16   pheInertiaAzimuth;      //! 光电惯性方位角 量纲360°/65536，范围（0-360°）
    qint16    pheInertiaPitch;        //! 光电惯性俯仰角 量纲360°/65536,范围（-90°-90°）
    quint16   distance;               //! 测距距离  M
    qint16    missX;                  //! X轴脱靶量  -960~960
    qint16    missY;                  //! Y轴脱靶量  -540~540
    quint8    currentChannel;         //! 当前通道 0x01  红外    0x02  电视（默认）
    quint8    infraredFocalLength;    //! 红外焦距 红外通道短焦 0x01; 红外通道长焦 0x02
    float     TVview;                 //! 电视视场 量纲0.1°，范围（0-360）

    //! 电源状态  0－故障， 1－正常
    quint8    low15VPower;              //! 低压15V电源
    quint8    computerPower;            //! 计算机板电源
    quint8    laserPower;               //! 激光测距仪电源
    quint8    infraredPowerSelf;        //! 红外电源自检
    quint8    low5VPower;               //! 低压5V电源
    quint8    servoDriveNeg15VPower;    //! 伺服驱动板-15V电源
    quint8    opticalPower;             //! 光发送板电源
    quint8    gyro5VPower;              //! 陀螺5V电源
    quint8    gyroNeg5VPower;           //! 陀螺-5V电源
    quint8    laserDazzlingPower;       //! 激光眩目电源
    quint8    strongLightPower;         //! 强光电源
    quint8    weaponBrakePower;         //! 武器方位俯仰制动器电源
    quint8    strongSoundBrakePower;    //! 强声俯仰制动器电源
    quint8    weaponServoPower;         //! 武器伺服电源

    //! 伺服驱动状态
    quint8    weaponAzimuthServo;       //! 武器方位伺服驱动检测
    quint8    weaponPitchServo;         //! 武器俯仰伺服驱动检测
    quint8    pheAzimuthServo;          //! 光电方位伺服驱动检测
    quint8    phePitchServo;            //! 光电俯仰伺服驱动检测
    quint8    phePitchUpperSwitch;      //! 光电俯仰上限位开关  1到位，0未到
    quint8    phePitchLowerSwitch;      //! 光电俯仰下限位开关  1到位，0未到
    quint8    weaponUpperSwitch;        //! 武器俯仰上限位开关  1到位，0未到
    quint8    weaponLowerSwitch;        //! 武器俯仰下限位开关  1到位，0未到
    quint8    strongVoiceUpperSwitch;   //! 强声俯仰上限位开关   1到位，0未到
    quint8    strongVoiceLowerSwitch;   //! 强声俯仰下限位开关   1到位，0未到
    quint8    phePosStopSwitch;         //! 光电方位止动到位开关
    quint8    phePosBackSwitch;         //! 光电方位回退到位开关
    quint8    phePitchStopSwitch;       //! 光电俯仰止动到位开关
    quint8    phePitchBackSwitch;       //! 光电俯仰回退到位开关

    //! 武器系统状态  0－故障， 1－正常
    quint8    shootBoard;               //! 射击控制板自检
    quint8    gunProhibition;           //! 枪禁射回告
    quint8    impeachment;              //! 弹禁射回告
    quint8    firstLoadBefore;          //! 首发装填前到位
    quint8    firstLoadAfter;           //! 首发装填后到位
    quint8    firstLoadInPlace;         //! 首发装填到位
    quint8    remainingBullets;         //! 余弹计数

    quint16   smallAmmNum;            //! 小口径机枪所剩弹药数量   颗
    qint8     dazzlingLaserAngle;     //! 炫目激光器发散角
    qint16    temperature;            //! 温度
    qint16    humidity;               //! 湿度
    qint16    TvZoomADvalue;          //! 电视变焦AD值
    qint16    TvFocusADvalue;         //! 电视调焦AD值
    qint8     workMode;               //! 工作模式
    quint16   machineGunCor;          //! 机枪俯仰弹道修正 360/65536
    quint16   grenadeCor;             //! 榴弹俯仰弹道修正 360/65536

    qint32    reserved1;              //! 预留位 25个字节  第8字节为喊话驱离开始
    qint16    reserved12;
    qint8     reserved13;
    qint8     leaveAllow;             //! 喊话驱离开始
    quint32   nTagLon;
    quint32   nTagLat;
    qint64    reserved3;
    qint8     reserved4;

}DeviceStatusTrans;


typedef struct _GoalResultInfoTrans
{
    quint16         batchNum;       //! 批号 1001-1999 电视目标; 2001-2999 红外目标; 3001-3999 手动目标
    quint16         azimuth;        //! 目标方位角  量纲360°/65536，范围（0-360°）
    qint16          pitchAngle;     //! 目标俯仰角  量纲90°/32768,范围（-90°-90°）
    quint16         distance;       //! 距离  0-65536
    quint8          type;           //! 目标类型 0x01 坦克; 0x02 车辆; 0x03 车辆; 0x04 人
    quint8          behavior;       //! 目标行为	0x01 攀爬翻越; 0x02 投掷; 0x03 持枪瞄准; 0x04 持械攻击; 0x05 人员快速接近;
                                    //!         0x06 车辆快速接近; 0x07 越界
    quint8          confidence;     //! 置信度	0-100
    quint8          threatLevel;    //! 目标威胁等级  十个等级  0x01-0x0A（最高等级0x01，最低等级0x0A）
}GoalResultInfoTrans;


//! 上报检测识别结果报文	   报文标识 71H
typedef struct _DetectRecognitResultTrans
{
    quint16             goalNum;        //! 目标个数
    QList<GoalResultInfoTrans> info;
}DetectRecognitResultTrans;


typedef struct _GoalDetectInfoTrans
{
    quint16         batchNum;       //! 批号 1001-1999 电视目标; 2001-2999 红外目标; 3001-3999 手动目标
    quint16         azimuth;        //! 目标方位角  量纲360°/65536，范围（0-360°）
    qint16          pitchAngle;     //! 目标俯仰角  量纲90°/32768,范围（-90°-90°）
    quint16         distance;       //! 距离  0-65536
    quint16         leftX;          //! 目标框左上角X  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16         leftY;          //! 目标框左上角Y  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16         rightX;         //! 目标框右上角X  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16         rightY;         //! 目标框右上角Y  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint8          type;           //! 目标类型 0x01 坦克; 0x02 重型卡车; 0x03 小轿车; 0x04 人
    quint8          confidence;     //! 置信度	0-100
}GoalDetectInfoTrans;


//! 上报检测目标列表报文	   报文标识 73H
typedef struct _DetectGoalListTrans
{
    quint16             goalNum;        //! 目标个数
    QList<GoalDetectInfoTrans> info;
}DetectGoalListTrans;


//! 图像信息报文	           报文标识 74H
typedef struct _ImageInforTrans
{
    quint8              videoChannel;       //! 视频通道 0x01 红外; 0x02 电视（默认）
    quint8              imageResolution;    //! 图像分辨率  0：480P；1：D1；2：720P；3：960P；4：1080P; 5：640P
    quint8              imageFrame;         //! 图像帧频	  1到25
    quint8              compression;        //! 图像压缩比  1~100
    quint8              saveImageLogo;      //! 是否保存图像标识 0x00：不保存；0x01：保存
    quint8              subMsgHead;         //! 子报文头	0:0xf1第一个报文; 1:0xf2中间报文; 2:0xf3最后一个报文
    QList<quint8>       imageInfo;          //! 图像信息 N字节	压缩编码后图像
}ImageInforTrans;

/**********************************串口数据,上位机与下位机之间通信的信息********************************/
//系统时间
typedef struct _SystemTimeInfoTrans {
    quint16 year;
    quint8  month;
    quint8  day;
    quint8  hour;
    quint8  minute;
    quint8  second;
} SystemTimeInfoTrans;


//gps字段的16个卫星信息
typedef struct _SatelliteInfoTrans {
    quint8 numbering;      //编号
    quint8 elevateAngle;   //仰角
    quint16 azimuth;       //方位角
    quint8 sigNoiseRatio;  //信噪比
} SatelliteInfoTrans;


//gps字段
typedef struct _GpsInfoTrans {
    quint8 satellitenum;                //卫星数
    SatelliteInfoTrans satellInfo[16];  //16个卫星信息
    SystemTimeInfoTrans time;
    quint32 latitude;                   //纬度
    quint8 north_south;                 //01 N 02 S
    quint32 longitude;                  //经度
    quint8 east_west;
    quint32 altitude;                   //海拔
    quint8 gpsStatus;                   //gps状态
    quint8 positsateNum;                //用于定位的卫星数
    quint8 positsateNumbering[16];      //用于定位的卫星编号
    quint8 locateType;                  //定位类型
    quint32 positlongitFactor;          //位置经度因子
    quint32 HorizlongitFactor;          //水平经度因子
    quint32 vertilongitFactor;          //垂直经度因子
    quint16 groundSpeed;                //地面速度
} GpsInfoTrans;


//加速度字段
typedef struct _AccelerateInfoTrans {
    qint16 x;       //x
    qint16 y;       //y
    qint16 z;       //z
} AccelerateInfoTrans;


//磁力计字段
typedef struct _MagnetometerInfoTrans {
    qint16 x;   //x
    qint16 y;   //y
    qint16 z;   //z
} MagnetometerInfoTrans;


//摇杆值
/* 1、水平方向为x，竖直方向为y
     2、x值为左负右正，y值为下负上正*/
typedef struct _JoystickInfoTrans {
    qint16 x_left;
    qint16 y_left;
    qint16 x_right;
    qint16 y_right;
} JoystickInfoTrans;


/*电池状态*/
typedef struct _BATTERYINFOTrans {
    quint8  percent;        //电量 (0~100)
    quint8  status;         //状态（0：没有充电；1：正在充电）
    quint16 temperature;    //温度
    quint16 remainPower;    //实际功率
    quint16 voltage;        //电压
    quint16 totalPower;     //总功率
} BatteryInfoTrans;


/*终端上的按键值*/
typedef enum{
    Key_None_Value=0,
    Key_Up_Value,
    Key_Down_Value,
    Key_Left_Value,
    Key_Right_Value,
    Key_Enter_Value,        //确认键，左边第一个键
    Key_Cancel_Value,       //取消键，右边第一个键
    Key_Switch_Value,       //切换键，右边第二个键
    Key_Unlock_Value,       //确保键，左边第二个键
    Key_Launch_Value,       //击发键，红色按钮建
    Key_F1_Value,           //后面的,左边的按键
    Key_F2_Value            //后面的,右边的按键
}KeyValue ;


//! ************************************无人机定位定向数据**********************************************/
//! 定位定向信息消息(辅助通道)
//! *
//! *
//! *
//! */
/* alling 定位信息*/
typedef struct _ICD_ALLIGN_DWDX_INFO_MSG_TRANS{
    float longitude;                   //! 基站经度坐标(GPS)，值域，刻度0.000001度,范围-180~180度;
    float latitude;                    //! 基站纬度坐标(GPS)，值域，刻度0.000001度,范围-90~90度;
    int   ilongitude;                   //! 基站经度坐标(GPS)，值域，刻度0.000001度,范围-180~180度;
    int   ilatitude;                    //! 基站纬度坐标(GPS)，值域，刻度0.000001度,范围-90~90度;
    qint32 altitude;                   //! 基站海拔高度，单位cm；
    qint32 easterly_velocity;          //! 基站东向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 northward_velocity;         //! 基站北向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 celestial_velocity;         //! 基站天向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 double_headingangle;        //! 基站双天线航向角，单位0.01deg，北偏东正;
    quint8 positioning_status;         //! 1-定位信息可用 0-定位信息不可用;
    quint8 DF_status;                  //! 1-定位信息可用 0-定位信息不可用;
} ICD_ALLIGN_DWDX_INFO_MSG_TRANS;


/* 区域中心点信息 */
typedef struct _ICD_ALLING_QYZXD_INFO_MSG_TRANS
{
    double static_longitude;                   //! 静态目标区域中心点经度,LSB = 1*10-7
    double static_latitude;                    //! 静态目标区域中心点纬度,LSB = 1*10-7
    double dynamic_longitude;                  //! 动态目标区域中心点经度,LSB = 1*10-7
    double dynamic_latitude;                   //! 动态目标区域中心点纬度,LSB = 1*10-7
}ICD_ALLING_QYZXD_INFO_MSG_TRANS;


/* 侦察目标定位信息 */
typedef struct  _ICD_ALLING_ZCMBDW_INFO_MSG_TRANS
{
    quint8 task;                //! 任务阶段标识  静态：0x11 动态：0x66
    float center_longitude;                   //! 目标区域中心点经度,LSB = 1*10-7
    float center_latitude;                    //! 目标区域中心点纬度,LSB = 1*10-7
}ICD_ALLING_ZCMBDW_INFO_MSG_TRANS;


/* 图片接收 */
typedef struct _ICD_RECV_IMAGE_INFO_MSG_TRANS{
    char contentName[50];            //! 内容名字　忽略即可
    char data[1024*63];                 //! 具体数据,初步定于1400字节
    int datasize;                    //! 数据长度
    int segmentNum;                  //! 包序号，排序用的
    /**
     * 是否为最后一个包
     * 不是：　end = 0
     * 是：　end = 1
     */
    int end;
}ICD_RECV_IMAGE_INFO_MSG_TRANS;



/**
  *
  */
typedef  enum{
    DjxlcOperationMode_Stop,
    DjxlcOperationMode_Autonomous,
    DjxlcOperationMode_Remote_Driver,
    DjxlcOperationMode_Pause,
    DjxlcOperationMode_Guard,
}DjxlcOperationMode;





//! 报文2
typedef struct _OcuToChassisParaTrans
{
    quint8 dlms;                //! 动力模式，值域，00H-纯电动模式，01H-混合动力模式
    quint8 modeSwitch;           /** 操控模式切换 分为6种工况（具体工况待定）：
                                        * 00—停车
                                        * 02—遥控
                                        * 01—自主
                                        * 03—自主侦察
                                        * 04—预留
                                        */
    quint8 chassisSpeedLimit;   /** 底盘限速设定，0~80，单位为km/h，低位在前，高位在后*/
    qint8  rockerHorizontal;    /** 摇杆水平方向值：0~100（左转），0~-100（右转）*/
    qint8  rockerVertical;      /** 摇杆垂直方向值：0~100（向前，油门开度），0~-100（向后，制动量）*/
    quint8 gear;                /** 驱动档位和负载档位(前进档和倒车档各3个，中心转向1个)
                                  * =0：空挡
                                  * =1：前进低档
                                  * =3：前进中档
                                  * =5：前进高档
                                  * =2：后退低档
                                  * =4：后退中档
                                  * =6：后退高档
                                  * =7：中心转向*/

    /** 底盘控制*/
    quint8 batteryControl;        /** 高压电池控制:强电上电（=1）,强电下电（=0）*/
    quint8 emergencyStopButton;   /** 紧急停车按钮:接通（=1）,断开（=0）*/
    quint8 parkingControl;	  /** 驻车控制:驻车（=1）,无驻车（=0）  底盘/输送模块功能切换；底盘（=0）默认发0，过渡托盘摇杆值不输出。输送模块（=1）*/
    quint8 chassisEnableControl;  /** 底盘使能控制：底盘使能（=1），底盘不使能（=0）*/
    quint8 drivePowerUpcontrol;   /** 驱动器 上电控制 0：未上电；1：已上电*/
    quint8 steeringController;    /** 转向控制器上电控制  0：未上电；1：已上电*/
    quint8 weaponPowerUpControl;  /** 武器系统上电控制  0：未上电；1：已上电*/



    /*设备控制+车辆工作模式切换*/
    quint8 autonomicComputerPowerUpControl; /** 自主计算机上电控制(自主驾驶12V） 0：未上电；1：已上电*/
    quint8 LiDAR_PowerUpControl;            /** 激光雷达上电状态 0：未上电；1：已上电*/
    quint8 monocularColorCamera;            /** Bit2：单目彩色相机（监视相机组件） 0：未上电；1：已上电；*/
    quint8 INS_PowerUpControl;              /** 惯导/卫星定位装置上电状态 0：未上电；1：已上电*/
    quint8 soundPickUp;                     /** 拾音器（惯导/卫星定位装置上电控制) 0：未上电；1：已上电  预留1*/
    quint8 singleSoldierCharginginterface;  /** 单兵充电接口 0：未上电；1：已上电  预留1*/
    quint8 videoProccessUnit;               /** 视频处理单元（遥控驾驶12V） 0：未上电；1：已上电*/

    /*辅助控制*/
    quint8 highLampPowerUpControl;          /** 前大灯上电状态 0：未上电；1：已上电*/
    quint8 alertLampPowerUpControl;         /** 双闪灯上电状态 0：未上电；1：已上电*/
    quint8 trumpetPowerUpControl;           /** 喇叭上电状态 0：未上电；1：已上电*/
    quint8 receveCarInfoPowerUpControl;     /** 接收车辆底盘详细信息：开（=1），关（=0）*/

    quint8 dataDestroy;                     /** 数据销毁：0xaa*/

    /*电气管理系统控制*/
    quint8 faultResetControl;               /** 故障复位控制:不复位（=0），复位所有故障（=1）*/
    quint8 guardMaskCommand;                /** 保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/
    quint8 investigationSystemPowerUP;      /** 保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/
    quint8 powerModuleOneSwitchingControl;  /** 保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/
    quint8 powerModuleTwoSwitchingControl;  /** 保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/
    quint8 wholeMachineOnOrOffControl;      /** 保护屏蔽命令:不屏蔽保护（=0）,屏蔽所有保护（=1）*/

}OcuToChassisParaTrans;

}

Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_STATUS_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_CSDQ_CMD_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_CSXG_CMD_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_DZ_CMD_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_ZBZD_CMD_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_ZJ_CMD_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_INIT_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_DWDX_HALT_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_STATUS_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_BDJD_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_HALT_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_INIT_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_XTTC_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_YKJS_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_MIDDLE_CZ_XTJK_ZZJS_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CRAWLER_CZ_XTJK_ZZJS_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_ZZJS_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_COMMON_CZ_XTJK_ZZJS_PLAN_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_CZ_XTJK_NOP_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_YKJS_CMD_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_DWDX_INFO_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_DPZT_STAT_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_DPCZ_CMD_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_YCKZ_INFO_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_JSCK_HEART_INFO_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::DriverWidgetPara)
Q_DECLARE_METATYPE(Qxxlc::StatusParaWidget)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_RWZT_INFO_CAR_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_P_ZHZT_INFO_CAR_MSG_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_ACK_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_CHANNEL_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_ADJUST_RESOLUTION_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_ADJUST_CODE_RATE_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_ADJUST_FRAM_RATE_TRANS)
Q_DECLARE_METATYPE(Qxxlc::ICD_VIDEO_PLAY_CONTROL_TRANS)
Q_DECLARE_METATYPE(Qxxlc::rockerMomentControlDataTrnas)
Q_DECLARE_METATYPE(Qxxlc::AdminInfo)
Q_DECLARE_METATYPE(Qxxlc::ActionBarsSerialPortPacketTrans)
Q_DECLARE_METATYPE(Qxxlc::OcuToControlMsgIDTrans)
Q_DECLARE_METATYPE(Qxxlc::OcuToControlFrameHeadTrans)
Q_DECLARE_METATYPE(Qxxlc::MobilePlatStatusTrans)
Q_DECLARE_METATYPE(Qxxlc::PlatEnvirStatusTrans)
Q_DECLARE_METATYPE(Qxxlc::CarActionTrans)
Q_DECLARE_METATYPE(Qxxlc::CarControlTrans)
Q_DECLARE_METATYPE(Qxxlc::TurnInPlaceTrans)
Q_DECLARE_METATYPE(Qxxlc::VerticalAndFormationFollowTrans)
Q_DECLARE_METATYPE(Qxxlc::ConventionalManeuverTrans)
Q_DECLARE_METATYPE(Qxxlc::ManyTaskPointTrans)
Q_DECLARE_METATYPE(Qxxlc::ControlMsgData)
Q_DECLARE_METATYPE(Qxxlc::DC_IC_01Trans)
Q_DECLARE_METATYPE(Qxxlc::DC_IC_02Trans)
Q_DECLARE_METATYPE(Qxxlc::DC_IC_03Trans)
Q_DECLARE_METATYPE(Qxxlc::DC_IC_04Trans)
Q_DECLARE_METATYPE(Qxxlc::IC_DC_01Trans)
Q_DECLARE_METATYPE(Qxxlc::IC_DC_02Trans)
Q_DECLARE_METATYPE(Qxxlc::TargetInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::AI_DC_O1Trans)
Q_DECLARE_METATYPE(Qxxlc::RadioLinkQualityTrans)
Q_DECLARE_METATYPE(Qxxlc::DeviceStatusTrans)
Q_DECLARE_METATYPE(Qxxlc::GoalResultInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::DetectRecognitResultTrans)
Q_DECLARE_METATYPE(Qxxlc::GoalDetectInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::DetectGoalListTrans)
Q_DECLARE_METATYPE(Qxxlc::ImageInforTrans)
Q_DECLARE_METATYPE(Qxxlc::SystemTimeInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::SatelliteInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::GpsInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::AccelerateInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::MagnetometerInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::JoystickInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::BatteryInfoTrans)
Q_DECLARE_METATYPE(Qxxlc::KeyValue)
Q_DECLARE_METATYPE(Qxxlc::ICD_ALLIGN_DWDX_INFO_MSG_TRANS);
Q_DECLARE_METATYPE(Qxxlc::ICD_ALLING_QYZXD_INFO_MSG_TRANS);
Q_DECLARE_METATYPE(Qxxlc::ICD_ALLING_ZCMBDW_INFO_MSG_TRANS);
Q_DECLARE_METATYPE(Qxxlc::ICD_RECV_IMAGE_INFO_MSG_TRANS);
Q_DECLARE_METATYPE(Qxxlc::DjxlcOperationMode);
Q_DECLARE_METATYPE(Qxxlc::OcuToChassisParaTrans);
