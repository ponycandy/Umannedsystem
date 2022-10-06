#include "avdecoder.h"
#include <QTimer>
#include <QMutex>
#include <QFile>
#include <QDebug>
static bool g_decoding = false;
static QMutex g_mutex;
#define RTP
AvDecoder::AvDecoder(QObject *parent)
    : QThread(parent)
{
    init();

    m_isThreadRunningState = false;
}

AvDecoder::~AvDecoder()
{
    release();
}

void AvDecoder::startDecode(const QString &url)
{
    m_videoPath = url;

    stopDecode();

    m_isThreadRunningState = true;

    g_decoding = true;
    this->start();
}

void AvDecoder::stopDecode()
{
    if (this->isRunning() && g_decoding) {
        this->requestInterruption();
        this->quit();
        g_decoding = false;
        this->wait(1000);
    }
}

void AvDecoder::run()
{
    decode();
}

void AvDecoder::init()
{
    av_register_all();
    avformat_network_init();
}

void AvDecoder::release()
{
    stopDecode();
}

void AvDecoder::decode()
{
    AVFormatContext *pAvFmtCtx = avformat_alloc_context();
#ifdef RTP
    const QString sdpPath = m_videoPath;
    QFile file(sdpPath);
    if (!file.open(QIODevice::ReadWrite)) {
        return;
    }
    QByteArray ba = file.readAll();
    file.close();
    AVIOContext * avio = avio_alloc_context((unsigned char *)ba.data(), ba.size(), 0, (void*)NULL, NULL, NULL, NULL);
    pAvFmtCtx->pb = avio;
    pAvFmtCtx->iformat = av_find_input_format("sdp");
    AVDictionary *option = NULL;

    /*timeout:设置超时时间，否则阻塞在av_read_frame中*/
    av_dict_set(&option, "timeout", "100000", 0);

    /*reorder_queue_size:为处理重新排序的包而缓冲的包数，主要用于处理视频源重新推流时接收端因未收到完整的最后一帧而阻塞的情况*/
    av_dict_set(&option, "reorder_queue_size", "0", 0);

    if (avformat_open_input(&pAvFmtCtx, "nothing", NULL, &option/*NULL*/) < 0) {
        debugInfo(QString("open video(%1) failed !").arg(m_videoPath));

        emit signalDecodeFinished();

        return;
    }
#else
    if (avformat_open_input(&pAvFmtCtx, m_videoPath.toStdString().data(), NULL, /*&option*/NULL) < 0) {
        debugInfo(QString("open video(%1) failed !").arg(m_videoPath));

        emit signalDecodeFinished();

        return;
    }
#endif
    /*遍历流*/
    for (uint i = 0; i < pAvFmtCtx->nb_streams; i++) {
        if (pAvFmtCtx->streams[i]->codecpar->codec_type == AVMediaType::AVMEDIA_TYPE_VIDEO) {
            decodeFrame(pAvFmtCtx, i);
            break;
        }
    }

    /*释放上下文*/
    avformat_close_input(&pAvFmtCtx);
    avformat_free_context(pAvFmtCtx);
}

void AvDecoder::decodeFrame(AVFormatContext *pAvFmtCtx, uint streamIndex)
{
    do {
        AVStream *pAvStream = pAvFmtCtx->streams[streamIndex];
        AVCodecContext *pAvCodecCtx = pAvStream->codec;
        AVCodec *pAvCodec = avcodec_find_decoder(pAvCodecCtx->codec_id);
        if (pAvCodec == NULL) {
            debugInfo(QString("cannot find video decoder !!!"), AVDEBUG_ERROR);
            break;
        }
        if (avcodec_open2(pAvCodecCtx, pAvCodec, NULL) < 0) {
            debugInfo(QString("open video decoder failed !!!"), AVDEBUG_ERROR);
            break;
        }
        AVPacket *pAvPkt = av_packet_alloc();
        AVFrame *pAvFrame = av_frame_alloc();
        av_init_packet(pAvPkt);

        while (/*av_read_frame(pAvFmtCtx, pAvPkt) >= 0*/1) {

            if(QThread::currentThread()->isInterruptionRequested())
            {
                break;
            }


            if (av_read_frame(pAvFmtCtx, pAvPkt) < 0) {
//                qDebug() << "&&&&&&&&&&&&&&&&&&&&&&";
                continue;
            }
            if (!g_decoding) {
                break;
            }
            /*验证流index*/
            if (pAvPkt->stream_index != streamIndex) {
                continue;
            }
            /*将未解码的packet发送至上下文*/
            if (avcodec_send_packet(pAvCodecCtx, pAvPkt) != 0) {
                continue;
            }
            /*接收解码后的frame*/
            if (avcodec_receive_frame(pAvCodecCtx, pAvFrame) != 0) {
                continue;
            }
            /*用于存储RGB图像*/
            AVFrame *pAvFrameRGB = av_frame_alloc();
            /*获取图像大小*/
            int picSize = avpicture_get_size(AV_PIX_FMT_RGB24, pAvCodecCtx->width, pAvCodecCtx->height);
            uint8_t *buf = (uint8_t *)av_malloc(picSize);
            /*填充RGB图像*/
            avpicture_fill((AVPicture *)pAvFrameRGB, buf, AV_PIX_FMT_RGB24, pAvCodecCtx->width, pAvCodecCtx->height);
            /*转换图像格式，将解压出来的YUV转换为RGB24*/
            struct SwsContext *pSwsCtx = sws_getContext(pAvCodecCtx->width, pAvCodecCtx->height, pAvCodecCtx->pix_fmt,
                                                        pAvCodecCtx->width, pAvCodecCtx->height, AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);
            sws_scale(pSwsCtx, (const uint8_t * const *)pAvFrame->data, pAvFrame->linesize, 0,
                      pAvCodecCtx->height, pAvFrameRGB->data, pAvFrameRGB->linesize);

            /*构造图像，将图像放进缓存队列*/
            QSharedPointer<QImage> spFrameImage;
            spFrameImage = QSharedPointer<QImage>(new QImage(pAvCodecCtx->width, pAvCodecCtx->height, QImage::Format_RGB888));
            memcpy((void *)spFrameImage->bits(), (void *)pAvFrameRGB->data[0], picSize);

            /*触发信号抛出一帧图像*/
            emit signalFrameImage(spFrameImage);

            /*av_read_frame导致内存泄露，每读完一个packet，必须调用av_packet_unref函数进行内存释放，否则会导致内存释泄漏*/
            av_packet_unref(pAvPkt);
            av_frame_free(&pAvFrameRGB);
            av_free(buf);
            sws_freeContext(pSwsCtx);
        }
        av_frame_free(&pAvFrame);
        av_packet_free(&pAvPkt);

    } while (0);

//    emit signalDecodeFinished();

    return;
}

void AvDecoder::debugInfo(const QString &text, AVDEBUG_TYPE type)
{
    QString debugText = QString("[AVDECODER]");
    switch (type) {
    case 0:
        debugText.append("[INFO]: ");
        break;
    case 1:
        debugText.append("[WARNING]: ");
        break;
    case 2:
        debugText.append("[ERROR]: ");
        break;
    default:
        break;
    }

    qDebug() << debugText.append(text);
}
