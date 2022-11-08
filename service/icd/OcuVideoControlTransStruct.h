#pragma once

#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QDateTime>




namespace VideoControl {

//! *********************************** middle crawler car 视频控制协议命令*******************************************/
//! 视频控制ack*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_ACK_TRANS
{
    qint8   Ack;
}ICD_MIDDLE_CAR_VIDEO_ACK_TRANS;


//! 视频流切换*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_CHANNEL_TRANS
{
    qint8   VideoChannel;        /** 0=>拼接模块输出右单路视频
                                   * 1=>拼接模块输出中单路视频
                                   * 2=>拼接模块输出左单路视频
                                   * 3=>左前方单路视频
                                   * 4=>右前方单路视频
                                   * 5=>后方单路视频
                                   * 6=>拼接模块输出组合视频
                                   */
    qint8   overlayCoefficient;  /**  高4位（overlay图像使能，仅在输出组合视频时有效)
                                   * 0x0~0xe=>使能图像叠加模式
                                   * eg. X表示使能图像叠加模式，叠加图像缩小1+0.2*X倍
                                   * 0xf=>禁止图像叠加模式
                                  */
}ICD_MIDDLE_CAR_VIDEO_CHANNEL_TRANS;


//! 调节分辨率*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION_TRANS
{
    quint16 x;
    quint16 y;
    quint16 crop_width;
    quint16 crop_height;             //! (x, y)为裁剪起始点，如0x00000000_05000320表示从(0, 0)开始裁剪1280x800大小的图像
    quint16 scale_width;
    quint16 scale_height;            //! scale_width为前两个字节，scale_height为后两个字节，均为无符号整数。如0x0A000320表示分辨率设置为2560x800。
}ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION_TRANS;


//! 调节码率*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE_TRANS
{
    qint8   controlMode;
    qint32  codeRate;
}ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE_TRANS;


//! 调节帧率*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE_TRANS
{
    qint8   FPS;
}ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE_TRANS;


//! 调节播放控制*/
typedef struct _ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL_TRANS
{
    qint8   playControl;
    qint8   ipFistWord;
    qint8   ipSecondWord;
    qint8   ipThreeWord;
    qint8   ipFourWord;
    qint16  port;
}ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL_TRANS;







/** *******************************知新思明相机控制协议*************************************/

//! insert by yx start
/**
 * ocu端到视频端 打开音视频流消息
 */
typedef struct _VideoOpenTrans
{
    qint32                payload;  /** 01H：视频； 02H：音频； 03H：视频+音频；*/
}VideoOpenTrans;

/**
 * ocu端到视频端 关闭音视频消息
 */
typedef struct _VideoCloseTrans
{
    qint32                payload;  /** 01H：视频； 02H：音频； 03H：视频+音频；*/
}VideoCloseTrans;

/**
 * ocu端到视频端 设置视频码率消息
 */
typedef struct _VideoCodeRateSetTrans
{
    qint32                payload;  /** 256Kbps; 512Kbps; 640Kbps; 768Kbps; 1024Kbps; 2048Kbps*/
}VideoCodeRateSetTrans;
//! insert by yx end

typedef  enum{
    VIDEO_NONE,
    VIDEO_NONE_FRONT_WHITE_LIGHT,
    VIDEO_NONE_FRONT_NIGHT_VISION,
    VIDEO_NONE_BACK_WHITE_LIGHT,
    VIDEO_NONE_BACK_NIGHT_VISION,
}VideoDisplayModeEnum;



typedef  enum{
    VIDEO_SUB_NONE,
    VIDEO_SUB_NONE_WHITE_LIGHT,
    VIDEO_SUB_NONE_NIGHT_VISION,
}VideoDisplaySubModeEnum;


typedef struct _VideoDisplayModeTrans
{
    qint8   msnum;/*响应顺序号*/
    VideoDisplayModeEnum   videoDisplayMode;/*显示模式*/
    VideoDisplaySubModeEnum videoDisplaySubMode;
}VideoDisplayModeTrans;


typedef struct _GetVideoDisplayModeTrans
{
    qint8   msnum;/*响应顺序号*/
}GetVideoDisplayModeTrans;


/*OCU到本地视频端通信结构体*/
typedef struct _OcuToLocalVideoTransTopic
{
    qint8            commandOne;
    qint8            commandTwo;
}OcuToLocalVideoTransTopic;


/*设置视频分辨率*/
typedef struct _OcuToVideoResolutionSettingTransTopic
{
    quint8          Msnum;      /*消息号*/
    quint8          ID;               /*ID*/
    quint8          FPS;             /*FPS*/
    quint16        Width;         /*高度*/
    quint16        Height;        /*宽度*/
    quint16        Bitrate;        /*码率*/
    quint16        Gop;            /*每帧间隔*/
    quint16        Reserved;   /*预留*/
}OcuToVideoResolutionSettingTransTopic;


/*设置辅助控制量*/
typedef struct _OcuToVideoAssistantSwitchTransTopic
{
    quint8         Msnum;      /*消息号*/
    quint32        AssistantSwitch;   /*辅助开关量*/
}OcuToVideoAssistantSwitchTransTopic;




//! *********************************** 惠联相机协议 视频控制协议命令*******************************************/
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


}

Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_ACK_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_CHANNEL_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL_TRANS)



Q_DECLARE_METATYPE(VideoControl::VideoDisplayModeEnum)
Q_DECLARE_METATYPE(VideoControl::VideoDisplaySubModeEnum)
Q_DECLARE_METATYPE(VideoControl::VideoDisplayModeTrans)
Q_DECLARE_METATYPE(VideoControl::GetVideoDisplayModeTrans)
Q_DECLARE_METATYPE(VideoControl::OcuToLocalVideoTransTopic)
Q_DECLARE_METATYPE(VideoControl::OcuToVideoResolutionSettingTransTopic)
Q_DECLARE_METATYPE(VideoControl::OcuToVideoAssistantSwitchTransTopic)


Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_ACK_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_CHANNEL_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_ADJUST_RESOLUTION_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_ADJUST_CODE_RATE_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_ADJUST_FRAM_RATE_TRANS)
Q_DECLARE_METATYPE(VideoControl::ICD_VIDEO_PLAY_CONTROL_TRANS)
















