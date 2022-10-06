#pragma once

#include <QtPlugin>

#include <QWidget>
#include "icd/DjxlcOcuControlICDTransStruct.h"

struct DjxlcMapService
{
public:
    /**
     * @brief ~MapService
     */
    virtual ~DjxlcMapService() {}

    /**
     * @brief getMapWidget
     * @return
     */
    virtual QWidget *getMapWidget() = 0;

    /**
     * @brief getMapAttributeWidget
     * @return
     */
    virtual QWidget *getMapAttributeWidget() = 0;

    /**
     * @brief drawPathFollow
     * @param pathFollowTask
     */
    virtual void drawPathFollow(Djxlc::PathFollowTask   &pathFollowTask) = 0;

    /**
     * @brief getPlottingManagerIndex
     * @return
     */
    virtual int  getPlottingManagerIndex() =0;

    /**
     * @brief getPlottingManager
     * @return
     */
    virtual QMap<int ,Djxlc::PlottingManager> getPlottingManager() = 0;

    /**
     * @brief deletePlottingManager
     * @param index
     * @param data
     */
    virtual void deletePlottingManager(int index, const Djxlc::PlottingManager &data) = 0;

    /**
     * @brief editColorPlottingManager
     * @param index
     * @param color
     */
    virtual void editColorPlottingManager(int index, QColor color) = 0;

    /**
     * @brief editLineWidthPlottingManager
     * @param index
     * @param lineWidth
     */
    virtual void editLineWidthPlottingManager(int index, int lineWidth) = 0;

    virtual bool drawRoadNetworkFile(const char* pts, const char* edge) = 0;
};

Q_DECLARE_INTERFACE(DjxlcMapService, "Djxlc.service.MapService")
