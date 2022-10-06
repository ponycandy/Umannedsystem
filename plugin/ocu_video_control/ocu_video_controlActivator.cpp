#include "ocu_video_controlActivator.h"


ocu_video_controlActivator* ocu_video_controlActivator::m_instance=Q_NULLPTR;
PluginContext* ocu_video_controlActivator::m_CONTEXT=Q_NULLPTR;
ocu_video_controlActivator::ocu_video_controlActivator(QObject *parent) : QObject(parent)
{
    m_instance=this;
}
void ocu_video_controlActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void ocu_video_controlActivator::start()
{

}
void ocu_video_controlActivator::stop()
{
delete this;

}
