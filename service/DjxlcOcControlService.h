#pragma once

#include <QtPlugin>

#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcOcControlService
{
public:
    virtual ~DjxlcOcControlService() {}

    /**
     * @brief setHighLampPowerUpControl 设置前大灯状态
     * @param value
     */
    virtual void setHighLampPowerUpControl(int value) = 0;

    /**
     * @brief setTrumpetPowerUpControl  设置喇叭状态
     * @param value
     */
    virtual void setTrumpetPowerUpControl(int value) = 0;

    /**
     * @brief setEmergencyStopButton    设置急停按钮状态
     * @param value
     */
    virtual void setEmergencyStopButton(int value) = 0;

    virtual void getAxisJoystickData(const Djxlc::OcuToChassisParaOneTrans &paraOne) = 0;
};

Q_DECLARE_INTERFACE(DjxlcOcControlService, "DjxlcOcControlService")
