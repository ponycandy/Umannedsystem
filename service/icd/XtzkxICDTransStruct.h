#pragma once

#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QString>

namespace Xtzkx {

/**
 * 0-静默值守；1-自主机动行驶；2-自主侦察；3自主车辆跟随；4-自主人员跟随；5-定点打击；6-定域打击；7-机动打击；8-引导打击；9-协同侦察；10-编队行驶；11-协同打击；12-通信中继
 **/
typedef  enum {
    SilentUnattended,
    AutonomousDriving,
    IndependentInvestigation,
    IndependentFollow,
    IndependentPersonFollow,
    FixedPointAttached,
    LocalizedAttached,
    MotorAttached,
    GuideAttacehd,
    CooperativeInvestigation,
    FormationDriving,
    CooperativeAttrached,
    CommunicationsRelay,
}CooperativeTaskType;

/**
 * 0-无协同成员 1-真打1号车，2-真打2号车，  3-真打3号车,4-寻罗景界3号车,5-寻罗景界1号车,6-tongxin中纪1号车,7-tongxin中纪2号车
 */
typedef  enum {
    CooperativeMemberTypeNone,
    DetectionAndStrikeOne,
    DetectionAndStrikeTwo,
    DetectionAndStrikeThree,
    PatrolAndVigilanceOne,
    PatrolAndVigilanceTwo,
    CommunicationsRelayOne,
    CommunicationsRelayTwo,
}CooperativeMemberType;

/**
 * 0-协同主导者   1-协同配合者   2-目标引导者   3-目标打击者    4-编队领航者   5-编队跟随者
 */
typedef  enum {
    CooperativeDominator,
    CooperativeCooperator,
    TargetGuider,
    TargetAttacher,
    FormationLeader,
    FormationFollower,
}CooperativeRole;

/**
 *
 **/
typedef  enum {
    CooperativeTaskActionTypeNone,
    CooperativeTaskActionTypeCancel,
    CooperativeTaskActionTypePause,
}CooperativeTaskActionType;

/**
 *
 **/
typedef enum{
    OperationalAreaDescriptionCircle,   //! 圆
    OperationalAreaDescriptionPolygon,  //! 多边形
}OperationalAreaDescription;

/**
 *
 **/
typedef   enum{
    SensorTypeNone,
    SensorTypeRadar,
    SensorTypeInfrared,
    SensorTypeVisibleLight,
}SensorType;

/**
 * 0-人员，1-工事；2-汽车；3-装甲车辆；
 **/
typedef   enum{
    TargetTypePerson,
    TargetTypeFortifications,
    TargetTypeAutomobile,
    TargetTypeArmouredVehicle,
}TargetType;

/**
 * 1-敌方；2-我方；3-友邻；4-中立；5-不明；6-未定义
 **/
typedef   enum{
    FriendFoePropertiesEnemy,
    FriendFoePropertiesOurParty,
    FriendFoePropertiesFriendlyNeighbor,
    FriendFoePropertiesNeutrality,
    FriendFoePropertiesUndefined,
    FriendFoePropertiesNone,
}FriendFoeProperties;


/**
 *
 **/
typedef  enum{
    CoordinateSystemTypePolar,
    CoordinateSystemTypeGis,
    CoordinateSystemTypeRightAngle,
}CoordinateSystemType;

/**
 *
 **/
typedef  enum{
    TaskActionTypeNone,
    TaskActionTypeBackout,
    TaskActionTypeComplete,
    TaskActionTypeProcess,
    TaskActionTypeNoneStart,
    TaskActionTypePause,
}TaskActionType;

/**
 *
 **/
typedef  enum{
    TargetDamageStateDestroy,
    TargetDamageStateExit,
}TargetDamageState;

/**
 *
 **/
typedef  struct _TaskSystemTimeTrans{
    short   wYear;         /// 年
    unsigned char     wMonth;        /// 月 。1月份则值为1，2月份则值为2，…..
    char     wDay;          /// 日
    char     wHour;         /// 时
    char     wMinute;       /// 分
    char     wSecond;       /// 秒
}TaskSystemTimeTrans;


/**
 *
 **/
typedef  struct   _TaskPositonTrnas{
    double   longtitude;
    double   latitude;
    double   altitude;
    int      attribute;
}TaskPostitonTrans;


/**
 *
 **/
typedef  struct   _TaskTargetTrans{
    double   targetNum;
    QString  targetName;
    quint8   targetType;
    double   longtitude;
    double   latitude;
    double   altitude;
}TaskTargetTrans;


/**
 *
 **/
typedef  struct  _TargetDamageInformationTrans{
    double        targetNum;
    TargetDamageState  targetDamageState;
}TargetDamageInformationTrans;

/**
 *
 **/
typedef  struct   _TaskTargetInfoTrans{
    int      targetCount;
    int      targetNum;
    TargetType   targetType;
    double   longtitude;
    double   latitude;
    double   altitude;
    double   moveDirection;
    double   distance;
}TaskTargetInfoTrans;

typedef  struct  _PermissionTrans{
    char UVID[33];
    char UVIP[22];
    char ckxwID;
}PermissionTrans;

/** *************************** 操控席位<-协同指控席位*****************************************/
/**
 * 1.1 任务下发
 **/
#define   TaskPositionNum   2
#define   OperationUnitNumber 33
#define   NameMaxNum  50
#define   ProccessDescriptionNum  50
#define associatedtargetnum 30
#define associatedtargetcode 33

typedef  struct  _CoorperativeTaskIssuedTrans{
    char      operationalUnitNumber[OperationUnitNumber];
    char      actionName[NameMaxNum];
    CooperativeTaskType   cooperativeTaskType;
    CooperativeMemberType cooperativeMemberType;
    CooperativeRole       cooperativeRole;
    CooperativeTaskActionType cooperativeTaskActionType;
    TaskSystemTimeTrans     taskStartTime;
    TaskSystemTimeTrans     taskCompleteTime;
    OperationalAreaDescription  areaDescription;
    quint32                 areaPostitonNum;///
    QVector<TaskPostitonTrans>  areaPosition;
    QString                 processDescription;
    quint32                 taskPostitonNum;
    QVector<TaskPostitonTrans>  processPosition;
    quint32                 tasktargetnum;
    QVector<TaskTargetTrans>     taskTarget;
}CoorperativeTaskIssuedTrans;

/**
 * 1.2 统一目标（协同席位下发发给操控席位的目标信息）
 **/
typedef  struct _UnifiedTargetTrans{
    char   unifiedCode[32];
    char   targetName[60];
    TargetType  targetType;
    double      longtitude;
    double      latitude;
    double      altitude;
    TaskSystemTimeTrans time;
    quint16     moveSpeed;
    quint16     moveDirection;
    float       targetThreat;
    char      associatedTargetTable[associatedtargetnum];
    char      associatedTargetCode[associatedtargetcode];
}UnifiedTargetTrans;


/** ***************************操控席位->协同指控席位*****************************************/

/**
 *     2.1.2 任务执行情况上报
 **/
typedef  struct _ReportTaskExecutionTrans{
    QString         operationalUnitNumber;
    QString         actionName;
    TaskSystemTimeTrans  reportTime;
    TaskActionType  taskActionType;
    TaskSystemTimeTrans  realStartTime;
    TaskSystemTimeTrans  realEndTime;
    int targetnum;
    QVector<TargetDamageInformationTrans> targetDamageInformation;
    QVector<TaskTargetInfoTrans>  taskTargetInfo;
}ReportTaskExecutionTrans;

/**
 *  2.1.2 侦察情报上报
 **/
typedef  struct _InvestigationIntelligenceTrans{
    quint32  operationalUnitCode;
    quint32  sensorNum;
    SensorType sensorType;
    int   targetNum;
    int   targetMotorState;
    double targetTypeRaliable;
    FriendFoeProperties friendFoeProperties;
    CoordinateSystemType coordinateSystemType;
    double   longtitude;
    double   latitude;
    double   altitude;
    char      dataAcquisitionTime[6];
    char      dataAcquisitionDay[8];
}InvestigationIntelligenceTrans;

/**
 * 态势信息
 **/
typedef  struct _SituationalInformationTrans
{
    quint16 senderCode;
    quint16 recvieCode;
    quint32 currentOperationalUnitCode;
    quint8  operationalUnitCode;
    float   speed;
    float   direction;
    double  longtitude;
    double  latitude;
    double  altitude;
    float   lineFireDirection;
}SituationalInformationTrans;

/**
 * 操控权限配置
 **/
typedef  struct _CKpermissionconfigTrans
{
    char infonum;
    QVector<PermissionTrans> permissiontrans;
}CKpermissionconfigTrans;

}


Q_DECLARE_METATYPE(Xtzkx::CooperativeTaskType)
Q_DECLARE_METATYPE(Xtzkx::CooperativeMemberType)
Q_DECLARE_METATYPE(Xtzkx::CooperativeRole)
Q_DECLARE_METATYPE(Xtzkx::CooperativeTaskActionType)
Q_DECLARE_METATYPE(Xtzkx::OperationalAreaDescription)
Q_DECLARE_METATYPE(Xtzkx::SensorType)
Q_DECLARE_METATYPE(Xtzkx::TargetType)
Q_DECLARE_METATYPE(Xtzkx::FriendFoeProperties)
Q_DECLARE_METATYPE(Xtzkx::CoordinateSystemType)
Q_DECLARE_METATYPE(Xtzkx::TaskActionType)
Q_DECLARE_METATYPE(Xtzkx::TargetDamageState)
Q_DECLARE_METATYPE(Xtzkx::TaskSystemTimeTrans)
Q_DECLARE_METATYPE(Xtzkx::TaskPostitonTrans)
Q_DECLARE_METATYPE(Xtzkx::TaskTargetTrans)
Q_DECLARE_METATYPE(Xtzkx::TargetDamageInformationTrans)
Q_DECLARE_METATYPE(Xtzkx::TaskTargetInfoTrans)
Q_DECLARE_METATYPE(Xtzkx::CoorperativeTaskIssuedTrans)
Q_DECLARE_METATYPE(Xtzkx::UnifiedTargetTrans)
Q_DECLARE_METATYPE(Xtzkx::ReportTaskExecutionTrans)
Q_DECLARE_METATYPE(Xtzkx::InvestigationIntelligenceTrans)
Q_DECLARE_METATYPE(Xtzkx::SituationalInformationTrans)
Q_DECLARE_METATYPE(Xtzkx::CKpermissionconfigTrans)
