#pragma once

#include <QtPlugin>

#include "OcuDefines.h"

struct FireControlCoreService
{
public:
    virtual ~FireControlCoreService() {}

    /**
        * @brief addView
        * @param viewKind
        * @param view
        */
    virtual void addView(UcsDefines::UcsViewKind viewKind, QWidget *view) = 0;

    /**
        * @brief changeView
        * @param viewKind
        */
    virtual void changeView(UcsDefines::UcsViewKind viewKind) = 0;
};

Q_DECLARE_INTERFACE(FireControlCoreService, "FireControlCoreService")
