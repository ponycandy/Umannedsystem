#include "coreviewmanager.h"

/**
 * @brief CoreViewManager::CoreViewManager 构造函数
 * @param parent
 */
CoreViewManager::CoreViewManager(QWidget *parent)
    : QStackedWidget(parent)
    , m_currentViewkind(UcsDefines::UCS_VIEW_KIND_NONE)
    , m_widgets()
{
    m_widgets.clear();
}

CoreViewManager::~CoreViewManager()
{
    releaseUi();
}

/**
 * @brief CoreViewManager::addView  界面插入接口
 * @param viewKind
 * @param view
 * @return
 */
bool CoreViewManager::addView(UcsDefines::UcsViewKind viewKind, QWidget *view)
{
    addWidget(view);

    m_widgets.insert(viewKind, view);

    return true;
}

/**
 * @brief CoreViewManager::changeView 界面切换接口
 * @param viewKind
 */
void CoreViewManager::changeView(UcsDefines::UcsViewKind viewKind)
{
    if (m_currentViewkind != viewKind)
    {
        m_currentViewkind = viewKind;
        setCurrentWidget(m_widgets.value(m_currentViewkind));
    }


}

void CoreViewManager::releaseUi()
{

}
