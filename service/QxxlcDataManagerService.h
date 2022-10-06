#pragma once

#include <QtPlugin>
#include "icd/QxxlcIcdTransStruct.h"

struct QxxlcDataManagerService
{
public:
    /**
     * @brief ~QxxlcDataManagerService
     */
    virtual ~QxxlcDataManagerService() {}

    /**
     * @brief setdpxs 底盘限速，值域，0.0～100.0，单位是m/s
     * @param dpxs
     */
    virtual void setdpxs(float dpxs) = 0;

    /**
     * @brief setdpsn_flag 底盘使能标志，值域，00H-底盘使能为假、01H-底盘使能为真
     * @param dpsn_flag
     */
    virtual void setdpsn_flag(unsigned char dpsn_flag) = 0;

    /**
     * @brief setgear 档位命令，值域，00H-倒档，01H-前进档，02H-空档、03H-中心转向
     * @param gear
     */
    virtual void setgear(unsigned char gear) = 0;

    /**
     * @brief setdlms 动力模式，值域，00H-纯电动模式，01H-混合动力模式
     * @param dlms
     */
    virtual void setdlms(unsigned char dlms) = 0;

    /**
     * @brief setDjms 电机模式，值域，00H-转矩模式，01H-转速模式
     * @param djms
     */
    virtual void setDjms(const quint8 djms) = 0;

    /**
     * @brief setCEnginePower 发动机发电功率,值域，0-80KW
     * @param djms
     */
    virtual void setCEnginePower(const quint8 djms) = 0;

    /**
     * @brief setjmzhsh 静默值守模式,值域，00H-非值守模式，01H-值守模式   （值守模式后不能进行其他操作，直到启动非值守模式
     * @param jmzhsh
     */
    virtual void setjmzhsh(unsigned char jmzhsh) = 0;

    /**
     * @brief setparking 驻车命令，值域，00H-无驻车制动，01H-驻车制动，预留，不使用。
     * @param parking
     */
    virtual void setparking(unsigned char parking) = 0;

    /**
     * @brief setCzsn 车姿使能，值域，00H-下使能，01H-上使能
     * @param value
     */
    virtual void setCzsn(const quint16 value) = 0;

    /**
     * @brief setCzms 车姿控制模式（轮式），值域，00H-手动模式，01H-自动模式
     * @param value
     */
    virtual void setCzms(const quint16 value) = 0;

    /**
     * @brief setCzgysd 车姿高压上电命令（轮式），值域，00H-高压下电，01H-高压上电
     * @param value
     */
    virtual void setCzgysd(const quint16 value) = 0;


    /** 辅助控制命令*/

    /**
     * @brief setgeneratorController 设备：发电机控制器；定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setGeneratorController(const quint16 value) = 0;

    /**
     * @brief setvehicleAttitudeController 设备：车姿控制器； 定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setVehicleAttitudeController(const quint16 value) = 0;

    /**
     * @brief setimageRadio 设备：电台；定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setImageRadio(const quint16 value) = 0;

    /**
     * @brief setremoteDriving12V 设备：遥控驾驶12V；定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setRemoteDriving12V(const quint16 value) = 0;

    /**
     * @brief setautonomousDriving12V 设备：自主驾驶12V；定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setAutonomousDriving12V(const quint16 value) = 0;

    /**
     * @brief setsurveillanceCameraAssembly 设备：监视相机组件;定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setSurveillanceCameraAssembly(const quint16 value) = 0;

    /**
     * @brief setdecisionPerceptionComputers 设备：决策与感知计算机；定义：1表示开启，0表示关闭；
     * @param value
     */
    virtual void setDecisionPerceptionComputers(const quint16 value) = 0;

    /**
     * @brief setinertialNavigation 设备：惯导；定义：1表示开启，0表示关闭；
     * @param inertialNavigation
     */
    virtual void setinertialNavigation(quint16 inertialNavigation) = 0;

    /**
     * @brief settrumpet 设备：喇叭；定义：1表示开启，0表示关闭；
     * @param trumpet
     */
    virtual void settrumpet(quint16 trumpet) = 0;

    /**
     * @brief setoutlineMarkerLamps 设备：示廓灯；定义：1表示开启，0表示关闭；
     * @param outlineMarkerLamps
     */
    virtual void setoutlineMarkerLamps(quint16 outlineMarkerLamps) = 0;

    /**
     * @brief setdippedHeadlight 设备：近光灯；定义：1表示开启，0表示关闭；
     * @param dippedHeadlight
     */
    virtual void setdippedHeadlight(quint16 dippedHeadlight) = 0;

    /**
     * @brief sethighBeam 设备：远光灯；定义：1表示开启，0表示关闭；
     * @param highBeam
     */
    virtual void sethighBeam(quint16 highBeam) = 0;





    /**
     * @brief getEmergencyStop  设备：急停；定义：1表示开启急停，0表示关闭急停；
     * @return
     */
    virtual int getEmergencyStop() = 0;

    /**
     * @brief setEmergencyStop 设备：急停；定义：1表示开启急停，0表示关闭急停；
     * @param value
     */
    virtual void setEmergencyStop(quint16 value) = 0;

    /** *车姿手动调节命令*/

    /**
      * @brief setVehicleAttitudeManualRightThree 设备：手动右3调节指令; 定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualRightThree(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualRightTwo 设备：手动右2调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualRightTwo(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualRightOne 设备：手动右1调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualRightOne(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualLeftThree 设备：手动左3调节指令; 定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualLeftThree(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualLeftTwo  设备：手动左2调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualLeftTwo(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualLeftOne 设备：手动左1调节指令；定义：00-停止，01-上升,10-下降(高位在左)；
      * @param value
      */
    virtual void setVehicleAttitudeManualLeftOne(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualBackWheel  设备：手动后轴提轮；定义：1-提轮，0-停止；
      * @param value
      */
    virtual void setVehicleAttitudeManualBackWheel(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualMiddleWheel 设备：手动中轴提轮；定义：1-提轮，0-停止；
      * @param value
      */
    virtual void setVehicleAttitudeManualMiddleWheel(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualFrontWheel 设备：手动前轴提轮；定义：1-提轮，0-停止；
      * @param value
      */
    virtual void setVehicleAttitudeManualFrontWheel(const quint16 value) = 0;

    /**
      * @brief setVehicleAttitudeManualSpringLatching 设备：手动弹簧闭锁；定义：1-手动弹簧闭锁，0-开锁；
      * @param value
      */
    virtual void setVehicleAttitudeManualSpringLatching(const quint16 value) = 0;

    /** **自动调节命令*/
    /**
     * @brief setczkz_auto_cmd
     * @param czkz_auto_cmd
     */
    virtual void setczkz_auto_cmd(unsigned int czkz_auto_cmd) = 0;

    /**
     * @brief setOilPumpCmd 油缸动作指令，值域，00H-等待，01H-缩短，02H-伸长
     * @param value
     */
    virtual void setOilPumpCmd(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectLeftOne 设备：油缸伸缩选择-左1 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectLeftOne(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectLeftTwo 设备：油缸伸缩选择-左2 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectLeftTwo(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectLeftThree 设备：油缸伸缩选择-左3 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectLeftThree(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectRightOne 设备：油缸伸缩选择-右1 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectRightOne(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectRightTwo 设备：油缸伸缩选择-右2 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectRightTwo(const quint16 value) = 0;

    /**
     * @brief setOilPumpSelectRightThree 设备：油缸伸缩选择-右3 定义：1＝选中；0=未选中
     * @param value
     */
    virtual void setOilPumpSelectRightThree(const quint16 value) = 0;

    /**
     * @brief setczkz_tsms_cmd 底盘考核越野特殊车姿控制命令
     * @param czkz_tsms_cmd
     */
    virtual void setczkz_tsms_cmd(unsigned char czkz_tsms_cmd) = 0;

    /**
     * @brief setCross 垂直墙模式，值域，00H-正常模式，01H-垂直墙模式
     * @param value
     */
    virtual void setCross(const quint16 value) = 0;

    /**
     * @brief setthrottle 油门控制量，值域，0~100%
     * @param throttle
     */
    virtual void setthrottle(unsigned int throttle) = 0;

    /**
     * @brief setbraking  制动控制量，值域,0~100%
     * @param braking
     */
    virtual void setbraking(unsigned int braking) = 0;

    /**
     * @brief steering 转向控制量，值域-100%~100%
     * @param steering
     */
    virtual void steering(int steering) = 0;

    /**
     * @brief sete_stop_flag 紧急停车标志，值域，00H-不紧急停车，01H-紧急停车
     * @param e_stop_flag
     */
    virtual void sete_stop_flag (unsigned char e_stop_flag) = 0;

    /**
     * @brief setMCRemoteDriverPara
     */
    virtual void setMCRemoteDriverPara() = 0;

    /**
     * @brief getChassisOperationData 获取底盘操作数据
     * @param chassisOperationData
     */
    virtual void getChassisOperationData(Qxxlc::ICD_P_DPCZ_CMD_MSG_TRANS& chassisOperationData) = 0;

    /**
     * @brief getRemoteDriverPara get  remote driver parameter
     * @param remoteDriverPara
     */
    virtual void getRemoteDriverPara(Qxxlc::ICD_P_YKJS_CMD_MSG_TRANS& remoteDriverPara) = 0;

    /**
     * @brief getDriverPara
     * @param para
     */
    virtual void getDriverPara(Qxxlc::DriverWidgetPara&  para) = 0;

    /**
     * @brief getCurrentTaskNum
     * @return
     */
    virtual int  getCurrentTaskNum() = 0;

    /**
     * @brief getCurrentDlms
     * @return
     */
    virtual int getCurrentDlms() = 0;

    /**
     * @brief getCurrentGear
     * @return
     */
    virtual int getCurrentGear() = 0;

    /**
     * @brief getTargetNumber 目标编号
     * @return
     */
    virtual int getTargetNumber() = 0;

    /**
     * @brief setOperationMode
     * @param value
     */
    virtual void  setOperationMode(const Qxxlc::DjxlcOperationMode mode) = 0;

    /**
     * @brief getOcuToChassisParaTrans
     * @param topic
     */
    virtual void  getOcuToChassisParaTrans(Qxxlc::OcuToChassisParaTrans& topic) = 0;

    /**
     * @brief loadHistoryRecordData
     * @param fileName
     * @return
     */
    virtual QVector<strPose> loadHistoryRecordData(QString fileName) = 0;

    /**
     * @brief setPathFileSettingStepValue
     * @param value
     */
    virtual void setPathFileSettingStepValue(int value) = 0;

    /**
      * @brief writePathRecordData
      */
    virtual void writePathRecordData() = 0;
};

Q_DECLARE_INTERFACE(QxxlcDataManagerService, "QxxlcDataManagerService")
