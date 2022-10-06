#pragma once

#include <QtPlugin>

struct QxxlcOcVideoPlayerService
{
public:
    /**
     * @brief ~QxxlcOcVideoPlayerService
     */
    virtual ~QxxlcOcVideoPlayerService() {}

    /**
     * @brief getVideoPlayerWindow
     * @return
     */
    virtual QWidget *getVideoPlayerWindow() = 0;

    /**
     * @brief setVideoSceneDisplayMode
     * @param mode 0 = full scene; 1 = half scene; 2 = minimum scene;
     */
    virtual void setVideoSceneDisplayMode(quint8 mode = 0) = 0;
};

Q_DECLARE_INTERFACE(QxxlcOcVideoPlayerService, "QxxlcOcVideoPlayerService")
