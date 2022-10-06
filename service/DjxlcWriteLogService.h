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
     * @brief writeLog ������־
     * @param data
     */
    virtual void writeLog(LogDefines::TaskLogData data) = 0;

    /**
     * @brief writeLog ϵͳ������־
     * @param data
     */
    virtual void writeLog(LogDefines::SystemHandleData data) = 0;

    /**
     * @brief writeLog ����״̬��־
     * @param data
     */
    virtual void writeLog(LogDefines::CarStateData data) = 0;

    /**
     * @brief writeLog ����������־
     * @param data
     */
    virtual void writeLog(LogDefines::CarRunData data) = 0;

    /**
     * @brief insertAppRunData ���������־
     * @param infoText
     * @return
     */
    virtual bool insertAppRunData(const QString &infoText) =0;

    /**
     * @brief insertTaskLogData ������־
     * @param data
     * @return
     */
    virtual bool insertTaskLogData(const Djxlc::ReceiveTaskLogData &data) = 0;

    /**
     * @brief insertSystemOperationData ϵͳ������־
     * @param data
     * @return
     */
    virtual bool insertSystemOperationData(const Djxlc::SystemOperationData &data) = 0;

    /**
     * @brief insertVehicleStatusData ����״̬��־
     * @param data
     * @return
     */
    virtual bool insertVehicleStatusData(const Djxlc::VehicleStatusData &data) = 0;

    /**
     * @brief insertRemoteDrivingData ����������־ ң�ؼ�ʻ����
     * @param data
     * @return
     */
    virtual bool insertRemoteDrivingData(const Djxlc::RemoteDrivingData &data) = 0;

    /**
     * @brief insertAutoDrivingData ������ʻ����
     * @param data
     * @return
     */
    virtual bool insertAutoDrivingData(const Djxlc::AutoDrivingData &data) = 0;
};

Q_DECLARE_INTERFACE(DjxlcWriteLogService, "Djxlc.service.WriteLogService")
