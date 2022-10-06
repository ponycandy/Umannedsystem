#pragma once

#include <QtPlugin>

#include <QWidget>

struct DjxlcOperationModeService
{
public:
    virtual ~DjxlcOperationModeService() {}
	
    /**
     * @brief getOprationModeWidget ��ȡ����ģʽ����
     * @return
     */
    virtual QWidget *getOprationModeWidget() = 0;

    /**
     * @brief getPathFollowWidget ��ȡ·���������
     * @return
     */
    virtual QWidget *getPathFollowWidget() = 0;

    /**
     * @brief getOneKeyBackWidget ��ȡһ����������
     * @return
     */
    virtual QWidget *getOneKeyBackWidget() = 0;

    virtual QWidget *getComputerImage(void)  = 0;
};

Q_DECLARE_INTERFACE(DjxlcOperationModeService, "Djxlc.service.OperationModeService")
