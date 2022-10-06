#pragma once

#include <QtPlugin>
#include "icd/QxxlcIcdTransStruct.h"
#include "icd/OcuCommandControlTransStruct.h"


struct QxxlcOcCommunicationService
{
public:
    virtual ~QxxlcOcCommunicationService() {}
	
	   //! ***********************************super car chassis command********************************************
    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_P_DPCZ_CMD_MSG_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_P_YKJS_CMD_MSG_TRANS  command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_P_JSCK_HEART_INFO_MSG_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_CZ_DWDX_ZBZD_CMD_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_CZ_XTJK_HALT_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_CZ_XTJK_INIT_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_CZ_XTJK_YKJS_PLAN_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_CZ_XTJK_ZZJS_PLAN_TRANS   command) =0;

    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_P_YCKZ_INFO_MSG_TRANS   command) =0;

    //! ***********************************TaskMsg 自主驾驶通用********************************************
    /**
     * @brief send
     * @param pathKey
     * @param command
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_COMMON_CZ_XTJK_ZZJS_PLAN_TRANS   command) =0;



    //!***************************视频流控制消息***************************************/
    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_VIDEO_CHANNEL_TRANS   topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_VIDEO_ADJUST_RESOLUTION_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_VIDEO_ADJUST_FRAM_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_VIDEO_ADJUST_CODE_RATE_TRANS  topic) =0;

    /**
     * @brief send
     * @param pathKey
     * @param topic
     * @return
     */
    virtual qint32 send(const QString pathKey,const Qxxlc::ICD_VIDEO_PLAY_CONTROL_TRANS  topic) =0;

    /**
     * @brief setRcsInit
     * @param lhost
     * @param rhost
     */
    virtual void  setRcsInit(QString lhost, QString rhost) = 0;

    /**
     * @brief setRcsInit
     * @param carInfo
     */
    virtual void  setRcsInit(CarInfo& carInfo) = 0;

    /**
     * @brief setRcsStart
     */
    virtual void  setRcsStart() =0;

    /**
     * @brief setRcsStop
     */
    virtual void  setRcsStop() =0;

    /**
     * @brief setRcsRealese
     */
    virtual void  setRcsRealese() =0;

    //!***************************Ocu Send instructions or messages  to control software********************************/
    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::MobilePlatStatusTrans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::PlatEnvirStatusTrans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::IC_DC_01Trans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::IC_DC_02Trans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::AI_DC_O1Trans topic) =0;

    //!****************************Ocu Send instructions or messages  to the alert monitor****************************/

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::DC_IC_01Trans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::DC_IC_02Trans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::DC_IC_03Trans topic) =0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual quint32 send(const Qxxlc::DC_IC_04Trans topic) =0;

    //!*******************************************portable car communication send interface ****************************/

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Qxxlc::ICD_ALLIGN_DWDX_INFO_MSG_TRANS topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Qxxlc::ICD_ALLING_QYZXD_INFO_MSG_TRANS topic) = 0;


    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Qxxlc::OcuToChassisParaTrans& topic) = 0;
};

Q_DECLARE_INTERFACE(QxxlcOcCommunicationService, "QxxlcOcCommunicationService")
