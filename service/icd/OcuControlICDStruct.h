#pragma once
#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>

#include <stdint.h>
#include <QVector>



///< 全局路径点数组最大值
#define QJLJD_ARRAY_SIZE 300

/// 全局经纬度信息
struct GlobalPointMsg {
    ///经度，单位是deg
    double longitude;
    ///纬度，单位是deg
    double latitude;
    ///高度，单位是m
    double global_h;
    ///任务限时
    int time;
    ///属性，同路网文件，0-起点/1-终点/2-必经点/3-定点侦查点/4-定位打击点/5-机动打击入口点/6-机动打击出口点/7-shuoshi砾石路/8-涉水路/9-壕沟/10-弹坑/11-凸台/12-S路段/13-队形变换点
    unsigned char attribute;
    ///预留
    int reserve1;
    double reserve2;
    unsigned char reserve3;
};


#pragma pack(1)
//! ***********************************合成营摇杆串口数据接口*******************************************/
//! 上层应用数据
typedef   struct _ControlRocker{
    quint8   head;
    quint8   type;
    quint8   xAxisHight;
    quint8   xAxisLow;
    quint8   yAxisHight;
    quint8   yAxisLow;
    quint8   topButtonSwitchesLeft;
    quint8   topButtonSwitchesMiddle;
    quint8   topButtonSwitchesRight;
    quint8   leftButtonSwitch;
    quint8   triggerSwitch;
    quint8   crc;
}ControlRocker;



//!**************************************************ocu到本地视频端*******************************************************
typedef struct _OcuToLocalVideo{
    quint32         cmd;                //! 10:底盘视频;11:火控视频
    unsigned char   other[64];
    quint32         alpha;
    quint32         brightness;
    quint32         image_width;
    quint32         image_height;
}OcuToLocalVideo;
//! **************************************************jgyddj*******************************************************

//! 头部
typedef struct _RemoteHead
{
    quint8      head;           //! 报文头       0x7F
    quint8      sourceCode;     //! 信源主机代号  数据发送方设备代号
    quint8      letterCode;     //! 信宿主机代号  数据接收方设备代号
    quint16     len;            //! 报文长度     从报文头开始的整个报文的长度
    quint8      msgID;          //! 报名标志
}RemoteHead;

//! 尾部
typedef struct _RemoteEnd
{
    quint8      checkWord;      //! 校验字 CRC8校验，从报文头到数据尾所有数据
    quint8      end;            //! 报文尾 0x7E
}RemoteEnd;

typedef struct	_MsgJGYD
{
    RemoteHead head;
    char XXLSH[50];//流水号
    char ZZDYBH[50];//作战单元编号  16136000
    int	 YDLX;  //引导类型 枚举类型 66
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
    RemoteEnd end;
}MsgCommJGYD;

typedef struct	_OcuCarPosition
{
    quint16 head;
    double  lon;
    double  lat;
    double  yaw;
    double  pitch;
    double  roll;
    double  reserv;
}OcuCarPosition;
#pragma pack()

//!载荷任务完成情况反馈 操控端下发给自主软件 关键字段： zhzt
typedef struct _OcuFireControlTaskStateMsg{
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
}OcuFireControlTaskStateMsg;

typedef   struct  _ICD_CZ_XTJK_ZZJS_PLAN_COMMON                 //!中型轮式车和履带车自主驾驶都用这个结构体
{
    double time_label;                 //! 时间戳

    //! 机动任务，0-空闲/1-任务理解/2-自主通行/3-自主侦查/4-智能打击/5-机动歼敌/6-协同编队/7-协同侦查/8-协同打击/9-机动歼敌（折返）/ 保留
    unsigned char jdrw_flag;

    //! 全局路径点，最大长度为QJLJD_ARRAY_LENGTH的GlobalPosition类型的数组
    //! DECLARE_NML_DYNAMIC_LENGTH_ARRAY(GlobalPosition, qjljd, QJLJD_ARRAY_SIZE)
    //! vector<GlobalPosition> qjljd;
    //! 全局任务（点经纬度高程属性）,最大长度为 QJLJD_ARRAY_SIZE 的 GlobalLonLat 类型的数组
    int    task_num;                    //! 任务号 表示当前执行的任务序号；
    int    qjjwd_length;
    GlobalPointMsg qjjwd[QJLJD_ARRAY_SIZE];
    //! DECLARE_NML_DYNAMIC_LENGTH_ARRAY(GlobalLonLat, qjjwd, QJLJD_ARRAY_SIZE);
    unsigned char jsck_qjlj_flag;       //! 驾驶操控发送一次全局任务,加一,0-255循环,发一次加一
    float vmax;                         //! 自主导航最高速度，值域0.0~100.0,单位是m/s
    unsigned char jjsn_flag;            //! 降级使能标志，值域，00H-不降级使用，01H-降级使用
    unsigned char bxsn_flag;            //! 紧急避险使能标志，值域，00H-不执行紧急避险，01H-执行紧急避险
}ICD_CZ_XTJK_ZZJS_PLAN_COMMON;








