#pragma once

#include <QtPlugin>
#include <QWidget>

struct DjxlcRadioSettingService
{
public:
    /**
     * @brief ~RadioSettingService
     */
    virtual ~DjxlcRadioSettingService() {}

    /**
     * @brief getRadioSettingWidget
     * @return
     */
    virtual QWidget* getRadioSettingWidget() = 0;
    
    /**
     * @brief setOperationMode 设置业务模式
     * @param operationMode
     */
    virtual void setOperationMode(int operationMode) =0;

    /**
     * @brief setRemoteOperationMode
     * @param operationMode
     */
    virtual void setRemoteOperationMode(int operationMode) =0;

    /**
     * @brief setConstantsFrequency 设置定频频率
     * @param constantsFrequency
     */
    virtual void setConstantsFrequency(double constantsFrequency) =0;

    /**
     * @brief setRemoteConstantsFrequency
     * @param constantsFrequency
     */
    virtual void setRemoteConstantsFrequency(double constantsFrequency) =0;

    /**
     * @brief setFrequencyHoppingTableNumber 设置跳频表号
     * @param frequencyHoppingTableNumber
     */
    virtual void setFrequencyHoppingTableNumber(int frequencyHoppingTableNumber) =0;

    /**
     * @brief setRemoteFrequencyHoppingTableNumber
     * @param frequencyHoppingTableNumber
     */
    virtual  void setRemoteFrequencyHoppingTableNumber(int frequencyHoppingTableNumber) =0;

    /**
     * @brief setWorkMode 设置工作模式
     * @param workMode
     */
    virtual void setWorkMode(int workMode) =0;

    /**
     * @brief setRemoteWorkMode
     * @param workMode
     */
    virtual void setRemoteWorkMode(int workMode) =0;

    /**
     * @brief setUserRate 设置用户速率
     * @param userRate
     */
    virtual void setUserRate(int userRate) =0;

    /**
     * @brief setLocalUserRate
     * @param userRate
     */
    virtual void setLocalUserRate(int  userRate) =0;

    /**
     * @brief setRemoteUserRate
     * @param userRate
     */
    virtual void setRemoteUserRate(int  userRate) =0;

    /**
     * @brief setTransmittedPower 设置发射功率
     * @param power
     */
    virtual void setTransmittedPower(int power) =0;

    /**
     * @brief setRemoteTransmittedPower
     * @param power
     */
    virtual void setRemoteTransmittedPower(int power) =0;

    /**
     * @brief setWaveWorkState 设置波形工作状态
     * @param state
     * @param local
     */
    virtual void setWaveWorkState(int state, int local) =0;

    /**
     * @brief setControlPower 设置控制权
     * @param type
     */
    virtual void setControlPower(int type) =0;
};

Q_DECLARE_INTERFACE(DjxlcRadioSettingService, "Djxlc.service.RadioSettingService")
