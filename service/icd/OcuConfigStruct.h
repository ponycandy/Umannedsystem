#pragma once

#include <QObject>


typedef struct _CarControlIpConfig
{
    int id;
    QString localip;
    int localport;
    QString remoteip;
    int remoteport;
    QString carType;
    int carindex;
}CarControlIpConfig;
Q_DECLARE_METATYPE(CarControlIpConfig)


typedef struct _FireControlIpConfig
{
    int id;
    QString localip;
    int localport;
    QString remoteip;
    int remoteport;
    QString carType;
    int carindex;
}FireControlIpConfig;
Q_DECLARE_METATYPE(FireControlIpConfig)

