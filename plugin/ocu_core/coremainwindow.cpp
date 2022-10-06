#include "coremainwindow.h"
#include "ocu_coreActivator.h"
coremainwindow::coremainwindow(QWidget *parent) : QWidget(parent)
    , m_centralWidget(NULL)
    , m_viewManager(NULL)
    , m_CurrentViewKind()
    , m_CurrentCarIndex()
{
    setupUi();

    ocu_coreActivator::registerservice(this,"Coreservice");
    showFullScreen();

    this->setGeometry(0,0,1920,1080);
}

/**
 * @brief CoreMainWindow::~CoreMainWindow
 */
coremainwindow::~coremainwindow()
{
    releaseUi();
}

/**
 * @brief CoreMainWindow::addView
 * @param viewKind
 * @param view
 */
void coremainwindow::addView(UcsDefines::UcsViewKind viewKind, QWidget *view)
{
    if (m_viewManager)
    {
        m_viewManager->addView(viewKind, view);
    }
}

/**
 * @brief CoreMainWindow::changeView
 * @param viewKind
 */
void coremainwindow::changeView(UcsDefines::UcsViewKind viewKind)
{
    m_CurrentViewKind = viewKind;

    if (m_viewManager)
    {
        m_viewManager->changeView(viewKind);
    }
}

/**
 * @brief CoreMainWindow::getCurrentView
 * @return
 */
UcsDefines::UcsViewKind coremainwindow::getCurrentView()
{
    return m_CurrentViewKind;
}

void coremainwindow::setCurCarIndex(UcsDefines::UcsViewIndex index)
{
    m_CurrentCarIndex = index;
}

UcsDefines::UcsViewIndex coremainwindow::getCurCarIndex()
{
    return  m_CurrentCarIndex;
}


/**
 * @brief setWdigetSwitch
 * 0：标识视频界面是第一个屏，主控界面为第二个屏
 * 1：标识视频界面是第二个屏，主控界面为第一个屏
 */
void coremainwindow::setWdigetSwitch(int type)
{
//    if(type == 0)
//    {
//        this->setGeometry(0,0,1920,1080);
//    }
//    else if(type == 1){
//        this->setGeometry(0,0,1920,1080);
//    }
}

/**
 * @brief CoreMainWindow::setupUi
 */
void coremainwindow::setupUi()
{

    //! 设置透明属性，为了显示视频
   // setAttribute(Qt::WA_TranslucentBackground, true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    this->setLayout(mainLayout);

    m_centralWidget = new QWidget;
    mainLayout->addWidget(m_centralWidget);

    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(0);
    centralLayout->setMargin(0);

    m_viewManager = new CoreViewManager;
    centralLayout->addWidget(m_viewManager);

    m_centralWidget->setLayout(centralLayout);
}

/**
 * @brief CoreMainWindow::releaseUi
 */
void coremainwindow::releaseUi()
{
    if(m_centralWidget)
    {
        delete m_centralWidget;
        m_centralWidget = NULL;
    }

//    if(m_framelessHelper)
//    {
//        delete m_framelessHelper;
//        m_framelessHelper = NULL;
//    }

    if(m_viewManager)
    {
        delete m_viewManager;
        m_viewManager = NULL;
    }
}

/**
 * @brief CoreMainWindow::slotCloseBtnClicked
 */
void coremainwindow::slotCloseBtnClicked()
{
    QCloseEvent *event = new QCloseEvent;
    closeEvent(event);
}

/**
 * @brief CoreMainWindow::closeEvent
 * @param event
 */
void coremainwindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    QApplication::exit();
}

/**
 * @brief CoreMainWindow::resizeEvent
 * @param event
 */
void coremainwindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
}

/**
 * @brief CoreMainWindow::showEvent
 * @param event
 */
void coremainwindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
}

/**
 * @brief CoreMainWindow::paintEvent
 * @param event
 */
void coremainwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0));
    Q_UNUSED(event)
}
