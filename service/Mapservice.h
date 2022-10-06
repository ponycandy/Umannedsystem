
#ifndef MAPSERVICE_H
#define MAPSERVICE_H
#pragma once
#include <QObject>


#include <QtPlugin>

#include "icd/OcuControlICDTransStruct.h"
class MapService
{
public:
    virtual ~MapService(){}

    /**
     * @brief getMapWidget
     * @return
     */
    virtual QWidget *getMapWidget() = 0;

    virtual void setMapWidgetType(MapWidgetType type) = 0;

    /**
     * @brief getMapWidget
     * @return
     */
    virtual void realeseMapWidget() = 0;

    /**
     * @brief drawTaskManagementPointPath
     * @param dataList
     */
    virtual void drawTaskManagementPointPath(const QList<TaskPointData> &dataList) = 0;

    /**
     * @brief drawCommandTaskPointPath
     * @param dataList
     */
    virtual void drawCommandTaskPointPath(CommandTaskTurnToAutoDriverTrans &taskInfo) = 0 ;

    /**
     * @brief updateMyLocation
     */
    virtual void updateMyLocation() = 0;

    /**
     * @brief zoomIn
     */
    virtual void zoomIn() = 0;

    /**
     * @brief zoomOut
     */
    virtual void zoomOut() = 0;

    /**
     * @brief clearPlotting
     */
    virtual void clearPlotting() = 0;


    /**
     * @brief moveUp
     */
    virtual void moveUp()= 0;

    /**
     * @brief moveDown
     */
    virtual void moveDown()= 0;

    /**
     * @brief moveLeft
     */
    virtual void moveLeft()= 0;

    /**
     * @brief moveRight
     */
    virtual void moveRight()= 0;

    /**
     * @brief ZoomIntoMax
     */
    virtual void ZoomIntoMax()= 0;

    /**
     * @brief drawMiddleCarComponentTask
     * @param taskInfo
     */
    virtual  void  drawMiddleCarComponentTask(int taskIndex,QVector<MiddleCarComponentTask> &taskInfo) = 0;

    /**
     * @brief drawMiddleCarBattlefieldTargetPositionTask
     * @param taskInfo
     */
    //virtual  void  drawMiddleCarBattlefieldTargetPositionTask(int taskIndex,QVector<MiddleCarBattlefieldTargetPosition> &taskInfo) = 0;

    /**
     * @brief drawAndUpdateBattlefieldTargetPosition
     * @param id
     * @param point
     * @param img
     * @param yaw
     */
    virtual  void drawAndUpdateBattlefieldTargetPosition(int id,QPointF point,QPixmap img,double yaw) = 0;

    /**
     * @brief drawMiddleCarTargetAttachResultTask
     * @param taskInfo
     */
    //virtual  void  drawMiddleCarTargetAttachResultTask(int taskIndex,QVector<MiddleCarTargetAttachResult> &taskInfo) = 0;


    /**
     * @brief LocationByList
     * @param pointList
     */
    virtual void LocationByList(QList<QPointF>  pointList) = 0;


    /**
     * @brief LocationByPoint
     * @param point
     */
    virtual void LocationByPoint(QPointF point) = 0;

    /**
     * @brief deleteShapeById
     * @param id
     */
    virtual void deleteShapeById(int id) = 0;

    /**
     * @brief getFireControlMapWidget
     * @return
     */
    virtual QWidget *getFireControlMapWidget() = 0;


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
    virtual QVector<QPointF> FindPath(double start_lon, double start_lat, double stop_lon, double stop_lat,const QString& errorStr) = 0;

    /**
     * @brief LoadPts 加载路网文件
     * @param pts
     * @param edge
     * @return
     */
    virtual bool LoadPts(const QString pts, const QString edge, const QString &errorStr) = 0;

    /**
     * @brief GetAStarNavMapPoints
     * @return
     */
    virtual QList<QPointF> GetAStarNavMapPoints() = 0;


    /** ******************************************************军标绘制相关接口**************************************************/
    /**
     * @brief CreateSvg
     * @param codeID
     * @param point
     * @param rotateAngle
     * @return
     */
    virtual bool CreateSvg(int codeID,const QPointF& point,int rotateAngle) = 0;


    virtual bool DrawTargetSvg(int codeID, const QPointF& point, int rotateAngle, QString svgPath)= 0;

    /** ******************************************************绘制圆接口**************************************************/
    virtual bool CreateNewCircle(int iPlottingElementID, const QPointF& centerPoint,int iLineWidth,\
                         double dRadius,QColor lineColor,QColor fillColor,QString strRemark = "cilce") = 0;

    /** ******************************************************绘制多边形接口**************************************************/
    virtual bool CreateNewPolygon(int iPlottingElementID, const QVector<QPointF>& pointVectro,int iLineWidth,QColor lineColor,QColor fillColor,QString strRemark = "polygon") = 0;





    /** ******************************************************绘制管理ID相关接口**************************************************/
    /**
     * @brief getNewPlottingId 地图标会相关接口
     * @return
     */
    virtual int getNewPlottingId() = 0;


    /**
     * @brief getNewTaskId 任务标会相关接口
     * @return
     */
    virtual int getNewTaskId() = 0;


};
#define MapService_iid "MapService"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(MapService,MapService_iid  )
QT_END_NAMESPACE

#endif

