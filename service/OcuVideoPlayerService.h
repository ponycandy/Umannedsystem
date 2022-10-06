#pragma once

#include <QtPlugin>

#include "icd/OcuControlICDTransStruct.h"

struct OcuVideoPlayerService
{
public:
    virtual ~OcuVideoPlayerService() {}

    /**
     * @brief getVideoPlayerWindow
     * @return
     */
    virtual QWidget *getVideoPlayerWindow() = 0;


    /**
     * @brief getVideoPlayerWindow
     * @param type
     * @return
     */
    virtual QWidget *getVideoPlayerWindow(VehicleType type) = 0;



    /**
     * @brief releaseVideoPlayerWindow
     * @return
     */
    virtual void releaseVideoPlayerWindow() = 0;

    /**
     * @brief setVideoSceneDisplayMode
     * @param mode 0 = full scene; 1 = half scene; 2 = minimum scene;
     */
    virtual void setVideoSceneDisplayMode(quint8 mode = 0) = 0;

    /**
     * @brief setReconnectFrameImageDisplay
     */
    virtual void setReconnectFrameImageDisplay() = 0;

    /**
     * @brief setReconnectFrameImageDisplay
     */
    virtual void setReconnectFrameImageDisplay(VehicleType type) = 0;
};

Q_DECLARE_INTERFACE(OcuVideoPlayerService, "OcuVideoPlayerService")
