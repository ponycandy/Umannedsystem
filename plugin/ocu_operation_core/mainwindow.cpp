//! widget include
#include "mainwindow.h"
#include "titlewidget.h"
#include "statuswidget.h"
#include "menumanager.h"
#include "viewmanager.h"
#include "ocu_operation_coreActivator.h"
//! qt include
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QPainter>

//! soy include
//#include <soyFramelessHelper.h>
//#include <soyContextManager.h>
//#include <soyUtils/soyStyleSheetUtil.h>
//#include <soyUtils/soyWidgetUtil.h>
//#include <soyUtils/soyTranslatorUtil.h>

//! services include
#include "service/Coreservice.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_centralWidget(NULL)
    , m_titleWidget(NULL)
    , m_statusWidget(NULL)
    , m_menuManager(NULL)
    , m_viewManager(NULL)
    , m_isWidgetShowState(false)
    , m_CurrentViewKind(UcsDefines::UcsViewKind::UCS_VIEW_KIND_NONE)
{
//    new soyContextManager(this, this);
    setupUi();
//    m_framelessHelper->activateOn(this);
//    m_framelessHelper->setWidgetMovable(false);
//    m_framelessHelper->setWidgetResizable(false);
//    m_framelessHelper->useRubberBandOnMove(false);
//    m_framelessHelper->useRubberBandOnResize(false);

    //setWindowIcon(QPixmap(":/img/car"));
    ocu_operation_coreActivator::registerservice(this,"OperationCoreServices");
    m_isWidgetShowState = false;

    //! showFullScreen();

    setFixedSize(1920,1080);

    Coreservice* coreService = ocu_operation_coreActivator::getService<Coreservice>("Coreservice");
    if(coreService)
    {
        coreService->addView(UcsDefines::UcsViewKind::UCS_VIEW_KIND_MIANWIDOW_CORE,this);
    }



    this->setObjectName("OcuOperationMainWidget");
}

MainWindow::~MainWindow()
{
    releaseUi();
}

/**
 * @brief MainWindow::setTitleHide
 * @param isHide
 */
void MainWindow::setTitleHide(bool isHide)
{
    isHide ? m_titleWidget->hide() : m_titleWidget->show();
}

/**
 * @brief MainWindow::addView
 * @param viewKind
 * @param view
 */
void MainWindow::addView(UcsDefines::UcsViewKind viewKind, QWidget *view)
{
    if (m_viewManager)
    {
        m_viewManager->addView(viewKind, view);
    }
}

/**
 * @brief MainWindow::changeView
 * @param viewKind
 */
void MainWindow::changeView(UcsDefines::UcsViewKind viewKind)
{
    m_CurrentViewKind = viewKind;

    if (m_viewManager)
    {
        m_viewManager->changeView(viewKind);
    }

    if (m_menuManager)
    {
        m_menuManager->viewChanged(viewKind);
    }

    if(m_statusWidget)
    {
        m_statusWidget->changeView(viewKind);
    }
}

/**
 * @brief MainWindow::getCurrentView
 * @return
 */
UcsDefines::UcsViewKind MainWindow::getCurrentView()
{
    return m_CurrentViewKind;
}

/**
 * @brief MainWindow::changeMenu
 * @param oldMenu
 * @param newMenu
 * @param text
 */
void MainWindow::changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text)
{
    if (m_menuManager)
    {
        m_menuManager->changeMenuButton(oldMenu, newMenu, text);
    }
}

/**
 * @brief MainWindow::changeMenu
 * @param num
 * @param newMenu
 * @param text
 */
void MainWindow::changeMenu(const int num,const QString &newMenu, const QString &text)
{
    if (m_menuManager)
    {
        m_menuManager->changeMenuButton(num,newMenu,text);
    }
}

/**
 * @brief MainWindow::setupUi
 */
void MainWindow::setupUi()
{
    //! 设置透明属性，为了显示视频
    //setAttribute(Qt::WA_TranslucentBackground, true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);

    //! 状态栏
//    m_statusWidget = new StatusWidget;
//    mainLayout->addWidget(m_statusWidget);

    //! 内容页
    m_centralWidget = new QWidget;
    m_centralWidget->setFixedSize(1920,980);
    mainLayout->addWidget(m_centralWidget);

    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(0);
    centralLayout->setMargin(0);

    //! 菜单栏
    m_menuManager = new MenuManager;
    m_menuManager->install(centralLayout);

    m_viewManager = new ViewManager;

    if (centralLayout->count() >= 2)
    {
        centralLayout->insertWidget(1, m_viewManager);
    }

    m_centralWidget->setLayout(centralLayout);
}

void MainWindow::releaseUi()
{
    if(m_centralWidget)
    {
        delete  m_centralWidget;
        m_centralWidget = NULL;
    }

    if(m_framelessHelper)
    {
        delete  m_framelessHelper;
        m_framelessHelper = NULL;
    }

    if(m_titleWidget)
    {
        delete m_titleWidget;
        m_titleWidget = NULL;
    }

    if(m_statusWidget)
    {
        delete  m_statusWidget;
        m_statusWidget = NULL;
    }

   if(m_menuManager)
   {
       delete m_menuManager;
       m_menuManager = NULL;
   }

   if(m_viewManager)
   {
       delete  m_viewManager;
       m_viewManager = NULL;
   }
}

/**
 * @brief MainWindow::slotCloseBtnClicked
 */
void MainWindow::slotCloseBtnClicked()
{
    QCloseEvent *event = new QCloseEvent;
    closeEvent(event);
}

/**
 * @brief MainWindow::slotMiniBtnClicked
 */
void MainWindow::slotMiniBtnClicked()
{
    this->showMinimized();
    m_isWidgetShowState = true;
}

/**
 * @brief MainWindow::slotMaxBtnClicked
 */
void MainWindow::slotMaxBtnClicked()
{
    this->showMaximized();
    m_isWidgetShowState = false;
}

/**
 * @brief MainWindow::closeEvent
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    QApplication::exit();
}

/**
 * @brief MainWindow::resizeEvent
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
}

/**
 * @brief MainWindow::showEvent
 * @param event
 */
void MainWindow::showEvent(QShowEvent *event)
{
    if(!this->m_isWidgetShowState){
        showFullScreen();
        this->m_isWidgetShowState = true;
    }
    else
    {
        showMinimized();
        this->m_isWidgetShowState = false;
    }

    Q_UNUSED(event)
}

/**
 * @brief MainWindow::setConnectStatus
 * @param connectStatus
 */
void MainWindow::setConnectStatus(bool connectStatus)
{
    //m_statusWidget->switchConnectStatus(connectStatus);
}

/**
 * @brief MainWindow::setControlStatus
 * @param controlStatus
 */
void MainWindow::setControlStatus(bool controlStatus)
{

    //m_statusWidget->switchControlStatus(controlStatus);
}

/**
 * @brief MainWindow::paintEvent
 * @param event
 */
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0));  //QColor最后一个参数80代表背景的透明度
    Q_UNUSED(event)
}

