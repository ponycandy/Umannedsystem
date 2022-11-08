#pragma once

#include <QObject>

#pragma pack(1)
//如果编译时存在相同变量名称，导致编译通不过，请修改为合适的变量名称编译通过即可
//请不要修改数据类型！


typedef struct _MsgHead
{
    quint16 head;
    quint16 type;
    quint16 length;
}MsgHead;

typedef struct _MsgEnd
{
    quint8 crc;
}MsgEnd;

//! 任务编号
typedef  struct _IssueTaskNumComm
{
    MsgHead head;
    double taskNum;
    MsgEnd end;
}IssueTaskNum;

//! 目标编号
typedef  struct _ReportTargetNum
{
    MsgHead head;
    double targetNum;
    MsgEnd end;
}ReportTargetNum;

typedef struct _MsgCommTaskReplyGroup12
{
    short NIAN;//年 6029 001 8.1.1.5.1
    unsigned char YUE;//月 6030 001 8.1.1.5.2逻辑值
    char RI;//日 6031 001 8.1.1.5.3
    char XS;//小时 6032 001 8.1.1.5.4
    char FZ;//分钟 6033 001 8.1.1.5.5
    char MIAO;//秒 6034 001 8.1.1.5.6
}MsgCommTaskReplyGroup12;

typedef  struct _MsgTaskReplyGroup11
{
    short NIAN;//年 6029 001 8.1.1.4.1
    unsigned char YUE;//月 6030 001 8.1.1.4.2逻辑值
    char RI;//日 6031 001 8.1.1.4.3
    char XS;//小时 6032 001 8.1.1.4.4
    char FZ;//分钟 6033 001 8.1.1.4.5
    char MIAO;//秒 6034 001 8.1.1.4.6
}MsgCommTaskReplyGroup11;

typedef struct _MsgTaskReplyRGroup10
{
    char ZBLX[25];//资源编号 6260 404 8.1.1.2
    quint32 SHSL;//损耗数量 6043 415 8.1.1.3
    bool bMsgTaskReplyGroup11;//普通组
    MsgCommTaskReplyGroup11 g11;//普通组 8.1.1.4
    bool bMsgTaskReplyGroup12;//普通组
    MsgCommTaskReplyGroup12 g12;//普通组 8.1.1.5
}MsgCommTaskReplyRGroup10;

typedef struct _MsgTaskReplyGroup9
{
    unsigned char MsgTaskReplyRGroup10Num;//重复组 8.1.1.1

    MsgCommTaskReplyRGroup10 Rg10[10];//重复组 8.1.1.1
}MsgCommTaskReplyGroup9;

typedef struct _MsgTaskReplyRGroup8
{
    double MBBH;//目标编号 6051 401 7.1.1.2
    bool bFPIMBHSCD;//FPI 7.1.1.3
    unsigned char MBHSCD;//目标状态 6437 401 7.1.1.3.1逻辑值
    bool bFPISSZS;//FPI 7.1.1.4
    quint32 SSZS;//目标毁伤数量 6043 405 7.1.1.4.1
}MsgCommTaskReplyRGroup8;

typedef struct _MsgTaskReplyGroup7
{
    unsigned char MsgTaskReplyRGroup8Num;//重复组 7.1.1.1
    MsgCommTaskReplyRGroup8 Rg8[10];//重复组 7.1.1.1
}MsgCommTaskReplyGroup7;

typedef struct _MsgTaskReplyGroup6
{
    short NIAN;//年 6029 001 6.3.1
    unsigned char YUE;//月 6030 001 6.3.2逻辑值
    char RI;//日 6031 001 6.3.3
    char XS;//小时 6032 001 6.3.4
    char FZ;//分钟 6033 001 6.3.5
    char MIAO;//秒 6034 001 6.3.6
}MsgCommTaskReplyGroup6;

typedef struct _MsgTaskReplyGroup5
{
    bool bFPISJNM;//FPI 6.1
    double SJNM;//事件内码 6050 485 6.1.1
    bool bFPIMS_20ZF;//FPI 6.2
    char MS_20ZF[21];//事件名称 4265 024 6.2.1
    bool bMsgTaskReplyGroup6;//事件发生时间
    MsgCommTaskReplyGroup6 g6;//事件发生时间 6.3
    bool bFPIMS_50ZF;//FPI 6.4
    char MS_50ZF[51];//事件描述 4265 018 6.4.1
}MsgCommTaskReplyGroup5;

typedef struct _MsgTaskReplyGroup4
{
    short NIAN;//年 6029 001 5.6.1
    unsigned char YUE;//月 6030 001 5.6.2逻辑值
    char RI;//日 6031 001 5.6.3
    char XS;//小时 6032 001 5.6.4
    char FZ;//分钟 6033 001 5.6.5
    char MIAO;//秒 6034 001 5.6.6
}MsgCommTaskReplyGroup4;

typedef struct _MsgTaskReplyGroup3
{
    short NIAN;//年 6029 001 5.5.1
    unsigned char YUE;//月 6030 001 5.5.2逻辑值
    char RI;//日 6031 001 5.5.3
    char XS;//小时 6032 001 5.5.4
    char FZ;//分钟 6033 001 5.5.5
    char MIAO;//秒 6034 001 5.5.6
}MsgCommTaskReplyGroup3;

typedef struct _MsgTaskReplyGroup2
{
    double XDBM;//行动编码 6051 405 5.1
    bool bFPIXDZT;//FPI 5.2
    unsigned char XDZT;//行动状态 4306 001 5.2.1逻辑值   //行动状态(1:”未定义” 2:”撤销” 3:”完成” 4:”进行中” 5:”未开始” 6:”暂停”)
    bool bFPIRYSSL;//FPI 5.3
    double RYSSL;//人员损伤率 4307 002 5.3.1
    bool bFPISSZS;//FPI 5.4
    quint32 SSZS;//损失总数 6043 405 5.4.1
    bool bMsgTaskReplyGroup3;//普通组
    MsgCommTaskReplyGroup3 g3;//普通组 5.5
    bool bMsgTaskReplyGroup4;//普通组
    MsgCommTaskReplyGroup4 g4;//普通组 5.6
}MsgCommTaskReplyGroup2;

typedef struct _MsgTaskReplyGroup1
{
    short NIAN;//年 6029 001 4.1
    unsigned char YUE;//月 6030 001 4.2逻辑值
    char RI;//日 6031 001 4.3
    char XS;//小时 6032 001 4.4
    char FZ;//分钟 6033 001 4.5
    char MIAO;//秒 6034 001 4.6
}MsgCommTaskReplyGroup1;

typedef struct	_MsgTaskReply
{
    MsgHead head;                   //! 0xaabb
    bool bFPIZZDYBH;//FPI 1
    double ZZDYBH;//来报单位编码 6051 402 1.1
    bool bFPIBDNM;//FPI 2
    char BDNM[25];//部队内码 4271 012 2.1
    bool bFPIBGNM;//FPI 3
    double BGNM;//报告内码 6050 486 3.1
    bool bMsgTaskReplyGroup1;//普通组
    MsgCommTaskReplyGroup1 g1;//普通组 4
    bool bMsgTaskReplyGroup2;//普通组
    MsgCommTaskReplyGroup2 g2;//普通组 5
    bool bMsgTaskReplyGroup5;//普通组
    MsgCommTaskReplyGroup5 g5;//普通组 6
    bool bMsgTaskReplyGroup7;//普通组
    MsgCommTaskReplyGroup7 g7;//普通组 7
    bool bMsgTaskReplyGroup9;//普通组
    MsgCommTaskReplyGroup9 g9;//普通组 8
    bool bFPIBZ_40ZF;//FPI 9
    char BZ_40ZF[41];//备注_40字符 4075 006 9.1
    MsgEnd end;
}MsgCommTaskReply;

typedef struct _MsgMotionAimGroup4
{
    int CGCZDMBDFW;//车到目标的方位
}MsgCommMotionAimGroup4;

typedef struct _MsgMotionAimGroup3
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}MsgCommMotionAimGroup3;

typedef  struct _MsgMotionAimGroup2  //战场目标
{
    int MBSL; //目标数量
    int MBDX; //目标队形
    char MBBH[50]; //目标编号
    char MBMC[50];  //目标名称
    int MBSX;  //目标属性
    int MBFL;  //目标分类
    int GJLMDQ;  //国家或联盟或地区
    char MBJD[50];  //目标经度
    char MBWD[50];  //目标纬度
    char MBGD[50];  //目标高度
    char YDSD[50];  //运动速度
    char YDFX[50];  //运动方向
    int QDQKTZ;  //活动情况特征
    int MBZT;    //目标状态
    int GJWQ;    //攻击武器
    int ZCXW;    //战场行为
    char XWYT[50];  ///行为意图
    char MBMS[50];  //目标描述
    int FXSD;      //发现手段

    MsgCommMotionAimGroup3 BCWZ; //本车位置
    MsgCommMotionAimGroup4 CYMBXDWZ; //车与目标相对位置

    char ZXPD[50];//最小频段
    char ZDPD[50];//最大频段
    int FSYXH;//辐射源型号
    char PTXH[50];//平台型号

    char MBFWJ[50]; //目标方位角
    char MBFYJ[50]; //目标俯仰角
    int MBJL;  //目标距离
    int ZXD;  //置信度
}MsgCommMotionAimGroup2;


typedef struct _MsgMotionAimGroup1
{
    int NIAN;//年
    int YUE;//月
    int RI;//日
    int XS;//时
    int FZ;//分
    int MIAO;//秒
}MsgCommMotionAimGroup1;

typedef struct	_MsgMotionAim
{
    MsgHead head;                       //! 0x2233
    char SJLX[50]; //数据类型
    char ZZDYBH[50];//作战单元编号
    MsgCommMotionAimGroup1 SBSJ;  //上报时间
    unsigned char MsgMotionAimRMBXXNum;
    MsgCommMotionAimGroup2 MBXX[20];
    MsgEnd  end;
}MsgCommMotionAim;

typedef struct _MsgObstacleGroup3
{
    char GD[50]; //高度
    char KD[50]; //宽度
    char SD[50]; //深度
}MsgCommObstacleGroup3;


typedef struct _MsgObstacleGroup2
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}MsgCommObstacleGroup2;

typedef struct _MsgObstacleGroup1
{
    int NIAN;//年_相对7位 6029 401 5.1
    int YUE;//月 6030 001 5.2逻辑值
    int RI;//日 6031 001 5.3
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommObstacleGroup1;

typedef struct	_MsgObstacle
{
    MsgHead head;                       //! 0x4455
    char SJLX[50];  //数据类型
    char XXLSH[50];//流水号 6050 401 2
    char ZZDYBH[50];//来报单位编码 6051 402 1
    char KNM[50];//障碍内码 6050 496 9.1
    int ZAZT;//障碍状态 4306 002 25.1逻辑值
    MsgCommObstacleGroup1 SBSJ;//来报时间组 5
    MsgCommObstacleGroup2 PTWZ; //平台位置
    int MsgObstacleZAWZNum; //障碍位置
    MsgCommObstacleGroup2 ZAWZ[60];  //障碍位置
    MsgCommObstacleGroup3 ZADX; //障碍大小
    int ZAZCZ;  //障碍造成者
    int ZALX;  //障碍类型
    char ZYDW[30];  //自由电文
    char AWTP[50];	//障碍图片
    MsgEnd  end;
}MsgCommObstacle;


typedef struct _MsgStaticAimGroup1
{
    int NIAN;//年
    int YUE;//月
    int RI;//日
    int XS;//时
    int FZ;//分
    int MIAO;//秒
}MsgCommStaticAimGroup1;

typedef struct	_MsgStaticAim
{
    MsgHead head;                       //! 0x3344
    char SJLX[50]; //数据类型
    char ZZDYBH[50];//作战单元编号
    MsgCommStaticAimGroup1 SBSJ;  //上报时间
    char MBBH[50];  //目标编号
    char MBMC[50];  //目标名称
    int MBSX;       //目标属性
    int MBFL;       //目标分类
    char MBJD[50];  //目标经度
    char MBWD[50];  //目标纬度
    char MBGD[50];  //目标高度
    int  MBSL;      //目标数量
    int  MBXZ;      //目标形状
    int  MBJG;      //目标结构
    int  MBCZ;      //目标材质
    int  MBHD;      //目标厚度
    char SSBDMBBH[50];  //所属部队目标编号
    char ZSBDMBBH[50];  //驻守部队目标编号
    int  JDBZ;      //禁打标志
    int  HSCD;      //毁伤程度
    char MBMS[50];  //目标描述
    int  FXSD;      //发现手段

    char ZXPD[50];//最小频段
    char ZDPD[50];//最大频段
    int FSYXH;//辐射源型号
    char PTXH[50];//平台型号

    char MBFWJ[50]; //目标方位角
    char MBFYJ[50]; //目标俯仰角
    int MBJL;  //目标距离
    int ZXD;  //置信度
    MsgEnd  end;

}MsgCommStaticAim;

//! 侦察监视无人车
typedef struct _MsgStatus201ZCJSZDYTGroup2
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}MsgCommStatus201ZCJSZDYTGroup2;


typedef struct _MsgStatus201ZCJSZDYTGroup5  //任务载荷状态信息
{
    int SZGZZT;  //上装工作状态
    int ZCZBSNZT; //侦察设备使能状态
    int JQSYDYSL;  //机枪剩余弹药数量
    int DLDSYSL;   //催泪弹剩余数量

    int QWLXXZ;  //武器类型选择
    int DDSYDYSL; //导弹剩余弹药数量
    int SLPSYDL;//30炮剩余弹量
    int YMDSYDL;  //烟幕弹剩余弹量
}MsgCommStatus201ZCJSZDYTGroup5;


//专用信息
typedef struct _MsgStatus201ZCJSZDYTGroup4
{
    int DWZL;  //定位质量
    MsgCommStatus201ZCJSZDYTGroup5 RWZHZTXX;
    unsigned char MsgStatus201ZCJSZDYTRWLJDNum; //任务路径点个数
    MsgCommStatus201ZCJSZDYTGroup2 RWLJD[50];  //任务路径点
}MsgCommStatus201ZCJSZDYTGroup4;

typedef struct _MsgStatus201ZCJSZDYTGroup3
{
    char FWJ[50]; //方位角
    char CQJ[50];  //侧倾角
    char YJJ[50];  //俯仰角
}MsgCommStatus201ZCJSZDYTGroup3;

typedef struct _MsgStatus201ZCJSZDYTGroup1
{
    int NIAN_XD7;//年_相对7位 6029 401 5.1
    int YUE;//月 6030 001 5.2逻辑值
    int RI;//日 6031 001 5.3
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommStatus201ZCJSZDYTGroup1;

typedef struct	_MsgStatus201ZCJSZDYT
{
    MsgHead head;                       //! 0xccdd
    char SJLX[50]; //数据类型
    char XXLSH[50];//流水号
    char ZZDYBH[50];//作战单元编号
    MsgCommStatus201ZCJSZDYTGroup1 SBSJ;  //无人平台状态上报时间
    MsgCommStatus201ZCJSZDYTGroup2 PTWZ;  //无人平台位置
    MsgCommStatus201ZCJSZDYTGroup2 ZDWZ;  //终端位置（远程操控车或便携式操控终端）

    MsgCommStatus201ZCJSZDYTGroup3 PTZTJ;  //平台姿态角

    int PTDW;  //无人平台档位
    char PTYDSD[50];  //平台运动速度
    int PTKZMS;  //平台控制模式
    int PTJMZSZT;  //无人平台静默值守状态
    int DLMS;  //动力模式
    char XHLC[50]; //续航里程（公里，字符串）
    int XHSJ;      //续航时间（分钟,整形）
    int	SYDL;     //剩余电量（整形）
    int	SYYL;      //剩余油量（整形）
    int ZBZHJKZT;  //装备综合健康状态（枚举值）
    int PTDPJKZT;  //平台底盘健康状态（枚举值）
    int TXSBJKZT;  //通信设备健康状态（枚举值）
    char GZMXX[100];     //故障码信息（字符串）
    char ZYDW[30];    //自由电文（不超过30字符）

    MsgCommStatus201ZCJSZDYTGroup4 ZYXX;  //专用信息
    MsgEnd end;
}MsgCommStatus201ZCJSZDYT;


//! 电子作战无人车
typedef struct _MsgStatusDZZZGroup2
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}MsgCommStatusDZZZGroup2;

typedef struct _MsgStatusDZZZGroup10
{
    int VHFUHF_BDZCGRSB; //VHF/UHF波段侦察干扰设备
    int LSC_BDZCGRSB;  //L/S/C波段侦察干扰设备
    int XKUKA_BDZCGRSB; //X/Ku/Ka波段侦察干扰设备
    int GXGCSB; //光学观察设备
    int SJCLYKZSB;  //数据处理与控制设备
    int SFCDSB; //伺服传动设备
}MsgCommStatusDZZZGroup10;

typedef struct _MsgStatusDZZZGroup9
{
    int SFZTFWJ;  //伺服转台方位角
    int SFZTFYJ;  //伺服转台俯仰角
}MsgCommStatusDZZZGroup9;

typedef struct _MsgStatusDZZZGroup8
{
    int GZZT;  //工作状态
    char MNFSYXH[50];  //模拟辐射源型号
}MsgCommStatusDZZZGroup8;

typedef struct _MsgStatusDZZZGroup7
{
    int GZZT;  //工作状态
    int GRQSPL; //干扰起始频率
    int GRZZPL; //干扰终止频率
}MsgCommStatusDZZZGroup7;


typedef struct _MsgStatusDZZZGroup6
{
    int GZZT;  //工作状态
    int ZCQSPL; //侦察起始频率
    int ZCZZPL; //侦察终止频率
}MsgCommStatusDZZZGroup6;

typedef struct _MsgStatusDZZZGroup5
{
    MsgCommStatusDZZZGroup6 LDZCZT;  //雷达侦察状态
    MsgCommStatusDZZZGroup7 LDGRZT;  //雷达干扰状态
    MsgCommStatusDZZZGroup6 TXZCZT;  //通信侦察状态
    MsgCommStatusDZZZGroup7 TXGRZT;  //通信干扰状态
    MsgCommStatusDZZZGroup8 XHMNZT;  //信号模拟状态
    int GXGCZT;  //光学观察状态
    MsgCommStatusDZZZGroup9 SFCDSBZT;  //伺服传动设备状态
    MsgCommStatusDZZZGroup10 ZHJKZT;  //载荷健康状态
}MsgCommStatusDZZZGroup5;

//专用信息
typedef struct _MsgStatusDZZZGroup4
{
    int DWZL;  //定位质量
    unsigned char MsgStatusDZZZRWLJDNum; //任务路径点个数
    MsgCommStatusDZZZGroup2 RWLJD[50];  //任务路径点
    MsgCommStatusDZZZGroup5 RWZHZTXX;  //任务载荷状态信息
}MsgCommStatusDZZZGroup4;

typedef struct _MsgStatusDZZZGroup3
{
    char HXJ[50]; //航向角
    char CQJ[50];  //侧倾角
    char YJJ[50];  //俯仰角
}MsgCommStatusDZZZGroup3;


typedef struct _MsgStatusDZZZGroup1
{
    int NIAN_XD7;//年_相对7位 6029 401 5.1
    int YUE;//月 6030 001 5.2逻辑值
    int RI;//日 6031 001 5.3
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommStatusDZZZGroup1;



typedef struct	_MsgStatusDZZZ
{
    MsgHead head;               //! 0xbbcc
    char SJLX[50]; //数据类型
    char XXLSH[50];//流水号
    char ZZDYBH[50];//作战单元编号
    MsgCommStatusDZZZGroup1 SBSJ;  //无人平台状态上报时间
    MsgCommStatusDZZZGroup2 PTWZ;  //无人平台位置
    MsgCommStatus201ZCJSZDYTGroup2 ZDWZ;  //终端位置（远程操控车或便携式操控终端）
    MsgCommStatusDZZZGroup3 PTZTJ;  //平台姿态角
    int PTJDZT;  //无人平台机动状态
    char PTYDSD[50];  //平台运动速度
    int PTKZMS;  //平台控制模式
    int PTJMZSZT;  //无人平台静默值守状态
    int DLMS;  //动力模式
    char XHLC[50]; //续航里程（公里，字符串）
    int XHSJ;      //续航时间（分钟,整形）
    int	SYDL;     //剩余电量（整形）
    int	SYYL;      //剩余油量（整形）
    int ZBZHJKZT;  //装备综合健康状态（枚举值）
    int PTDPJKZT;  //平台底盘健康状态（枚举值）
    int TXSBJKZT;  //通信设备健康状态（枚举值）
    char GZMXX[100];     //故障码信息（字符串）
    char ZYDW[30];    //自由电文（不超过30字符）
    MsgCommStatusDZZZGroup4 ZYXX;  //专用信息
    MsgEnd end;
}MsgCommStatusDZZZ;

//! 防空支援无人车
typedef struct _MsgStatusFKZYGroup2
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}MsgCommStatusFKZYGroup2;

typedef struct _MsgStatusFKZYGroup6  //上装健康状态
{
    int LD;	//雷达（枚举值）
    int GD;	//光电（枚举值）
    int HLZT;	//火力转塔（枚举值）
    int ZZGLKZXT;	//作战管理控制系统（枚举值）
    int FK;  //导弹发控（枚举值）
    int GUANDAO;  //惯导（枚举值）
    int TXXT; //通信系统（枚举值）
}MsgCommStatusFKZYGroup6;

typedef struct _MsgStatusFKZYGroup5  //任务载荷状态信息
{
    int HJDSYDL;	//火箭弹剩余弹量（整形）
    int DDSYDL;	//导弹剩余弹量（整形）
}MsgCommStatusFKZYGroup5;


//专用信息
typedef struct _MsgStatusFKZYGroup4
{
    int SXZL;  //搜星质量（枚举值）
    int CFDWZL;  //差分定位质量（枚举值）
    int SZSDQK; //上装上电情况（枚举值）
    MsgCommStatusFKZYGroup5 ZHZTSJ; //载荷状态数据
    int DZXX;   //弹种信息（枚举值）
    MsgCommStatusFKZYGroup6 SZJKZT; //上装健康状态
    int SZGZMS;  //上装工作模式（枚举值）

}MsgCommStatusFKZYGroup4;

typedef struct _MsgStatusFKZYGroup3
{
    char FWJ[50]; //方位角
    char CQJ[50];  //侧倾角
    char YJJ[50];  //俯仰角
}MsgCommStatusFKZYGroup3;

typedef struct _MsgStatusFKZYGroup1
{
    int NIAN_XD7;//年_相对7位 6029 401 5.1
    int YUE;//月 6030 001 5.2逻辑值
    int RI;//日 6031 001 5.3
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommStatusFKZYGroup1;



typedef struct	_MsgStatusFKZY
{
    MsgHead head;                   //! 0xddee
    char SJLX[50]; //数据类型
    char XXLSH[50];//流水号
    char ZZDYBH[50];//作战单元编号
    MsgCommStatusFKZYGroup1 SBSJ;  //无人平台状态上报时间
    MsgCommStatusFKZYGroup2 PTWZ;  //无人平台位置
    MsgCommStatus201ZCJSZDYTGroup2 ZDWZ;  //终端位置（远程操控车或便携式操控终端）

    MsgCommStatusFKZYGroup3 PTZTJ;  //平台姿态角

    int PTJDZT;  //平台机动状态（枚举值）
    char PTYDSD[50];  //平台运动速度
    int PTKZMS;  //平台控制模式
    char XHLC[50]; //续航里程（公里，字符串）
    int XHSJ;      //续航时间（分钟,整形）
    int	SYDL;     //剩余电量（整形）
    int	SYYL;      //剩余油量（整形）
    int ZBZHJKZT;  //装备综合健康状态（枚举值）
    int PTDPJKZT;  //平台底盘健康状态（枚举值）
    int TXSBJKZT;  //通信设备健康状态（枚举值）
    char GZMXX[100];     //故障码信息（字符串）
    char ZYDW[30];    //自由电文（不超过30字符）

    MsgCommStatusFKZYGroup4 ZYXX;  //专用信息
    MsgEnd end;
}MsgCommStatusFKZY;

typedef struct _MsgTaskGroup18
{
    double JD_JD00013F;//位置点经度_精度0.0013分   6013 001 10.1.1.3.2.1.2
    double WD_JD00013F;//位置点纬度_精度0.0013分 6013 002 10.1.1.3.2.1.3
    double GD_JD00013F;//位置点高度 6013 002 9.2.2.1.3
}MsgCommTaskGroup18;

typedef struct _MsgTaskGroup17
{
    short NIAN;//年 6029 001 12.1.1.5.1
    unsigned char YUE;//月 6030 001 12.1.1.5.2逻辑值
    char RI;//日 6031 001 12.1.1.5.3
    char XS;//小时 6032 001 12.1.1.5.4
    char FZ;//分钟 6033 001 12.1.1.5.5
    char MIAO;//秒 6034 001 12.1.1.5.6
}MsgCommTaskGroup17;

typedef struct _MsgTaskGroup16
{
    short NIAN;//年 6029 001 12.1.1.4.1
    unsigned char YUE;//月 6030 001 12.1.1.4.2逻辑值
    char RI;//日 6031 001 12.1.1.4.3
    char XS;//小时 6032 001 12.1.1.4.4
    char FZ;//分钟 6033 001 12.1.1.4.5
    char MIAO;//秒 6034 001 12.1.1.4.6
}MsgCommTaskGroup16;

typedef struct _MsgTaskRGroup15
{
    char WZLX[25];//物资类型 6260 406 12.1.1.2
    quint32 SL_17;//物资数量 6043 504 12.1.1.3
    bool bMsgTaskGroup16;//资源计划开始使用时间组
    MsgCommTaskGroup16 g16;//资源计划开始使用时间组 12.1.1.4
    bool bMsgTaskGroup17;//资源计划结束使用时间组
    MsgCommTaskGroup17 g17;//资源计划结束使用时间组 12.1.1.5
}MsgCommTaskRGroup15;

typedef struct _MsgTaskGroup14
{
    unsigned char MsgTaskRGroup15Num;//重复组 12.1.1.1
    MsgCommTaskRGroup15 Rg15[10];//重复组 12.1.1.1
}MsgCommTaskGroup14;

typedef struct _MsgTaskRGroup13
{
    double MBBH;//目标编号 6051 401 11.1.1.2
    unsigned char MBHSCD;//目标状态 6437 401 11.1.1.3逻辑值
    bool bFPISSZS;//FPI 11.1.1.4
    quint32 SSZS;//目标毁伤数量 6043 405 11.1.1.4.1
    bool bFPIMS_50ZF;//FPI 11.1.1.5
    char MS_50ZF[51];//目的描述 4265 018 11.1.1.5.1
    char MBLX[41];//目标类型 4054 050 4 设施目标 武器装备类 敌部队部署目标
    bool bMsgTaskGroup18;//行动目标位置组
    MsgCommTaskGroup18 g18;//行动目标位置组 12.1.1.5
}MsgCommTaskRGroup13;

typedef struct _MsgTaskGroup12
{
    unsigned char MsgTaskRGroup13Num;//重复组 11.1.1.1
    MsgCommTaskRGroup13 Rg13[10];//重复组 11.1.1.1
}MsgCommTaskGroup12;

typedef struct _MsgTaskRGroup11
{
    double JD_JD00013F;//位置点经度_精度0.0013分   6013 001 10.1.1.3.2.1.2
    double WD_JD00013F;//位置点纬度_精度0.0013分 6013 002 10.1.1.3.2.1.3
    double GD_JD00013F;//位置点高度 6013 002 9.2.2.1.3
    char ZBSX[11];//坐标属性 4054 050 4 起始点 途径点 终止点 作战点
}MsgCommTaskRGroup11;

typedef struct _MsgTaskGroup10
{
    double JBCODE;//军标CODE 4259 002 10.1.1.3.1
    unsigned char MsgTaskRGroup11Num;//重复组 10.1.1.3.2.1.1
    MsgCommTaskRGroup11 Rg11[20];//重复组 10.1.1.3.2.1.1
}MsgCommTaskGroup10;

typedef struct _MsgTaskRGroup9
{
    bool bFPIMS_50ZF;//FPI 10.1.1.2
    char MS_50ZF[51];//行动过程描述_50字符 4265 018 10.1.1.2.1
    bool bMsgTaskGroup10;//行动地点相关军标组
    MsgCommTaskGroup10 g10;//行动地点相关军标组 10.1.1.3
}MsgCommTaskRGroup9;

typedef struct _MsgTaskGroup8
{
    unsigned char MsgTaskRGroup9Num;//行动过程重复组 10.1.1.1
    MsgCommTaskRGroup9 Rg9[5];//行动过程重复组 10.1.1.1
}MsgCommTaskGroup8;

typedef struct _MsgTaskRGroup7
{
    double JD_JD00013F;//位置点经度_精度0.0013分   6013 001 9.2.2.1.2
    double WD_JD00013F;//位置点纬度_精度0.0013分 6013 002 9.2.2.1.3
    double GD_JD00013F;//位置点高度 6013 002 9.2.2.1.3
    char ZBSX[11];//坐标属性 4054 050 4
}MsgCommTaskRGroup7;

typedef struct _MsgTaskGroup6
{
    double JBCODE;//军标CODE 4259 002 9.2.1
    unsigned char MsgTaskRGroup7Num;//位置信息重复组 9.2.2.1.1
    MsgCommTaskRGroup7 Rg7[20];//位置信息重复组 9.2.2.1.1 如果Num是2就是圆  大于2是多边形 按照他发的顺序链接
}MsgCommTaskGroup6;

typedef struct _MsgTaskGroup5
{
    bool bFPIMS_50ZF;//FPI 9.1
    char MS_50ZF[51];//行动地点描述 4265 018 9.1.1
    bool bMsgTaskGroup6;//行动地点相关军标组
    MsgCommTaskGroup6 g6;//行动地点相关军标组 9.2
}MsgCommTaskGroup5;

typedef struct _MsgTaskGroup4
{
    short NIAN;//年 6029 001 8.2.1
    unsigned char YUE;//月 6030 001 8.2.2逻辑值
    char RI;//日 6031 001 8.2.3
    char XS;//小时 6032 001 8.2.4
    char FZ;//分钟 6033 001 8.2.5
    char MIAO;//秒 6034 001 8.2.6
}MsgCommTaskGroup4;

typedef struct _MsgTaskGroup3
{
    short NIAN;//年 6029 001 8.1.1
    unsigned char YUE;//月 6030 001 8.1.2逻辑值
    char RI;//日 6031 001 8.1.3
    char XS;//小时 6032 001 8.1.4
    char FZ;//分钟 6033 001 8.1.5
    char MIAO;//秒 6034 001 8.1.6
}MsgCommTaskGroup3;

typedef struct _MsgTaskGroup2
{
    bool bMsgTaskGroup3;//行动计划开始执行时间组
    MsgCommTaskGroup3 g3;//行动计划开始执行时间组 8.1
    bool bMsgTaskGroup4;//行动计划结束执行时间组
    MsgCommTaskGroup4 g4;//行动计划结束执行时间组 8.2
}MsgCommTaskGroup2;

typedef struct _MsgTaskGroup1
{
    short NIAN;//年 6029 001 2.1
    unsigned char YUE;//月 6030 001 2.2逻辑值
    char RI;//日 6031 001 2.3
    char XS;//小时 6032 001 2.4
    char FZ;//分钟 6033 001 2.5
    char MIAO;//秒 6034 001 2.6
}MsgCommTaskGroup1;

//! 新添加
typedef struct _MsgTaskGroup20
{
    bool BFPIXTCYZL;
    char XTCYZL;//协同成员种类 4271 012 5.1
    bool BFPIXTJS;
    char XTJS;//协同角色 4265 018 6.1
    bool BFPIXTMS;
    char XTMS[51];//协同描述 4271 012 5.1
}MsgCommTaskGroup20;


typedef struct _MsgTaskGroup19
{
    unsigned char MsgTaskGroup20Num;//协同信息重复组
    MsgCommTaskGroup20 Rg20[5];//协同信息重复组
}MsgCommTaskGroup19;
//! 新添加

typedef struct	_MsgTask
{
    MsgHead head;                       //! 0x6677
    bool bFPIZZDYBH;//FPI 1
    double ZZDYBH;//发布命令的席位编号 6051 402 1.1
    bool bMsgTaskGroup1;//发布时间组
    MsgCommTaskGroup1 g1;//发布时间组 2
    double XDBM;//行动编码 6051 405 3
    char XDMC[41];//行动名称 4054 050 4
    bool bFPIBDNM;//FPI 5
    char BDNM[25];//部队内码 4271 012 5.1
    bool bFPIMS_50ZF;//FPI 6
    char MS_50ZF[51];//命令的文字描述 4265 018 6.1、

    bool bMsgTaskGroup19;//协同信息组
    MsgCommTaskGroup19 g19;// 协同信息组

//    char RWMGMBLX;//任务敏感目标类型 4265 018 6.1 // 暂时不要了
    bool bFPIXDZT;//FPI 7
    unsigned char XDZT;//行动状态 4306 001 7.1逻辑值
    bool bMsgTaskGroup2;//时间要求组
    MsgCommTaskGroup2 g2;//时间要求组 8
    bool bMsgTaskGroup5;//行动地点组
    MsgCommTaskGroup5 g5;//行动地点组 9  作战区域 地图标会 有圆 和其他的
    bool bMsgTaskGroup8;//行动过程组
    MsgCommTaskGroup8 g8;//行动过程组 10 路点信息 地图显示 发给地盘
    bool bMsgTaskGroup12;//行动目的组
    MsgCommTaskGroup12 g12;//行动目的组 11 目标信息 地图上标会 引导打击
    bool bMsgTaskGroup14;//作战资源组
    MsgCommTaskGroup14 g14;//作战资源组 12
    bool bFPIBZ_40ZF;//FPI 13
    char BZ_40ZF[41];//备注_40字符 4075 006 13.1
    bool bXDXX;
    char XDXX[1000];
    MsgEnd  end;
}MsgCommTask;


typedef struct _TSFFWQRGroup6
{
    char JD[50];//经度 6013 001 23.9.1.2
    char WD[50];//纬度 6013 002 23.9.1.3
}CommTSFFWQRGroup6;

typedef struct _TSFFWQGroup3
{
    qint32 JBKH;//军标库号 4259 026 23.2
    qint32 JBDH;//军标代号 4259 027 23.3
    unsigned char TSFFWQRJBWZNum;//重复组 23.9.1.1
    CommTSFFWQRGroup6 JBWZ[60];//重复组 23.9.1.1
}CommTSFFWQGroup3;

typedef struct _TSFFWQGroup1
{
    int NIAN_XD7;//年
    int YUE;//月
    int RI;//日
    int XS;//时
    int FZ;//分
    int MIAO;//秒
}CommTSFFWQGroup1;

typedef struct	_TSFFWQ
{
    MsgHead head; //! 0xaabb
    char ZZDYBH[50];//来报单位编码
    char XXLSH1[50];//流水号

    bool bTSFFWQGroup1;//普通组
    CommTSFFWQGroup1 SBSJ;//普通组

    bool bFPIBDNM;
    char BDNM[25];//部队内码(我部队不可缺省)

    bool bFPIBDBS;
    char BDBS[81];//部队标识

    int JZ;//军种 枚举

    bool bFPIBZ;
    int BZ;//兵种 枚举

    bool bFPIJB;
    int JB;//部队级别

    bool bFPIZCXW;
    int ZCXW;//战场行为

    bool bFPIYDFX;
    int YDFX;//运动方向 0~360

    bool bFPIYDSD;
    char YDSD14W[50];//运动速度14位

    bool bTSFFWQGroup3;//普通组
    CommTSFFWQGroup3 JBXX;//普通组 军标信息
    MsgEnd end;
}CommTSFFWQ;

//障碍大小
typedef struct _CommTSFFZAGroup3
{
    char GD[50]; //高度
    char KD[50]; //宽度
    char SD[50]; //深度
}CommTSFFZAGroup3;


typedef struct _TSFFZAGroup2
{
    char JD[50];//经度
    char WD[50];//纬度
    char HB[50];//海拔
}CommTSFFZAGroup2;



typedef struct _TSFFZAGroup1
{
    int NIAN;//年_相对7位 6029 401 5.1
    int YUE;//月 6030 001 5.2逻辑值
    int RI;//日 6031 001 5.3
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}CommTSFFZAGroup1;

typedef struct	_TSFFZA
{
    MsgHead head;       //! 0xbbcc
    char XXLSH[50];//流水号 6050 401 2
    char ZZDYBH[50];//来报单位编码 6051 402 1
    char KNM[50];//障碍内码 6050 496 9.1
    int ZAZT;//障碍状态 4306 002 25.1逻辑值
    CommTSFFZAGroup1 SBSJ;//来报时间组 5
    int TSFFZAZAWZNum; //障碍位置
    CommTSFFZAGroup2 ZAWZ[20];  //障碍位置
    CommTSFFZAGroup3 ZADX; //障碍大小
    int ZAZCZ;  //障碍造成者
    int ZALX;  //障碍类型
    char ZYDW[30];  //自由电文
    char AWTP[50];	//障碍图片
    MsgEnd end;
}CommTSFFZA;


/** ***************激光引导*************/

typedef struct _MsgJGYDXXGroup1
{
    int XS;//时 6032 001 5.4
    int FZ;//分 6033 001 5.5
    int MIAO;//秒 6034 001 5.6
}MsgCommJGYDXXGroup1;

typedef struct	_MsgJGYDXX
{
    MsgHead head;               //! 0xccdd
    char XXLSH[50];//流水号
    char ZZDYBH[50];//作战单元编号
    int JGZSZL; //激光照射指令
    MsgCommJGYDXXGroup1 JGZSSK;  //激光照射时刻
    int JGZSQBM; //激光照射器编码
    int ZSCXSJ;  //照射持续时间 秒
    MsgEnd end;
}MsgCommJGYDXX;

/** ************敌部队**************/
typedef struct _MsgEnemyforcesRGroup3
{
        char JD[50];	//经度
        char WD[50];	//纬度
        char HB[50];	//海拔
}MsgCommEnemyforcesRGroup3;
typedef struct _MsgEnemyforcesGroup2
{
        unsigned char JBLX;	//军标类型
        char JBKH;			//军标库号
        long JBDH;			//军标代号
}MsgCommEnemyforcesGroup2;
typedef struct _MsgEnemyforcesGroup1
{
        short NIAN_XD7;		//年
        unsigned char YUE;	//月
        char RI;			//日
        char XS;			//时
        char FZ;			//分
        char MIAO;			//秒
}MsgCommEnemyforcesGroup1;

typedef struct	_MsgEnemyforces
{
        char SJLX[50];	//数据类型 “MBQB”
        char ZZDYBH[50]; //作战单元编号
        bool bMsgEnemyforcesGroup1;
        MsgCommEnemyforcesGroup1 SBSJ;	//上报时间
        bool bFPIMBBH;
        char MBBH[50]; //目标编号
        char MBFL[65];//目标分类
        bool bFPIZYCD;
        int ZYCD;//重要程度
        bool bFPIFXSD;
        int FXSD;//发现手段
        bool bFPIBDFH;
        char BDFH[81];//部队番号(我部队不可缺省)
        int DFJZ;//军种
        bool bFPIDFBZ;
        int DFBZ;//台军外军兵种
        bool bFPIBDDJ;
        int BDDJ;//台军外军部队等级
        bool bFPIZCXW;
        int ZCXW;//战场行为
        bool bMsgEnemyforcesGroup2;
        MsgCommEnemyforcesGroup2 JBXX;	//军标信息
        int MsgEnemyforcesNum;	//位置点数量
        MsgCommEnemyforcesRGroup3 BDWZ[60];	//部队位置
        bool bFPIYDSD;
        char YDSD[50]; //运动速度
        bool bFPIYDFX;
        char YDFX[50]; //运动方向
        bool bFPIZSWB;
        char ZSWB[101];//注释文本
}MsgCommEnemy;
/** ************卫星定位数据************/

typedef  struct _WXDWSJ
{
    MsgHead head;       //!0xaaff
    qint32 lon;
    qint32 lat;
    qint32 fwj;
    MsgEnd end;
}WXDWSJ;

typedef  struct _MsgAck
{
    MsgHead head;
}MsgAck;

typedef  struct _MsgCommTargetInfo
{
    MsgHead head;       //!0xbbff
    double lon;
    double lat;
    double resvel;
    qint32 resve2;
}MsgCommTargetInfo;
#pragma pack()
