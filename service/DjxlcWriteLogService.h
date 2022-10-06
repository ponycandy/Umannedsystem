#pragma once

#include <QtPlugin>

#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcWriteLogService
{
public:
    virtual ~DjxlcWriteLogService() {}
    /**
     * @brief writeLog
     * @param data
     */
    virtual void writeLog(QString data) = 0;

    /**
     * @brief writeLog 任务日志
     * @param data
     */
    virtual void writeLog(LogDefines::TaskLogData data) = 0;

    /**
     * @brief writeLog 系统操作日志
     * @param data
     */
    virtual void writeLog(LogDefines::SystemHandleData data) = 0;

    /**
     * @brief writeLog 车辆状态日志
     * @param data
     */
    virtual void writeLog(LogDefines::CarStateData data) = 0;

    /**
     * @brief writeLog 车辆机动日志
     * @param data
     */
    virtual void writeLog(LogDefines::CarRunData data) = 0;

    /**
     * @brief insertAppRunData 软件运行日志
     * @param infoText
     * @return
     */
    virtual bool insertAppRunData(const QString &infoText) =0;

    /**
     * @brief insertTaskLogData 任务日志
     * @param data
     * @return
     */
    virtual bool insertTaskLogData(const Djxlc::ReceiveTaskLogData &data) = 0;

    /**
     * @brief insertSystemOperationData 系统操作日志
     * @param data
     * @return
     */
    virtual bool insertSystemOperationData(const Djxlc::SystemOperationData &data) = 0;

    /**
     * @brief insertVehicleStatusData 车辆状态日志
     * @param data
     * @return
     */
    virtual bool insertVehicleStatusData(const Djxlc::VehicleStatusData &data) = 0;

    /**
     * @brief insertRemoteDrivingData 车辆机动日志 遥控驾驶任务
     * @param data
     * @return
     */
    virtual bool insertRemoteDrivingData(const Djxlc::RemoteDrivingData &data) = 0;

    /**
     * @brief insertAutoDrivingData 自主驾驶任务
     * @param data
     * @return
     */
    virtual bool insertAutoDrivingData(const Djxlc::AutoDrivingData &data) = 0;
};

Q_DECLARE_INTERFACE(DjxlcWriteLogService, "Djxlc.service.WriteLogService")
