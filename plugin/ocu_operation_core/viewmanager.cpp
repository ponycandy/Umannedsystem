#include "viewmanager.h"

/**
 * @brief ViewManager::ViewManager  构造函数
 * @param parent
 */
ViewManager::ViewManager(QWidget *parent)
    : QStackedWidget(parent)
    , m_currentViewkind(UcsDefines::UCS_VIEW_KIND_NONE)
{

}

/**
 * @brief ViewManager::addView
 * @param viewKind
 * @param view
 * @return
 */
bool ViewManager::addView(UcsDefines::UcsViewKind viewKind, QWidget *view)
{
    addWidget(view);

    m_widgets.insert(viewKind, view);

    return true;
}

/**
 * @brief ViewManager::changeView
 * @param viewKind
 */
void ViewManager::changeView(UcsDefines::UcsViewKind viewKind)
{
    if (m_currentViewkind != viewKind)
    {
        m_currentViewkind = viewKind;
        setCurrentWidget(m_widgets.value(m_currentViewkind));
    }
}
