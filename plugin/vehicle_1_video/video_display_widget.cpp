#include "video_display_widget.h"
#include "ui_video_display_widget.h"
#include <QTimer>
#include <QDebug>
#define RECV_FRAME_IMAGE_TIMEOUT 2000
#define VIDEO_CONTROL_DISPLAY
video_display_widget::video_display_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video_display_widget)
{
    ui->setupUi(this);
    init();

    m_isOverlay = true;

    m_SpinboxValue = 10;

    float enlargementFactor = 1 + 0.2 * m_SpinboxValue;

}

video_display_widget::~video_display_widget()
{
    delete ui;
}

void video_display_widget::init()
{
    initModule();
    initUi();
    initConnector();
}

void video_display_widget::initModule()
{
    m_pAvPlayer = new AvPlayer(this);
    m_pRecvFrameImageTimer = new QTimer(this);
    m_pRecvFrameImageTimer->setInterval(RECV_FRAME_IMAGE_TIMEOUT);
}

void video_display_widget::initUi()
{
#ifndef VIDEO_CONTROL_DISPLAY
    ui->comboBox_route->setVisible(false);
    ui->pushButton_connect->setVisible(false);
    QLayout *layout = ui->frame_mainframe->layout();
    if (layout != NULL) {
        layout->setMargin(0);
    }
#endif

    ui->checkBox_trim->setVisible(true);
   // createReconnectFrameImageDisplay();

}

void video_display_widget::initConnector()
{
    connect(ui->comboBox_route, SIGNAL(currentIndexChanged(int)), this, SLOT(slotOnComboBoxCurrentIndexChanged(int)));
    connect(ui->pushButton_connect, SIGNAL(clicked()), this, SLOT(slotOnConnectBtnClicked()));

    qRegisterMetaType<QSharedPointer<QImage>>("QSharedPointer<QImage>");
    qRegisterMetaType<IMAGE_DATA::_IMAGEDATA>("IMAGE_DATA::_IMAGEDATA");

    connect(m_pAvPlayer, SIGNAL(signalFrameImage(IMAGE_DATA::_IMAGEDATA)), this, SLOT(slotOnFrameImageNotify(IMAGE_DATA::_IMAGEDATA)), Qt::QueuedConnection);
    connect(m_pAvPlayer, SIGNAL(signalTryReconnect()), this, SLOT(slotOnTryReconnect()));
    connect(m_pAvPlayer, SIGNAL(signalVideoPlayFinished()), this, SLOT(slotOnVideoPlayFinished()));
    connect(m_pRecvFrameImageTimer, SIGNAL(timeout()), this, SLOT(slotOnRecvFrameImageTimeout()));
    connect(ui->checkBox_trim, SIGNAL(toggled(bool)), this, SLOT(slotOnNestModeVideoTrimCheckChanged(bool)));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotDoubleSpinBox(int)));

}

void video_display_widget::routeSwitchRequest(int route)
{

}

void video_display_widget::createReconnectFrameImageDisplay()
{
    QSharedPointer<QImage> spImage = QSharedPointer<QImage>(new QImage(":/img/titan.PNG"));
    ui->widget_video->setImage(spImage.data());//set the background image of the display window


}

void video_display_widget::slotOnComboBoxCurrentIndexChanged(int index)
{
    if(index < 0)
        return;

    routeSwitchRequest(index);

}

void video_display_widget::slotOnConnectBtnClicked()
{
    Q_ASSERT(m_pAvPlayer);

    QString btnText = ui->pushButton_connect->text();
    if (btnText == QStringLiteral("start")) {
        ui->pushButton_connect->setText(QStringLiteral("stop"));

        QString rtmp_path=ui->lineEdit->text();
        qDebug()<<rtmp_path;
        m_pAvPlayer->play(rtmp_path);
        m_pRecvFrameImageTimer->start();

        /** 下发一条当前的线路*/
        routeSwitchRequest(ui->comboBox_route->currentIndex());
    }
    else if (btnText == QStringLiteral("stop")) {
        ui->pushButton_connect->setText(QStringLiteral("start"));

        m_pAvPlayer->stop();
        m_pRecvFrameImageTimer->stop();
        createReconnectFrameImageDisplay();
    }
    else {

    }

}

void video_display_widget::slotOnFrameImageNotify(IMAGE_DATA::_IMAGEDATA spFrameImage)
{
    ui->widget_video->setImage(spFrameImage.sp_t_image.data());
}

void video_display_widget::slotOnTryReconnect()
{
    createReconnectFrameImageDisplay();

}

void video_display_widget::slotOnVideoPlayFinished()
{
    createReconnectFrameImageDisplay();
    m_pRecvFrameImageTimer->stop();

}

void video_display_widget::slotOnRecvFrameImageTimeout()
{
    createReconnectFrameImageDisplay();
}

void video_display_widget::slotOnNestModeVideoTrimCheckChanged(bool checked)
{
    if(checked)
    {
       m_isOverlay = true;
    }else{
       m_isOverlay = false;
    }
}

void video_display_widget::slotDoubleSpinBox(int value)
{
    m_SpinboxValue = value;

    float enlargementFactor = 1 + 0.2 * m_SpinboxValue;

    ui->enlargementFactor->setText(QString::number(enlargementFactor));
}
