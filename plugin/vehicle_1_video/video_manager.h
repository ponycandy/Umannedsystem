#ifndef VIDEO_MANAGER_H
#define VIDEO_MANAGER_H

#include "avplayer/avplayer.h"
#include "service/vehicle_1_VideoPlayerservice.h"
#include "service/vehicle_1_coreservice.h"
#include "video_display_widget.h"
#include "vehicle_1_videoplayerview.h"
class video_manager:public QObject,public vehicle_1_VideoPlayerservice
{
    Q_OBJECT
public:
    video_manager(QObject *parent = nullptr);
    AvPlayer *m_player;
    vehicle_1_coreservice *m_service;
    video_display_widget *m_display;
    Vehicle_1_VideoPlayerView *m_player_view;
    QWidget * getVideoPlayerWindow() override;
    QWidget * getVideoPlayerWindow(int type) override;
    void releaseVideoPlayerWindow() override;
    void setReconnectFrameImageDisplay() override;
    void setReconnectFrameImageDisplay(int type) override;
    void setVideoSceneDisplayMode(quint8 mode = 0) override;


};

#endif // VIDEO_MANAGER_H
