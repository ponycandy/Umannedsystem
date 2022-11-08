#include "mapmanager.h"
#include "ocu_mapActivator.h"
#include "defines/OcuDefines.h"

/**
 * @brief MapManager::MapManager
 * @param parent
 */
MapManager::MapManager(QObject *parent)
    : QObject(parent),m_service(NULL)
    , m_mapWidget(NULL)
{
    /** 注册地图服务*/
    m_mapWidget=new MapWidget;
    m_service=ocu_mapActivator::getService<ocu_car_coreservice>("ocu_car_coreservice");
    m_service->addView(UcsDefines::OCU_MAP_DISPLAY,m_mapWidget);
    ocu_mapActivator::registerservice(this,"MapService");
}

/**
 * @brief MapManager::~MapManager
 */
MapManager::~MapManager()
{
}

