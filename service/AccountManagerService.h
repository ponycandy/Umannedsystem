#pragma once

#include <QtPlugin>

#include "icd/OcuControlICDTransStruct.h"

struct AccountManagerService
{
public:
    virtual ~AccountManagerService() {}

    /**
     * @brief getAllUserInfo
     * @return
     */
    virtual QMap<QString,UserInfo> getAllUserInfo()= 0;

    /**
     * @brief getUserInfoByName
     * @param userName
     * @param data
     * @return
     */
    virtual bool getUserInfoByName(QString &userName, UserInfo &data) = 0;

    /**
     * @brief editUserInfo
     * @param data
     */
    virtual void editUserInfo(const UserInfo &data) = 0;

    /**
     * @brief setAdminUsetInfo
     * @param userInfo
     */
    virtual void setAdminUsetInfo(const UserInfo &userInfo) = 0;

    /**
     * @brief setWaringMessageAndShow
     * @param message
     * @return
     */
    virtual bool setWaringMessageAndShow(const QString &message) = 0;

    /**
     * @brief showWaringMessageCancelButton
     */
    virtual void showWaringMessageCancelButton() = 0;


    /**
     * @brief setCurrentOperatorRole
     * @param role
     */
    virtual void setCurrentOperatorRole(const OperatorRole role) = 0;

    /**
     * @brief setCurrentOperatorRole
     * @param role
     */
    virtual OperatorRole getCurrentOperatorRole() = 0;
};

Q_DECLARE_INTERFACE(AccountManagerService, "AccountManagerService")
