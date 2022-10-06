//! widget include
#include "titlewidget.h"
#include "mainwindow.h"


//! qt include
#include <QMouseEvent>
#include <QHBoxLayout>

/**
 * @brief TitleWidget::TitleWidget
 * @param mainWindow
 * @param parent
 */
TitleWidget::TitleWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget(parent)
    , m_mainWindow(mainWindow)
    , m_pressPoint()
    , m_movePoint()
    , m_isMove(false)
    , m_mousePressed(false)
{
    setupUi();
}

/**
 * @brief TitleWidget::~TitleWidget
 */
TitleWidget::~TitleWidget()
{
    releaseUi();
}

/**
 * @brief TitleWidget::mousePressEvent
 * @param event
 */
void TitleWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->y() < 10 || event->x() < 10
                || rect().width()- event->x() < 10)
        {
            m_mousePressed = false;
            event->ignore();
            return;
        }

        m_mousePressed = true;
        m_pressPoint = event->globalPos();
    }

    event->ignore();
}

/**
 * @brief TitleWidget::mouseReleaseEvent
 * @param event
 */
void TitleWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_mousePressed = false;
    }

    event->ignore();
}

/**
 * @brief TitleWidget::mouseMoveEvent
 * @param event
 */
void TitleWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed)
    {
        m_movePoint = event->globalPos();

        // Only movable in none-maximize mode.
        if (!m_mainWindow->isMaximized()){
            m_mainWindow->move(m_mainWindow->pos() + m_movePoint - m_pressPoint);
        }

        m_pressPoint = m_movePoint;
    }

    event->ignore();
}

/**
 * @brief TitleWidget::mouseDoubleClickEvent
 * @param event
 */
void TitleWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (m_mainWindow->isMaximized())
    {
        m_mainWindow->showNormal();
      //  m_systemButtonBar->setRestored();
    }
    else
    {
        m_mainWindow->showMaximized();
      //  m_systemButtonBar->setMaximized();
    }

    event->ignore();
}

/**
 * @brief TitleWidget::setupUi
 */
void TitleWidget::setupUi()
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    layout->addStretch();

//    m_menuButton = new soyImageButton();
//    m_menuButton->setImageName(":/soy/img/menu");
//    connect(m_menuButton, SIGNAL(clicked()), this, SIGNAL(menuRequested()));

//    m_systemButtonBar = new soySystemButtonBar;
//    m_systemButtonBar->installOn(m_mainWindow);

//    m_systemButtonBar->setCloseButtonEnabled(true);

//    layout->addWidget(m_menuButton, 0, Qt::AlignTop);
//    layout->addWidget(m_systemButtonBar, 0, Qt::AlignTop);
}

void TitleWidget::releaseUi()
{
//    if(m_menuButton)
//    {
//        delete m_menuButton;
//        m_menuButton = NULL;
//    }

//    if(m_systemButtonBar)
//    {
//        delete m_systemButtonBar;
//        m_systemButtonBar = NULL;
//    }
}
