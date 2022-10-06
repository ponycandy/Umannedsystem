#pragma once

#include <QtPlugin>

#include "defines/OcuDefines.h"

struct PluginManagerService
{
public:
    virtual ~PluginManagerService() {}

    /**
        * @brief startCarTypePlugins
        * @param carType
        */
    virtual void startCarTypePlugins(QString carType) = 0;

    /**
        * @brief stopCarTypePlugins
        * @param carType
        */
    virtual void stopCarTypePlugins(QString carType) = 0;
};

Q_DECLARE_INTERFACE(PluginManagerService, "PluginManagerService")
