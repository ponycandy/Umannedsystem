#pragma once

#include <QObject>
#include <QVector>
#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcControlService
{
public:
    virtual ~DjxlcControlService() {}

    /**
     * @brief setHighLampPowerUpControl ����ǰ���״̬
     * @param value
     */
    virtual void setHighLampPowerUpControl(int value) = 0;

    /**
     * @brief setTrumpetPowerUpControl  ��������״̬
     * @param value
     */
    virtual void setTrumpetPowerUpControl(int value) = 0;

    /**
     * @brief setEmergencyStopButton    ���ü�ͣ��ť״̬
     * @param value
     */
    virtual void setEmergencyStopButton(int value) = 0;

    virtual void getAxisJoystickData(const OcuToChassisParaOneTrans &paraOne) = 0;

};

Q_DECLARE_INTERFACE(DjxlcControlService, "Djxlc.service.ControlService")

