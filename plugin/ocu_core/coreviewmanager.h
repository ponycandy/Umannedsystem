#ifndef COREVIEWMANAGER_H
#define COREVIEWMANAGER_H
#pragma once

#include <QMap>
#include <QStackedWidget>
#include "defines/OcuDefines.h"

class CoreViewManager : public QStackedWidget
{
    Q_OBJECT
public:
    /**
     * @brief CoreViewManager
     * @param parent
     */
    explicit CoreViewManager(QWidget *parent = nullptr);

    ~CoreViewManager();

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
     * @brief releaseUi
     */
    void releaseUi();

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


#endif // COREVIEWMANAGER_H
