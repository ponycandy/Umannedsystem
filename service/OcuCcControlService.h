#pragma once

#include <QtPlugin>

#include "defines/OcuCcDefines.h"

struct OcuCcControlService
{
public:
    virtual ~OcuCcControlService() {}

    /**
     * @brief addView
     * @param viewKind
     * @param view
     */
    virtual void addView(OcuCcDefines::OcuCcViewKind viewKind, QWidget *view) = 0;

    /**
     * @brief changeView
     * @param viewKind
     */
    virtual void changeView(OcuCcDefines::OcuCcViewKind viewKind) = 0;

};

Q_DECLARE_INTERFACE(OcuCcControlService, "OcuCcControlService")
