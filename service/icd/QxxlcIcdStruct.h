#pragma once

#include <stdint.h>
#include <QVector>

#pragma pack(1)

//! *********************************************遥控端与警戒监视模块信息交互**************************************
//! 头部
typedef struct _RemoteToAlertHead
{
    quint8      head;           //! 报文头       0x7F
    quint8      sourceCode;     //! 信源主机代号  数据发送方设备代号
    quint8      letterCode;     //! 信宿主机代号  数据接收方设备代号
    quint16     len;            //! 报文长度     从报文头开始的整个报文的长度
    quint8      msgID;          //! 报名标志
}RemoteToAlertHead;

//! 尾部
typedef struct _RemoteToAlertEnd
{
    quint8      checkWord;      //! 校验字 CRC8校验，从报文头到数据尾所有数据
    quint8      end;            //! 报文尾 0x7E
}RemoteToAlertEnd;

//! **************************************遥控端向警戒监视模块发送报文*****************************************
//! 系统工作模式设置报文	   报文标识 01H
typedef struct _SystemWorkModeSet
{
    RemoteToAlertHead   head;
    quint8              mode;     //! 系统工作 0x00:值更; 0x01:搜索; 0x02:跟踪; 0x03:拒止
    RemoteToAlertEnd    end;
}SystemWorkModeSet;

//! 视频通道选择报文	   报文标识 03H
typedef struct _VideoChannelSelect
{
    RemoteToAlertHead   head;
    quint8              channel;     //! 通道 0x01 红外; 0x02 电视（默认） 0x03 周视通道一; 0x04 周视通道二; 0x05 周视通道三
                                     //!      0x06 周视通道四; 0x07 周视通道五; 0x08 周视通道六; 0x09 周视全通道
    RemoteToAlertEnd    end;
}VideoChannelSelect;

//! 行为识别操作报文	   报文标识 04H
typedef struct _BehaviorRecognition
{
    RemoteToAlertHead   head;
    quint8              behavior;     //! 行为识别 0x05：行为识别；0x00：取消
    RemoteToAlertEnd    end;
}BehaviorRecognition;

//! 系统关闭报文             报文标识 06H
typedef struct _SystemShutdown
{
    RemoteToAlertHead   head;
    RemoteToAlertEnd    end;
}SystemShutdown;

//! 图像保存报文             报文标识 07H
typedef struct _ImageSave
{
    RemoteToAlertHead   head;
    quint8              startSave;      //! 开始存图 0x00：停止保存；0x01：开始保存
    quint8              timeInterval;   //! 时间间隔  [1,10]
    RemoteToAlertEnd    end;
}ImageSave;

//! 自主工作模式报文	   报文标识 08H
typedef struct _AutoWorkModeSet
{
    RemoteToAlertHead   head;
    quint8              mode;     //! 自主模式 0x01:模式1; 0x02:模式2; 0x03:模式3; 0x04:模式4; 0x05:模式5;
                                  //!        0x06:模式6; 0x07:模式7; 0x08:模式8; 0x00:模式0
    quint8              control;  //! 开始/停止控制 0x01:任务开始；0x10:任务结束
    RemoteToAlertEnd    end;
}AutoWorkModeSet;

//! 设备使能设置报文	   报文标识 21H
typedef struct _DeviceEnableSet
{
    RemoteToAlertHead   head;
    quint8              enable;     //! 设备使能 1：使能 0：不使能
                                    //! Bit0 伺服使能; Bit1 红外使能; Bit2 测距激光使能; Bit3 眩目激光使能;
                                    //! Bit4 强光使能; Bit5 预留; Bit6 光发送板使能; Bit7 多路（头部电源板、电视电源板、光接收板、射击控制板、计算机板、全景相机）使能
    RemoteToAlertEnd    end;
}DeviceEnableSet;

//! 目标指示报文             报文标识 22H
typedef struct _GoalIndication
{
    RemoteToAlertHead   head;
    quint8              coordinateSystem; //! 目指坐标系 0x01：大地系；0x02： 载体系
    quint16             posAngle;         //! 目标方位角	量纲360°/65536，范围（0-360°）
    qint16              pitchAngle;       //! 目标俯仰角	量纲90°/32768,范围（-90°-90°）
    qint8               reserved1;        //! 预留位
    RemoteToAlertEnd    end;
}GoalIndication;

//! 手动伺服控制命令报文	   报文标识 24H
typedef struct _ManualServoControl
{
    RemoteToAlertHead   head;
    quint8              JoystickFlag;        //! 操纵杆标志位 0x01 光电方位俯仰; 0x02 拒止方位俯仰; 0x03 强声俯仰; 0x04 武器随动光电
    qint8               posSpeed;            //! 方位伺服速度 -128-127（顺时针为正值，逆时针为负值，向上为正值，向下为负值）
    qint8               pitchServoSpeed;     //! 俯仰伺服速度 -128-127（顺时针为正值，逆时针为负值，向上为正值，向下为负值）
    quint8              joystickSpeed;       //! 操纵杆速度档位 0x01-0x0A 十个速度等级可选（默认0x05不变）
    RemoteToAlertEnd    end;
}ManualServoControl;

//! 开始/停止激光测距命令报文  报文标识 25H
typedef struct _LaserRang
{
    RemoteToAlertHead   head;
    quint8              rang;           //! 测距命令 0x00 停止测距; 0x01 开始测距
    qint8               reserved1;      //! 预留位
    qint8               reserved2;
    qint8               reserved3;
    qint8               reserved4;
    qint8               reserved5;
    qint8               reserved6;
    RemoteToAlertEnd    end;
}LaserRang;


//! 电视传感器操作报文	   报文标识 27H
typedef struct _TVSensor01
{
    RemoteToAlertHead   head;
    quint8              type;           //! 指令类型 0x01
    quint8              zoom;           //! 变焦	0x01 视场变大; 0x02 视场变小; 0x00 视场变化停止（默认）
    quint8              focus;          //! 调焦	0x01 调焦远; 0x02 调焦近; 0x00 调焦动作停止（默认）
    quint8              posSet;         //! 预置位设置 0x00 不设置（手动调焦）（默认）; 0x01 3-5Km; 0x02 1.5-3Km; 0x03 1-1.5Km
                                        //! 0x04 0.5-1Km; 0x05 0.2-0.5Km; 0x06 0.1-0.2Km; 0x07 100m内
    quint8              reserved1;      //! 预留位
    quint8              reserved2;
    quint8              reserved3;
    RemoteToAlertEnd    end;
}TVSensor01;

typedef struct _TVSensor02
{
    RemoteToAlertHead   head;
    quint8              type;           //! 指令类型 0x02
    quint8              zoom;           /** 功能控制
                                            0x01 光学透雾开
                                            0x02 光学透雾关
                                            0x03 电子透雾开
                                            0x04 电子透雾关
                                            0x05 恢复自动曝光
                                            0x06 自动聚焦开
                                            0x07 自动聚焦关
                                            0x08 手动一键聚焦
                                            0x09 自动曝光开
                                            0x0A 自动曝光关
                                            0x0B 彩色模式
                                            0x0C 黑白模式
                                            0x0D 降噪开
                                            0x0E 降噪关
                                            0x0F 十字丝开
                                            0x10 十字丝关
                                            0x18 亮度＋
                                            0x19 亮度－
                                            0x20 保存设置
                                            0x21 恢复出厂 */
    qint8              reserved1;      //! 预留位
    qint8              reserved2;
    qint8              reserved3;
    qint8              reserved4;
    qint8              reserved5;
    RemoteToAlertEnd    end;
}TVSensor02;

//! 红外传感器操作报文	   报文标识 28H
typedef struct _InfraredSensor
{
    RemoteToAlertHead   head;
    quint8              commandWord;     /** 命令字  0x01 步进调焦＋
                                                    0x02 步进调焦－
                                                    0x03 连续调焦＋
                                                    0x04 连续调焦－
                                                    0x05 停止连续调焦
                                                    0x06 变焦（宽视场）
                                                    0x07 变焦（中视场）
                                                    0x08 关挡板
                                                    0x09 开挡板
                                                    0x0A 自动齐焦开放
                                                    0x0B 自动齐焦关闭
                                                    0x0C 全自动校正（一键对挡板）
                                                    0x0D 全自动校正（一键对空）*/
    quint8              reserved1;      //! 预留位
    quint8              reserved2;
    quint8              reserved3;
    quint8              reserved4;
    quint8              reserved5;
    quint8              reserved6;
    RemoteToAlertEnd    end;
}InfraredSensor;

//! 眩目激光器操作报文	   报文标识 29H
typedef struct _DazzlingLaser
{
    RemoteToAlertHead   head;
    quint8              commandWord;     /** 命令字  0x00 停止发射激光
                                                    0x01 脉冲发射激光
                                                    0x02 连续发射激光
                                                    0x03 增大发射角
                                                    0x04 减小发射角
                                                    0x05 自动调节发射角
                                                    0x06 手动调节发射角
                                                    0x07 目标距离设定 */
    quint16             distance;       //! 目标距离数据 目标距离（m）（当命令字为0x07目标距离设定时该字段才有效）
    quint8              reserved1;      //! 预留位
    quint8              reserved2;
    quint8              reserved3;
    quint8              reserved4;
    RemoteToAlertEnd    end;
}DazzlingLaser;

//! 机枪操作报文	           报文标识 2AH
typedef struct _MachineGun
{
    RemoteToAlertHead   head;
    quint8              loadGun;       //! 装枪	0x01 装枪;  0x10 锁枪
    quint8              startReload;   //! 首发装填 0x01 首发装填; 0x10 取消首发装填; 0x02 上保险; 0x20 保险解锁 其它无效
    quint8              shootMode;     //! 射击模式 0x01 单点; 0x02 短点; 0x03 连射;  其它无效
    quint8              shootReady;    //! 射击准备 0x01 射击允许; 0x10 射击禁止
    quint8              shoot;         //! 射击 0x01 射击; 0x10 停止射击
    RemoteToAlertEnd    end;
}MachineGun;

//! 防暴弹操作报文	           报文标识 2BH
typedef struct _RiotBomb
{
    RemoteToAlertHead   head;
    quint8              pick;           /** 选弹	Bit0:催泪弹1    1：选 0：不选
                                                Bit1:催泪弹2    1：选 0：不选
                                                Bit2:爆震弹     1：选 0：不选
                                                Bit3:痛球弹     1：选 0：不选*/

    quint8              shootAllowed;   //! 射击允许 0x01 射击允许; 0x10 射击禁止
    quint8              shoot;          /** 射击	0x01: 射击         （火力电源加电）
                                                0x10：停止射击      （火力电源断电）*/
    RemoteToAlertEnd    end;
}RiotBomb;

//! 强光灯操作报文	           报文标识 2CH
typedef struct _StrongLight
{
    RemoteToAlertHead   head;
    quint8              opcode;     /** 操作码	0x01 高亮工作模式
                                                0x02 中亮工作模式
                                                0x03 低亮工作模式
                                                0x04 SOS工作模式
                                                0x05 闪频工作模式
                                                0x06 关闭工作模式
                                                0x07 近光工作模式
                                                0x08 远光工作模式
                                                0x09 调焦停止   */
    RemoteToAlertEnd    end;
}StrongLight;

//! 强声操作报文	           报文标识 2DH
typedef struct _StrongVoice
{
    RemoteToAlertHead   head;
    quint8              order;      //! 指令
    quint8              data;       //! 数据
    /** 指令                   数据
        0x01 报警音控制       0x01 打开报警音
                            0x02 关闭报警音

        0x02 播放控制	    0x01 上一曲
                            0x02 下一曲
                            0x03 停止MP3
                            0x04 播放MP3
                            0x05 单曲循环
                            0x06 所有曲目循环

        0x03 指定播放mp3	     0-255 指定播放0-255编号的歌曲

        0x04 音量控制         0-32
                             0表示静音
                             32表示最大音量 */
    RemoteToAlertEnd    end;
}StrongVoice;

//! 扇扫设置报文	           报文标识 2EH
typedef struct _FanSweepSet
{
    RemoteToAlertHead   head;
    quint8              referenceSystem;//! 0x01 惯性性; 0x02 甲板系
    quint16             fanAngleLeft;   //! 扇扫角度左极限	 量纲360°/65536，范围（0-360°）
    quint16             fanAngleRight;  //! 扇扫角度右极限	 量纲360°/65536，范围（0-360°）
    quint8              fanSweepRate;   //! 扇扫速率 0x01-0x0A十个速度等级可选
    RemoteToAlertEnd    end;
}FanSweepSet;

//! 跟踪设置报文              报文标识 0x23
typedef struct _TrackSet
{
    RemoteToAlertHead   head;
    quint8              trackSourceSelection;       //! 跟踪源选择 0x00:跟踪板；0x01:GPU
    quint8              trackAlgorithm;             //! 跟踪算法	1字节	0x00:相关；0x01:质心
    qint16              crossGuideX;                //! 十字引导X	2字节	[-960,960]屏幕坐标转换为图像坐标
    qint16              crossGuideY;                //! 十字引导Y	2字节	[-540,540]屏幕坐标转换为图像坐标
    quint8              pomenAdjust;                //! 波门调节 0x00: 波门无动作; 0x01:波门+; 0x02:波门-; 0x03:波门显示;
                                                    //! 0x04:波门隐藏; 0x05:波门回中
    quint8              crossAdjust;                //! 十字调节 0x00: 十字方位无动作；0x01: TV十字方位+;0x02: TV十字方位-;
                                                    //! 0x03:TV十字俯仰+;0x04:TV十字俯仰-;0x05: IR十字方位+;0x06: IR十字方位-;
                                                    //! 0x07:IR十字俯仰+;0x08:IR十字俯仰-;0x09:十字显示;0x0A:十字隐藏;0xff:引导标识
    quint8              type;                       //! 目标类型	1字节	0x00: 白目标；0x01: 黑目标
    qint8               reserved1;                  //! 预留位
    qint8               reserved2;
    qint8               reserved3;
    RemoteToAlertEnd    end;
}TrackSet;

//! 制动器设置报文	           报文标识 2FH
typedef struct _BrakeSet
{
    RemoteToAlertHead   head;
    quint8              controlFlag;     /** 命令字  Bit0:武器制动        1：选 0：不选
                                                    Bit1:光电制动        1：选 0：不选
                                                    Bit2:强声俯仰制动     1：选 0：不选
                                                    其他无效*/
    qint8               reserved1;      //! 预留位
    qint8               reserved2;
    qint8               reserved3;
    qint8               reserved4;
    qint8               reserved5;
    qint8               reserved6;
    RemoteToAlertEnd    end;
}BrakeSet;

//! 行进间控制报文           报文标识 30H
typedef struct _OnTheGoControl
{
    RemoteToAlertHead   head;
    quint8              controlId;     //! 控制标识 0x00：静止状态; 0x01: 行进间状态
    RemoteToAlertEnd    end;
}OnTheGoControl;

//! 惯导标校报文             报文标识 32H
typedef struct _InertNavCalibration
{
    RemoteToAlertHead   head;
    quint8              order;          //! 指令	0x01：参数设定; 0x02：保存标校数据 其他无效
    qint16              revisedAngle;   //! 航向角修订值	比例：0.01            范围[-30,30]
    qint16              pitchAngle;     //! 俯仰角修订值	比例：0.01            范围[-30,30]
    qint16              rollAngle;      //! 横摇角修订值	比例：0.01            范围[-30,30]
    RemoteToAlertEnd    end;
}InertNavCalibration;

//! 搜索设置报文             报文标识 51H
typedef struct _SearchSet
{
    RemoteToAlertHead   head;
    quint16             time;           //! 搜索时间 [5-200] 默认5
    quint8              sensitivity;    //! 灵敏度  [1-100]，默认20
    RemoteToAlertEnd    end;
}SearchSet;

//! 图像控制信息报文	   报文标识 53H
typedef struct _ImageControlInfo
{
    RemoteToAlertHead   head;
    quint8              imageFrame;         //! 图像帧频	  1到25，默认5
    quint8              compression;        //! 压缩因子	  1~100，默认20
    quint8              imageResolution;    //! 图像分辨率  0：480P；1：D1；2：720P；3：960P；4：1080P; 5：640P默认0；
    RemoteToAlertEnd    end;
}ImageControlInfo;

//! 越界控制报文	   报文标识 54H         (点选跟踪信息)
typedef struct _OutBoundsControl
{
    RemoteToAlertHead   head;
    quint16             leftX;      //! 目标框左上角X  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16             leftY;      //! 目标框左上角Y  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16             rightX;     //! 目标框右上角X  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    quint16             rightY;     //! 目标框右上角Y  屏幕坐标转化为图像坐标后发送 转化标准：电视，1080*1920；红外，640*512
    RemoteToAlertEnd    end;
}OutBoundsControl;


typedef struct _FunctionArae
{
    RemoteToAlertHead head;
    quint8 task_property;           //! 默认0, 静态目标0x01;动态目标0x02;行为识别0x03;
    quint32 target_longtitude;       //! 原始经度
    quint32 target_latitude;         //! 原始纬度
    quint8 task_confirmation_flag;  //! 默认0,功能开始确认0x01;功能完成确认0x10;
    quint8 platform_small_state;    //! 默认0,小平台开始0x01;小平台搜寻完成0x10;
    quint8 UAV_state;               //! 默认0;无人机起飞状态0x01;无人机降落完成0x10
    quint8 full_function_done_flag; //! 初始化0x00,全功能完成0x01，无人车前往终点

    quint8 resrv1;
    quint8 resrv2;
    quint8 resrv3;
    RemoteToAlertEnd end;
}FunctionArae;



//! *************************************************警戒监视模块向遥控端发送的信息报文**********************************
//! 上报设备状态报文	   报文标识 61H
typedef struct _DeviceStatus
{
    RemoteToAlertHead   head;
    quint8              equWorkMode;            //! 0x00 值更 0x01 搜索 0x02 跟踪 0x03 拒止
    quint16             photoelectricAzimuth;   //! 光电方位角 量纲360°/65536，范围（0-360°）
    qint16              photoelectricPitch;     //! 光电俯仰角 量纲90°/32768,范围（-90°-90°）
    quint16             weaponAzimuth;          //! 武器方位角 量纲360°/65536，范围（0-360°）
    qint16              weaponPitch;            //! 武器俯仰角 量纲90°/32768,范围（-90°-90°）
    qint16              strongPitchAngle;       //! 强声俯仰角度 量纲360°/65536,范围（-90°-90°）
    quint16             pheInertiaAzimuth;      //! 光电惯性方位角 量纲360°/65536，范围（0-360°）
    qint16              pheInertiaPitch;        //! 光电惯性俯仰角 量纲360°/65536,范围（-90°-90°）
    quint16             distance;               //! 测距距离  M
    qint16              missX;                  //! X轴脱靶量  -960~960
    qint16              missY;                  //! Y轴脱靶量  -540~540
    quint8              currentChannel;         //! 当前通道 0x01  红外    0x02  电视（默认）
    quint8              infraredFocalLength;    //! 红外焦距 红外通道短焦 0x01; 红外通道长焦 0x02
    quint16             TVview;                 //! 电视视场 量纲0.1°，范围（0-360）
    quint16             powerState;             /** 电源状态  0－故障， 1－正常
                                                    Bit0: 低压15V电源
                                                    Bit1: 计算机板电源
                                                    Bit2: 激光测距仪电源
                                                    Bit3: 红外电源自检
                                                    Bit4: 低压5V电源
                                                    Bit5: 伺服驱动板-15V电源
                                                    Bit6: 光发送板电源
                                                    Bit7: 陀螺5V电源
                                                    Bit8：陀螺-5V电源
                                                    Bit9: 激光眩目电源
                                                    Bit10：强光电源
                                                    Bit11：武器方位俯仰制动器电源
                                                    Bit12：强声俯仰制动器电源
                                                    Bit13:武器伺服电源 */

    quint16             servoDriveStatus;       /**     伺服驱动状态
                                                        Bit0: 武器方位伺服驱动检测
                                                        Bit1: 武器俯仰伺服驱动检测
                                                        Bit2: 光电方位伺服驱动检测
                                                        Bit3: 光电俯仰伺服驱动检测
                                                        Bit4: 光电俯仰上限位开关  1到位，0未到
                                                        Bit5: 光电俯仰下限位开关  1到位，0未到
                                                        Bit6: 武器俯仰上限位开关  1到位，0未到
                                                        Bit7: 武器俯仰下限位开关  1到位，0未到
                                                        Bit8：强声俯仰上限位开关   1到位，0未到
                                                        Bit9: 强声俯仰下限位开关   1到位，0未到
                                                        Bit10：光电方位止动到位开关
                                                        Bit11：光电方位回退到位开关
                                                        Bit12：光电俯仰止动到位开关
                                                        Bit13:光电俯仰回退到位开关 */

    quint16             weaponState;            /** 武器系统状态  0－故障， 1－正常
                                                    Bit0: 射击控制板自检
                                                    Bit1: 枪禁射回告
                                                    Bit2: 弹禁射回告
                                                    Bit3: 首发装填前到位
                                                    Bit4: 首发装填后到位
                                                    Bit5: 首发装填到位
                                                    Bit6: 余弹计数  */

    quint16             smallAmmNum;            //! 小口径机枪所剩弹药数量   颗
    qint8               dazzlingLaserAngle;     //! 炫目激光器发散角
    qint16              temperature;            //! 温度
    qint16              humidity;               //! 湿度
    qint16              TvZoomADvalue;          //! 电视变焦AD值
    qint16              TvFocusADvalue;         //! 电视调焦AD值
    qint8               workMode;               //! 工作模式
    quint16             machineGunCor;          //! 机枪俯仰弹道修正 360/65536
    quint16             grenadeCor;             //! 榴弹俯仰弹道修正 360/65536

    qint32              reserved1;              //! 预留位 25个字节  第8字节为喊话驱离开始
    qint16              reserved12;
    qint8               reserved13;
    qint8               leaveAllow;             //! 喊话驱离开始
    quint32             nTagLon;
    quint32             nTagLat;
    qint64              reserved3;
    qint8               reserved4;
    RemoteToAlertEnd    end;
}DeviceStatus;

typedef struct _GoalResultInfo
{
    quint16         batchNum;       //! 批号 1001-1999 电视目标; 2001-2999 红外目标; 3001-3999 手动目标
    quint16         azimuth;        //! 目标方位角  量纲360°/65536，范围（0-360°）
    qint16          pitchAngle;     //! 目标俯仰角  量纲90°/32768,范围（-90°-90°）
    quint16         distance;       //! 距离  0-65536
    quint8          type;           //! 目标类型 0x01 坦克; 0x02 车辆; 0x03 车辆; 0x04 人
    quint8          behavior;       //! 目标行为	0x01 攀爬翻越; 0x02 投掷; 0x03 持枪瞄准; 0x04 持枪瞄准; 0x05 人员快速接近;
                                    //!         0x06 车辆快速接近; 0x07 越界
    quint8          confidence;     //! 置信度	0-100
    quint8          threatLevel;    //! 目标威胁等级  十个等级  0x01-0x0A（最高等级0x01，最低等级0x0A）
}GoalResultInfo;

#define  GOAL_INFO_MAX      300

//! 上报检测识别结果报文	   报文标识 71H
typedef struct _DetectRecognitResult
{
    RemoteToAlertHead   head;
    quint16             goalNum;        //! 目标个数
    GoalResultInfo      info[GOAL_INFO_MAX];
    RemoteToAlertEnd    end;
}DetectRecognitResult;

typedef struct _GoalDetectInfo
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
}GoalDetectInfo;

//! 上报检测目标列表报文	   报文标识 73H
typedef struct _DetectGoalList
{
    RemoteToAlertHead   head;
    quint16             goalNum;        //! 目标个数
    GoalDetectInfo      info[GOAL_INFO_MAX];
    RemoteToAlertEnd    end;
}DetectGoalList;


#define     IMAGE_INFO      1024

//! 图像信息报文	           报文标识 74H
typedef struct _ImageInfor
{
    RemoteToAlertHead   head;
    quint8              videoChannel;       //! 视频通道 0x01 红外; 0x02 电视（默认）
    quint8              imageResolution;    //! 图像分辨率  0：480P；1：D1；2：720P；3：960P；4：1080P; 5：640P
    quint8              imageFrame;         //! 图像帧频	  1到25
    quint8              compression;        //! 图像压缩比  1~100
    quint8              saveImageLogo;      //! 是否保存图像标识 0x00：不保存；0x01：保存
    quint8              subMsgHead;         //! 子报文头	0:0xf1第一个报文; 1:0xf2中间报文; 2:0xf3;最后一个报文
    quint8              imageInfo[IMAGE_INFO]; //! 图像信息 N字节	压缩编码后图像
    RemoteToAlertEnd    end;
}ImageInfor;



//! *************************Communication between driving control software and control software*****************************/
//! Definition rules for msgID*/
typedef struct _OcuToControlMsgID{
    quint8      infoType;               //! *1- Receive information; 2- send information*/
    quint8      vehicleNumber;          //! *10- Default vehicle; 11-ZC car; 12-DJ car; 13-XL car; 14-YS car*/
    quint8      mobilePlatform;         //! *30-default platform; 31-Universal Mobile Platform*/
    quint8      msgFlag;                //! *40-default load; 42-ZC guide load; 43-HLDJ payload; 50-default communication
                                        //!                  60-default protection; 70-empty*/

//! For example: 1113171, namely receiving 1, ZC car 11, general mobile platform 31, message identification 71;
//! 2113171, which is to issue 2, ZC car 11, general mobile platform 31, message identification 71;*/
}OcuToControlMsgID;

//! Data header definition*/
typedef struct _OcuToControlFrameHead{
    OcuToControlMsgID     msgID;         //! Distinguish between different commands and messages
    quint32               msgLenth;      //! The length of the entire data frame
    qint64                timeStamp;     //! current tim(Structure day-hour-minute-second)
}OcuToControlFrameHead;

/** control software report information
  * Mobile platform status
  */
typedef struct _MobilePlatStatus{
    OcuToControlFrameHead    frameHead;   //! Message ID 1113171
                                          //! Message length 79 (104 in the original document, please confirm)
                                          //!                                    Timestamp XX*/
    quint8  platformHealth;               //! 0x01-normal; 0x02-fault*/
    quint8  communicationStatus;          //! 0x01-normal; 0x02-disconnection*/
    quint8  taskStatus;                   //! 0x01-executing; 0x02-Pause;0x03 not executed*/
    quint8  controlMode;                  //! 0x01-Autonomous mode; 0x02-Remote control mode*/
    quint8  powerMode;                    //! 0x01-hybrid; 0x02 pure electric*/
    quint8  parkingState;                 //! 0x01-parking; 0x02-No parking*/
    quint8  currentGear;                  //! 0x01-forward gear;0x02-Neutral; 0x03-reverse gear*/
    quint8  vehicleHeightStatus;          //! 0x01-mid position; 0x02-low bit;0x03-high*/
    quint8  steeringMode;                 //! 0x01-forward steering; 0x02-rear steering; 0x03-full steering*/
    qint16  oilVolume;                    //! Value range is 0～100, scale is 1, factor=1, offset=0*/
    qint16  electricVolume;               //! Value range is 0～100, scale is 1, factor=1, offset=0*/
    qint32  hybridDrivingRange;           //! Value range is 0～500000, scale is 1m, factor=1, offset=0*/
    qint32  pureElectricDrivingRange;     //! Value range is 0～500000, scale is 1m, factor=1, offset=0*/
    qint32  longitude;                    //! Scale 0.0000001 degrees, range -180~180 degrees factor=0.0000001 offset=0*/
    qint32  latitude;                     //! Scale 0.0000001 degrees, range -90~90 degrees factor=0.0000001 offset=0*/
    qint32  elevation;                    //! Scale 0.1m, range -100000~100000 degrees factor=0.1 offset=0*/
    quint32 globalCoord_X_north;          //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    quint32 globalCoord_Y_east;           //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    quint32 globalCoordHeight_H;          //! The range is 0～99999999, the scale is 0.1 meters; factor=0.1 offset=0*/
    qint16  global_X_axisEastSpeed;       //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    qint16  global_Y_axisNorthSpeed;      //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    qint16  global_H_axisSpeed;           //! Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0*/
    quint16 heading;                      //! The value range is 0～36000, the angle scale is 0.01°, factor=0.01, offset=0*/
    qint16  pitchAngle;                   //! Value range -9000～9000, angle scale is 0.01°, factor=0.01, offset=0*/
    qint16  rollAngle;                    //! Value range -9000～9000, angle scale is 0.01°, factor=0.01, offset=0*/
    qint16  headingSpeed;                 //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
    qint16  pitchAngleSpeed;              //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
    qint16  rollAngleSpeed;               //! Value range -10000～10000, coordinate scale is 0.01°/s, factor=0.01, offset=0*/
}MobilePlatStatus;

/** control software report information
 * Platform environment awareness status (reserved and not uploaded)
 */
typedef struct _PlatEnvirStatus{

    OcuToControlFrameHead    frameHead;  //! Message ID 1113172
                                         //! Message length 19 (24 in the original document, please confirm)*/
    qint8       roadFeatures;
    qint8       obstacleFeatures;
    qint8       terrainFeatures;
}PlatEnvirStatus;

//! The struct is just a data frame header*/
typedef struct _CarAction{
    OcuToControlFrameHead   frameHead;    //! msgID:2113171 Pause the current action
                                          //! 2113172 Continue the current action temporarily
                                          //! 2113173 Terminate current action
                                          //! 2113176 Stop + action after parking*/
}CarAction;

//! The structure is a data frame header and a byte*/
typedef struct _CarControl{
    OcuToControlFrameHead   frameHead;    //! msgID:2113178 Lifting body
                                          //! 2113179 Power switch
                                          //! 2113181 self-destruct and self-destruct*/
    qint8   dataOne;
}CarControl;

typedef struct _TurnInPlace{
    OcuToControlFrameHead   frameHead;    //! *msgID:2113177*/
    quint16   turnAngle;                  //! *The value range is 0～36000, the angle scale is 0.01°, factor=0.01, offset=0*/
    qint8     turnMode;                   //! *0x01-forward steering; 0x02-rear steering; 0x03-full steering*/
}TurnInPlace;

typedef struct _VerticalAndFormationFollow{
    OcuToControlFrameHead   frameHead;    //! *msgID:2113180*/
    quint8   powerMode;
    quint16  followDistance;              //!*Range 0-200 meters, scale 1 meter, factor=0.01, offset=0*/
}VerticalAndFormationFollow;

typedef struct _KeyPointInfo{
    qint16   serialNum;                   //! *Range 0-10000, current key point sequence number*/
    qint32   longitude;                   //! *Scale 0.0000001 degrees, range -180~180 degrees factor=0.0000001 offset=0*/
    qint32   latitude;                    //! *Scale 0.0000001 degrees, range -90~90 degrees factor=0.0000001 offset=0*/
    quint8   attribute;                   //! *1-起始点; 2-导航点; 3-结束点
}KeyPointInfo;

#define  KEY_POINT_MAX_NUM  10000

//! Conventional maneuver instructions*/
typedef struct _ConventionalManeuver{
    OcuToControlFrameHead frameHead;      //! msgID:2113174;msgLenth:21+11*n*/
    qint8    powerMode;                   //! *0x01-hybrid 0x02-pure electric*/
    qint16   referenceSpeed;              //! *Value range -10000～10000, coordinate scale is 0.01m/s, factor=0.01, offset=0;*/
    qint16   keyPointNum;                 //! *Value 0-10000*/
    KeyPointInfo       keyPointInfo[KEY_POINT_MAX_NUM];
}ConventionalManeuver;

//! many task point message*/
typedef struct _ManyTaskPoint{
    OcuToControlFrameHead   frameHead;    //! msgID:2113175; msgLenth:20+11*n*/
    qint16  maxInterval;                  //! *Unit: second*/
    qint16  keyPointNum;                  //! *Value 0-10000*/
    KeyPointInfo       keyPointInfo[KEY_POINT_MAX_NUM];
}ManyTaskPoint;







///!*****************************************R W L J Interactive protocol******************************************/
//! RWLJ for frame header*/
typedef struct _OcuToRWLJFrameHeader{
    quint32     msgID;                    //! 0x00060001 Mode setting               msgType(0x02)
                                          //! 0x00070001 On standby                 msgType(0x02)
                                          //! 0x00070002 Orientation ZhenCha        msgType(0x02)
                                          //! 0x00070003 Localized ZhenCha          msgType(0x02)
                                          //! 0x00070004 Fixed-point ZhenCha        msgType(0x02)
                                          //! 0x00070005 Orientation                msgType(0x02)
                                          //! 0x00070006 Localized strike           msgType(0x02)
                                          //! 0x00070007 Fixed-point strike         msgType(0x02)
                                          //! 0x00070008 Turn on laser irradiation  msgType(0x02)
                                          //! 0x00070009 End laser irradiation      msgType(0x02)
                                          //! 0x00070010 Laser Ranging              msgType(0x02)
                                          //! 0x000A0001 Situation report           msgType(0x02)
                                          //! 0x000A0002 Task feedback              msgType(0x02)
                                          //! 0x000A0003 Equipment status feedback  msgType(0x02)*/
    quint32     frameLength;              //!The number of bytes from the Client ID to the end of the message.*/
    quint16     clientID;                 //! 0x0010 Task understanding computer
                                          //! 0x0015 Reconnaissance load control screen
                                          //! 0x0016 HuoLi load control screen
                                          //! 0x0020 Detect chassis
                                          //! 0x0022 HuoLi chassis
                                          //! 0x0030 Detected payload
                                          //! 0x0032 HuoLi payload*/
    quint16     sessionID;                //!
    quint8      protocolVersion;          //! fill in 1*/
    quint8      interfaceVersion;         //! fill in 1*/
    quint8      msgType;                  //! 0x00 request_need to answer
                                          //! 0x01 Request_No response required
                                          //! 0x02 Notification No response required
                                          //! 0x80 message response
                                          //! 0x81 contains wrong response*/
    quint8       returnCode;              //! 0x00	E_OK
                                          //! 0x01	E_NOT_OK*/
    //quint32      timeStamp;             //! day, hour, minute, second*/
    quint8      day;
    quint8      hour;
    quint8      minute;
    quint8      second;

}OcuToRWLJFrameHeader;

//! RWLJ for check code*/
typedef struct _OcuToRWLJCheckCode{
    quint32     checkCode;
}OcuToRWLJCheckCode;


//! ***************RWLJ report information to Ocu**************/
//! Target information*/
//! typedef struct _TargetInfor{
//!    quint32             targetDetailedData;
//! TargetInfor;

#define  RWLJ_TARGET_INFOR_MAX_LEN  20
#define  RWLJ_TARGET_MAX_NUM        2000

//! Target data layerr*/
typedef struct _TargetDataLayer{
    quint32   number;        //! *[1,65535]*/
    quint32   dataLength;    //! * targetContentIndex and targetInfo total length*/
    quint32   contentIndex;
    quint32   targetInfor[RWLJ_TARGET_INFOR_MAX_LEN];
}TargetDataLayer;

/** Situation report Payload data layer
 * msgID:0x000A0001*/
typedef struct _SituationReport{
    OcuToRWLJFrameHeader    frameHeader;
    quint16                 targetNum;      //! Number of targets*/
    quint16                 packagesNum;    //! The last package, high eight FF
                                            //! The lower eight bits represent the number of packages, up to 5 packages*/
    TargetDataLayer         targetDataLayer[RWLJ_TARGET_MAX_NUM];
    //OcuToRWLJCheckCode      checkCode;
}SituationReport;

/** Task feedback Payload data layer
 * msgID:0x000A0002*/
typedef struct _TaskFeedback{
    OcuToRWLJFrameHeader    frameHeader;
    quint32   currentTaskCode;
    quint32   taskStatus;           //! *1 is to be executed, 2 is executing, 3 is suspended, 4 is completed.*/
    quint32   taskFailureStatus;    //! * 1 Task conflict, continue to perform the original task
                                    //! * 2 System status cannot perform this task
                                    //! * 3 The current task data is incorrect
                                    //! * 4 The scope cannot be in place
                                    //! * 5 Startup recognition failed
                                    //! * 6 Task progress is disorderly
                                    //! * 7 The specified target was not found
                                    //! * 8 Ranging failed
                                    //! * 9 The original target was not found, looking for an approximate target*/
    //OcuToRWLJCheckCode        checkCode;
}TaskFeedback;

/** Equipment status feedback payload data layer
 * msgID:0x000A0003*/
typedef struct _EquipStatus{
    OcuToRWLJFrameHeader frameHeader;
    quint32 photoelectricSensorStatus; //!*0 not turned on, 1 standby (identification not turned on), 2 search (identification turned on), 3 tracking, 4 guidance*/
    quint32 radarSensorStatus;       //! *0 not open, 1 standby, 2 search, 2 tracking*/
    quint32 directWuQiStatus;        //! *0 is not turned on, 1 is on standby, 2 is hit*/
    quint32 ammunSurplus58;          //! *0 No such ammunition*/
    quint32 ammunSurplus762;         //! *0 No such ammunition*/
    quint32 ammunSurplus127;         //! *0 No such ammunition*/
    quint32 ammunSurplusPierc30;     //! *0 No such ammunition*/
    quint32 ammunSurplusKill127;     //! *0 No such ammunition*/
    quint32 ammunSurplusHongJian13;  //! *0 No such ammunition*/
    quint32 ammunSurplusGrenade35;   //! *0 No such ammunition*/
    quint32 ammunSurplusHongJian12;  //! *0 No such ammunition*/
    OcuToRWLJCheckCode checkCode;
}EquipStatus;


/** RWLJ's response to Ocu's message*/
typedef struct _RWLJResponseToOcu{
        quint32   msgID;               //!  0x00060001 Mode setting                          msgType(0x02)
                                       //!  0x00070001 On standby                            msgType(0x02)
                                       //!  0x00070002 Orientation ZhenCha                   msgType(0x02)
                                       //!  0x00070003 Localized ZhenCha                     msgType(0x02)
                                       //!  0x00070004 Fixed-point ZhenCha                   msgType(0x02)
                                       //!  0x00070005 Orientation strike                    msgType(0x02)
                                       //!  0x00070006 Localized strike                      msgType(0x02)
                                       //!  0x00070007 Fixed-point strike                    msgType(0x02)
                                       //!  0x00070008 Turn on laser irradiation             msgType(0x02)
                                       //!  0x00070009 End laser irradiation                 msgType(0x02)
                                       //!  0x00070010 Laser Ranging                         msgType(0x02)
                                       //!  0x000A0001 Situation report                      msgType(0x02)
                                       //!  0x000A0002 Task feedback                         msgType(0x02)
                                       //!  0x000A0003 Equipment status feedback         msgType(0x02)*/
        quint32   frameLength;         //!  The number of bytes from the Client ID to the end of the message.*/
        quint16   clientID;            //!  0x0010 Task understanding computer
                                       //!  0x0015 Reconnaissance load control screen
                                       //!  0x0016 HuoLi load control screen
                                       //!  0x0020 Detect chassis
                                       //!  0x0022 HuoLi chassis
                                       //!  0x0030 Detected payload
                                       //!  0x0032 HuoLi payload*/
        quint16   sessionID;           //!
        quint8    protocolVersion;     //!  fill in 1
        quint8    interfaceVersion;    //!  fill in 1
        quint8    msgType;             //!  0x00 request_need to answer
                                       //!  0x01 Request_No response required
                                       //!  0x02 Notification No response required
                                       //!  0x80 message response
                                       //!  0x81 contains wrong response*/
        quint8   returnCode;           //!  0x00     E_OK                 0x01    E_NOT_OK*/
}RWLJResponseToOcu;



//! *************************************The alert monitor******************************************/
typedef struct _OcuToAlertMonitorFrameHeader{
    quint8      header;                //!0x7F
    quint8      sourceHost;            //!（数据发送方设备代号）
    quint8      letterHost;            //!（数据接收方设备代号）
    quint16     length;                //!The length of the entire message starting from the message header
}OcuToAlertMonitorFrameHeader;

typedef struct _OcuToAlertMonitorDataTail{
    quint8      checkCode;             //!CRC8 check, all data from the head of the message to the end of the data
    quint8      tail;                  //!0x7E
}OcuToAlertMonitorDataTail;

//! ****************ocu send information to the alert monitor*****************/
//!自主参数设置报文
typedef struct _DC_IC_01{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8          msgID;             //!0x91
    quint8          autoWorkMode;      //!自主工作模式;0x01: 巡线侦察监视;0x02: 定点侦察监视告警;0x03: 定点侦打一体
    quint16         targetDistance;    //!目标大致距离; 米
    qint16          targetPitchRange;  //!目标俯仰角范围;量纲90°/32768,范围（-90°-90°）
    quint16         scanPosition;      //!扫描方位;【A,B】°（默认为周扫）（0°~360°）360/65536
    qint16          scanRange;         //!扫描左极限=扫描方位-扫描范围/2;扫描右极限=扫描方位+扫描范围/2
    quint8          loadImagingSensor; //!载荷成像传感器选择;0x01 电视;0x02 红外
    quint8          autoTracking;      //!是否自动跟踪;0x01 非自动跟踪;0x02 自动跟踪
    quint8          autoRanging;       //!是否自动测距;0x01 非自动测距;0x02 自动测距
    OcuToAlertMonitorDataTail   dataTail;
}DC_IC_01;

//!自主工作开始/结束控制
typedef struct _DC_IC_02{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8              msgID;          //!0x92
    quint8              autoWorkMode;   //!0x01: 开始自主工作（光电自主）;0x02: 停止自主工作（待命状态）
    OcuToAlertMonitorDataTail   dataTail;
}DC_IC_02;

//!允许打击（非致命武器）指令
typedef struct _DC_IC_03{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8      msgID;                  //!0x93
    quint8      autoWorkMode;           //!0x01: 不允许自动打击（非致命武器）;0x02: 允许自动打击（非致命武器）
    OcuToAlertMonitorDataTail   dataTail;
}DC_IC_03;

//!允许打击（致命武器）指令
typedef struct _DC_IC_04{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8      msgID;                  //!0x94
    quint8      autoWorkMode;           //!0x01: 不允许自动打击（致命武器）;0x02: 允许自动打击（致命武器）
    OcuToAlertMonitorDataTail   dataTail;
}DC_IC_04;

//! ****************the alert monitor send information to ocu*****************/
//!打击请求报文
typedef struct _IC_DC_01{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8              msgID;          //!0x9A
    OcuToAlertMonitorDataTail   dataTail;
}IC_DC_01;

//!光电状态上报报文
typedef struct _IC_DC_02{
    OcuToAlertMonitorFrameHeader  frameHead;
    quint8      msgID;                    //!0x61
    quint8      equipWorkMode;            //!设备工作模式;0x00 值更;0x01 搜索;0x02 跟踪;0x03 拒止
    quint16     photoelectricAzimuth;     //!光电方位角;量纲360°/65536，范围（0-360°）（大地坐标系）
    qint16      photoelectricPitchAngle;  //!光电俯仰角;量纲360°/65536,范围（-90°-90°）
    quint16     weaponAzimuth;            //!武器方位角;量纲360°/65536，范围（0-360°）
    qint16      weaponPitchAngle;         //!武器俯仰角;量纲360°/65536,范围（-90°-90°）
    qint16      strongPitchAngle;         //!强声俯仰角度;量纲360°/65536,范围（-90°-90°）
    quint16     azimuthInertialAngle;     //!惯性方位角惯导角;量纲360°/65536，范围（0-360°）
    qint16      pitchAngleInertialAngle;  //!惯性俯仰角惯导角;量纲360°/65536,范围（-90°-90°）
    quint16     rangDistance;             //!测距距离;M(100~6000m)
    quint8      currentChannel;           //!当前通道;0x02  红外;0x01  电视（默认）
    quint8      infraredFocalLength;      //!红外焦距;红外通道短焦 0x01;红外通道长焦 0x02
    quint16     TVFieldView;              //!电视视场;量纲0.1°，范围（0-3600）
    quint8      powerState;               //!健康状态;0x00 ：正常;0x01 ：异常
    OcuToAlertMonitorDataTail   dataTail;
}IC_DC_02;

#define  ALERT_TARGET_MAX_NUM  2000

typedef struct _TargetInfo{
    quint16     num;
    qint32      longitude;
    qint32      latitude;
    qint16      height;
    quint8      type;                      //!0x01轻质装甲;0x02重型装甲;0x03 无人机 ;0x04 直升机;0x05武装人员;0x06卡车;0x07汽车
    quint8      confidence;                //!0-100
    quint8      threatLevel;               //!1-5（1为最高等级）
    quint8      alertSign;                 //!0x01:告警；0x10:不告警
}TargetInfo;

//!检测识别结果上报报文
typedef struct _AI_DC_O1{
    OcuToAlertMonitorFrameHeader        frameHead;
    quint8          msgID;                 //!0x72
    quint16         targetNum;
    TargetInfo      targetInfo[ALERT_TARGET_MAX_NUM];
    OcuToAlertMonitorDataTail   dataTail;
}AI_DC_O1;


//! ***********************************super car 视频控制协议命令*******************************************/
//! 视频控制ack
typedef struct _ICD_VIDEO_ACK
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   Ack;
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_ACK;

//! 视频流切换
typedef struct _ICD_VIDEO_CHANNEL
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   VideoChannel;
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_CHANNEL;

//! 调节分辨率
typedef struct _ICD_VIDEO_ADJUST_RESOLUTION
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    quint16 x;
    quint16 y;
    quint16 crop_width;
    quint16 crop_height;     //! (x, y)为裁剪起始点，如0x00000000_05000320表示从(0, 0)开始裁剪1280x800大小的图像
    quint16 scale_width;
    quint16 scale_height;    //! scale_width为前两个字节，scale_height为后两个字节，均为无符号整数。如0x0A000320表示分辨率设置为2560x800。
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_ADJUST_RESOLUTION;

//! 调节码率
typedef struct _ICD_VIDEO_ADJUST_CODE_RATE
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   controlMode;
    qint32  codeRate;
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_ADJUST_CODE_RATE;

//! 调节帧率
typedef struct _ICD_VIDEO_ADJUST_FRAM_RATE
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   FPS;
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_ADJUST_FRAM_RATE;

//! 调节码率
typedef struct _ICD_VIDEO_PLAY_CONTROL
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   playControl;
    qint8   ipFistWord;
    qint8   ipSecondWord;
    qint8   ipThreeWord;
    qint8   ipFourWord;
    qint16  port;
    qint8   CRC;
    qint16  EndCode;
}ICD_VIDEO_PLAY_CONTROL;

/** *********************************OCU端到轻小型便携式车辆通信结构体*************************************/

/*ocu端到视频端消息头*/
typedef struct _OcuToVideoFrameHeadTrans
{
    quint8   SYNC1;   /*同步头1*/
    quint8   SYNC2;   /*同步头2*/
    quint8   SRCID;   /*源ID*/
    quint8   DSTID;   /*目标ID*/
    quint8   MSIGID;  /*消息编号*/
    qint8    MSNUM;   /*消息编号*/
    quint16  PPLEN;   /*数据后续长度（不包括pllen本身），长度为0-1460个字节*/
}OcuToVideoFrameHeadTrans ;

//便携式和小履带
typedef struct _V1VideoDisplayMode
{
    OcuToVideoFrameHeadTrans   frameHead;/*帧头*/
    qint32         videoDisplayMode;/*显示模式*/
}V1VideoDisplayMode;


/*ocu端到底盘的消息报头*/
typedef struct _OcuToChassisFrameHead
{
    quint16  prop;   /*帧头*/
    quint8   type;   /*帧类型*/
    quint8   len;   /*帧长度*/
}OcuToChassisFrameHead;

typedef struct _OcuToPortableCarControlParaTopic
{
    OcuToChassisFrameHead   frameHead;
    quint8 controlModeSwitch;       /*00—停车;02—遥控;自主模式(待开发模块);01—人员跟随;03—暂停;04—一键返航;05—驻车（所有抱闸下电）*/
    qint8  rightRockerHorizontal;   /*0~100（左转）；0~-100（右转）*/
    qint8  rightRockerVertical;     /*向前 0~100;向后 0~-100*/
    qint8  leftRockerHorizontal;    /*0~100（向左）（前摆臂向车前方向转动）；0~-100（向右）（前摆臂向车后方向转动）*/
    qint8  leftRockerVertical;      /*0~100（向前）（后摆臂向车前方向转动）；0~-100（向后）（后摆臂向车后方向转动）*/
    quint8 driveAndLoadGear;        /*=0：主履带速度空挡
                                          =1：主履带速度低档
                                          =2：主履带速度中档
                                          =3：主履带速度高档
                                          =4：主履带中心转向
                                          =5：摆臂速度空挡
                                          =6：摆臂速度低档
                                          =7：摆臂速度高档*/
    quint8 chassisControl;          /*Bit0：底盘使能（=1）底盘不使能（=0）
                                          Bit1：（驱动器现物理设计为开机即默认上电）驱动器上电（=1）驱动器下电（=0）
                                          Bit2：主履带抱闸上电（=1）主履带抱闸下电（=0）
                                          Bit3：前后摆臂抱闸上电（=1）前后摆臂抱闸下电（=0） 其他位保留*/
    quint8 equipmentControl;        /*Bit0：车载前摄像头上电控制 =1，上电;=0，下电
                                          Bit1：车载后摄像头上电控制=1，上电;=0，下电
                                          Bit2：图像板卡上电控制（=1）上电（=0）下电；
                                          Bit3: 可见光照明设备上电控制（=1）上电（=0）下电；
                                          Bit4: 载荷上电控制（=1）上电（=0）下电；其他位保留：*/
    quint16 loadControl;            /*保留给侦察模块、机械臂*/
    quint8 CRC16CheckLowBit;        /*前面所有字节 CRC 校验低位（数据包是固定长度，但不是固定值！校验码是从 0xffaa 一直加到校验码之前的所有数据）*/
    quint8 CRC16CheckHighBit;       /*前面所有字节 CRC 校验高位（数据包是固定长度，但不是固定值！校验码是从 0xffaa 一直加到校验码之前的所有数据）*/
    quint8 frameTail;
}OcuToPortableCarControlParaTopic;



/*便携式车辆底盘上报到Ocu的车辆的主要信息的消息内容-上层应用*/
typedef struct _PortableCarStatusInfoTopic
{
    OcuToChassisFrameHead   frameHead;
    quint8  platformMoblieState;        /*平台机动信息
                                                值为0：停车状态；
                                                值为1: 遥控状态
                                                值为2：人员跟随模式
                                                值为3：暂停模式
                                                值为4：返航模式
                                                值为5：摆臂调试模式*/
    quint8 carSpeed;                    /*车速;方向速度，0.1m/s /bit;最高位 0：前进方向,最高位 1：后退方向*/
    quint8 carYawSpeed;                 /*车横摆角速度;横摆角速度，0.1rad/s /bit; 最高位 1：顺时针方向;最高位 0：逆时针方向*/
    quint8 frontSwingArmAngleSpeed;     /*前摆臂角速度;方向角速度，1°/s /bit;最高位 0：前进方向;最高位 1：后退方向*/
    quint8 rearSwingArmAngleSpeed;      /*后摆臂角速度;方向角速度，1°/s /bit;最高位 0：前进方向;最高位 1：后退方向*/
    quint8 batteryResidualCapacity;     /*电池剩余电量，0.5/bit*/
    quint8 systemVoltage;               /*系统电压，0.25V/bit实际电压值 46-59V;当低于 48 或高于 56 时告警显示。*/
    quint8  devicePowerUpState;         /*0：未上电；1：已上电
                                                Bit0：车载前摄像头
                                                Bit1：电台
                                                Bit2：图像板卡
                                                Bit3：车载后摄像头
                                                Bit4：驱动器
                                                Bit5：可见光设备
                                                Bit6：摆臂抱闸
                                                Bit7：保留*/
    quint16 loadState;                  /*载荷状态;留给侦察模块、摄像头*/
    quint8 CRC16CheckLowBit;            /*前面所有字节 CRC 校验低位（数据包是固定长度，但不是固定值！校验码是从 0xffbb 一直加到校验码之前的所有数据）*/
    quint8 CRC16CheckHighBit;           /*前面所有字节 CRC 校验高位（数据包是固定长度，但不是固定值！校验码是从 0xffbb 一直加到校验码之前的所有数据）*/
    quint8 frameTail;
}PortableCarStatusInfoTopic;

/**********************************串口数据,上位机与下位机之间通信的信息********************************/
//系统时间
typedef struct _SystemTimeInfo {
    quint16 year;
    quint8  month;
    quint8  day;
    quint8  hour;
    quint8  minute;
    quint8  second;
} SystemTimeInfo;

//gps字段的16个卫星信息
typedef struct _SatelliteInfo {
    quint8 numbering;      //编号
    quint8 elevateAngle;   //仰角
    quint16 azimuth;       //方位角
    quint8 sigNoiseRatio;  //信噪比
} SatelliteInfo;

//gps字段
typedef struct _GpsInfo {
    quint8 satellitenum;            //卫星数
    SatelliteInfo satellInfo[16];   //16个卫星信息
    SystemTimeInfo time;
    quint32 latitude;               //纬度
    quint8 north_south;             //01 N 02 S
    quint32 longitude;              //经度
    quint8 east_west;
    quint32 altitude;               //海拔
    quint8 gpsStatus;               //gps状态
    quint8 positsateNum;            //用于定位的卫星数
    quint8 positsateNumbering[16];  //用于定位的卫星编号
    quint8 locateType;              //定位类型
    quint32 positlongitFactor;      //位置经度因子
    quint32 HorizlongitFactor;      //水平经度因子
    quint32 vertilongitFactor;      //垂直经度因子
    quint16 groundSpeed;            //地面速度
} GpsInfo;

//加速度字段
typedef struct _AccelerateInfo {
    qint16 x;                       //x
    qint16 y;                       //y
    qint16 z;                       //z
} AccelerateInfo;

//磁力计字段
typedef struct _MagnetometerInfo {
    qint16 x;                       //x
    qint16 y;                       //y
    qint16 z;                       //z
} MagnetometerInfo;

//摇杆值
/* 1、水平方向为x，竖直方向为y
   2、x值为左负右正，y值为下负上正*/
typedef struct _JoystickInfo {
    qint16 x_left;
    qint16 y_left;
    qint16 x_right;
    qint16 y_right;
} JoystickInfo;

/*电池状态*/
typedef struct _BATTERYINFO {
    quint8  percent;            //电量 (0~100)
    quint8  status;             //状态（0：没有充电；1：正在充电）
    quint16 temperature;        //温度
    quint16 remainPower;        //实际功率
    quint16 voltage;            //电压
    quint16 totalPower;         //总功率
} BatteryInfo;

/*上位机与下位机之间通信的信息*/
typedef struct _UartInfo {
    quint32 frameheader;            //帧头 两个字节
    quint16 keyValue;               //按键值 两个字节
    GpsInfo gpsInfo;                //gps信息
    AccelerateInfo acceleInfo;      //加速度字段
    MagnetometerInfo magneInfo;     //磁力计字段
    BatteryInfo batteryInfo;        //电池信息
    JoystickInfo joystickInfo;      //摇杆值
    quint8 checkValue;              //校验值
}UartInfo;

/************************************无人机定位定向数据**********************************************/
/*定位定向信息消息(辅助通道)*/
typedef struct _ICD_ALLIGN_DWDX_INFO_MSG
{
    quint8 start;                      //! 开始
    quint8 len;                        //! 长度
    quint8 number;                     //! 序列
    quint8 systemId;                   //! 系统ID
    quint8 comId;                      //! 组件ID
    quint8 messageId;                  //! 消息ID
    qint32 longitude;                   // 基站经度坐标(GPS)，值域，刻度0.000001度,范围-180~180度;
    qint32 latitude;                    // 基站纬度坐标(GPS)，值域，刻度0.000001度,范围-90~90度;
    qint32 altitude;                   // 基站海拔高度，单位cm；
    qint32 easterly_velocity;          // 基站东向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 northward_velocity;         // 基站北向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 celestial_velocity;         // 基站天向速度，单位cm/s（静态降落此部分数据可用0替代）；
    qint32 double_headingangle;        // 基站双天线航向角，单位0.01deg，北偏东正;
    quint8 positioning_status;         // 1-定位信息可用 0-定位信息不可用;
    quint8 DF_status;                  // 1-定位信息可用 0-定位信息不可用;
    quint8 crclow;                     //! 校验和低字节
    quint8 crchigh;                    //! 校验和高字节
}ICD_ALLIGN_DWDX_INFO_MSG;

/* 区域中心点信息 */
typedef struct _ICD_ALLING_QYZXD_INFO_MSG
{
    unsigned char synchronization;           //! 同步码 0x55
    unsigned char synchronization1;           //! 同步码 0xaa
    unsigned char msg_id;                     //! 消息ID 0x41
    unsigned char msg_len;                    //! 消息长度 0x15
    int static_longitude;                     //! 静态目标区域中心点经度,LSB = 1*10-7
    int static_latitude;                      //! 静态目标区域中心点纬度,LSB = 1*10-7
    int dynamic_longitude;                    //! 动态目标区域中心点经度,LSB = 1*10-7
    int dynamic_latitude;                     //! 动态目标区域中心点纬度,LSB = 1*10-7
    unsigned char sum_check;                  //! 和校验，Low8bit(Sum(Byte4,…20))
}ICD_ALLING_QYZXD_INFO_MSG;
//#pragma pack(1)
/* 侦察目标定位信息 */
typedef struct  _ICD_ALLING_ZCMBDW_INFO_MSG
{
    unsigned char synchronization;            //! 同步码 0x55
    unsigned char synchronization1;           //! 同步码 0xaa
    unsigned char msg_id;                     //! 消息ID 0x41
    unsigned char msg_len;                    //! 消息长度 0x0D
    unsigned char task;                //! 任务阶段标识  静态：0x11  动态：0x66
    int center_longitude;                     //! 目标区域中心点经度,LSB = 1*10-7
    int center_latitude;                      //! 目标区域中心点纬度,LSB = 1*10-7
    unsigned char sum_check;                  //! 和校验，Low8bit(Sum(Byte4,…20))
}ICD_ALLING_ZCMBDW_INFO_MSG;


/* 图片接收 */
#pragma pack(1)
typedef struct _ICD_RECV_IMAGE_INFO_MSG{
    char synchronization;            //! 同步码 0x88
    char msg_id;                     //! 消息ID 0x89
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
}ICD_RECV_IMAGE_INFO_MSG;


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
typedef struct _OcuToChassisPara
{
    OcuToChassisFrameHead   frameHead;
    quint8 dlms;
    quint8 modeSwitch;
    quint8 chassisSpeedLimit;         /** 底盘限速设定，0~80，单位为km/h，低位在前，高位在后*/
    qint8  rockerHorizontal;          /** 摇杆水平方向值：0~100（左转），0~-100（右转）*/
    qint8  rockerVertical;            /** 摇杆垂直方向值：0~100（向前，油门开度），0~-100（向后，制动量）*/
    quint8 gear;
    quint8 chassisControl;
    quint8 equipmentControl;
    quint8 subcontrol;
    quint8 dataDestroy;                /** 数据销毁（预留）：0xaa*/
    quint8 electricalManagementControl;
    OcuToChassisEnd  end;
}OcuToChassisPara;

#pragma pack()
