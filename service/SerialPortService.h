#pragma once

#include <QtPlugin>

#include <QtSerialPort/QSerialPort>

#include "icd/OcuControlICDTransStruct.h"

struct SerialPortService
{
public:
    virtual ~SerialPortService() {}

    /**
     * @brief open
     * @param pathKey
     * @param portName
     * @return
     */
    virtual bool open(const QString &pathKey,const QString &portName) = 0;

    /**
     * @brief close
     * @param portName
     * @return
     */
    virtual bool close(const QString &portName) = 0;

    /**
     * @brief setBaudRate
     * @param baudRate
     * @param directions
     * @return
     */
    virtual bool setBaudRate(qint32 baudRate, QSerialPort::Directions directions = QSerialPort::AllDirections) = 0;

    /**
     * @brief setDataBits 设置数据位
     * @param dataBits
     * @return
     */
    virtual bool setDataBits(QSerialPort::DataBits dataBits)  = 0;

    /**
     * @brief setStopBits 设置停止位
     * @param stopBits
     * @return
     */
    virtual bool setStopBits(QSerialPort::StopBits stopBits)  = 0;

    /**
     * @brief setParityBits 设置校验位
     * @param parityBits
     * @return
     */
    virtual bool setParityBits(QSerialPort::Parity parityBits)  = 0;

    /**
     * @brief getAvailablePortsName
     * @return
     */
    virtual QStringList getAvailablePortsName()  = 0;

    /**
     * @brief sendSerialData
     * @param data
     * @return
     */
    virtual qint64 sendSerialData(const QByteArray &data)  = 0;

};

Q_DECLARE_INTERFACE(SerialPortService, "SerialPortService")
