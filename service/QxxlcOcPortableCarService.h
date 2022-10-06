#pragma once

#include <QtPlugin>
#include <QWidget>

struct QxxlcOcPortableCarService
{
public:
    /**
     * @brief ~QxxlcOcPortableCarService
     */
    virtual ~QxxlcOcPortableCarService() {}

    /**
     * @brief getPortableCarInfoWidget
     * @return
     */
    virtual QWidget* getPortableCarInfoWidget() = 0;

    /**
     * @brief getPortableCarViceControlWidget
     * @return
     */
    virtual QWidget* getPortableCarViceControlWidget() = 0;

    /**
     * @brief getPortableCarElectrocControlWidget
     * @return
     */
    virtual QWidget* getPortableCarElectrocControlWidget() = 0;

    /**
     * @brief getPortableCarGearControlWidget
     * @return
     */
    virtual QWidget* getPortableCarGearControlWidget() = 0;

    /**
     * @brief getPortableCarInfoWidget
     * @return
     */
    virtual void releasePortableCarInfoWidget() = 0;

    /**
     * @brief getPortableCarViceControlWidget
     * @return
     */
    virtual void releasePortableCarViceControlWidget() = 0;

    /**
     * @brief getPortableCarElectrocControlWidget
     * @return
     */
    virtual void releasePortableCarElectrocControlWidget() = 0;

    /**
     * @brief getPortableCarGearControlWidget
     * @return
     */
    virtual void releasePortableCarGearControlWidget() = 0;
};

Q_DECLARE_INTERFACE(QxxlcOcPortableCarService, "QxxlcOcPortableCarService")
