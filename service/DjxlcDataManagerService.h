#pragma once

#include <QObject>
#include <QVector>
#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcDataManagerService
{
public:
    virtual ~DjxlcDataManagerService() {}

    /**
     * @brief setCurrentConnectedCarType:设置当前连接车辆类型
     * @param value
     */
    virtual void setCurrentConnectedCarType(Djxlc::CurrentConnectedCarType value) = 0;

    /**
     * @brief getCurrentConnectedCarType:获取当前连接车辆的类型
     * @return
     */
    virtual Djxlc::CurrentConnectedCarType getCurrentConnectedCarType() = 0;

    /**
     * @brief setPowerMode ocu 到底盘端的参数设置函数接口
     * @param value
     */
    virtual void setPowerMode(qint8 value) = 0;

    /**
     * @brief setChassisSpeedLimit
     * @param value
     */
    virtual void setChassisSpeedLimit(qint8 value) = 0;

    /**
     * @brief setRockerHorizontal
     * @param value
     */
    virtual void setRockerHorizontal(qint8 value) = 0;

    /**
     * @brief setRockerVertical
     * @param value
     */
    virtual void setRockerVertical(qint8 value) = 0;

    /**
     * @brief setGear
     * @param value
     */
    virtual void setGear(qint8 value) = 0;

    virtual void setManualExit(quint8 value) = 0;

    virtual void setClimbConditions(quint8 value) = 0;

    /**
     * @brief setBatteryControl
     * @param value
     */
    virtual void setBatteryControl(qint8 value) = 0;

    /**
     * @brief setEmergencyStopButton
     * @param value
     */
    virtual void setEmergencyStopButton(qint8 value) = 0;

    /**
     * @brief setParkingControl
     * @param value
     */
    virtual void setParkingControl(qint8 value) = 0;

    /**
     * @brief setChassisEnableControl
     * @param value
     */
    virtual void setChassisEnableControl(qint8 value) = 0;

    /**
     * @brief setPowerModulePowerUpControl
     * @param value
     */
    virtual void setPowerModulePowerUpControl(qint8 value) = 0;

    /**
     * @brief setAutonomicComputerPowerUpControl
     * @param value
     */
    virtual void setAutonomicComputerPowerUpControl(qint8 value) = 0;

    /**
     * @brief setLiDAR_PowerUpControl
     * @param value
     */
    virtual void setLiDAR_PowerUpControl(qint8 value) = 0;

    virtual void setVerticalWallCondition(quint8 value) = 0;

    /**
     * @brief setINS_PowerUpControl
     * @param value
     */
    virtual void setINS_PowerUpControl(qint8 value) = 0;

    /**
     * @brief setChargerInterfacePowerUpControl
     * @param value
     */
    virtual void setChargerInterfacePowerUpControl(qint8 value) = 0;

    /**
     * @brief setCarWorkModeSwitchControl
     * @param value
     */
    virtual void setCarWorkModeSwitchControl(qint8 value) = 0;

    /**
     * @brief setHighLampPowerUpControl
     * @param value
     */
    virtual void setHighLampPowerUpControl(qint8 value) = 0;

    /**
     * @brief setLowLampPowerUpControl
     * @param value
     */
    virtual void setLowLampPowerUpControl(qint8 value) = 0;

    /**
     * @brief setAlertLampPowerUpControl
     * @param value
     */
    virtual void setAlertLampPowerUpControl(qint8 value) = 0;

    /**
     * @brief setTrumpetPowerUpControl
     * @param value
     */
    virtual void setTrumpetPowerUpControl(qint8 value) = 0;

    /**
     * @brief setReceveCarInfoPowerUpControl
     * @param value
     */
    virtual void setReceveCarInfoPowerUpControl(qint8 value) = 0;

    /**
     * @brief setDataDestroy
     * @param value
     */
    virtual void setDataDestroy(qint8 value) = 0;

    /**
     * @brief setFaultResetControl
     * @param value
     */
    virtual void setFaultResetControl(qint8 value) = 0;

    /**
     * @brief setGuardMaskCommand
     * @param value
     */
    virtual void setGuardMaskCommand(qint8 value) = 0;

    /**
     * @brief getOcuToChassisControlPara
     * @param controlPara
     */
    virtual void getOcuToChassisControlParaOne(Djxlc::OcuToChassisParaOneTrans &controlPara) = 0;

    virtual void getOcuToChassisControlParaTwo(Djxlc::OcuToChassisParaTwoTrans &controlPara) = 0;

    /**
     * @brief getOcuToComputerHeartBeatPara
     * @param heartBeatPara
     */
    virtual void getOcuToComputerHeartBeatPara(Djxlc::OcuToComputerHeartBeatParaTransTopic &heartBeatPara) = 0;

    /**
     * @brief getOneKeyBackPoint 获取一键返回的路径点：为当前的任务点
     * @return
     */
    virtual QVector<Djxlc::strPose>  getOneKeyBackPoint()=0;

    /**
     * @brief initRecordState 初始记录状态
     */
    virtual void initRecordState()=0;

    /**
     * @brief writeRecordData 写入记录状态
     */
    virtual void writeRecordData()=0;

    /**
     * @brief loadHistoryRecordData 加载历史记录点
     * @param fileName
     * @return
     */
    virtual QVector<Djxlc::strPose> loadHistoryRecordData(QString fileName)=0;

    /**
     * @brief getOneKeyBackPathPoin
     * @return
     */
    virtual QVector<Djxlc::strPose> getOneKeyBackPathPoin()=0;
       
    /**
     * @brief getPlatformControlState 平台控制权状态
     * @return
     */  
    virtual int  getGlobalIndex()=0;

    /**
     * @brief getAuotonomusTaskConunter
     * @return
     */
    virtual int getAuotonomusTaskConunter() = 0;

    /**
     * @brief initOcuToChassisControlPara   初始化数据
     */
    virtual void initOcuToChassisControlPara() = 0;
};

Q_DECLARE_INTERFACE(DjxlcDataManagerService, "Djxlc.service.DataManagerService")

