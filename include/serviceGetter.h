#include <QString>
#include <QObject>
#include <plugincontext.h>
template<class S>
class servicegetter
{
public:
    servicegetter(PluginContext *CONTEXT);
    S* getservice(QString servicename);
private:
        PluginContext *m_CONTEXT;
};
