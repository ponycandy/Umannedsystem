#include "startwindow.h"
#include "ui_startwindow.h"
#include "vehicle1_coreActivator.h"
#include "event/OcuEventContants.h"
startwindow::startwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);
    setupwidget();

    m_service=vehicle1_coreActivator::getService<Coreservice>("Coreservice");
    vehicle1_coreActivator::registerservice(this,"vehicle_1_coreservice");

    m_service->addView(UcsDefines::UcsViewKind::VEHICLE_1_WINDOW,this);
     vehicle1_coreActivator::subscribevent(UcsEventConstants::TOPCI_MENU_CLICKED,this);
}

startwindow::~startwindow()
{
    delete ui;
}

void startwindow::setupwidget()
{
    /*初始化12个按钮，左右两边各6个，并将指针插入到节点管理器中*/
    /*左边的六个按钮*/
    m_leftWidget = new QWidget;
    m_leftWidget->setFixedSize(121,980);
    m_leftLayout = new QVBoxLayout;
    m_leftLayout->setContentsMargins(0, 0, 0, 0);
    m_leftLayout->setSpacing(0);
    m_leftWidget->setLayout(m_leftLayout);

    for (int i = 1; i <= 6; ++i)
    {
        QToolButton *button = new QToolButton;
        button->setProperty("style", "MenuLeftButton");
        button->setFixedSize(121,163);
        QSizePolicy policy = button->sizePolicy();
        policy.setVerticalPolicy(QSizePolicy::Fixed);
        button->setSizePolicy(policy);
        m_leftLayout->addWidget(button);
        m_buttons.insert(i, button);

        connect(button, &QToolButton::clicked, this, &startwindow::onMenuClicked);
    }

    /*右边的六个按钮*/
    m_rightWidget = new QWidget;
    m_rightWidget->setFixedSize(121, 980);
    m_rightLayout = new QVBoxLayout;
    m_rightLayout->setContentsMargins(0, 0, 0, 0);
    m_rightLayout->setSpacing(0);
    m_rightWidget->setLayout(m_rightLayout);

    for (int i = 7; i <= 12; ++i)
    {
        QToolButton *button = new QToolButton;
        button->setProperty("style", "MenuRightButton");

        button->setFixedSize(121,163);

        QSizePolicy policy = button->sizePolicy();
        policy.setVerticalPolicy(QSizePolicy::Fixed);
        button->setSizePolicy(policy);
        m_rightLayout->addWidget(button);
        m_buttons.insert(i, button);
        connect(button, &QToolButton::clicked, this, &startwindow::onMenuClicked);
    }
    ui->H_left->addWidget(m_leftWidget);
    ui->H_right->addWidget(m_rightWidget);
    m_whitewidget=new whitewidget;
    addView(UcsDefines::VEHICLE_1_WINDOW,m_whitewidget);
    changeView(UcsDefines::VEHICLE_1_WINDOW);/*根据主页面的值设置按钮值*/

}

void startwindow::EventTriggeres(XTLevent event)
{
    if (event.eventname==UcsEventConstants::TOPCI_MENU_CLICKED)
    {
        QString name=event.m_dict.value("property").toString();
        if(name== UcsEventConstants::VEHICLE_1_CONTROL)
        {
            changeView(UcsDefines::VEHICLE1_CONTROL);
            //            changeView(UcsDefines::UCS_VIEW_KIND_MAIN);
            //            return;
        }
        if(name== UcsEventConstants::VEHICLE_1_MAIN)
        {
            changeView(UcsDefines::VEHICLE_1_WINDOW);
            //            changeView(UcsDefines::UCS_VIEW_KIND_MAIN);
            //            return;
        }

    }
}

void startwindow::buildMenu(int type)
{
    clearMenu();
    switch (type)
    {
    case UcsDefines::VEHICLE_1_WINDOW:
    {
        setButton(1, QStringLiteral("Control \r\n Mode"), UcsEventConstants::VEHICLE_1_CONTROL, QString(":/b_img/六芒星.png"));
        //  setButton(2, QStringLiteral("Auto\r\nControl"), UcsEventConstants::MAPINTERFACE, QString(":/b_img/六芒星.png"));
        setButton(12, QStringLiteral("EXIT"), UcsEventConstants::EXITTOMAIN, QString(":/b_img/六芒星.png"));
        break;
    }
    case UcsDefines::VEHICLE1_CONTROL:
    {
      setButton(12, QStringLiteral("EXIT"), UcsEventConstants::VEHICLE_1_MAIN, QString(":/b_img/六芒星.png"));
        break;
    }
    default:
        break;
    }

}

void startwindow::clearMenu()
{
    QMapIterator<int, QToolButton *> i(m_buttons);
    while (i.hasNext())
    {
        i.next();
        QToolButton *button = i.value();

        button->setText("");
        button->setProperty("topic", "");
        button->setIcon(QIcon(""));
        button->setObjectName("");
    }

}

void startwindow::setButton(int index, const QString &text, const QString &topic, const QString &icon)
{
    QToolButton *button = m_buttons.value(index);
    button->setText(text);
    button->setProperty("topic", topic);
    button->setFont(QFont("Microsoft YaHei", 14, QFont::Bold));
    if (!icon.isEmpty()) {
        button->setIcon(QIcon(icon));
        button->setIconSize(QSize(49, 59));
    }
    //    button->setStyleSheet("QToolButton{padding-top:10px;margin-top:0px;}");
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    button->setVisible(true);

}

void startwindow::setConnectStatus(bool connectStatus)
{

}

void startwindow::setControlStatus(bool controlStatus)
{

}

void startwindow::addView(UcsDefines::UcsViewKind viewKind, QWidget *view)
{
    int i=ui->stackedWidget->count();
    widgetmap.insert(viewKind,i);
    ui->stackedWidget->addWidget(view);
}

void startwindow::changeView(UcsDefines::UcsViewKind viewKind)
{
    int i=widgetmap.value(viewKind);
    ui->stackedWidget->setCurrentIndex(i);
    buildMenu(viewKind);

}

UcsDefines::UcsViewKind startwindow::getCurrentView()
{

}

void startwindow::changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text)
{

}

void startwindow::changeMenu(const int num, const QString &newMenu, const QString &text)
{

}

void startwindow::onMenuClicked()
{
    QToolButton *button = dynamic_cast<QToolButton *>(sender());

    if (button->property("topic").toString().isEmpty())
        return;
    XTLevent event;
    event.eventname=   UcsEventConstants::TOPCI_MENU_CLICKED;
    event.m_dict.insert("property",button->property("topic"));
    vehicle1_coreActivator::postevent(event);

}
