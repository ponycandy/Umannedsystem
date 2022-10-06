#pragma once

#include <QtPlugin>

#include "icd/OcuControlICDTransStruct.h"
struct CarManagerService
{
public:
    virtual ~CarManagerService() {}

    virtual void stopCarConnected() = 0;


    virtual CarInfo getCurrentCarInfo() = 0;


};

Q_DECLARE_INTERFACE(CarManagerService, "CarManagerService")
