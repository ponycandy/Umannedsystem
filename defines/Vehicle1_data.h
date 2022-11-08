#pragma once
//do not declare pragma pack(1) here
//it will cause system crash
//do remember that pragma pack(4) is in default
#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QString>
#include <QImage>
#include <QSharedPointer>
namespace  IMAGE_DATA{

typedef struct _IMAGEDATA{
    uint32_t sec;
    uint32_t nsec;
    QSharedPointer<QImage> sp_t_image;
}_IMAGEDATA;
}
namespace V1DATA {
typedef  enum{
    NORMAL,
    EXCEPTION,
    WARNING_,
}vehicle_state;
typedef  enum{
    stop,
    remote,
    remote_automatation,
    automatation,
}control_mode;
typedef  enum{
    videoenable,
    videodisable,
}video_enable;
typedef  enum{
    lidarenable,
    lidardisable,
}lidar_enable;
typedef  enum{
    camera_state_turnon,
    camera_state_turnoff,
}camera_state;

typedef  struct _ROSTIMESTAMP{
    quint32     secs;
    quint32     nsecs;
}ROSTIMESTAMP;


/**
 *
 **/
typedef  struct   _LOCATIONINFO{
    double   longtitude;
    double   latitude;
    double   altitude;
    char      stitelite;
}LOCATIONINFO;
typedef  struct   _IMUDATA{
//    w a aw v
    float wx;
    float wy;
    float wz;
    float ax;
    float ay;
    float az;
    float awx;
    float awy;
    float awz;
    float vx;
    float vy;
    float vz;
}IMUDATA;
typedef  struct   _METAELEMENT4{
    float motor1;
    float motor2;
    float motor3;
    float motor4;
}METAELEMENT4;
typedef  struct   _SINGEPOINTDATA{
    float x;
    float y;
    float intensity;
    float timestamp;

}SINGEPOINTDATA;
typedef  struct   _ORIENTATION{
    _Float64 x;
    _Float64 y;
    _Float64 z;
    _Float64 w;
}ORIENTATION;
typedef  struct   _MOTORSTATE{

     METAELEMENT4 rpm;
     METAELEMENT4 current;
     METAELEMENT4 temperture;

}MOTORSTATE;
#pragma pack(push,1)
typedef  struct   _POINTCLOUD{
    short header;
    uint32_t secquense;
    ROSTIMESTAMP time;
    uint32_t pointnum;
    QVector<SINGEPOINTDATA> point_group;
}POINTCLOUD;
#pragma pack(pop)
typedef  struct   _SHARED_POINTCLOUD{
    QSharedPointer<POINTCLOUD> SH_POINTCLOUD;
}SHARED_POINTCLOUD;
typedef  struct   _TFTRANS{
    uint32_t secquense;
    ROSTIMESTAMP time;
    _Float64 x;
    _Float64 y;
    _Float64 z;
    ORIENTATION orien;
}TFTRANS;
typedef  struct   _DOWNSTREAM_INFO{
    short   header;
    vehicle_state   m_state;
    control_mode   m_mode;
    _Float32   electric_left;
    _Float32   omega_chasis;
    _Float32   lin_chasis;
    IMUDATA imu_data;
    MOTORSTATE motor_state;
    uint32_t left_odom;
    uint32_t right_odom;
    POINTCLOUD m_cloud;
    TFTRANS m_trans;
    LOCATIONINFO m_location;
    video_enable m_video_enable;
    lidar_enable m_lidar_enable;
    camera_state m_camera_state;
}DOWNSTREAM_INFO;
typedef  struct   _DOWNSTREAM_INFO_ISSUED{
    short   header;
    vehicle_state   m_state;
    control_mode   m_mode;
    _Float32   electric_left;
    _Float32   omega_chasis;
    _Float32   lin_chasis;
    IMUDATA imu_data;
    MOTORSTATE motor_state;
    uint32_t left_odom;
    uint32_t right_odom;
    POINTCLOUD m_cloud;
    TFTRANS m_trans;
    LOCATIONINFO m_location;
    video_enable m_video_enable;
    lidar_enable m_lidar_enable;
    camera_state m_camera_state;
}DOWNSTREAM_INFO_ISSUED;
typedef  struct   _USED_DATA{
    vehicle_state   m_state;
    control_mode   m_mode;
    _Float32   electric_left;
    _Float32   omega_chasis;
    _Float32   lin_chasis;
    IMUDATA imu_data;
    MOTORSTATE motor_state;
    uint32_t left_odom;
    uint32_t right_odom;
    POINTCLOUD m_cloud;
    TFTRANS m_trans;
    LOCATIONINFO m_location;
    video_enable m_video_enable;
    lidar_enable m_lidar_enable;
    camera_state m_camera_state;
}USED_DATA;
#pragma pack(push,1)
typedef  struct   _PLUSED_SWITCH_DATA{
    short   header;
    control_mode   m_mode;
}PLUSED_SWITCH_DATA;
#pragma pack(pop)
#pragma pack(push,1)
typedef  struct   _MOTIONCOMMAND{
    short   header;
    double linear;
    double angular;
}MOTIONCOMMAND;
#pragma pack(pop)
///** *************************** 操控席位<-协同指控席位*****************************************/
///**
// * 1.1 任务下发
// **/
//#define   TaskPositionNum   2
//#define   OperationUnitNumber 33
//#define   NameMaxNum  50
//#define   ProccessDescriptionNum  50
//#define associatedtargetnum 30
//#define associatedtargetcode 33

//typedef  struct  _CoorperativeTaskIssuedTrans{
//    char      operationalUnitNumber[OperationUnitNumber];
//    char      actionName[NameMaxNum];
//    CooperativeTaskType   cooperativeTaskType;
//    CooperativeMemberType cooperativeMemberType;
//    CooperativeRole       cooperativeRole;
//    CooperativeTaskActionType cooperativeTaskActionType;
//    TaskSystemTimeTrans     taskStartTime;
//    TaskSystemTimeTrans     taskCompleteTime;
//    OperationalAreaDescription  areaDescription;
//    quint32                 areaPostitonNum;///
//    QVector<TaskPostitonTrans>  areaPosition;
//    QString                 processDescription;
//    quint32                 taskPostitonNum;
//    QVector<TaskPostitonTrans>  processPosition;
//    quint32                 tasktargetnum;
//    QVector<TaskTargetTrans>     taskTarget;
//}CoorperativeTaskIssuedTrans;

/**
 * 1.2 统一目标（协同席位下发发给操控席位的目标信息）
 **/
//typedef  struct _UnifiedTargetTrans{
//    char   unifiedCode[32];
//    char   targetName[60];
//    TargetType  targetType;
//    double      longtitude;
//    double      latitude;
//    double      altitude;
//    TaskSystemTimeTrans time;
//    quint16     moveSpeed;
//    quint16     moveDirection;
//    float       targetThreat;
//    char      associatedTargetTable[associatedtargetnum];
//    char      associatedTargetCode[associatedtargetcode];
//}UnifiedTargetTrans;


/** ***************************操控席位->协同指控席位*****************************************/

/**
 *     2.1.2 任务执行情况上报
 **//*
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
}ReportTaskExecutionTrans;*/

/**
 *  2.1.2 侦察情报上报
 **/
//typedef  struct _InvestigationIntelligenceTrans{
//    quint32  operationalUnitCode;
//    quint32  sensorNum;
//    SensorType sensorType;
//    int   targetNum;
//    int   targetMotorState;
//    double targetTypeRaliable;
//    FriendFoeProperties friendFoeProperties;
//    CoordinateSystemType coordinateSystemType;
//    double   longtitude;
//    double   latitude;
//    double   altitude;
//    char      dataAcquisitionTime[6];
//    char      dataAcquisitionDay[8];
//}InvestigationIntelligenceTrans;

///**
// * 态势信息
// **/
//typedef  struct _SituationalInformationTrans
//{
//    quint16 senderCode;
//    quint16 recvieCode;
//    quint32 currentOperationalUnitCode;
//    quint8  operationalUnitCode;
//    float   speed;
//    float   direction;
//    double  longtitude;
//    double  latitude;
//    double  altitude;
//    float   lineFireDirection;
//}SituationalInformationTrans;

///**
// * 操控权限配置
// **/
//typedef  struct _CKpermissionconfigTrans
//{
//    char infonum;
//    QVector<PermissionTrans> permissiontrans;
//}CKpermissionconfigTrans;

//}


//Q_DECLARE_METATYPE(Xtzkx::CooperativeTaskType)
//Q_DECLARE_METATYPE(Xtzkx::CooperativeMemberType)
//Q_DECLARE_METATYPE(Xtzkx::CooperativeRole)
//Q_DECLARE_METATYPE(Xtzkx::CooperativeTaskActionType)
//Q_DECLARE_METATYPE(Xtzkx::OperationalAreaDescription)
//Q_DECLARE_METATYPE(Xtzkx::SensorType)
//Q_DECLARE_METATYPE(Xtzkx::TargetType)
//Q_DECLARE_METATYPE(Xtzkx::FriendFoeProperties)
//Q_DECLARE_METATYPE(Xtzkx::CoordinateSystemType)
//Q_DECLARE_METATYPE(Xtzkx::TaskActionType)
//Q_DECLARE_METATYPE(Xtzkx::TargetDamageState)
//Q_DECLARE_METATYPE(Xtzkx::TaskSystemTimeTrans)
//Q_DECLARE_METATYPE(Xtzkx::TaskPostitonTrans)
//Q_DECLARE_METATYPE(Xtzkx::TaskTargetTrans)
//Q_DECLARE_METATYPE(Xtzkx::TargetDamageInformationTrans)
//Q_DECLARE_METATYPE(Xtzkx::TaskTargetInfoTrans)
//Q_DECLARE_METATYPE(Xtzkx::CoorperativeTaskIssuedTrans)
//Q_DECLARE_METATYPE(Xtzkx::UnifiedTargetTrans)
//Q_DECLARE_METATYPE(Xtzkx::ReportTaskExecutionTrans)
//Q_DECLARE_METATYPE(Xtzkx::InvestigationIntelligenceTrans)
//Q_DECLARE_METATYPE(Xtzkx::SituationalInformationTrans)
//Q_DECLARE_METATYPE(Xtzkx::CKpermissionconfigTrans)
}
Q_DECLARE_METATYPE(V1DATA::POINTCLOUD);
Q_DECLARE_METATYPE(V1DATA::ROSTIMESTAMP);
Q_DECLARE_METATYPE(V1DATA::SINGEPOINTDATA);
Q_DECLARE_METATYPE(V1DATA::LOCATIONINFO);
Q_DECLARE_METATYPE(V1DATA::IMUDATA);
Q_DECLARE_METATYPE(V1DATA::PLUSED_SWITCH_DATA);
Q_DECLARE_METATYPE(V1DATA::MOTIONCOMMAND);
Q_DECLARE_METATYPE(IMAGE_DATA::_IMAGEDATA);


