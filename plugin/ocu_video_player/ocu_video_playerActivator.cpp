#include "ocu_video_playerActivator.h"


ocu_video_playerActivator* ocu_video_playerActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_video_playerActivator::m_CONTEXT=Q_NULLPTR;
ocu_video_playerActivator::ocu_video_playerActivator(QObject *parent) : QObject(parent)
{
    m_instance=this;
}
void ocu_video_playerActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_video_playerActivator::start()
{

}
void ocu_video_playerActivator::stop()
{
delete this;

}
