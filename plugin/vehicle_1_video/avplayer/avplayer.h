#ifndef AVPLAYER_H
#define AVPLAYER_H

#include <QObject>
#include <QSharedPointer>
#include <QImage>

class AvDecoder;

class AvPlayer : public QObject
{
    Q_OBJECT
public:
    AvPlayer(QObject *parent = 0);
    ~AvPlayer();

    void play(const QString &url);
    void stop();

signals:
    /*尝试重连*/
    void signalTryReconnect();
    /*视频播放结束*/
    void signalVideoPlayFinished();
    /*一帧图像*/
    void signalFrameImage(QSharedPointer<QImage> spFrameImage);

private slots:
    void slotOnDecodeFinished();

private:
    void init();
    void initConnector();
    void release();
    void releaseConnector();

private:
    AvDecoder *m_pAvDecoder;
    QString m_curVideoUrl;

    enum AvPlayState {
        PLAYSTATE_INVALID = 0,
        PLAYSTATE_PLAYING,
        PLAYSTATE_STOPPED,
    } m_playState;
};

#endif // AVPLAYER_H
