
#ifndef VEHICLE_1_VIDEOPLAYERSERVICE_H
#define VEHICLE_1_VIDEOPLAYERSERVICE_H

#include <QObject>
class vehicle_1_VideoPlayerservice
{
public:
    virtual ~vehicle_1_VideoPlayerservice(){}

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
    virtual QWidget *getVideoPlayerWindow(int type) = 0;



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
    virtual void setReconnectFrameImageDisplay(int type) = 0;

};
#define vehicle_1_VideoPlayerservice_iid "vehicle_1_VideoPlayerservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(vehicle_1_VideoPlayerservice,vehicle_1_VideoPlayerservice_iid  )
QT_END_NAMESPACE

#endif

