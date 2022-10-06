#pragma once

#include <QtPlugin>
#include <QString>


#include "icd/OcuVideoControlTransStruct.h"

struct OcuVideoControlService
{
public:
    virtual ~OcuVideoControlService() {}


    virtual void setStartVideoControl(QString carType) = 0;




    //!***************************视频流控制消息***************************************/
    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_MIDDLE_CAR_VIDEO_CHANNEL_TRANS   topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_RESOLUTION_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_FRAM_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_MIDDLE_CAR_VIDEO_ADJUST_CODE_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_MIDDLE_CAR_VIDEO_PLAY_CONTROL_TRANS  topic) =0;




    /** *************************************视频指令发送*****************************/
    /**
     * @brief send 设置视频控制模式
     * @param topic
     * @return
     */
    virtual qint32 send(const VideoControl::VideoDisplayModeTrans topic)=0;

    /**
     * @brief send 获取视频控制模式
     * @param topic
     * @return
     */
    virtual qint32 send(const VideoControl::GetVideoDisplayModeTrans topic)=0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(const VideoControl::OcuToVideoResolutionSettingTransTopic topic)=0;

    /**
     * @brief send 视频辅助控制量
     * @param topic
     * @return
     */
    virtual qint32 send(const VideoControl::OcuToVideoAssistantSwitchTransTopic topic)=0;


    //! 打开音视频流消息
    virtual qint32 send(const VideoControl::VideoOpenTrans topic)=0;

    //! 关闭音视频消息
    virtual qint32 send(const VideoControl::VideoCloseTrans topic)=0;

    //! 设置视频码率消息
    virtual qint32 send(const VideoControl::VideoCodeRateSetTrans topic)=0;


    //!***************************��Ƶ��������Ϣ***************************************/
    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_VIDEO_CHANNEL_TRANS   topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_VIDEO_ADJUST_RESOLUTION_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_VIDEO_ADJUST_FRAM_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_VIDEO_ADJUST_CODE_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const VideoControl::ICD_VIDEO_PLAY_CONTROL_TRANS  topic) =0;






};

Q_DECLARE_INTERFACE(OcuVideoControlService, "OcuVideoControlService")
