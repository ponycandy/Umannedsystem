#pragma once

#include <QtPlugin>

#include <QWidget>

struct DjxlcOperationModeService
{
public:
    virtual ~DjxlcOperationModeService() {}
	
    /**
     * @brief getOprationModeWidget 获取操作模式界面
     * @return
     */
    virtual QWidget *getOprationModeWidget() = 0;

    /**
     * @brief getPathFollowWidget 获取路径跟随界面
     * @return
     */
    virtual QWidget *getPathFollowWidget() = 0;

    /**
     * @brief getOneKeyBackWidget 获取一键返航界面
     * @return
     */
    virtual QWidget *getOneKeyBackWidget() = 0;

    virtual QWidget *getComputerImage(void)  = 0;
};

Q_DECLARE_INTERFACE(DjxlcOperationModeService, "Djxlc.service.OperationModeService")
