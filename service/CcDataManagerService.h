#pragma once

#include <QtPlugin>
#include <QMap>
struct CcDataManagerService
{
public:
    virtual ~CcDataManagerService() {}

    virtual void setTaskStatus(int value) = 0;

    virtual int getTaskStatus() = 0;

    virtual void setConvertTaskNum(QMap<double, int>&NumMap) = 0;

    virtual int getPlotTaskIndex() = 0;

    virtual int getXXLSH() = 0;

    virtual QMap<double, int>getConvertTaskNum() = 0;

};

Q_DECLARE_INTERFACE(CcDataManagerService, "CcDataManagerService")
