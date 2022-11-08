#pragma once
#include <stdint.h>
#include <QVector>

namespace Xtzkx
{

#pragma pack(1)

/**
 *
 **/
typedef  struct _TaskSystemTime{
    short   wYear;         /// 年
    unsigned char     wMonth;        /// 月 。1月份则值为1，2月份则值为2，…..
    char     wDay;          /// 日
    char     wHour;         /// 时
    char     wMinute;       /// 分
    char     wSecond;       /// 秒
}TaskSystemTime;

typedef  struct _TaskSystemTime_t2{
    unsigned short   wYear;         /// 年
    unsigned short     wMonth;        /// 月 。1月份则值为1，2月份则值为2，…..
    unsigned short     wDay;          /// 日
    unsigned short     wHour;         /// 时
    unsigned short     wMinute;       /// 分
    unsigned short     wSecond;       /// 秒
}TaskSystemTime_t2;
/**
 *
 **/
typedef  struct   _TaskPositon{
    quint32   longtitude;
    quint32   latitude;
    quint32   altitude;
    char      attribute;
}TaskPostiton;

typedef  struct  _Permission{
    char UVID[33];
    char UVIP[22];
    char ckxwID;
}Permission;

/**
 *
 **/
typedef  struct   _TaskTarget{
    quint32      targetNum;
    char         targetName[20];
    char         targetType;
    quint32      longtitude;
    quint32      latitude;
    quint32      altitude;
}TaskTarget;


/**
 *
 **/
typedef  struct  _TargetDamageInformation{
    double      targetNum;
    char      targetDamageState;
}TargetDamageInformation;

/**
 *
 **/
typedef  struct   _TaskTargetInfo{
    int      targetCount;
    int      targetNum;
    int      targetType;
    quint32      longtitude;
    quint32      latitude;
    quint32      altitude;
    double      moveDirection;
    double      distance;
}TaskTargetInfo;

/** *************************** 操控席位<-协同指控席位*****************************************/
/**
 * 1.1 任务下发
 **/
#define   TaskPositionNum   30
#define   OperationUnitNumber 33
#define   NameMaxNum  50
#define   ProccessDescriptionNum  50
#define   TaskTargetNum 30
#define   targetdamagenum 30
#define   targetinfonum 30
#define associatedtargetnum 30
#define associatedtargetcode 33
#define permissionnum 10

typedef struct _Header_Xtzkx{
    short _header;
    short _header_length;
    short _header_type;
}header_Xtzkx;

typedef  struct  _CoorperativeTaskIssued{
    _Header_Xtzkx header_Xtzkx;
    char      operationalUnitName[OperationUnitNumber];
    char      actionName[NameMaxNum];
    int       cooperativeTaskType;
    char       cooperativeMemberType;
    char       cooperativeRole;
    unsigned char   cooperativeTaskActionType;
    TaskSystemTime     taskStartTime;
    TaskSystemTime     taskCompleteTime;
    char       areaDescription;
    quint32       areaPointNum;
    TaskPostiton  taskAreaPoint[TaskPositionNum];
    char      processDescription[ProccessDescriptionNum];
    quint32       taskPostitonNum;
    TaskPostiton  taskPosition[TaskPositionNum];
    int tasktargetnum;
    TaskTarget  taskTarget[TaskTargetNum];
}CoorperativeTaskIssued;

/**
 * 1.2 统一目标（协同席位下发发给操控席位的目标信息）
 **/
typedef  struct _UnifiedTarget{
    _Header_Xtzkx header_Xtzkx;
    char   unifiedCode[32];
    char   targetName[60];
    quint32      targetType;
    quint32  longtitude;
    quint32  latitude;
    quint32  altitude;
    TaskSystemTime_t2 time;
    unsigned short  moveSpeed;
    unsigned short  moveDirection;
    float  targetThreat;
    char      associatedTargetTable[associatedtargetnum];
    char      associatedTargetCode[associatedtargetcode];
}UnifiedTarget;


/** ***************************操控席位->协同指控席位*****************************************/

/**
 *     2.1.1 任务执行情况上报
 **/

typedef  struct _ReportTaskExecution{
    _Header_Xtzkx header_Xtzkx;
    char         operationalUnitNumber[OperationUnitNumber];
    char         actionName[NameMaxNum];
    TaskSystemTime  reportTime;
    unsigned char             taskActionType;
    TaskSystemTime  realStartTime;
    TaskSystemTime  realEndTime;
    TargetDamageInformation targetDamageInformation[targetdamagenum];
    TaskTargetInfo  taskTargetInfo[targetinfonum];
}ReportTaskExecution;

/**
 *  2.1.2 侦察情报上报
 **/
typedef  struct _InvestigationIntelligence{
    _Header_Xtzkx header_Xtzkx;
    int  operationalUnitCode;
    int  sensorNum;
    int      sensorType;
    int      targetNum;
    bool      targetMotorState;
    int targetType;
    float  targetTypeRaliable;
    int      friendFoeProperties;
    int      coordinateSystemType;
    quint32  longtitude;
    quint32  latitude;
    quint32  altitude;
    char      dataAcquisitionTime[6];
    char      dataAcquisitionDay[8];
}InvestigationIntelligence;

/**
 * 态势信息
 **/
typedef  struct _SituationalInformation
{
    _Header_Xtzkx header_Xtzkx;
    quint16 senderCode;
    quint16 recvieCode;
    quint32 currentOperationalUnitCode;
    quint16  operationalUnitCode;
    float speed;
    float direction;
    quint32 longtitude;
    quint32 latitude;
    quint32 altitude;
    float lineFireDirection;
}SituationalInformation;



/**
 * 操控权限配置
 **/
typedef  struct _CKpermissionconfig
{
    _Header_Xtzkx header_Xtzkx;
    char infonum;
    Permission permission[permissionnum];
}CKpermissionconfig;

#pragma pack()

}
