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
     * @brief setOperationMode ����ҵ��ģʽ
     * @param operationMode
     */
    virtual void setOperationMode(int operationMode) =0;

    /**
     * @brief setRemoteOperationMode
     * @param operationMode
     */
    virtual void setRemoteOperationMode(int operationMode) =0;

    /**
     * @brief setConstantsFrequency ���ö�ƵƵ��
     * @param constantsFrequency
     */
    virtual void setConstantsFrequency(double constantsFrequency) =0;

    /**
     * @brief setRemoteConstantsFrequency
     * @param constantsFrequency
     */
    virtual void setRemoteConstantsFrequency(double constantsFrequency) =0;

    /**
     * @brief setFrequencyHoppingTableNumber ������Ƶ���
     * @param frequencyHoppingTableNumber
     */
    virtual void setFrequencyHoppingTableNumber(int frequencyHoppingTableNumber) =0;

    /**
     * @brief setRemoteFrequencyHoppingTableNumber
     * @param frequencyHoppingTableNumber
     */
    virtual  void setRemoteFrequencyHoppingTableNumber(int frequencyHoppingTableNumber) =0;

    /**
     * @brief setWorkMode ���ù���ģʽ
     * @param workMode
     */
    virtual void setWorkMode(int workMode) =0;

    /**
     * @brief setRemoteWorkMode
     * @param workMode
     */
    virtual void setRemoteWorkMode(int workMode) =0;

    /**
     * @brief setUserRate �����û�����
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
     * @brief setTransmittedPower ���÷��书��
     * @param power
     */
    virtual void setTransmittedPower(int power) =0;

    /**
     * @brief setRemoteTransmittedPower
     * @param power
     */
    virtual void setRemoteTransmittedPower(int power) =0;

    /**
     * @brief setWaveWorkState ���ò��ι���״̬
     * @param state
     * @param local
     */
    virtual void setWaveWorkState(int state, int local) =0;

    /**
     * @brief setControlPower ���ÿ���Ȩ
     * @param type
     */
    virtual void setControlPower(int type) =0;
};

Q_DECLARE_INTERFACE(DjxlcRadioSettingService, "Djxlc.service.RadioSettingService")
