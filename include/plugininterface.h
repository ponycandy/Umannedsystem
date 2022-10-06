#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QObject>
#include "plugincontext.h"
#include "serviceGetter.h"
//定义接口
class PluginInterface
{
public:
    virtual ~PluginInterface(){}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void init(PluginContext *CONTEXT)=0;
};

//一定是唯一的标识符
#define PluginInterface_iid "Examples.Plugin.PluginInterface_iid"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(PluginInterface,PluginInterface_iid )
QT_END_NAMESPACE

#endif // DECLAREINTERFACE_H

