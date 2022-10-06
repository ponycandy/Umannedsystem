#pragma once

#include <QMap>
#include <QStackedWidget>
#include "defines/OcuDefines.h"

class ViewManager : public QStackedWidget
{
    Q_OBJECT
public:
    /**
     * @brief ViewManager
     * @param parent
     */
    explicit ViewManager(QWidget *parent = nullptr);

    /**
     * @brief addView
     * @param viewKind
     * @param view
     * @return
     */
    bool addView(UcsDefines::UcsViewKind viewKind, QWidget *view);

    /**
     * @brief changeView
     * @param viewKind
     */
    void changeView(UcsDefines::UcsViewKind viewKind);

private:
    /**
     * @brief m_currentViewkind
     */
    UcsDefines::UcsViewKind m_currentViewkind;

    /**
     * @brief m_widgets
     */
    QMap<UcsDefines::UcsViewKind, QWidget *> m_widgets;
};
