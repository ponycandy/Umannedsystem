#ifndef AVDECODER_H
#define AVDECODER_H

#include <QThread>
#include <QImage>
#include <QSharedPointer>
#include <defines/Vehicle1_data.h>
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
};

class AvDecoder : public QThread
{
    Q_OBJECT
public:
    AvDecoder(QObject *parent = 0);
    ~AvDecoder();

public:
    /*解码*/
    void startDecode(const QString &url);
    void stopDecode();
    void parse_time( IMAGE_DATA::_IMAGEDATA *structdata, const AVFrame *Frame);

signals:
    void signalDecodeFinished();

protected:
    virtual void run() Q_DECL_OVERRIDE;

signals:
    /*已解码的一帧图像（连接信号槽需要跨线程连接Qt::QueuedConnection）*/
    void signalFrameImage(QSharedPointer<QImage> frameImage);

private:
    enum AVDEBUG_TYPE {
        AVDEBUG_INFO = 0,
        AVDEBUG_WARINIG,
        AVDEBUG_ERROR,
    };

private:
    void init();
    void release();

    void decode();
    void decodeFrame(AVFormatContext *pAvFmtCtx, uint streamIndex);

    /*type = 0: [info] type = 1: [warning] type = 2: [error]*/
    void debugInfo(const QString &text, AVDEBUG_TYPE type = AVDEBUG_INFO);

private:
    QString m_videoPath;


    bool m_isThreadRunningState;
};

#endif // AVDECODER_H
