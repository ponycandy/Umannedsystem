#pragma once

#include <QtPlugin>
#include "icd/DjxlcOcuControlICDTransStruct.h"

class DjxlcCommunicationService
{
public:
    virtual ~DjxlcCommunicationService() {}

    virtual qint32 send(Djxlc::OcuToChassisParaOneTrans topic)=0;

    virtual qint32 send(Djxlc::OcuToChassisParaTwoTrans topic)=0;

    /**
     * @brief sendoc到自主计算机惯导对指令
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::OcuToComputerHeartBeatParaTransTopic topic)=0;

    /**
     * @brief send:oc到自主计算机惯导对指令
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::OcuToComputerTaskParaTransTopic topic)=0;

    /**
     * @brief send:oc到自主计算机惯导对指令
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::OcuToComputerInertialAligCommandTrans topic)=0;
    
    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::OcuToComputerTaskControlTransTopic topic)=0;

/********************************************************************OCU video****************************************/

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoOpenTrans topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoStopTrans topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoSetParameterTrans topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoGetParameterTrans topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoSetShowModeTrans topic) = 0;

    /**
     * @brief send
     * @param topic
     * @return
     */
    virtual qint32 send(Djxlc::VideoGetShowModeTrans topic) = 0;

    virtual void startChassisParaTimer(bool control) = 0;

    virtual void startAutoComputerHeartTimer(bool control) = 0;
};

Q_DECLARE_INTERFACE(DjxlcCommunicationService, "Djxlc.service.CommunicationService")
