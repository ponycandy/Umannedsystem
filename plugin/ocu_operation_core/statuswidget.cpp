/******************************************************************************
* File:     statuswidget.cpp
* Author:   liziqiang
* Company:  xinchuanhui
* Time:     2021-07-02
******************************************************************************/
#include "statuswidget.h"
#include "event/OcuEventContants.h"

#include "batterywidget.h"

//! qt include
#include <QPainter>
#include <QStyleOption>

#include <QDateTime>

/**
 * @brief StatusWidget::StatusWidget
 * @param parent
 */
StatusWidget::StatusWidget(QWidget *parent)
    : QWidget(parent),
      m_logoWidget(nullptr),
      m_modeWidget(nullptr),
      m_statusWidget(nullptr),
      m_otherWidget(nullptr),
      m_statusAndOtherWidget(nullptr),
      m_exceptLogoWidget(nullptr),
      m_centralLayout(nullptr),
      m_logoLayout(nullptr),
      m_modeLayout(nullptr),
      m_statusLayout(nullptr),
      m_otherLayout(nullptr),
      m_statusAndOtherLayout(nullptr),
      m_exceptLogoLayout(nullptr),
      m_verticalSpacer(nullptr),
      timer(nullptr)
{
    setupUi();
    setupEvent();
    setupTimer();

    m_logoWidget->hide();
}

/**
 * @brief StatusWidget::~StatusWidget
 */
StatusWidget::~StatusWidget(void)
{
    releaseTimer();
    releaseMemberPointer();
}

/**
 * @brief StatusWidget::setupUi
 */
void StatusWidget::setupUi(void)
{
    this->setFixedHeight(100);

    m_logoWidget = new  QWidget(this);
    m_logoWidget->setFixedSize(530,100);
    m_logoWidget->setStyleSheet("background-image:url(:/img/logo.jpg)");
    m_logoWidget->setGeometry(QRect(0,0,530,100));
    m_logoWidget->show();

    m_statusWidget = new QWidget(this);
    m_statusWidget->setFixedSize(800,54);
    m_statusWidget->setGeometry(QRect(600,0,1500,54));
    m_statusWidget->show();

    m_otherWidget = new QWidget(this);
    m_otherWidget->setFixedSize(520,54);
    m_otherWidget->setGeometry(QRect(1400,0,1920,54));
    m_otherWidget->show();

    m_modeLayout = new QHBoxLayout;
    m_modeLayout->setContentsMargins(0, 0, 0, 0);
    m_modeLayout->setSpacing(0);

    m_modeWidget = new QWidget(this);
    m_modeWidget->setFixedSize(1020,54);
    m_modeWidget->setGeometry(QRect(900,45,1920,100));
    m_modeWidget->setLayout(m_modeLayout);
    m_modeWidget->show();

    setupOtherWidget();
}

/**
 * @brief StatusWidget::paintEvent
 */
void StatusWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


/**
 * @brief StatusWidget::setupOtherWidget
 */
void StatusWidget::setupOtherWidget(void)
{
    m_otherLayout = new  QHBoxLayout();
    m_otherLayout->setContentsMargins(0,0,0,0);
    m_otherLayout->setSpacing(10);


    m_otherWidget->setLayout(m_otherLayout);
    auto signalLayout = new QHBoxLayout();
    auto signaleWidget = new QWidget();
    signalLayout->setSpacing(0);
    signaleWidget->setLayout(signalLayout);


    m_otherLayout->addWidget(signaleWidget);//信号的widget

    QLabel *split_line = new QLabel;
    split_line->setPixmap(QPixmap(":/img/split_line.png"));
    //m_otherLayout->addWidget(split_line);

    auto electrictLayout = new QHBoxLayout();
    auto electrictWidget = new QWidget();
    electrictLayout->setSpacing(0);
    //electrictWidget->setLayout(electrictLayout);


    m_otherLayout->addWidget(electrictWidget);

    QLabel *split_line1 = new QLabel;
    split_line1->setPixmap(QPixmap(":/img/split_line.png"));
    //m_otherLayout->addWidget(split_line1);

    QString   timeStr = QDateTime::currentDateTime().toString("yyyy.MM.dd.hh.mm.ss");
    QStringList   timeStrList = timeStr.split(".");
    QString   currentTimeStr=QString("%1-%2-%3:%4:%5:%6").arg(timeStrList.at(0)).arg(timeStrList.at(1)).arg(timeStrList.at(2)).arg(timeStrList.at(3)).arg(timeStrList.at(4)).arg(timeStrList.at(5));

    m_timeIcon = new QLabel(currentTimeStr);

    //m_timeIcon->setMinimumWidth(200);
    m_otherLayout->addWidget(m_timeIcon);
    m_otherLayout->addStretch();

    m_otherLayout->setDirection(QBoxLayout::RightToLeft);

    //m_statusAndOtherLayout->addWidget(m_otherWidget);
}

/**
 * @brief StatusWidget::setupEvent
 */
void StatusWidget::setupEvent(void)
{
//    xtlEventAdmin* eventAdmin = OcuOperationCoreActivator::getService<xtlEventAdmin*>();
//    if(eventAdmin)
//    {

//    }
}

/**
 * @brief StatusWidget::releaseMemberPointer
 */
void StatusWidget::releaseMemberPointer(void)
{
    delete m_modeWidget;
    delete m_statusWidget;
    delete m_otherWidget;
    delete m_centralLayout;
    delete m_modeLayout;
    delete m_statusLayout;
    delete m_otherLayout;
    delete m_logoutIcon;
}

/**
 * @brief StatusWidget::setupTimer
 */
void StatusWidget::setupTimer(void)
{
    /*用于更新时间的定时器*/
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotUpDateTime()));
    timer->start(1000);
}

/**
 * @brief StatusWidget::releaseTimer
 */
void StatusWidget::releaseTimer(void)
{
    if(timer->isActive())
    {
        timer->stop();
    }
    delete timer;
}

/**
 * @brief StatusWidget::setupLogo
 */
void StatusWidget::setupLogo(void)
{
    m_logoLayout = new QHBoxLayout;
    m_logoLayout->setContentsMargins(0, 0, 0, 0);

    m_logoWidget = new QWidget;
    m_logoWidget->setMaximumWidth(502);
    m_logoWidget->resize(502,75);
    m_logoWidget->move(25, 7);
    m_logoWidget->setLayout(m_logoLayout);

    QLabel *logo = new QLabel;
    logo->resize(502, 75);
    logo->setPixmap(QPixmap(":/img/logo.jpg"));
    logo->setScaledContents(true);
    m_logoLayout->addWidget(logo);

    m_logoLayout->addStretch();
    m_centralLayout->addWidget(m_logoWidget);
}

/**
 * @brief StatusWidget::setExceptLogoWidget
 */
void StatusWidget::setExceptLogoWidget()
{
    m_statusAndOtherWidget = new QWidget;
    m_statusAndOtherWidget->setLayout(m_statusAndOtherLayout);

    m_exceptLogoLayout->addStretch();

    m_statusAndOtherLayout->addStretch();

    m_statusAndOtherLayout->addStretch();

    setupOtherWidget();

    m_exceptLogoLayout->addWidget(m_statusAndOtherWidget, 0, Qt::AlignTop | Qt::AlignLeft);

    m_exceptLogoLayout->addStretch();

    m_exceptLogoWidget->setLayout(m_exceptLogoLayout);
}

/**
 * @brief StatusWidget::slotCloseBtnClicked
 * @param state
 */
void StatusWidget::slotCloseBtnClicked(bool state)
{
    Q_UNUSED(state)
    emit sigCloseBtnClicked();
}

/**
 * @brief StatusWidget::slotLogoutBtnClicked
 * @param state
 */
void StatusWidget::slotLogoutBtnClicked(bool state)
{
    Q_UNUSED(state)
    emit sigLogoutBtnClicked();
}

/**
 * @brief StatusWidget::slotMinimumBtnClicked
 * @param state
 */
void StatusWidget::slotMinimumBtnClicked(bool state)
{
    Q_UNUSED(state)
    emit sigMinimumBtnClicked();
}

/**
 * @brief StatusWidget::slotMaxmumBtnClicked
 * @param state
 */
void StatusWidget::slotMaxmumBtnClicked(bool state)
{
    Q_UNUSED(state)
    emit sigMaxmumBtnClicked();
}

/**
 * @brief StatusWidget::slotCrawlerCarChassisInfo
 * @param event
 */
void StatusWidget::slotCrawlerCarChassisInfo(const XTLevent &event)
{

}

/**
 * @brief StatusWidget::slotMiddleCarChassisInfo
 * @param event
 */
void StatusWidget::slotMiddleCarChassisInfo(const XTLevent &event)
{

}

/**
 * @brief StatusWidget::slotCrawlerCarSpeedLimited
 * @param event
 */
void StatusWidget::slotCrawlerCarSpeedLimited(const XTLevent &event)
{

}

/**
 * @brief StatusWidget::slotMiddleCarSpeedLimited
 * @param event
 */
void StatusWidget::slotMiddleCarSpeedLimited(const XTLevent &event)
{

}

/**
 * @brief StatusWidget::slotFireControLinkState
 * @param event
 */
void StatusWidget::slotFireControLinkState(const XTLevent &event)
{

}

void StatusWidget::EventTriggeres(XTLevent event)
{

}

/**
 * @brief StatusWidget::slotUpDateTime
 */
void StatusWidget::slotUpDateTime()
{
    QString   timeStr = QDateTime::currentDateTime().toString("yyyy.MM.dd.hh.mm.ss");
    QStringList   timeStrList = timeStr.split(".");
    QString   currentTimeStr=QString("%1-%2-%3:%4:%5:%6").arg(timeStrList.at(0)).arg(timeStrList.at(1))\
            .arg(timeStrList.at(2)).arg(timeStrList.at(3)).arg(timeStrList.at(4)).arg(timeStrList.at(5));
    m_timeIcon->setText(currentTimeStr);
}


/**
 * @brief StatusWidget::changeView
 * @param viewKind
 */
void StatusWidget::changeView(UcsDefines::UcsViewKind viewKind)
{
   if(viewKind == UcsDefines::UCS_VIEW_KIND_CAR_MANAGER)
   {
       m_logoWidget->show();
   }
   else{
       m_logoWidget->hide();
   }

}


