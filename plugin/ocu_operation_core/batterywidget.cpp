#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QWidget>

class BatteryWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief BatteryWidget
     * @param parent
     */
    explicit BatteryWidget(QWidget *parent = 0);

    ~BatteryWidget();

public:
    /**
     * @brief getMinValue
     * @return
     */
    double getMinValue()           const;

    /**
     * @brief getMaxValue
     * @return
     */
    double getMaxValue()           const;

    /**
     * @brief getValue
     * @return
     */
    double getValue()              const;

    /**
     * @brief getAlarmValue
     * @return
     */
    double getAlarmValue()          const;

    /**
     * @brief getStep
     * @return
     */
    double getStep()                const;

    /**
     * @brief getBorderRadius
     * @return
     */
    int getBorderRadius()           const;

    /**
     * @brief getBgRadius
     * @return
     */
    int getBgRadius()               const;

    /**
     * @brief getHeadRadius
     * @return
     */
    int getHeadRadius()             const;

    /**
     * @brief getBorderColorStart
     * @return
     */

    QColor getBorderColorStart()    const;

    /**
     * @brief getBorderColorEnd
     * @return
     */
    QColor getBorderColorEnd()      const;

    /**
     * @brief getAlarmColorStart
     * @return
     */
    QColor getAlarmColorStart()     const;

    /**
     * @brief getAlarmColorEnd
     * @return
     */
    QColor getAlarmColorEnd()       const;

    /**
     * @brief getNormalColorStart
     * @return
     */
    QColor getNormalColorStart()    const;

    /**
     * @brief getNormalColorEnd
     * @return
     */
    QColor getNormalColorEnd()      const;

    /**
     * @brief sizeHint
     * @return
     */
    QSize sizeHint()                const;

    /**
     * @brief minimumSizeHint
     * @return
     */
    QSize minimumSizeHint()         const;

    /**
     * @brief setRecharge
     * @param state
     */
    void  setRecharge(bool state);

public slots:
    /**
     * @brief setRange  设置范围值
     * @param minValue  最小值
     * @param maxValue  最大值
     */
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    /**
     * @brief setMinValue 设置最大最小值
     * @param minValue
     */
    void setMinValue(double minValue);

    /**
     * @brief setMaxValue
     * @param maxValue
     */
    void setMaxValue(double maxValue);

    /**
     * @brief setValue 设置电池电量值
     * @param value
     */
    void setValue(double value);

    /**
     * @brief setValue
     * @param value
     */
    void setValue(int value);

    /**
     * @brief setAlarmValue 设置电池电量警戒值
     * @param alarmValue
     */
    void setAlarmValue(double alarmValue);

    /**
     * @brief setAlarmValue
     * @param alarmValue
     */
    void setAlarmValue(int alarmValue);

    /**
     * @brief setStep
     * @param step
     */
    void setStep(double step);

    /**
     * @brief setStep
     * @param step
     */
    void setStep(int step);

    /**
     * @brief setBorderRadius 设置边框圆角角度
     * @param borderRadius
     */
    void setBorderRadius(int borderRadius);

    /**
     * @brief setBgRadius 设置背景圆角角度
     * @param bgRadius
     */
    void setBgRadius(int bgRadius);

    /**
     * @brief setHeadRadius 设置头部圆角角度
     * @param headRadius
     */
    void setHeadRadius(int headRadius);

    /**
     * @brief setBorderColorStart 设置边框渐变颜色
     * @param borderColorStart
     */
    void setBorderColorStart(const QColor &borderColorStart);

    /**
     * @brief setBorderColorEnd
     * @param borderColorEnd
     */
    void setBorderColorEnd(const QColor &borderColorEnd);

    /**
     * @brief setAlarmColorStart 设置电池电量报警时的渐变颜色
     * @param alarmColorStart
     */
    void setAlarmColorStart(const QColor &alarmColorStart);

    /**
     * @brief setAlarmColorEnd
     * @param alarmColorEnd
     */
    void setAlarmColorEnd(const QColor &alarmColorEnd);

    /**
     * @brief setNormalColorStart 设置电池电量正常时的渐变颜色
     * @param normalColorStart
     */
    void setNormalColorStart(const QColor &normalColorStart);

    /**
     * @brief setNormalColorEnd
     * @param normalColorEnd
     */
    void setNormalColorEnd(const QColor &normalColorEnd);

protected:
    /**
     * @brief paintEvent
     */
    void paintEvent(QPaintEvent *);

    /**
     * @brief drawBorder
     * @param painter
     */
    void drawBorder(QPainter *painter);

    /**
     * @brief drawBg
     * @param painter
     */
    void drawBg(QPainter *painter);

    /**
     * @brief drawHead
     * @param painter
     */
    void drawHead(QPainter *painter);

    /**
     * @brief drawRechargeIcon
     * @param painter
     */
    void drawRechargeIcon(QPainter *painter);

private:
    /**
     * @brief isRecharge 充电状态
     */
    bool   isRecharge;

    /**
     * @brief minValue 最小值
     */
    double minValue;

    /**
     * @brief maxValue 最大值
     */
    double maxValue;

    /**
     * @brief value 目标电量
     */
    double value;

    /**
     * @brief alarmValue 电池电量警戒值
     */
    double alarmValue;

    /**
     * @brief step 每次移动的步长
     */
    double step;

    /**
     * @brief borderRadius 边框圆角角度
     */
    int borderRadius;

    /**
     * @brief bgRadius 背景进度圆角角度
     */
    int bgRadius;

    /**
     * @brief headRadius 头部圆角角度
     */
    int headRadius;

    /**
     * @brief borderColorStart 边框渐变开始颜色
     */
    QColor borderColorStart;

    /**
     * @brief borderColorEnd 边框渐变结束颜色
     */
    QColor borderColorEnd;

    /**
     * @brief alarmColorStart 电池低电量时的渐变开始颜色
     */
    QColor alarmColorStart;

    /**
     * @brief alarmColorEnd 电池低电量时的渐变结束颜色
     */
    QColor alarmColorEnd;

    /**
     * @brief normalColorStart 电池正常电量时的渐变开始颜色
     */
    QColor normalColorStart;

    /**
     * @brief normalColorEnd 电池正常电量时的渐变结束颜色
     */
    QColor normalColorEnd;

    /**
     * @brief isForward 是否往前移
     */
    bool isForward;

    /**
     * @brief currentValue 当前电量
     */
    double currentValue;

    /**
     * @brief batteryRect 电池主体区域
     */
    QRectF batteryRect;

};

#endif // BATTERYWIDGET_H
