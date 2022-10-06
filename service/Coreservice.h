
#ifndef CORESERVICE_H
#define CORESERVICE_H

#include <QObject>
#include <defines/OcuDefines.h>
class Coreservice
{
public:
    virtual ~Coreservice(){}
    virtual void addView(UcsDefines::UcsViewKind viewKind, QWidget *view) = 0;

    /**
           * @brief changeView
           * @param viewKind
           */
    virtual void changeView(UcsDefines::UcsViewKind viewKind) = 0;

    /**
           * @brief changeView
           * @param viewKind
           */
    virtual UcsDefines::UcsViewKind getCurrentView() = 0;


    virtual void setCurCarIndex(UcsDefines::UcsViewIndex index) = 0;

    virtual UcsDefines::UcsViewIndex getCurCarIndex() = 0;

    /**
        * @brief setWdigetSwitch
        * 0：标识视频界面是第一个屏，主控界面为第二个屏
        * 1：标识视频界面是第二个屏，主控界面为第一个屏
        */
    virtual void setWdigetSwitch(int type) = 0;

};
#define Coreservice_iid "Coreservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(Coreservice,Coreservice_iid  )
QT_END_NAMESPACE

#endif

