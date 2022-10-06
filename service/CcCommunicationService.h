#pragma once

#include <QtPlugin>

#include "icd/OcuCommandControlTransStruct.h"
#include "icd/OcuCommandControlStruct.h"
struct CcCommunicationService
{
public:
    virtual ~CcCommunicationService() {}

    virtual quint32 send(MsgTaskReplyTrans topic) = 0;

    virtual quint32 send(MsgMotionAimTrans topic) = 0;

    virtual quint32 send(MsgObstacleTrans topic) = 0;

    virtual quint32 send(MsgStaticAimTrans topic) = 0;

    virtual quint32 send(MsgStatusTrans topic) = 0;

    virtual quint32 send(MsgTaskTrans topic) = 0;

    virtual quint32 send(MsgStatusFKZYTrans topic) = 0;

    virtual quint32 send(MsgStatusDZZZTrans topic) = 0;

    virtual quint32 send(MsgStatus201ZCJSZDYTTrans topic) = 0;

    virtual quint32 send(ReportTargetNum topic) = 0;
};

Q_DECLARE_INTERFACE(CcCommunicationService, "CcCommunicationService")
