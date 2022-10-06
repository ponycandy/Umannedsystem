
#ifndef OCU_CAR_CORESERVICE_H
#define OCU_CAR_CORESERVICE_H

#include <QObject>
#include "defines/OcuDefines.h"

class ocu_car_coreservice
{
public:
    virtual ~ocu_car_coreservice(){}

    /**
     * @brief setConnectStatus
     * @param connectStatus
     */
    virtual void setConnectStatus(bool connectStatus)=0;

    /**
     * @brief setControlStatus
     * @param controlStatus
     */
    virtual void setControlStatus(bool controlStatus)=0;

    /**
     * @brief addView
     * @param viewKind
     * @param view
     */
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

    /**
     * @brief changeMenu
     * @param oldMenu
     * @param newMenu
     * @param text
     */
    virtual void changeMenu(const QString &oldMenu, const QString &newMenu, const QString &text) = 0;

    /**
     * @brief changeMenu
     * @param num
     * @param newMenu
     * @param text
     */
    virtual void changeMenu(const int num,const QString &newMenu,const QString &text) = 0;

};
#define ocu_car_coreservice_iid "ocu_car_coreservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(ocu_car_coreservice,ocu_car_coreservice_iid  )
QT_END_NAMESPACE

#endif

