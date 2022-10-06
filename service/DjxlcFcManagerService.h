#pragma once

#include <QObject>
#include <QVector>
#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcFcManagerService
{
public:
    virtual ~DjxlcFcManagerService() {}

    /**
     * @brief getFcTargetInfoWidget
     * @return
     */
    virtual QWidget* getFcTargetInfoWidget() = 0;

};

Q_DECLARE_INTERFACE(DjxlcFcManagerService, "Djxlc.service.FcManagerService")

