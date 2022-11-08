
#ifndef MAPSERVICE_H
#define MAPSERVICE_H
#pragma once
#include <QObject>


#include <QtPlugin>

#include "icd/OcuControlICDTransStruct.h"
class MapService
{
public:
    virtual ~MapService(){}


};
#define MapService_iid "MapService"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(MapService,MapService_iid  )
QT_END_NAMESPACE

#endif

