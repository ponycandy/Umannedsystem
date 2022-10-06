#pragma once

#include <QtPlugin>


#include "icd/XtzkxICDTransStruct.h"

struct XtzkxCommunicationService
{
public:
    virtual ~XtzkxCommunicationService() {}

    /**
     * @brief send
     * @param ptTopic
     */
    virtual void send(Xtzkx::ReportTaskExecutionTrans topic) = 0;

    /**
     * @brief send
     * @param ptTopic
     */
    virtual void send(Xtzkx::InvestigationIntelligenceTrans topic) = 0;

    /**
     * @brief send
     * @param ptTopic
     */
    virtual void send(Xtzkx::SituationalInformationTrans topic) = 0;


};

Q_DECLARE_INTERFACE(XtzkxCommunicationService, "XtzkxCommunicationService")
