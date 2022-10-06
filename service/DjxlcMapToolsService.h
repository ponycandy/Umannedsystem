#pragma once

#include <QtPlugin>
#include <QObject>
#include <QWidget>
#include <QDialog>
#include <icd/DjxlcOcuControlICDTransStruct.h>

struct DjxlcMapToolsService
{
public:
    /**
     * @brief ~MapToolsService
     */
    virtual ~DjxlcMapToolsService() {}

    /**
     * @brief getMapToolsWidget
     * @return
     */
    virtual QWidget *getMapToolsWidget() = 0;

    /**
     * @brief getDistanceMeasurmentWidget
     * @return
     */
    virtual QWidget *getDistanceMeasurmentWidget() = 0;

    /**
     * @brief getAreaMeasurmentWidget
     * @return
     */
    virtual QWidget *getAreaMeasurmentWidget() = 0;

    /**
     * @brief getMapImageLayerManagerWidget 图层管理界面
     * @return
     */
    virtual QWidget *getMapImageLayerManagerWidget() = 0;

    /**
     * @brief getMapMoveWidget 地图移动界面
     * @return
     */
    virtual QWidget *getMapMoveWidget() = 0;

    /**
     * @brief getPlottingManagerWidget
     * @return
     */
    virtual QWidget *getPlottingManagerWidget() = 0;

    /**
     * @brief getImageLayerDialog
     * @return
     */
    virtual QDialog* getImageLayerDialog() = 0;

    /**
     * @brief getPlottingManagerDialog
     * @return
     */
    virtual QDialog* getPlottingManagerDialog() = 0;
};

Q_DECLARE_INTERFACE(DjxlcMapToolsService, "Djxlc.service.MapToolsService")
