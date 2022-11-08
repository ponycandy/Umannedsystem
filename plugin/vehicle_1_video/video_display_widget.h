#ifndef VIDEO_DISPLAY_WIDGET_H
#define VIDEO_DISPLAY_WIDGET_H

#include <QWidget>
#include <avplayer/avplayer.h>
namespace Ui {
class video_display_widget;
}

class video_display_widget : public QWidget
{
    Q_OBJECT

public:
    explicit video_display_widget(QWidget *parent = nullptr);
    ~video_display_widget();
    void setConnectFrameImageDisplay(int vehicleType);

    void setReconnectFrameImageDisplay(int vehicleType);


    void setReconnectFrameImageDisplay();

    enum UcsVideoSceneModeEnum {
        VIDEOSCENE_FULLSCENE = 0,
        VIDEOSCENE_HALFSCENE,
        VIDEOSCENE_MINIMUM,
    };


private:
    /**
     * @brief init
     */
    void init();

    /**
     * @brief initModule
     */
    void initModule();

    /**
     * @brief initUi
     */
    void initUi();

    /**
     * @brief initConnector
     */
    void initConnector();


    /**
     * @brief release
     */
    void release();

    /**
     * @brief releaseModule
     */
    void releaseModule();

    /**
     * @brief releaseConnector
     */
    void releaseConnector();

    /**
     * @brief routeSwitchRequest
     * @param route
     */
    void routeSwitchRequest(int route);

    /**
     * @brief createDefaultFrameImageDisplay
     */
    void createDefaultFrameImageDisplay();

    /**
     * @brief createReconnectFrameImageDisplay
     */
    void createReconnectFrameImageDisplay();


private slots:
    /**
     * @brief slotOnComboBoxCurrentIndexChanged
     * @param index
     */
    void slotOnComboBoxCurrentIndexChanged(int index);

    /**
     * @brief slotOnConnectBtnClicked
     */
    void slotOnConnectBtnClicked();

    /**
     * @brief slotOnFrameImageNotify 视频一帧显示
     * @param spFrameImage
     */
    void slotOnFrameImageNotify(IMAGE_DATA::_IMAGEDATA spFrameImage);

    /**
     * @brief slotOnTryReconnect 尝试重连
     */
    void slotOnTryReconnect();

    /**
     * @brief slotOnVideoPlayFinished 视频播放结束
     */
    void slotOnVideoPlayFinished();

    /**
     * @brief slotOnRecvFrameImageTimeout 获取视频帧图像超时
     */
    void slotOnRecvFrameImageTimeout();

    /**
     * @brief slotOnNestModeVideoTrimCheckChanged 画中画模式视频裁切
     * @param checked
     */
    void slotOnNestModeVideoTrimCheckChanged(bool checked);

    /**
     * @brief slotDoubleSpinBox
     * @param value
     */
    void slotDoubleSpinBox(int value);

private:


    /**
     * @brief m_pAvPlayer
     */
    AvPlayer *m_pAvPlayer;

    /**
     * @brief m_pRecvFrameImageTimer
     */
    QTimer *m_pRecvFrameImageTimer;

    /**
     * @brief m_rtpSdpPath
     */
    QString m_rtpSdpPath;

    /**
     * @brief m_sceneMode
     */
    UcsVideoSceneModeEnum m_sceneMode;

    /**
     * @brief m_isOverlay
     */
    bool  m_isOverlay;

    /**
     * @brief m_SpinboxValue
     */
    int   m_SpinboxValue;

    /**
     * @brief m_DoubleSpinBox
     */
    double m_DoubleSpinBox;

private:
    Ui::video_display_widget *ui;
};

#endif // VIDEO_DISPLAY_WIDGET_H
