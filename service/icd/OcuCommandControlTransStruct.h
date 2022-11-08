#pragma once

#include <QObject>
#include <QVector>


#define ACCURACY 0.000001

#define AIM_OBSTACLE_DEFAULT_STRING "-999999"
#define AIM_OBSTACLE_DEFAULT_INT     -999999

#define STATUS_DEFAULT_STRING "-999"
#define STATUS_DEFAULT_INT     -999

//! 数据类型 - 平台状态
#define QXXLC_SJLX_PTZT "201ZCJSPTZT"
#define ZXLSC_SJLX_PTZT "201ZDYTPTZT"
#define ZXLDC_SJLX_PTZT "201ZDYTPTZT"
#define XXDZZ_SJLX_PTZT "29DZZZPTZT"

//! 数据类型 - 障碍上报 暂时用不到
#define QXXLC_SJLX_ZASB "201ZCJSZASB"
#define ZXLSC_SJLX_ZASB "201ZDYTZASB"
#define ZXLDC_SJLX_ZASB "201ZDYTZASB"
#define XXDZZ_SJLX_ZASB "29DZZZZASB"

//! 数据类型 - 动目标上报 暂时用不到 都是静态目标
#define QXXLC_SJLX_DMBSB "201ZCJSDMBSB"
#define ZXLSC_SJLX_DMBSB "201ZDYTDMBSB"
#define ZXLDC_SJLX_DMBSB "201ZDYTDMBSB"
#define XXDZZ_SJLX_DMBSB "29DZZZDMBSB"

//! 数据类型 - 静目标上报
#define QXXLC_SJLX_JMBSB "201ZCJSJMBSB"
#define ZXLSC_SJLX_JMBSB "201ZDYTJMBSB"
#define ZXLDC_SJLX_JMBSB "201ZDYTJMBSB"
#define XXDZZ_SJLX_JMBSB "29DZZZJMBSB"

//! 部队内码 172.174分别指的是ip地址
#define QXXLC_BDNM  "77711000003953"
#define ZXLSC_BDNM  "77711000003921"
#define ZXLDC_BDNM  "77711000003916"
#define XXDZZ_172_BDNM  "77711000003965"
#define XXDZZ_174_BDNM  "77711000003966"

//! 作战单元编号 172.174分别指的是ip地址
#define QXXLC_ZZDYBH        "16136000"
#define ZXLSC_ZZDYBH        "36472000"
#define ZXLDC_ZZDYBH        "42424000"
#define XXDZZ_172_ZZDYBH    "42377000"
#define XXDZZ_174_ZZDYBH    "24259000"

//! 任务回复的作战单元编号
#define QXXLC_ZZDYBH_REPLAY        16136000
#define ZXLSC_ZZDYBH_REPLAY       36472000
#define ZXLDC_ZZDYBH_REPLAY        42424000
#define XXDZZ_172_ZZDYBH_REPLAY    42377000
#define XXDZZ_174_ZZDYBH_REPLAY    24259000


#define EXPORT_TARGET_PATH "D:/testlog/targetInfo.txt"


#define JBCODE_STATIC           0   //! 敌方 设施目标 雷达
#define JBCODE_MOTION           1   //! 武器装备类
#define JBCODE_OBSTAXLE         2   //! 障碍
#define JBCODE_WQ               3   //! 我情 小队
#define JBCODE_CL               4   //! 车辆
#define JBCODE_RY               5   //! 人员
#define JBCODE_ZJ               6   //! 装甲
#define JBCODE_YRC              7   //! 有人车
#define JBCODE_WRC              8  //! 无人车
#define JBCODE_WRJ              9  //! 无人机
#define DESTORY_TARGET          10 //! 销毁目标



//!***********************************当前下发任务编号*****************************************/
typedef  struct _IssueTaskNum
{
    double taskNum;
}IssueTaskNumTrans;
Q_DECLARE_METATYPE(IssueTaskNumTrans)


typedef struct _MsgTaskReplyGroup12Trans
{
    int NIAN;                      //! 年 6029 001 8.1.1.5.1
    int YUE;                       //! 月 6030 001 8.1.1.5.2逻辑值
    int RI;                        //! 日 6031 001 8.1.1.5.3
    int XS;                        //! 小时 6032 001 8.1.1.5.4
    int FZ;                        //! 分钟 6033 001 8.1.1.5.5
    int MIAO;                      //! 秒 6034 001 8.1.1.5.6
}MsgTaskReplyGroup12Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup12Trans)

typedef  struct _MsgTaskReplyGroup11Trans
{
    int NIAN;                      //! 年 6029 001 8.1.1.5.1
    int YUE;                       //! 月 6030 001 8.1.1.5.2逻辑值
    int RI;                        //! 日 6031 001 8.1.1.5.3
    int XS;                        //! 小时 6032 001 8.1.1.5.4
    int FZ;                        //! 分钟 6033 001 8.1.1.5.5
    int MIAO;                      //! 秒 6034 001 8.1.1.5.6
}MsgTaskReplyGroup11Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup11Trans)

typedef struct _MsgTaskReplyRGroup10Trans
{
    QString ZBLX;                  //! 资源编号 6260 404 8.1.1.2
    quint16 SHSL;                  //! 损耗数量 6043 415 8.1.1.3
    bool bMsgTaskReplyGroup11;     //! 普通组
    MsgTaskReplyGroup11Trans g11;  //! 普通组 8.1.1.4
    bool bMsgTaskReplyGroup12;     //! 普通组
    MsgTaskReplyGroup12Trans g12;  //! 普通组 8.1.1.5
}MsgTaskReplyRGroup10Trans;
Q_DECLARE_METATYPE(MsgTaskReplyRGroup10Trans)

typedef struct _MsgTaskReplyGroup9Trans
{
    quint8 MsgTaskReplyRGroup10Num;//!重复组 8.1.1.1
    QVector<MsgTaskReplyRGroup10Trans>Rg10;
}MsgTaskReplyGroup9Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup9Trans)

typedef struct _MsgTaskReplyRGroup8Trans
{
    double MBBH;                   //! 目标编号 6051 401 7.1.1.2
    bool bFPIMBHSCD;               //! FPI 7.1.1.3
    quint8 MBHSCD;                 //! 目标状态 6437 401 7.1.1.3.1逻辑值
    bool bFPISSZS;                 //! FPI 7.1.1.4
    quint16 SSZS;                  //! 目标毁伤数量 6043 405 7.1.1.4.1
}MsgTaskReplyRGroup8Trans;
Q_DECLARE_METATYPE(MsgTaskReplyRGroup8Trans)

typedef struct _MsgTaskReplyGroup7Trans
{
    quint8 MsgTaskReplyRGroup8Num;//!重复组 7.1.1.1
    QVector<MsgTaskReplyRGroup8Trans>Rg8;
    //    MsgTaskReplyRGroup8Trans Rg8[10];//重复组 7.1.1.1
}MsgTaskReplyGroup7Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup7Trans)

typedef struct _MsgTaskReplyGroup6Trans
{
    int NIAN;                      //! 年 6029 001 6.3.1
    int YUE;                       //! 月 6030 001 6.3.2逻辑值
    int RI;                        //! 日 6031 001 6.3.3
    int XS;                        //! 小时 6032 001 6.3.4
    int FZ;                        //! 分钟 6033 001 6.3.5
    int MIAO;                      //! 秒 6034 001 6.3.6
}MsgTaskReplyGroup6Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup6Trans)

typedef struct _MsgTaskReplyGroup5Trans
{
    bool bFPISJNM;                 //! FPI 6.1
    double SJNM;                   //! 事件内码 6050 485 6.1.1
    bool bFPIMS_20ZF;              //! FPI 6.2
    QString MS_20ZF;               //! 事件名称 4265 024 6.2.1
    bool bMsgTaskReplyGroup6;      //! 事件发生时间
    MsgTaskReplyGroup6Trans g6;    //! 事件发生时间 6.3
    bool bFPIMS_50ZF;              //! FPI 6.4
    QString MS_50ZF;               //! 事件描述 4265 018 6.4.1
}MsgTaskReplyGroup5Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup5Trans)


typedef struct _MsgTaskReplyGroup4Trans
{
    int NIAN;                      //! 年 6029 001 5.6.1
    int YUE;                       //! 月 6030 001 5.6.2逻辑值
    int RI;                        //! 日 6031 001 5.6.3
    int XS;                        //! 小时 6032 001 5.6.4
    int FZ;                        //! 分钟 6033 001 5.6.5
    int MIAO;                      //! 秒 6034 001 5.6.6
}MsgTaskReplyGroup4Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup4Trans)

typedef struct _MsgTaskReplyGroup3Trans
{
    int NIAN;                      //! 年 6029 001 5.5.1
    int YUE;                       //! 月 6030 001 5.5.2逻辑值
    int RI;                        //! 日 6031 001 5.5.3
    int XS;                        //! 小时 6032 001 5.5.4
    int FZ;                        //! 分钟 6033 001 5.5.5
    int MIAO;                      //! 秒 6034 001 5.5.6
}MsgTaskReplyGroup3Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup3Trans)

typedef struct _MsgTaskReplyGroup2Trans
{
    double XDBM;                   //! 行动编码 6051 405 5.1
    bool bFPIXDZT;                 //! FPI 5.2
    quint8 XDZT;                   //! 行动状态 4306 001 5.2.1逻辑值   //行动状态(1:”未定义” 2:”撤销” 3:”完成” 4:”进行中” 5:”未开始” 6:”暂停”)
    bool bFPIRYSSL;                //! FPI 5.3
    double RYSSL;                  //! 人员损伤率 4307 002 5.3.1
    bool bFPISSZS;                 //! FPI 5.4
    quint16 SSZS;                  //! 损失总数 6043 405 5.4.1
    bool bMsgTaskReplyGroup3;      //! 普通组
    MsgTaskReplyGroup3Trans g3;    //! 普通组 5.5
    bool bMsgTaskReplyGroup4;      //! 普通组
    MsgTaskReplyGroup4Trans g4;    //! 普通组 5.6
}MsgTaskReplyGroup2Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup2Trans)

typedef struct _MsgTaskReplyGroup1Trans
{
    int NIAN;                      //! 年 6029 001 4.1
    int YUE;                       //! 月 6030 001 4.2逻辑值
    int RI;                        //! 日 6031 001 4.3
    int XS;                        //! 小时 6032 001 4.4
    int FZ;                        //! 分钟 6033 001 4.5
    int MIAO;                      //! 秒 6034 001 4.6
}MsgTaskReplyGroup1Trans;
Q_DECLARE_METATYPE(MsgTaskReplyGroup1Trans)

//! 任务回复 只上报g2之前的
typedef struct	_MsgTaskReplyTrans
{
    bool bFPIZZDYBH;                //! FPI 1
    double ZZDYBH;                  //! 作战单元编码 6051 402 1.1
    bool bFPIBDNM;                  //! FPI 2
    QString BDNM;                   //! 部队内码 4271 012 2.1
    bool bFPIBGNM;                  //! FPI 3
    double BGNM;                    //! 报告内码 6050 486 3.1
    bool bMsgTaskReplyGroup1;       //! 普通组
    MsgTaskReplyGroup1Trans g1;     //! 普通组 4
    bool bMsgTaskReplyGroup2;       //! 普通组
    MsgTaskReplyGroup2Trans g2;     //! 普通组 5
    bool bMsgTaskReplyGroup5;       //! 普通组
    MsgTaskReplyGroup5Trans g5;     //! 普通组 6
    bool bMsgTaskReplyGroup7;       //! 普通组
    MsgTaskReplyGroup7Trans g7;     //! 普通组 7
    bool bMsgTaskReplyGroup9;       //! 普通组
    MsgTaskReplyGroup9Trans g9;     //! 普通组 8
    bool bFPIBZ_40ZF;               //! FPI 9
}MsgTaskReplyTrans;
Q_DECLARE_METATYPE(MsgTaskReplyTrans)


typedef struct _MsgMotionAimGroup4Trans
{
    int CGCZDMBDFW;                 //! 车到目标的方位
}MsgMotionAimGroup4Trans;
Q_DECLARE_METATYPE(MsgMotionAimGroup4Trans)

typedef struct _MsgMotionAimGroup3Trans
{
    double JD;                       //! 经度
    double WD;                       //! 纬度
    double HB;                       //! 海拔
}MsgMotionAimGroup3Trans;
Q_DECLARE_METATYPE(MsgMotionAimGroup3Trans)

/**
 * 战场目标
 */
typedef  struct _MsgMotionAimGroup2Trans
{
    int MBSL;                        //! 目标数量
    int MBDX;                        //! 目标队形
    QString MBBH;                    //! 目标编号
    QString MBMC;                    //! 目标名称
    int MBSX;                        //! 目标属性
    int MBFL;                        //! 目标分类
    int GJLMDQ;                      //! 国家或联盟或地区
    double MBJD;                     //! 目标经度
    double MBWD;                     //! 目标纬度
    double MBGD;                     //! 目标高度
    double YDSD;                     //! 运动速度
    double YDFX;                     //! 运动方向
    int QDQKTZ;                      //! 活动情况特征
    int MBZT;                        //! 目标状态
    int GJWQ;                        //! 攻击武器
    int ZCXW;                        //! 战场行为
    QString XWYT;                    //! 行为意图
    QString MBMS;                    //! 目标描述
    int FXSD;                        //! 发现手段

    MsgMotionAimGroup3Trans BCWZ;    //!本车位置
    MsgMotionAimGroup4Trans CYMBXDWZ;//! 车与目标相对位置

    QString ZXPD;                    //! 最小频段
    QString ZDPD;                    //! 最大频段
    int FSYXH;                       //! 辐射源型号
    QString PTXH;                    //! 平台型号

    QString MBFWJ;                   //! 目标方位角
    QString MBFYJ;                   //! 目标俯仰角
    int MBJL;                        //! 目标距离
    int ZXD;                         //! 置信度
}MsgMotionAimGroup2Trans;
Q_DECLARE_METATYPE(MsgMotionAimGroup2Trans)

typedef struct _MsgMotionAimGroup1Trans
{
    int NIAN;                         //! 年
    int YUE;                          //! 月
    int RI;                           //! 日
    int XS;                           //! 时
    int FZ;                           //! 分
    int MIAO;                         //! 秒
}MsgMotionAimGroup1Trans;
Q_DECLARE_METATYPE(MsgMotionAimGroup1Trans)

typedef struct	_MsgMotionAimTrans
{
    QString SJLX;
    QString ZZDYBH;                   //! 作战单元编号
    MsgMotionAimGroup1Trans SBSJ;     //! 上报时间
    quint8 MsgMotionAimRMBXXNum;
    QVector<MsgMotionAimGroup2Trans>MBXX;
}MsgMotionAimTrans;
Q_DECLARE_METATYPE(MsgMotionAimTrans)

typedef struct _MsgObstacleGroup3Trans
{
    double GD;                        //! 高度
    double KD;                        //! 宽度
    double SD;                        //! 深度
}MsgObstacleGroup3Trans;
Q_DECLARE_METATYPE(MsgObstacleGroup3Trans)

typedef struct _MsgObstacleGroup2Trans
{
    double JD;                        //! 经度
    double WD;                        //! 纬度
    double HB;                        //! 海拔
}MsgObstacleGroup2Trans;
Q_DECLARE_METATYPE(MsgObstacleGroup2Trans)

typedef struct _MsgObstacleGroup1Trans
{
    int NIAN;                         //! 年_相对7位 6029 401 5.1
    int YUE;                          //! 月 6030 001 5.2逻辑值
    int RI;                           //! 日 6031 001 5.3
    int XS;                           //! 时 6032 001 5.4
    int FZ;                           //! 分 6033 001 5.5
    int MIAO;                         //! 秒 6034 001 5.6
}MsgObstacleGroup1Trans;
Q_DECLARE_METATYPE(MsgObstacleGroup1Trans)

typedef struct	_MsgObstacleTrans
{
    QString SJLX;                     //! 数据类型
    QString XXLSH;                    //! 流水号 6050 401 2
    QString ZZDYBH;                   //! 来报单位编码 6051 402 1
    QString KNM;                      //! 障碍内码 6050 496 9.1
    int ZAZT;                         //! 障碍状态 4306 002 25.1逻辑值
    MsgObstacleGroup1Trans SBSJ;      //! 来报时间组 5
    MsgObstacleGroup2Trans PTWZ;      //! 平台位置
    int MsgObstacleZAWZNum;           //! 障碍位置
    QVector<MsgObstacleGroup2Trans>ZAWZ;
    //    MsgObstacleGroup2Trans ZAWZ[20];  //障碍位置
    MsgObstacleGroup3Trans ZADX;      //! 障碍大小
    int ZAZCZ;                        //! 障碍造成者
    int ZALX;                         //! 障碍类型
    QString ZYDW;                     //! 自由电文
    QString AWTP;	              //! 障碍图片
}MsgObstacleTrans;
Q_DECLARE_METATYPE(MsgObstacleTrans)

typedef struct _MsgStaticAimGroup1Trans
{
    int NIAN;                         //! 年
    int YUE;                          //! 月
    int RI;                           //! 日
    int XS;                           //! 时
    int FZ;                           //! 分
    int MIAO;                         //! 秒
}MsgStaticAimGroup1Trans;
Q_DECLARE_METATYPE(MsgStaticAimGroup1Trans)

typedef struct	_MsgStaticAimTrans
{
    QString SJLX;                     //! 数据类型
    QString ZZDYBH;                   //! 作战单元编号
    MsgStaticAimGroup1Trans SBSJ;     //! 上报时间
    QString MBBH;                     //! 目标编号
    QString MBMC;                     //! 目标名称
    int MBSX;                         //! 目标属性
    int MBFL;                         //! 目标分类
    double MBJD;                      //! 目标经度
    double MBWD;                      //! 目标纬度
    double MBGD;                      //! 目标高度
    int  MBSL;                        //! 目标数量
    int  MBXZ;                        //! 目标形状
    int  MBJG;                        //! 目标结构
    int  MBCZ;                        //! 目标材质
    int  MBHD;                        //! 目标厚度
    QString SSBDMBBH;                 //! 所属部队目标编号
    QString ZSBDMBBH;                 //! 驻守部队目标编号
    int  JDBZ;                        //! 禁打标志
    int  HSCD;                        //! 毁伤程度
    QString MBMS;                     //! 目标描述
    int  FXSD;                        //! 发现手段

    QString ZXPD;                     //! 最小频段
    QString ZDPD;                     //! 最大频段
    int FSYXH;                        //! 辐射源型号
    QString PTXH;                     //! 平台型号

    QString MBFWJ;                    //! 目标方位角
    QString MBFYJ;                    //! 目标俯仰角
    int MBJL;                         //! 目标距离
    int ZXD;                          //! 置信度

}MsgStaticAimTrans;
Q_DECLARE_METATYPE(MsgStaticAimTrans)

typedef struct _MsgStatusGroup2Trans
{
    double JD;                        //! 经度
    double WD;                        //! 纬度
    double HB;                        //! 海拔
}MsgStatusGroup2Trans;
Q_DECLARE_METATYPE(MsgStatusGroup2Trans)

typedef struct _MsgStatusGroup5Trans   //! 任务载荷状态信息
{
    int SZGZZT;                        //! 上装工作状态
    int ZCZBSNZT;                      //! 侦察设备使能状态
    int JQSYDYSL;                      //! 机枪剩余弹药数量
    int DLDSYSL;                       //! 催泪弹剩余数量

    int QWLXXZ;                        //! 武器类型选择
    int DDSYDYSL;                      //! 导弹剩余弹药数量
    int SLPSYDL;                       //! 30炮剩余弹量
    int YMDSYDL;                       //! 烟幕弹剩余弹量
}MsgStatusGroup5Trans;
Q_DECLARE_METATYPE(MsgStatusGroup5Trans)

//专用信息
typedef struct _MsgStatusGroup4Trans
{
    int DWZL;                          //! 定位质量
    MsgStatusGroup5Trans RWZHZTXX;
}MsgStatusGroup4Trans;
Q_DECLARE_METATYPE(MsgStatusGroup4Trans)

typedef struct _MsgStatusGroup3Trans
{
    double FWJ;                        //! 方位角
    double CQJ;                        //! 侧倾角
    double YJJ;                        //! 俯仰角
}MsgStatusGroup3Trans;
Q_DECLARE_METATYPE(MsgStatusGroup3Trans)

typedef struct _MsgStatusGroup1Trans
{
    int NIAN_XD7;                      //! 年_相对7位 6029 401 5.1
    int YUE;                           //! 月 6030 001 5.2逻辑值
    int RI;                            //! 日 6031 001 5.3
    int XS;                            //! 时 6032 001 5.4
    int FZ;                            //! 分 6033 001 5.5
    int MIAO;                          //! 秒 6034 001 5.6
}MsgStatusGroup1Trans;
Q_DECLARE_METATYPE(MsgStatusGroup1Trans)

typedef struct	_MsgStatusTrans
{
    QString XXLSH;                     //! 流水号
    QString ZZDYBH;                    //! 作战单元编号
    MsgStatusGroup1Trans SBSJ;         //! 无人平台状态上报时间
    MsgStatusGroup2Trans PTWZ;         //! 无人平台位置
    MsgStatusGroup2Trans YCCKCWZ;      //! 远程操控车位置
    MsgStatusGroup3Trans PTZTJ;        //! 平台姿态角
    int PTDW;                      //! 无人平台档位
    QString PTYDSD;                    //! 平台运动速度
    int PTKZMS;                        //! 平台控制模式
    int PTJMZSZT;                      //! 无人平台静默值守状态
    int DLMS;                          //! 动力模式
    QString XHLC;                      //! 续航里程（公里，字符串）
    int XHSJ;                          //! 续航时间（分钟,整形）
    int	SYDL;                          //! 剩余电量（整形）
    int	SYYL;                          //! 剩余油量（整形）
    int ZBZHJKZT;                      //! 装备综合健康状态（枚举值）
    int PTDPJKZT;                      //! 平台底盘健康状态（枚举值）
    int TXSBJKZT;                      //! 通信设备健康状态（枚举值）
    QString GZMXX;                     //! 故障码信息（字符串）
    QString ZYDW;                      //! 自由电文（不超过30字符）
    MsgStatusGroup4Trans ZYXX;         //! 专用信息
}MsgStatusTrans;
Q_DECLARE_METATYPE(MsgStatusTrans)

//! 侦察监视无人车
typedef struct _MsgStatus201ZCJSZDYTGroup2Trans
{
    double JD;                          //! 经度
    double WD;                          //! 纬度
    double HB;                          //! 海拔
}MsgStatus201ZCJSZDYTGroup2Trans;
Q_DECLARE_METATYPE(MsgStatus201ZCJSZDYTGroup2Trans)

typedef struct _MsgStatus201ZCJSZDYTGroup5Trans  //任务载荷状态信息
{
    int SZGZZT;                         //! 上装工作状态
    int ZCZBSNZT;                       //! 侦察设备使能状态
    int JQSYDYSL;                       //! 机枪剩余弹药数量
    int DLDSYSL;                        //! 催泪弹剩余数量

    int QWLXXZ;                         //! 武器类型选择
    int DDSYDYSL;                       //! 导弹剩余弹药数量
    int SLPSYDL;                        //! 30炮剩余弹量
    int YMDSYDL;                        //! 烟幕弹剩余弹量
}MsgStatus201ZCJSZDYTGroup5Trans;
Q_DECLARE_METATYPE(MsgStatus201ZCJSZDYTGroup5Trans)

//专用信息
typedef struct _MsgStatus201ZCJSZDYTGroup4Trans
{
    int DWZL;                            //! 定位质量
    MsgStatus201ZCJSZDYTGroup5Trans RWZHZTXX;
    quint8 MsgStatus201ZCJSZDYTRWLJDNum; //! 任务路径点个数
    QVector<MsgStatus201ZCJSZDYTGroup2Trans>RWLJD;
//    MsgStatus201ZCJSZDYTGroup2Trans RWLJD[50];  //任务路径点
}MsgStatus201ZCJSZDYTGroup4Trans;

typedef struct _MsgStatus201ZCJSZDYTGroup3Trans
{
    double FWJ;                          //! 方位角
    double CQJ;                          //! 侧倾角
    double YJJ;                          //! 俯仰角
}MsgStatus201ZCJSZDYTGroup3Trans;

typedef struct _MsgStatus201ZCJSZDYTGroup1Trans
{
    int NIAN_XD7;                          //! 年_相对7位 6029 401 5.1
    int YUE;                               //! 月 6030 001 5.2逻辑值
    int RI;                                //! 日 6031 001 5.3
    int XS;                                //! 时 6032 001 5.4
    int FZ;                                //! 分 6033 001 5.5
    int MIAO;                              //! 秒 6034 001 5.6
}MsgStatus201ZCJSZDYTGroup1Trans;

typedef struct	_MsgStatus201ZCJSZDYTTrans
{
    QString SJLX;                          //! 数据类型
    QString XXLSH;                         //! 流水号
    QString ZZDYBH;                        //! 作战单元编号
    MsgStatus201ZCJSZDYTGroup1Trans SBSJ;  //! 无人平台状态上报时间
    MsgStatus201ZCJSZDYTGroup2Trans PTWZ;  //! 无人平台位置
    MsgStatus201ZCJSZDYTGroup2Trans ZDWZ;  //! 终端位置（远程操控车或便携式操控终端）

    MsgStatus201ZCJSZDYTGroup3Trans PTZTJ; //! 平台姿态角

    int PTDW;                               //! 无人平台档位
    QString PTYDSD;                        //! 平台运动速度
    int PTKZMS;                            //! 平台控制模式
    int PTJMZSZT;                          //! 无人平台静默值守状态
    int DLMS;                              //! 动力模式
    QString XHLC;                          //! 续航里程（公里，字符串）
    int XHSJ;                              //! 续航时间（分钟,整形）
    int	SYDL;                              //! 剩余电量（整形）
    int	SYYL;                              //! 剩余油量（整形）
    int ZBZHJKZT;                          //! 装备综合健康状态（枚举值）
    int PTDPJKZT;                          //! 平台底盘健康状态（枚举值）
    int TXSBJKZT;                          //! 通信设备健康状态（枚举值）
    QString GZMXX;                         //! 故障码信息（字符串）
    QString ZYDW;                          //! 自由电文（不超过30字符）

    MsgStatus201ZCJSZDYTGroup4Trans ZYXX;  //! 专用信息
}MsgStatus201ZCJSZDYTTrans;
Q_DECLARE_METATYPE(MsgStatus201ZCJSZDYTTrans)


//! 电子作战无人车
typedef struct _MsgStatusDZZZGroup2Trans
{
    double JD;                             //! 经度
    double WD;                             //! 纬度
    double HB;                             //! 海拔
}MsgStatusDZZZGroup2Trans;

typedef struct _MsgStatusDZZZGroup10Trans
{
    int VHFUHF_BDZCGRSB;                   //! VHF/UHF波段侦察干扰设备
    int LSC_BDZCGRSB;                      //! L/S/C波段侦察干扰设备
    int XKUKA_BDZCGRSB;                    //! X/Ku/Ka波段侦察干扰设备
    int GXGCSB;                            //! 光学观察设备
    int SJCLYKZSB;                         //! 数据处理与控制设备
    int SFCDSB;                            //! 伺服传动设备
}MsgStatusDZZZGroup10Trans;

typedef struct _MsgStatusDZZZGroup9Trans
{
    int SFZTFWJ;                           //! 伺服转台方位角
    int SFZTFYJ;                           //! 伺服转台俯仰角
}MsgStatusDZZZGroup9Trans;

typedef struct _MsgStatusDZZZGroup8Trans
{
    int GZZT;                              //! 工作状态
    QString MNFSYXH;                       //! 模拟辐射源型号
}MsgStatusDZZZGroup8Trans;

typedef struct _MsgStatusDZZZGroup7Trans
{
    int GZZT;                              //! 工作状态
    int GRQSPL;                            //! 干扰起始频率
    int GRZZPL;                            //! 干扰终止频率
}MsgStatusDZZZGroup7Trans;


typedef struct _MsgStatusDZZZGroup6Trans
{
    int GZZT;                              //! 工作状态
    int ZCQSPL;                            //! 侦察起始频率
    int ZCZZPL;                            //! 侦察终止频率
}MsgStatusDZZZGroup6Trans;

typedef struct _MsgStatusDZZZGroup5Trans
{
    MsgStatusDZZZGroup6Trans LDZCZT;       //! 雷达侦察状态
    MsgStatusDZZZGroup7Trans LDGRZT;       //! 雷达干扰状态
    MsgStatusDZZZGroup6Trans TXZCZT;       //! 通信侦察状态
    MsgStatusDZZZGroup7Trans TXGRZT;       //! 通信干扰状态
    MsgStatusDZZZGroup8Trans XHMNZT;       //! 信号模拟状态
    int GXGCZT;                            //! 光学观察状态
    MsgStatusDZZZGroup9Trans SFCDSBZT;     //! 伺服传动设备状态
    MsgStatusDZZZGroup10Trans ZHJKZT;      //! 载荷健康状态
}MsgStatusDZZZGroup5Trans;

//专用信息
typedef struct _MsgStatusDZZZGroup4Trans
{
    int DWZL;                               //! 定位质量
    quint8 MsgStatusDZZZRWLJDNum;           //! 任务路径点个数
//!    MsgStatusDZZZGroup2Trans RWLJD[50];  //! 任务路径点

    QVector<MsgStatusDZZZGroup2Trans>RWLJD;
    MsgStatusDZZZGroup5Trans RWZHZTXX;      //! 任务载荷状态信息
}MsgStatusDZZZGroup4Trans;

typedef struct _MsgStatusDZZZGroup3Trans
{
    double HXJ;                             //! 航向角
    double CQJ;                             //! 侧倾角
    double YJJ;                             //! 俯仰角
}MsgStatusDZZZGroup3Trans;


typedef struct _MsgStatusDZZZGroup1Trans
{
    int NIAN_XD7;                           //! 年_相对7位 6029 401 5.1
    int YUE;                                //! 月 6030 001 5.2逻辑值
    int RI;                                 //! 日 6031 001 5.3
    int XS;                                 //! 时 6032 001 5.4
    int FZ;                                 //! 分 6033 001 5.5
    int MIAO;                               //! 秒 6034 001 5.6
}MsgStatusDZZZGroup1Trans;



typedef struct	_MsgStatusDZZZTrans
{
    QString SJLX;                           //! 数据类型
    QString XXLSH;                          //! 流水号
    QString ZZDYBH;                         //! 作战单元编号
    MsgStatusDZZZGroup1Trans SBSJ;          //! 无人平台状态上报时间
    MsgStatusDZZZGroup2Trans PTWZ;     //     //! 无人平台位置
//!    MsgStatus201ZCJSZDYTGroup2 ZDWZ;     //! 终端位置（远程操控车或便携式操控终端）
    MsgStatusDZZZGroup3Trans PTZTJ;    //     //! 平台姿态角
    int PTJDZT;                             //! 无人平台机动状态
    QString PTYDSD;     //                    //! 平台运动速度
    int PTKZMS;         //                    //! 平台控制模式
    int PTJMZSZT;       //                    //! 无人平台静默值守状态
    int DLMS;           //                    //! 动力模式
    QString XHLC;                           //! 续航里程（公里，字符串）
    int XHSJ;                               //! 续航时间（分钟,整形）
    int	SYDL;           //                    //! 剩余电量（整形）
    int	SYYL;           //                    //! 剩余油量（整形）
    int ZBZHJKZT;                           //! 装备综合健康状态（枚举值）
    int PTDPJKZT;                           //! 平台底盘健康状态（枚举值）
    int TXSBJKZT;                           //! 通信设备健康状态（枚举值）
    QString GZMXX;      //                    //! 故障码信息（字符串）
    QString ZYDW;                           //! 自由电文（不超过30字符）
    MsgStatusDZZZGroup4Trans ZYXX;          //! 专用信息
}MsgStatusDZZZTrans;
Q_DECLARE_METATYPE(MsgStatusDZZZTrans)


//! 防空支援无人车
typedef struct _MsgStatusFKZYGroup2Trans
{
    double JD;                               //! 经度
    double WD;                               //! 纬度
    double HB;                               //! 海拔
}MsgStatusFKZYGroup2Trans;

typedef struct _MsgStatusFKZYGroup6Trans     //! 上装健康状态
{
    int LD;	                             //! 雷达（枚举值）
    int GD;	                             //! 光电（枚举值）
    int HLZT;	                             //! 火力转塔（枚举值）
    int ZZGLKZXT;	                     //! 作战管理控制系统（枚举值）
    int FK;                                  //! 导弹发控（枚举值）
    int GUANDAO;                             //! 惯导（枚举值）
    int TXXT;                                //! 通信系统（枚举值）
}MsgStatusFKZYGroup6Trans;

typedef struct _MsgStatusFKZYGroup5Trans     //任务载荷状态信息
{
    int HJDSYDL;	                     //! 火箭弹剩余弹量（整形）
    int DDSYDL;	                             //! 导弹剩余弹量（整形）
}MsgStatusFKZYGroup5Trans;


//专用信息
typedef struct _MsgStatusFKZYGroup4Trans
{
    int SXZL;                                //! 搜星质量（枚举值）
    int CFDWZL;                              //! 差分定位质量（枚举值）
    int SZSDQK;                              //! 上装上电情况（枚举值）
    MsgStatusFKZYGroup5Trans ZHZTSJ;         //! 载荷状态数据
    int DZXX;                                //! 弹种信息（枚举值）
    MsgStatusFKZYGroup6Trans SZJKZT;         //! 上装健康状态
    int SZGZMS;                              //! 上装工作模式（枚举值）

}MsgStatusFKZYGroup4Trans;

typedef struct _MsgStatusFKZYGroup3Trans
{
    double FWJ;                              //! 方位角
    double CQJ;                              //! 侧倾角
    double YJJ;                              //! 俯仰角
}MsgStatusFKZYGroup3Trans;

typedef struct _MsgStatusFKZYGroup1Trans
{
    int NIAN_XD7;                            //! 年_相对7位 6029 401 5.1
    int YUE;                                 //! 月 6030 001 5.2逻辑值
    int RI;                                  //! 日 6031 001 5.3
    int XS;                                  //! 时 6032 001 5.4
    int FZ;                                  //! 分 6033 001 5.5
    int MIAO;                                //! 秒 6034 001 5.6
}MsgStatusFKZYGroup1Trans;



typedef struct	_MsgStatusFKZYTrans
{
    QString SJLX;                            //! 数据类型
    QString XXLSH;                           //! 流水号
    QString ZZDYBH;                          //! 作战单元编号
    MsgStatusFKZYGroup1Trans SBSJ;           //! 无人平台状态上报时间
    MsgStatusFKZYGroup2Trans PTWZ;           //! 无人平台位置
//    MsgStatus201ZCJSZDYTGroup2 ZDWZ;       //! 终端位置（远程操控车或便携式操控终端）

    MsgStatusFKZYGroup3Trans PTZTJ;          //! 平台姿态角

    int PTJDZT;                              //! 平台机动状态（枚举值）
    QString PTYDSD;                          //! 平台运动速度
    int PTKZMS;                              //! 平台控制模式
    QString XHLC;                            //! 续航里程（公里，字符串）
    int XHSJ;                                //! 续航时间（分钟,整形）
    int	SYDL;                                //! 剩余电量（整形）
    int	SYYL;                                //! 剩余油量（整形）
    int ZBZHJKZT;                            //! 装备综合健康状态（枚举值）
    int PTDPJKZT;                            //! 平台底盘健康状态（枚举值）
    int TXSBJKZT;                            //! 通信设备健康状态（枚举值）
    QString GZMXX;                           //! 故障码信息（字符串）
    QString ZYDW;                            //! 自由电文（不超过30字符）

    MsgStatusFKZYGroup4Trans ZYXX;           //! 专用信息
}MsgStatusFKZYTrans;
Q_DECLARE_METATYPE(MsgStatusFKZYTrans)


typedef struct _MsgTaskGroup18Trans
{
    double JD_JD00013F;                      //! 位置点经度_精度0.0013分   6013 001 10.1.1.3.2.1.2
    double WD_JD00013F;                      //! 位置点纬度_精度0.0013分 6013 002 10.1.1.3.2.1.3
    double GD_JD00013F;                      //! 位置点高度 6013 002 9.2.2.1.3
}MsgTaskGroup18Trans;
Q_DECLARE_METATYPE(MsgTaskGroup18Trans)

typedef struct _MsgTaskGroup17Trans
{
    int NIAN;                                //! 年 6029 001 12.1.1.5.1
    int YUE;                                 //! 月 6030 001 12.1.1.5.2逻辑值
    int RI;                                  //! 日 6031 001 12.1.1.5.3
    int XS;                                  //! 小时 6032 001 12.1.1.5.4
    int FZ;                                  //! 分钟 6033 001 12.1.1.5.5
    int MIAO;                                //! 秒 6034 001 12.1.1.5.6
}MsgTaskGroup17Trans;
Q_DECLARE_METATYPE(MsgTaskGroup17Trans)

typedef struct _MsgTaskGroup16Trans
{
    int NIAN;                                //! 年 6029 001 12.1.1.4.1
    int YUE;                                 //! 月 6030 001 12.1.1.4.2逻辑值
    int RI;                                  //! 日 6031 001 12.1.1.4.3
    int XS;                                  //! 小时 6032 001 12.1.1.4.4
    int FZ;                                  //! 分钟 6033 001 12.1.1.4.5
    int MIAO;                                //! 秒 6034 001 12.1.1.4.6
}MsgTaskGroup16Trans;
Q_DECLARE_METATYPE(MsgTaskGroup16Trans)

typedef struct _MsgTaskRGroup15Trans
{
    QString WZLX;                            //! 物资类型 6260 406 12.1.1.2
    quint16 SL_17;                           //! 物资数量 6043 504 12.1.1.3
    bool bMsgTaskGroup16;                    //! 资源计划开始使用时间组
    MsgTaskGroup16Trans g16;                 //! 资源计划开始使用时间组 12.1.1.4
    bool bMsgTaskGroup17;                    //! 资源计划结束使用时间组
    MsgTaskGroup17Trans g17;                 //! 资源计划结束使用时间组 12.1.1.5
}MsgTaskRGroup15Trans;
Q_DECLARE_METATYPE(MsgTaskRGroup15Trans)

typedef struct _MsgTaskGroup14Trans
{
    quint8 MsgTaskRGroup15Num;               //! 重复组 12.1.1.1
    QVector<MsgTaskRGroup15Trans>Rg15;
    //    MsgTaskRGroup15Trans Rg15[10];//重复组 12.1.1.1
}MsgTaskGroup14Trans;
Q_DECLARE_METATYPE(MsgTaskGroup14Trans)

typedef struct _MsgTaskRGroup13Trans
{
    double MBBH;                             //! 目标编号 6051 401 11.1.1.2
    quint8 MBHSCD;                           //! 目标状态 6437 401 11.1.1.3逻辑值
    bool bFPISSZS;                           //! FPI 11.1.1.4
    quint16 SSZS;                            //! 目标毁伤数量 6043 405 11.1.1.4.1
    bool bFPIMS_50ZF;                        //! FPI 11.1.1.5
    QString MS_50ZF;                         //! 目的描述 4265 018 11.1.1.5.1
    QString MBLX;                            //! 目标类型 4054 050 4
    bool bMsgTaskGroup18;                    //! 行动目标位置组
    MsgTaskGroup18Trans g18;                 //! 行动目标位置组 12.1.1.5
}MsgTaskRGroup13Trans;
Q_DECLARE_METATYPE(MsgTaskRGroup13Trans)

typedef struct _MsgTaskGroup12Trans
{
    quint8 MsgTaskRGroup13Num;//重复组 11.1.1.1
    QVector<MsgTaskRGroup13Trans>Rg13;
    //    MsgTaskRGroup13Trans Rg13[10];//重复组 11.1.1.1
}MsgTaskGroup12Trans;
Q_DECLARE_METATYPE(MsgTaskGroup12Trans)

typedef struct _MsgTaskRGroup11Trans
{
    double JD_JD00013F;                      //! 位置点经度_精度0.0013分   6013 001 10.1.1.3.2.1.2
    double WD_JD00013F;                      //! 位置点纬度_精度0.0013分 6013 002 10.1.1.3.2.1.3
    double GD_JD00013F;                      //! 位置点高度 6013 002 9.2.2.1.3
    QString ZBSX;                            //! 坐标属性 4054 050 4
}MsgTaskRGroup11Trans;
Q_DECLARE_METATYPE(MsgTaskRGroup11Trans)

typedef struct _MsgTaskGroup10Trans
{
    double JBCODE;                           //! 军标CODE 4259 002 10.1.1.3.1
    quint8 MsgTaskRGroup11Num;               //! 重复组 10.1.1.3.2.1.1
    QVector<MsgTaskRGroup11Trans>Rg11;
    //    MsgTaskRGroup11Trans Rg11[20];//重复组 10.1.1.3.2.1.1
}MsgTaskGroup10Trans;
Q_DECLARE_METATYPE(MsgTaskGroup10Trans)

typedef struct _MsgTaskRGroup9Trans
{
    bool bFPIMS_50ZF;                        //! FPI 10.1.1.2
    QString MS_50ZF;                         //! 行动过程描述_50字符 4265 018 10.1.1.2.1
    bool bMsgTaskGroup10;                    //! 行动地点相关军标组
    MsgTaskGroup10Trans g10;                 //! 行动地点相关军标组 10.1.1.3
}MsgTaskRGroup9Trans;
Q_DECLARE_METATYPE(MsgTaskRGroup9Trans)

typedef struct _MsgTaskGroup8Trans
{
    quint8 MsgTaskRGroup9Num;                //! 行动过程重复组 10.1.1.1
    QVector<MsgTaskRGroup9Trans>Rg9;
    //    MsgTaskRGroup9Trans Rg9[5];//行动过程重复组 10.1.1.1
}MsgTaskGroup8Trans;
Q_DECLARE_METATYPE(MsgTaskGroup8Trans)

typedef struct _MsgTaskRGroup7Trans
{
    double JD_JD00013F;                     //! 位置点经度_精度0.0013分   6013 001 9.2.2.1.2
    double WD_JD00013F;                     //! 位置点纬度_精度0.0013分 6013 002 9.2.2.1.3
    double GD_JD00013F;                     //! 位置点高度 6013 002 9.2.2.1.3
    QString ZBSX;                           //! 坐标属性 4054 050 4
}MsgTaskRGroup7Trans;
Q_DECLARE_METATYPE(MsgTaskRGroup7Trans)

typedef struct _MsgTaskGroup6Trans
{
    double JBCODE;                          //! 军标CODE 4259 002 9.2.1
    quint8 MsgTaskRGroup7Num;               //! 位置信息重复组 9.2.2.1.1

    QVector<MsgTaskRGroup7Trans>Rg7;
    //    MsgTaskRGroup7Trans Rg7[20];//位置信息重复组 9.2.2.1.1
}MsgTaskGroup6Trans;
Q_DECLARE_METATYPE(MsgTaskGroup6Trans)

typedef struct _MsgTaskGroup5Trans
{
    bool bFPIMS_50ZF;                        //! FPI 9.1
    QString MS_50ZF;                         //! 行动地点描述 4265 018 9.1.1
    bool bMsgTaskGroup6;                     //! 行动地点相关军标组
    MsgTaskGroup6Trans g6;                   //! 行动地点相关军标组 9.2
}MsgTaskGroup5Trans;
Q_DECLARE_METATYPE(MsgTaskGroup5Trans)

typedef struct _MsgTaskGroup4Trans
{
    int NIAN;                                //! 年 6029 001 8.2.1
    int YUE;                                 //! 月 6030 001 8.2.2逻辑值
    int RI;                                  //! 日 6031 001 8.2.3
    int XS;                                  //! 小时 6032 001 8.2.4
    int FZ;                                  //! 分钟 6033 001 8.2.5
    int MIAO;                                //! 秒 6034 001 8.2.6
}MsgTaskGroup4Trans;
Q_DECLARE_METATYPE(MsgTaskGroup4Trans)

typedef struct _MsgTaskGroup3Trans
{
    int NIAN;                                 //! 年 6029 001 8.1.1
    int YUE;                                  //! 月 6030 001 8.1.2逻辑值
    int RI;                                   //! 日 6031 001 8.1.3
    int XS;                                   //! 小时 6032 001 8.1.4
    int FZ;                                   //! 分钟 6033 001 8.1.5
    int MIAO;                                 //! 秒 6034 001 8.1.6
}MsgTaskGroup3Trans;
Q_DECLARE_METATYPE(MsgTaskGroup3Trans)

typedef struct _MsgTaskGroup2Trans
{
    bool bMsgTaskGroup3;                      //! 行动计划开始执行时间组
    MsgTaskGroup3Trans g3;                    //! 行动计划开始执行时间组 8.1
    bool bMsgTaskGroup4;                      //! 行动计划结束执行时间组
    MsgTaskGroup4Trans g4;                    //! 行动计划结束执行时间组 8.2
}MsgTaskGroup2Trans;
Q_DECLARE_METATYPE(MsgTaskGroup2Trans)

typedef struct _MsgTaskGroup1Trans
{
    int NIAN;                                //! 年 6029 001 2.1
    int YUE;                                 //! 月 6030 001 2.2逻辑值
    int RI;                                  //! 日 6031 001 2.3
    int XS;                                  //! 小时 6032 001 2.4
    int FZ;                                  //! 分钟 6033 001 2.5
    int MIAO;                                //! 秒 6034 001 2.6
}MsgTaskGroup1Trans;
Q_DECLARE_METATYPE(MsgTaskGroup1Trans)

typedef struct _MsgTaskGroup20Trans
{
    bool BFPIXTCYZL;
    quint8 XTCYZL;//协同成员种类 4271 012 5.1
    bool BFPIXTJS;
    quint8 XTJS;//协同角色 4265 018 6.1
    bool BFPIXTMS;
    QString XTMS;//协同描述 4271 012 5.1
}MsgCommTaskGroup20Trans;


typedef struct _MsgTaskGroup19Trans
{
    quint8 MsgTaskGroup20Num;//协同信息重复组
    QVector<MsgCommTaskGroup20Trans>Rg20;
//    MsgCommTaskGroup20Trans Rg20[5];//协同信息重复组
}MsgCommTaskGroup19Trans;


typedef struct	MsgTaskTrans
{
    bool bFPIZZDYBH;                         //! FPI 1
    double ZZDYBH;                           //! 发布命令的席位编号 6051 402 1.1
    bool bMsgTaskGroup1;                     //! 发布时间组
    MsgTaskGroup1Trans g1;                   //! 发布时间组 2
    double XDBM;                             //! 行动编码 6051 405 3
    QString XDMC;                            //! 行动名称 4054 050 4
    bool bFPIBDNM;                           //! FPI 5
    QString BDNM;                            //! 部队内码 4271 012 5.1
    bool bFPIMS_50ZF;                        //! FPI 6
    QString MS_50ZF;                         //! 命令的文字描述 4265 018 6.1
    bool bMsgGroup19Trans;                   //! 协同信息组
    MsgCommTaskGroup19Trans g19;             //! 协同信息组
    quint8 XTCYZL;                           //! 协同成员种类 4271 012 5.1
    quint8 XTJS;                             //! 协同角色 4265 018 6.1
    QString XTMS;                            //! 协同描述 4271 012 5.1
//    quint8 RWMGMBLX;                         //! 任务敏感目标类型 4265 018 6.1
    bool bFPIXDZT;                           //! FPI 7
    quint8 XDZT;                             //! 行动状态 4306 001 7.1逻辑值
    bool bMsgTaskGroup2;                     //! 时间要求组
    MsgTaskGroup2Trans g2;                   //! 时间要求组 8
    bool bMsgTaskGroup5;                     //! 行动地点组
    MsgTaskGroup5Trans g5;                   //! 行动地点组 9    作战区域
    bool bMsgTaskGroup8;                     //! 行动过程组
    MsgTaskGroup8Trans g8;                   //! 行动过程组 10   路径点
    bool bMsgTaskGroup12;                    //! 行动目的组
    MsgTaskGroup12Trans g12;                 //! 行动目的组 11   目标
    bool bMsgTaskGroup14;                    //! 作战资源组
    MsgTaskGroup14Trans g14;                 //! 作战资源组 12
    bool bFPIBZ_40ZF;                        //! FPI 13
    QString BZ_40ZF;
    bool bXDXX;
    QString XDXX;
}MsgTaskTrans;
Q_DECLARE_METATYPE(MsgTaskTrans)


typedef struct _TSFFWQRGroup6Trans
{
    double JD;                         //! 经度 6013 001 23.9.1.2
    double WD;                         //! 纬度 6013 002 23.9.1.3
}CommTSFFWQRGroup6Trans;
Q_DECLARE_METATYPE(CommTSFFWQRGroup6Trans)


typedef struct _TSFFWQGroup3Trans
{
    quint8 JBKH;                        //! 军标库号 4259 026 23.2
    quint32 JBDH;                       //! 军标代号 4259 027 23.3
    unsigned char TSFFWQRJBWZNum;       //! 重复组 23.9.1.1
    QVector<CommTSFFWQRGroup6Trans>JBWZ;
}CommTSFFWQGroup3Trans;
Q_DECLARE_METATYPE(CommTSFFWQGroup3Trans)

typedef struct _TSFFWQGroup1Trans
{
    int NIAN_XD7;                       //! 年
    int YUE;                            //! 月
    int RI;                             //! 日
    int XS;                             //! 时
    int FZ;                             //! 分
    int MIAO;                           //! 秒
}CommTSFFWQGroup1Trans;
Q_DECLARE_METATYPE(CommTSFFWQGroup1Trans)

typedef struct	_TSFFWQTrans
{
    QString ZZDYBH;                     //! 来报单位编码
    QString XXLSH1;                     //! 流水号

    bool bTSFFWQGroup1;                 //! 普通组
    CommTSFFWQGroup1Trans SBSJ;         //! 普通组

    QString BDNM;                       //! 部队内码(我部队不可缺省)
    QString BDBS;                       //! 部队标识
    int JZ;                             //! 军种 枚举
    int BZ;                             //! 兵种 枚举
    int JB;                             //! 部队级别
    int ZCXW;                           //! 战场行为
    int YDFX;                           //! 运动方向 0~360
    QString YDSD14W;                    //! 运动速度14位

    bool bTSFFWQGroup3;                 //! 普通组
    CommTSFFWQGroup3Trans JBXX;         //! 普通组 军标信息
}CommTSFFWQTrans;
Q_DECLARE_METATYPE(CommTSFFWQTrans)

//障碍大小
typedef struct _CommTSFFZAGroup3Trans
{
    double GD;                          //! 高度
    double KD;                          //! 宽度
    double SD;                          //! 深度
}CommTSFFZAGroup3Trans;
Q_DECLARE_METATYPE(CommTSFFZAGroup3Trans)


typedef struct _TSFFZAGroup2Trans
{
    double JD;                          //! 经度
    double WD;                          //! 纬度
    double HB;                          //! 海拔
}CommTSFFZAGroup2Trans;
Q_DECLARE_METATYPE(CommTSFFZAGroup2Trans)


typedef struct _TSFFZAGroup1Trans
{
    int NIAN;                           //! 年_相对7位 6029 401 5.1
    int YUE;                            //! 月 6030 001 5.2逻辑值
    int RI;                             //! 日 6031 001 5.3
    int XS;                             //! 时 6032 001 5.4
    int FZ;                             //! 分 6033 001 5.5
    int MIAO;                           //! 秒 6034 001 5.6
}CommTSFFZAGroup1Trans;
Q_DECLARE_METATYPE(CommTSFFZAGroup1Trans)

typedef struct	_TSFFZATrans
{
    QString XXLSH;                      //! 流水号 6050 401 2
    QString ZZDYBH;                     //! 来报单位编码 6051 402 1
    QString KNM;                        //! 障碍内码 6050 496 9.1
    int ZAZT;                           //! 障碍状态 4306 002 25.1逻辑值
    CommTSFFZAGroup1Trans SBSJ;         //! 来报时间组 5

    int TSFFZAZAWZNum;                  //! 障碍位置
    QVector<CommTSFFZAGroup2Trans>ZAWZ;
    CommTSFFZAGroup3Trans ZADX;         //! 障碍大小
    int ZAZCZ;                          //! 障碍造成者
    int ZALX;                           //! 障碍类型
    QString ZYDW;                       //! 自由电文
    QString AWTP;	                //! 障碍图片
}CommTSFFZATrans;
Q_DECLARE_METATYPE(CommTSFFZATrans)


/** *************激光引导***************/
typedef struct _MsgJGYDXXGroup1Trans
{
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommJGYDXXGroup1Trans;

typedef struct	_MsgJGYDXXTrans
{
    QString XXLSH;//流水号
    QString ZZDYBH;//作战单元编号
    int JGZSZL; //激光照射指令
    MsgCommJGYDXXGroup1Trans JGZSSK;  //激光照射时刻
    int JGZSQBM; //激光照射器编码
    int ZSCXSJ;  //照射持续时间 秒
}MsgCommJGYDXXTrans;



/** ************************************/
typedef struct _GNGNSTrans
{
    quint8 hour;
    quint8 minute;
    quint8 second;
    quint8 millisecond;
    double lat;
    quint8 latdir;  //! 纬度方向 0 ：N北+ 1：S南
    double lon;
    quint8 londir;  //! 经度方向 0 ：E东+ 1：W西
    quint8 modelindication; //!模式指示
    quint8 satelliteNum;        //! 卫星数量
    double accuracyFactor;      //! 水平精度因子
    double alt;                 //! 大地高
    double gap;                 //! 大地水准面差距


}GNGNSTrans;
Q_DECLARE_METATYPE(GNGNSTrans)

#define MAX_SIZE      1000
typedef struct _NodeStateTrans           //! 类型ID：0x030F
{
    quint8 first[4];

    //! BYTE[0]：01；
    //! BYTE[1]：设备类型；0=无人车；1=无人机；2=操控车；3=无人车；4=便携；
    //! BYTE[2]：09
    //! BYTE[3]：00=未同步；01=同步；02=入网。


    quint8 second[10];

    //! BYTE[0]：02：节点自检信息；
    //! BYTE[1]：基带单元，00：正常  01：异常；
    //! BYTE[2]：射频单元，00：正常  01：异常；（不同平台，多个射频单元）
    //! BYTE[3]：同步设备，00：连接  01：未连接；
    //! BYTE[4]：北斗连接，00：连接  01：未连接；
    //! BYTE[5]：保密连接，00：连接  01：未连接；
    //! BYTE[6]：工作参数，00：正常  01：异常；
    //! BYTE[7]：功率值状态，00：正常   01：功率值偏大；-1：功率值偏小。
    //! BYTE[8]：天线状态，00：正常连接  01：异常未连接
    //! BYTE[9]：温度状态，00：正常     01：告警温度超过90度。

    quint8  third[MAX_SIZE];

    //! BYTE[0]： 09：电台软件版本
    //! BYTE[1~n] 波形版本，根据数据包实际长度确定


    quint8 fourth[2];
    //! BYTE[0]： 10：网控器状态
    //! BYTE[1]：00=正常；01异常

}NodeStateTrans;
Q_DECLARE_METATYPE(NodeStateTrans)

typedef  struct _GJQY
{
    double alt;
    double lon;
    double lat;
    QString sx;
}GJQYTrans;
Q_DECLARE_METATYPE(GJQYTrans)


typedef  struct _CZRYZZWZTrans
{
    double lon;
    double lat;
}CZRYZZWZTrans;
Q_DECLARE_METATYPE(CZRYZZWZTrans)

typedef  struct _XDXXTrans
{
    QString MBBH;
    QString MBLX;
    QString MBMC;
    double alt;
    double lon;
    double lat;
    QString RWYQ;
    int RWMGMBLX;
    QString XTLX;
    QString GZMS;
    QString DPPL;
    QString TPPL;
    QString TPWH;
    QString XXMY;
    QString CSMY;
    QVector<GJQYTrans>GJQY;
    QString FSSK;
    QString FXGD;
    QString KZDDSJ;
    QString GJSK;
    CZRYZZWZTrans CZRYZZWZ;

    QString CZRYRWYQ;
    QString CZRYFHYQ;
    QString XZYQ;
    QString DYMC;
    int DL;
    QString QSPL;
    QString ZZPL;
}XDXXTrans;
Q_DECLARE_METATYPE(XDXXTrans)

typedef  struct _WXDWSJTrans
{
    double lon;
    double lat;
    double fwj;
}WXDWSJTrans;
Q_DECLARE_METATYPE(WXDWSJTrans)
/** ************敌部队**************/
typedef struct _MsgEnemyforcesRGroup3Trans
{
        double JD;	//经度
        double WD;	//纬度
        double HB;	//海拔
}MsgCommEnemyforcesRGroup3Trans;
Q_DECLARE_METATYPE(MsgCommEnemyforcesRGroup3Trans)
typedef struct _MsgEnemyforcesGroup2Trans
{
        unsigned char JBLX;	//军标类型
        char JBKH;			//军标库号
        long JBDH;			//军标代号
}MsgCommEnemyforcesGroup2Trans;
Q_DECLARE_METATYPE(MsgCommEnemyforcesGroup2Trans)

typedef struct _MsgEnemyforcesGroup1Trans
{
        short NIAN_XD7;		//年
        unsigned char YUE;	//月
        char RI;			//日
        char XS;			//时
        char FZ;			//分
        char MIAO;			//秒
}MsgCommEnemyforcesGroup1Trans;
Q_DECLARE_METATYPE(MsgCommEnemyforcesGroup1Trans)

typedef struct	_MsgEnemyforcesTrans
{
        QString SJLX;	//数据类型 “MBQB”
        QString ZZDYBH; //作战单元编号
        bool bMsgEnemyforcesGroup1;
        MsgCommEnemyforcesGroup1Trans SBSJ;	//上报时间
        bool bFPIMBBH;
        QString MBBH; //目标编号
        QString MBFL;//目标分类
        bool bFPIZYCD;
        int ZYCD;//重要程度
        bool bFPIFXSD;
        int FXSD;//发现手段
        bool bFPIBDFH;
        QString BDFH;//部队番号(我部队不可缺省)
        int DFJZ;//军种
        bool bFPIDFBZ;
        int DFBZ;//台军外军兵种
        bool bFPIBDDJ;
        int BDDJ;//台军外军部队等级
        bool bFPIZCXW;
        int ZCXW;//战场行为
        bool bMsgEnemyforcesGroup2;
        MsgCommEnemyforcesGroup2Trans JBXX;	//军标信息
        int MsgEnemyforcesNum;	//位置点数量
        QVector<MsgCommEnemyforcesRGroup3Trans>BDWZ;//部队位置
        bool bFPIYDSD;
        QString YDSD; //运动速度
        bool bFPIYDFX;
        QString YDFX; //运动方向
        bool bFPIZSWB;
        QString ZSWB;//注释文本
}MsgCommEnemyTrans;
Q_DECLARE_METATYPE(MsgCommEnemyTrans)
/** ************卫星定位数据************/
/*********************行动过程描述****************************/
typedef  struct _XDGCMS
{
    bool bxdgcms;
    QString xdgcms;
    bool bjbcode;
    double jbcode;
    double lon;
    double lat;
    double alt;
}XDGCMS;
Q_DECLARE_METATYPE(XDGCMS)
/**********************目标信息*******************************/
typedef  struct _TargetinfoTrans
{
    double targetNum;
    quint32 targetIndex;
    double lon;
    double lat;
    double alt;
}TargetinfoTrans;
Q_DECLARE_METATYPE(TargetinfoTrans)

typedef  struct _TaskNumberIndexTrans
{
    double num;
    QString pathKey;
}TaskNumberIndexTrans;
Q_DECLARE_METATYPE(TaskNumberIndexTrans)

typedef  struct _StaticAimInfoTrans
{
    double lon;
    double lat;
    double alt;
    QString prop;
}StaticAimInfoTrans;
Q_DECLARE_METATYPE(StaticAimInfoTrans)

typedef  struct _FeedbackTargetNum
{
    double lon;
    double lat;
}FeedbackTarget;
Q_DECLARE_METATYPE(FeedbackTarget)

typedef  struct _MsgCommTargetInfoTrans
{
    double lon;
    double lat;
    double resvel;
    qint32 resve2;
}MsgCommTargetInfoTrans;
Q_DECLARE_METATYPE(MsgCommTargetInfoTrans)
