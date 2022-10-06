#include "mapmanager.h"
#include "ocu_mapActivator.h"
#include "MapWidget.h"

/**
 * @brief MapManager::MapManager
 * @param parent
 */
MapManager::MapManager(QObject *parent)
    : QObject(parent)
    , m_mapWidget(NULL)
{
    /** 注册地图服务*/
    ocu_mapActivator::registerservice(this,"MapService");
}

/**
 * @brief MapManager::~MapManager
 */
MapManager::~MapManager()
{
    if(m_mapWidget)
    {
        delete m_mapWidget;
        m_mapWidget = NULL;
    }
}

/**
 * @brief MapManager::getMapWidget
 * @return
 */
QWidget *MapManager::getMapWidget()
{
    if(m_mapWidget == NULL){
        m_mapWidget = new  MapWidget();
    }
    return m_mapWidget;
}

void MapManager::setMapWidgetType(MapWidgetType type)
{
    return m_mapWidget->setMapWidgetType(type);
}

void MapManager::realeseMapWidget()
{
    if(m_mapWidget)
    {
        delete  m_mapWidget;
        m_mapWidget = NULL;
    }
}

/**
 * @brief MapManager::drawTaskManagementPointPath
 * @param dataList
 */
void MapManager::drawTaskManagementPointPath(const QList<TaskPointData> &dataList)
{
    m_mapWidget->drawTaskManagementPointPath(dataList);
}

/**
 * @brief MapManager::drawCommandTaskPointPath
 * @param taskInfo
 */
void MapManager::drawCommandTaskPointPath(CommandTaskTurnToAutoDriverTrans &taskInfo)
{
    m_mapWidget->drawCommandTaskPointPath(taskInfo);
}

/**
 * @brief MapManager::updateMyLocation
 */
void MapManager::updateMyLocation()
{
    m_mapWidget->updateMyLocation();
}

/**
 * @brief MapManager::zoomIn
 */
void MapManager::zoomIn()
{
    m_mapWidget->zoomIn();
}

/**
 * @brief MapManager::zoomOut
 */
void MapManager::zoomOut()
{
    m_mapWidget->zoomOut();
}

/**
 * @brief MapManager::clearPlotting
 */
void MapManager::clearPlotting()
{
    m_mapWidget->clearPlotting();
}

/**
 * @brief MapManager::moveUp
 */
void MapManager::moveUp()
{
     m_mapWidget->moveUp();
}

/**
 * @brief MapManager::moveDown
 */
void MapManager::moveDown()
{
     m_mapWidget->moveDown();
}

/**
 * @brief MapManager::moveLeft
 */
void MapManager::moveLeft()
{
    m_mapWidget->moveLeft();
}

/**
 * @brief MapManager::moveRight
 */
void MapManager::moveRight()
{
    m_mapWidget->moveRight();
}

/**
 * @brief MapManager::ZoomIntoMax
 */
void MapManager::ZoomIntoMax()
{
    m_mapWidget->ZoomIntoMax();
}

/**
 * @brief MapManager::drawMiddleCarComponentTask
 * @param taskIndex
 * @param taskInfo
 */
void MapManager::drawMiddleCarComponentTask(int taskIndex, QVector<MiddleCarComponentTask> &taskInfo)
{
    m_mapWidget->drawMiddleCarComponentTask(taskIndex,taskInfo);
}

/**
 * @brief MapManager::drawAndUpdateBattlefieldTargetPosition
 * @param id
 * @param point
 * @param img
 * @param yaw
 */
void MapManager::drawAndUpdateBattlefieldTargetPosition(int id, QPointF point, QPixmap img, double yaw)
{
    m_mapWidget->drawAndUpdateBattlefieldTargetPosition(id,point,img,yaw);
}

/**
 * @brief MapManager::LocationByList
 * @param pointList
 */
void MapManager::LocationByList(QList<QPointF> pointList)
{
    m_mapWidget->LocationByList(pointList);
}

/**
 * @brief MapManager::LocationByPoint
 * @param point
 */
void MapManager::LocationByPoint(QPointF point)
{
    m_mapWidget->LocationByPoint(point);
}

/**
 * @brief MapManager::deleteShapeById
 * @param id
 */
void MapManager::deleteShapeById(int id)
{
    m_mapWidget->deleteShapeById(id);
}

/**
 * @brief MapManager::getFireControlMapWidget
 * @return
 */
QWidget *MapManager::getFireControlMapWidget()
{
    if(m_mapWidget == NULL)
    {
       m_mapWidget  = new MapWidget();
       m_mapWidget->show();
       m_mapWidget->setGeometry(1920,0,1920,1080);
    }

    return m_mapWidget;
}

/**
 * @brief MapManager::FindPath
 * @param start_lon
 * @param start_lat
 * @param stop_lon
 * @param stop_lat
 * @param errorStr
 * @return
 */
QVector<QPointF> MapManager::FindPath(double start_lon, double start_lat, double stop_lon, double stop_lat, const QString &errorStr)
{
    return m_mapWidget->FindPath(start_lon,start_lat,stop_lon,stop_lat,errorStr);
}

/**
 * @brief MapManager::LoadPts
 * @param pts
 * @param edge
 * @param errorStr
 * @return
 */
bool MapManager::LoadPts(const QString pts, const QString edge, const QString &errorStr)
{
    return m_mapWidget->LoadPts(pts,edge,errorStr);
}

/**
 * @brief MapManager::GetAStarNavMapPoints
 * @return
 */
QList<QPointF> MapManager::GetAStarNavMapPoints()
{
    return m_mapWidget->GetAStarNavMapPoints();
}

/**
 * @brief MapManager::CreateSvg
 * @param codeID
 * @param point
 * @param rotateAngle
 * @return
 */
bool MapManager::CreateSvg(int codeID, const QPointF &point, int rotateAngle)
{
    return m_mapWidget->CreateSvg(codeID,point,rotateAngle);
}

bool MapManager::DrawTargetSvg(int codeID, const QPointF &point, int rotateAngle, QString svgPath)
{
    return m_mapWidget->DrawTargetSvg(codeID,point,rotateAngle,svgPath);
}

bool MapManager::CreateNewCircle(int iPlottingElementID, const QPointF &centerPoint, int iLineWidth, double dRadius, QColor lineColor, QColor fillColor, QString strRemark)
{
    return m_mapWidget->CreateNewCircle(iPlottingElementID,centerPoint,iLineWidth,dRadius,lineColor,fillColor,strRemark);
}

bool MapManager::CreateNewPolygon(int iPlottingElementID, const QVector<QPointF>& pointVectro, int iLineWidth, QColor lineColor, QColor fillColor, QString strRemark)
{
    return m_mapWidget->CreateNewPolygon(iPlottingElementID,pointVectro,iLineWidth,lineColor,fillColor,strRemark);
}

/**
 * @brief MapManager::getNewPlottingId
 * @return
 */
int MapManager::getNewPlottingId()
{
    return MapWidget::getNewPlottingId();
}

/**
 * @brief MapManager::getNewTaskId
 * @return
 */
int MapManager::getNewTaskId()
{
    return MapWidget::getNewTaskId();
}

/**
 * @brief MapManager::slotSelectPointFromMap
 */
void MapManager::slotSelectPointFromMap()
{

}
