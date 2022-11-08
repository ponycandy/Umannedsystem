#include "video_manager.h"
#include "vehicle_1_videoActivator.h"
video_manager::video_manager(QObject *parent) : QObject(parent),m_display(nullptr)
{
    m_display=new video_display_widget;
    vehicle_1_videoActivator::registerservice(this,"vehicle_1_VideoPlayerservice");
    m_service=vehicle_1_videoActivator::getService<vehicle_1_coreservice>("vehicle_1_coreservice");
    m_service->addView(UcsDefines::VEHICLE1_VIDEO,m_display);
}

QWidget *video_manager::getVideoPlayerWindow()
{

    return m_display;

}

QWidget *video_manager::getVideoPlayerWindow(int type)
{

}

void video_manager::releaseVideoPlayerWindow()
{

}

void video_manager::setReconnectFrameImageDisplay()
{

}

void video_manager::setReconnectFrameImageDisplay(int type)
{

}

void video_manager::setVideoSceneDisplayMode(quint8 mode)
{

}
