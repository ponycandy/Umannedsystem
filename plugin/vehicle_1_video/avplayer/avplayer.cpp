#include "avplayer.h"
#include "avdecoder.h"

AvPlayer::AvPlayer(QObject *parent)
    : QObject(parent),
      m_playState(PLAYSTATE_INVALID),
      m_pAvDecoder(NULL)
{
    init();
}

AvPlayer::~AvPlayer()
{
    release();
}

void AvPlayer::play(const QString &url)
{
    m_curVideoUrl = url;
    m_pAvDecoder->startDecode(url);
    m_playState = PLAYSTATE_PLAYING;
}

void AvPlayer::stop()
{
    m_pAvDecoder->stopDecode();
    m_playState = PLAYSTATE_STOPPED;
}

void AvPlayer::slotOnDecodeFinished()
{
    switch (m_playState) {
    case PLAYSTATE_PLAYING:
        {
            /*尝试重连*/
            emit signalTryReconnect();
            m_pAvDecoder->startDecode(m_curVideoUrl);
        }
        break;
    case PLAYSTATE_STOPPED:
        {
            /*视频结束*/
            emit signalVideoPlayFinished();
        }
        break;
    default:
        break;
    }
}

void AvPlayer::init()
{
    m_pAvDecoder = new AvDecoder(this);
    initConnector();
}

void AvPlayer::initConnector()
{
    qRegisterMetaType<QSharedPointer<QImage>>("QSharedPointer<QImage>");
    connect(m_pAvDecoder, SIGNAL(signalFrameImage(QSharedPointer<QImage>)),
            this, SIGNAL(signalFrameImage(QSharedPointer<QImage>)), Qt::QueuedConnection);
    connect(m_pAvDecoder, SIGNAL(signalDecodeFinished()), this, SLOT(slotOnDecodeFinished()));

    connect(m_pAvDecoder,&QThread::finished,m_pAvDecoder,&AvDecoder::deleteLater);
}

void AvPlayer::release()
{
    releaseConnector();
    m_pAvDecoder->stopDecode();
    //m_pAvDecoder->deleteLater();
    m_pAvDecoder->wait();
}

void AvPlayer::releaseConnector()
{
    disconnect(m_pAvDecoder, SIGNAL(signalFrameImage(QSharedPointer<QImage>)),
               this, SIGNAL(signalFrameImage(QSharedPointer<QImage>)));
    disconnect(m_pAvDecoder, SIGNAL(signalDecodeFinished()), this, SLOT(slotOnDecodeFinished()));
}
