#pragma once

#include <QMap>
#include <QObject>
#include <QSize>
#include <QWidget>
#include <QVBoxLayout>
#include <QToolButton>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QToolButton>
#include "defines/OcuDefines.h"


class MenuManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief MenuManager
     * @param parent
     */
    explicit MenuManager(QObject *parent = nullptr);

    ~MenuManager();

    /**
     * @brief install
     * @param parent
     */
    void install(QWidget *parent);

    /**
     * @brief install
     * @param parent
     */
    void install(QHBoxLayout *parent);

    /**
     * @brief viewChanged
     * @param viewKind
     */
    void viewChanged(UcsDefines::UcsViewKind viewKind);

    /**
     * @brief changeMenuButton
     * @param oldMenu
     * @param newMenu
     * @param text
     */
    void changeMenuButton(const QString &oldMenu, const QString &newMenu, const QString &text);

    /**
     * @brief changeMenuButton
     * @param num
     * @param newMenu
     * @param text
     */
    void changeMenuButton(const int& num,const QString &newMenu, const QString &text);


private:
    /**
     * @brief setupUi
     */
    void setupUi(void);

    /**
     * @brief releaseUi
     */
    void releaseUi(void);

    /**
     * @brief setButton
     * @param index
     * @param text
     * @param topic
     * @param icon
     */
    void setButton(int index, const QString &text, const QString &topic, const QString &icon = QString());

    /**
     * @brief clearMenu
     */
    void clearMenu(void);

    /**
     * @brief buildMenu
     * @param viewKind
     */
    void buildMenu(UcsDefines::UcsViewKind viewKind);

private slots:
    /**
     * @brief onMenuClicked
     */
    void onMenuClicked(void);

private:
    /**
     * @brief m_leftWidget 左边按钮界面
     */
    QWidget *m_leftWidget;

    /**
     * @brief m_rightWidget 右边按钮界面
     */
    QWidget *m_rightWidget;

    /**
     * @brief m_leftLayout 左边按钮界面布局
     */
    QVBoxLayout *m_leftLayout;

    /**
     * @brief m_rightLayout 右边按钮界面布局
     */
    QVBoxLayout *m_rightLayout;

    /**
     * @brief m_buttons 按钮管理器
     */
    QMap<int, QToolButton *> m_buttons;
};
