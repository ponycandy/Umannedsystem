#include "ocu_mapActivator.h"


ocu_mapActivator* ocu_mapActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_mapActivator::m_CONTEXT=Q_NULLPTR;
ocu_mapActivator::ocu_mapActivator(QObject *parent) : QObject(parent),m_MapManager(NULL)
{
    m_instance=this;
}
void ocu_mapActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_mapActivator::start()
{
    if(m_MapManager == NULL)
    {
        m_MapManager = new MapManager;
    }

}
void ocu_mapActivator::stop()
{
delete this;

}
