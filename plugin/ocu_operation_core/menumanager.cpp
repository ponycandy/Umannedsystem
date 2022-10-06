#include "menumanager.h"
#include "ocu_operation_coreActivator.h"


#include <QVariant>
#include <QSizePolicy>
#include <QPainter>


#include "event/OcuEventContants.h"


const char MENU_PROPERTY_NAME[] = "topic";

/**
 * @brief MenuManager::MenuManager 构造函数
 * @param parent
 */
MenuManager::MenuManager(QObject *parent)
    : QObject(parent)
    , m_leftWidget(NULL)
    , m_rightWidget(NULL)
    , m_leftLayout(NULL)
    , m_rightLayout(NULL)
    , m_buttons()
{
    setupUi();
}

/**
 * @brief MenuManager::~MenuManager 析构函数
 */
MenuManager::~MenuManager()
{
    releaseUi();
}

/**
 * @brief MenuManager::install
 * @param parent
 */
void MenuManager::install(QWidget *parent)
{
    if (parent->layout())
    {
        parent->layout()->addWidget(m_leftWidget);
        parent->layout()->addWidget(m_rightWidget);
    }
}

/**
 * @brief MenuManager::install
 * @param parent
 */
void MenuManager::install(QHBoxLayout *parent)
{
    if (parent->layout())
    {
        parent->addWidget(m_leftWidget);
        parent->addWidget(m_rightWidget);
    }
}

/**
 * @brief MenuManager::viewChanged
 * @param viewKind
 */
void MenuManager::viewChanged(UcsDefines::UcsViewKind viewKind)
{
    buildMenu(viewKind);
}

/**
 * @brief MenuManager::changeMenuButton
 * @param oldMenu
 * @param newMenu
 * @param text
 */
void MenuManager::changeMenuButton(const QString &oldMenu, const QString &newMenu, const QString &text)
{
    QMapIterator<int, QToolButton *> i(m_buttons);
    while (i.hasNext())
    {
        i.next();
        QToolButton *button = i.value();

        if (button->property(MENU_PROPERTY_NAME).toString() == oldMenu)
        {
            button->setProperty(MENU_PROPERTY_NAME, newMenu);
            button->setText(text);
            break;
        }
    }
}

/**
 * @brief MenuManager::changeMenuButton
 * @param num
 * @param newMenu
 * @param text
 */
void MenuManager::changeMenuButton(const int &num,const QString &newMenu,const QString &text)
{
    if(m_buttons.contains(num))
    {
        QToolButton *button = m_buttons.value(num);
        button->setProperty(MENU_PROPERTY_NAME, newMenu);
        button->setText(text);
    }
}

/**
 * @brief MenuManager::setupUi  初始化界面
 */
void MenuManager::setupUi(void)
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

        connect(button, &QToolButton::clicked, this, &MenuManager::onMenuClicked);
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
        connect(button, &QToolButton::clicked, this, &MenuManager::onMenuClicked);
    }

    buildMenu(UcsDefines::UCS_VIEW_KIND_LOGIN);/*根据主页面的值设置按钮值*/
}

/**
 * @brief MenuManager::releaseUi
 */
void MenuManager::releaseUi()
{
    QMap<int, QToolButton *>::const_iterator iter = m_buttons.begin();
    for(iter; iter != m_buttons.end(); iter ++)
    {
        delete  iter.value();
    }

    if(m_leftLayout){
    delete  m_leftLayout;   m_leftLayout = NULL;
    }

    if(m_rightLayout){
        delete  m_rightLayout;   m_rightLayout = NULL;
    }

    if(m_leftWidget){
        delete  m_leftWidget;   m_leftWidget = NULL;
    }

    if(m_rightWidget){
        delete  m_rightWidget;   m_rightWidget = NULL;
    }
}

/**
 * @brief MenuManager::setButton
 * @param index
 * @param text
 * @param topic
 * @param icon
 */
void MenuManager::setButton(int index, const QString &text, const QString &topic, const QString &icon)
{
    QToolButton *button = m_buttons.value(index);
    button->setText(text);
    button->setProperty(MENU_PROPERTY_NAME, topic);

    if (!icon.isEmpty()) {
        button->setIcon(QIcon(icon));
        button->setIconSize(QSize(49, 59));
    }
//    button->setStyleSheet("QToolButton{padding-top:10px;margin-top:0px;}");
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    button->setVisible(true);
}

/**
 * @brief MenuManager::clearMenu 清楚界面按钮显示
 */
void MenuManager::clearMenu(void)
{
    QMapIterator<int, QToolButton *> i(m_buttons);
    while (i.hasNext())
    {
        i.next();
        QToolButton *button = i.value();

        button->setText("");
        button->setProperty(MENU_PROPERTY_NAME, "");
        button->setIcon(QIcon(""));
        button->setObjectName("");
    }
}

/**
 * @brief MenuManager::buildMenu 根据界面切换按钮
 * @param viewKind
 */
void MenuManager::buildMenu(UcsDefines::UcsViewKind viewKind)
{
    clearMenu();
    switch (viewKind)
    {
        case UcsDefines::UCS_VIEW_KIND_LOGIN:
        {
            setButton(11, QStringLiteral("登录"), UcsEventConstants::MENU_EVENT_LOGIN, QString(":/img/login_pre"));
            setButton(12, QStringLiteral("管理\r\n登录"), UcsEventConstants::MENU_EVENT_LOGIN_ADMIN, QString(":/img/admin_login_pre"));
            break;
        }
        case UcsDefines::UCS_VIEW_KIND_SYSTEM_SETTING:
        {
            setButton(12, QStringLiteral("返回"), UcsEventConstants::MENU_EVENT_SYSTEM_SETTING_RETURN, QString(":/img/cancel"));
            break;
        }
        case UcsDefines::UCS_VIEW_KIND_CAR_MANAGER:
        {
//          setButton(1, QStringLiteral("电台\r\n设置"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_RADIO, QString(":/img/radio_set"));
//          setButton(2, QStringLiteral("系统\r\n设置"), UcsEventConstants::MENU_EVENT_LOGIN_SYSTEM_SETTING, QString(":/img/system_set"));
//          setButton(3, QStringLiteral("日志\r\n管理"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_LOGMANAGER, QString(":/img/log_manage"));

            setButton(7, QStringLiteral("新建\r\n车辆"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_ADD, QString(":/img/add_car"));
            setButton(8, QStringLiteral("编辑\r\n车辆"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_EDIT, QString(":/img/edit_car"));
            setButton(9, QStringLiteral("删除\r\n车辆"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_DELETE, QString(":/img/delete_car"));
            setButton(10, QStringLiteral("连接\r\n车辆"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_CONNECT, QString(":/img/connect_car"));
            setButton(12, QStringLiteral("退出\r\n登录"), UcsEventConstants::MENU_EVENT_CAR_MANAGER_RETURN, QString(":/img/cancel_login"));
            break;
        }
        case UcsDefines::UCS_VIEW_KIND_CAR_NET_PARA_CONFIG:
        {
            setButton(12, QStringLiteral("返回"), UcsEventConstants::MENU_EVENT_SYSTEM_SETTING_RETURN, QString(":/img/cancel"));
            break;
        }
        case UcsDefines::UCS_VIEW_KIND_RADIO_MANAGER:
        {
            setButton(1, QStringLiteral("本地参\r\n数设置"), UcsEventConstants::MENU_EVENT_RADIO_SETTING_LOCAL_PARA, QString(":/img/local_parameter"));
            setButton(2, QStringLiteral("远端参\r\n数设置"), UcsEventConstants::MENU_EVENT_RADIO_SETTING_REMOTE_PARA, QString(":/img/distal_parameter"));
            setButton(3, QStringLiteral("频谱\r\n信息"), UcsEventConstants::MENU_EVENT_RADIO_SETTING_FREQUENCE_INFO, QString(":/img/frequent_info"));
            setButton(4, QStringLiteral("RRU\r\n信息"), UcsEventConstants::MENU_EVENT_RADIO_SETTING_RRU_INFO, QString(":/img/rru_info"));
            setButton(5, QStringLiteral("网络\r\n状态"), UcsEventConstants::MENU_EVENT_RADIO_SETTING_NETWORK_INFO, QString(":/img/network_status"));
            setButton(12, QStringLiteral("返回"), UcsEventConstants::MENU_EVENT_SYSTEM_SETTING_RETURN, QString(":/img/cancel"));
            break;
        }
        default:
            break;
    }
}

/**
 * @brief MenuManager::onMenuClicked 按钮点击事件槽函数
 */
void MenuManager::onMenuClicked(void)
{
    QToolButton *button = dynamic_cast<QToolButton *>(sender());

    if (button->property(MENU_PROPERTY_NAME).toString().isEmpty())
        return;
    XTLevent event;
    event.eventname=UcsEventConstants::TOPCI_MENU_CLICKED;
    event.m_dict.insert("property",button->property(MENU_PROPERTY_NAME));
    ocu_operation_coreActivator::postevent(event);
}




