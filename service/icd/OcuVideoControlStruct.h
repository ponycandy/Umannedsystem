#pragma once
#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>

namespace VideoControl {

//! ***********************************middle crawler car 视频控制协议命令*******************************************/
//! 视频控制ack
typedef struct _ICD_MIDDLE_CAR_VIDEO_ACK
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   Ack;
    qint8   CRC;
    qint16  EndCode;
}ICD_MIDDLE_CAR_VIDEO_ACK;

//! 视频流切换
typedef struct _ICD_MIDDLE_CAR_VIDEO_CHANNEL
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   VideoChannel;    /** 0=>拼接模块输出右单路视频
                               * 1=>拼接模块输出中单路视频
                               * 2=>拼接模块输出左单路视频
                               * 3=>左前方单路视频
                               * 4=>右前方单路视频
                               * 5=>后方单路视频
                               * 6=>拼接模块输出组合视频 */
    qint8   CRC;
    qint16  EndCode;
}ICD_MIDDLE_CAR_VIDEO_CHANNEL;

//! 调节分辨率
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION
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
}ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION;

//! 调节码率
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   controlMode;
    qint32  codeRate;
    qint8   CRC;
    qint16  EndCode;
}ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE;

//! 调节帧率
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE
{
    qint32  SynCode;
    qint16  Len;
    qint8   OPCode;
    qint8   FPS;
    qint8   CRC;
    qint16  EndCode;
}ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE;

//! 调节码率
typedef struct _ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL
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
}ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL;


/** ******************************OCU端与视频端通信结构体*************************************/
/**
 * ocu端到视频端消息头
 */
typedef struct _OcuToVideoFrameHead
{
    quint8   SYNC1;      /** 同步头1*/
    quint8   SYNC2;      /** 同步头2*/
    quint8   SRCID;      /** 源ID*/
    quint8   DSTID;      /** 目标ID*/
    quint8   MSIGID;     /** 消息编号*/
    qint8    MSNUM;      /** 消息编号*/
    quint16  PPLEN;      /** 数据后续长度（不包括pllen本身），长度为0-1460个字节*/
}OcuToVideoFrameHead;

//! insert by yx start
/**
 * ocu端到视频端 打开音视频流消息
 */
typedef struct _VideoOpen
{
    OcuToVideoFrameHead   frameHead;/** 帧头*/
    qint32                payload;  /** 01H：视频； 02H：音频； 03H：视频+音频；*/
}VideoOpen;

/**
 * ocu端到视频端 关闭音视频消息
 */
typedef struct _VideoClose
{
    OcuToVideoFrameHead   frameHead;/** 帧头*/
    qint32                payload;  /** 01H：视频； 02H：音频； 03H：视频+音频；*/
}VideoClose;

/**
 * ocu端到视频端 设置视频码率消息
 */
typedef struct _VideoCodeRateSet
{
    OcuToVideoFrameHead   frameHead;/** 帧头*/
    qint32                payload;  /** 256Kbps; 512Kbps; 640Kbps; 768Kbps; 1024Kbps; 2048Kbps*/
}VideoCodeRateSet;
//! insert by yx end

/**
 * ocu端到视频端设置视频显示模式消息
 */
typedef struct _VideoDisplayMode
{
    OcuToVideoFrameHead   frameHead;/** 帧头*/
    qint32         videoDisplayMode;/** 显示模式*/
}VideoDisplayMode;

/**
 * ocu端到视频端获取视频显示模式消息
 */
typedef OcuToVideoFrameHead   GetVideoDisplayModeCommand;

typedef struct _OcuToVideoResolutionSettingTopic
{
    OcuToVideoFrameHead   frameHead;/** 帧头*/
    quint8          ID;             /** ID*/
    quint8          FPS;            /** FPS*/
    quint16        Width;           /** 高度*/
    quint16        Height;          /** 宽度*/
    quint16        Bitrate;         /** 码率*/
    quint16        Gop;             /** 每帧间隔*/
    quint16        Reserved;        /** 预留*/
}OcuToVideoResolutionSettingTopic;

/**
 * 设置辅助控制量
 */
typedef struct _OcuToVideoAssistantSwitchTopic
{
    OcuToVideoFrameHead   frameHead;  /** 帧头*/
    quint32        AssistantSwitch;   /** 辅助开关量*/
}OcuToVideoAssistantSwitchTopic;




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

}











