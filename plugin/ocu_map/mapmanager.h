#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#pragma once

#include <QObject>
#include <service/Mapservice.h>

class MapWidget;

class MapManager : public QObject, public MapService
{
    Q_OBJECT
    Q_INTERFACES(MapService)
public:
    /**
     * @brief MapManager
     * @param parent
     */
    explicit MapManager(QObject *parent = nullptr);

    ~MapManager();

    /**
     * @brief getMapWidget
     * @return
     */
    QWidget *getMapWidget() override;

    void setMapWidgetType(MapWidgetType type) override;

    /**
     * @brief getMapWidget
     * @return
     */
    void realeseMapWidget() override;

    /**
     * @brief drawTaskManagementPointPath
     * @param dataList
     */
    void drawTaskManagementPointPath(const QList<TaskPointData> &dataList) override;

    /**
     * @brief drawCommandTaskPointPath
     * @param dataList
     */
    void drawCommandTaskPointPath(CommandTaskTurnToAutoDriverTrans &taskInfo) override;

    /**
     * @brief updateMyLocation
     */
    void updateMyLocation() override;

    /**
     * @brief zoomIn
     */
    void zoomIn() override;

    /**
     * @brief zoomOut
     */
    void zoomOut() override;

    /**
     * @brief clearPlotting
     */
    void clearPlotting() override;


    /**
     * @brief moveUp
     */
    void moveUp() override;

    /**
     * @brief moveDown
     */
    void moveDown() override;

    /**
     * @brief moveLeft
     */
    void moveLeft() override;

    /**
     * @brief moveRight
     */
    void moveRight() override;

    /**
     * @brief ZoomIntoMax
     */
    void ZoomIntoMax() override;

    /**
     * @brief drawMiddleCarComponentTask
     * @param taskInfo
     */
    void  drawMiddleCarComponentTask(int taskIndex,QVector<MiddleCarComponentTask> &taskInfo) override;

    /**
     * @brief drawAndUpdateBattlefieldTargetPosition
     * @param id
     * @param point
     * @param img
     * @param yaw
     */
    void drawAndUpdateBattlefieldTargetPosition(int id,QPointF point,QPixmap img,double yaw) override;

    /**
     * @brief LocationByList
     * @param point
     */
    void LocationByList(QList<QPointF>  pointList) override;

    /**
     * @brief LocationByPoint
     * @param point
     */
    void LocationByPoint(QPointF point) override;


    /**
     * @brief deleteShapeById
     * @param id
     */
    void deleteShapeById(int id) override;

    /**
     * @brief getFireControlMapWidget
     * @return
     */
    QWidget *getFireControlMapWidget() override;


    /** ***************************************路径规划相关接口******************************************************************/
    /**
     * @brief FindPath
     * @param start_lon
     * @param start_lat
     * @param stop_lon
     * @param stop_lat
     * @param errorStr
     * @return
     */
    QVector<QPointF> FindPath(double start_lon, double start_lat, double stop_lon, double stop_lat,const QString& errorStr) override;

    /**
     * @brief LoadPts 加载路网文件
     * @param pts
     * @param edge
     * @return
     */
    bool LoadPts(const QString pts, const QString edge, const QString &errorStr) override;

    /**
     * @brief GetAStarNavMapPoints
     * @return
     */
    QList<QPointF> GetAStarNavMapPoints() override;


    /** ******************************************************军标绘制相关接口**************************************************/
    /**
     * @brief CreateSvg
     * @param codeID
     * @param point
     * @param rotateAngle
     * @return
     */
    bool CreateSvg(int codeID,const QPointF& point,int rotateAngle) override;



    bool DrawTargetSvg(int codeID, const QPointF& point, int rotateAngle, QString svgPath) override;

    /** ******************************************************绘制圆接口**************************************************/
    bool CreateNewCircle(int iPlottingElementID, const QPointF& centerPoint,int iLineWidth,\
                         double dRadius,QColor lineColor,QColor fillColor,QString strRemark = "cilce") override;


    /** ******************************************************绘制多边形接口**************************************************/
    bool CreateNewPolygon(int iPlottingElementID, const QVector<QPointF>& pointVectro,int iLineWidth,QColor lineColor,QColor fillColor,QString strRemark = "polygon") override;


    /** ******************************************************绘制管理ID相关接口**************************************************/
    /**
     * @brief getNewPlottingId 地图标会相关接口
     * @return
     */
    int getNewPlottingId() override;


    /**
     * @brief getNewTaskId 任务标会相关接口
     * @return
     */
    int getNewTaskId() override;


public slots:

    /**
     * @brief slotSelectPointFromMap
     */
    void  slotSelectPointFromMap();

private:

    /**
     * @brief m_mapWidget 地图界面指针
     */
    MapWidget *m_mapWidget;

};
#endif // MAPMANAGER_H
