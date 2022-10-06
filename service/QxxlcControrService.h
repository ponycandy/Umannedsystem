#pragma once

#include <QtPlugin>
#include "icd/QxxlcIcdTransStruct.h"

struct QxxlcControrService
{
public:
    virtual ~QxxlcControrService() {}


    /**
     * @brief getSuperCarControlWidget
     * @return
     */
    virtual QWidget* getSuperCarControlWidget() = 0;

    /**
     * @brief loadCommadTaskTurnToAutoDriver
     */
    virtual void loadCommadTaskTurnToAutoDriver(CommandTaskTurnToAutoDriverTrans &taskInfo) = 0;
};

Q_DECLARE_INTERFACE(QxxlcControrService, "QxxlcControrService")
