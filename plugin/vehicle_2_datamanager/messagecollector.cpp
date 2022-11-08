#include "messagecollector.h"
#include "vehicle_2_datamanagerActivator.h"
#include <QDebug>
#include <defines/Vehicle1_data.h>

#define ASSERT_LEN_BREAK(x, y) if((x) > (y)){break;}

messagecollector::messagecollector(QObject *parent) : QObject(parent),m_Data(NULL)
{
    m_Data=new Datacollection;
    m_Data_Ptr.setpointee(m_Data);
    vehicle_2_datamanagerActivator::registerservice(this,"vehicle_2_Datamanageservice");
}

void messagecollector::store(QSharedPointer<QByteArray> sptba)
{
    if (sptba->length() <= 2) { return; }

    quint8 *ptCach = (quint8 *)sptba->data();
    if (ptCach[0] == 0xbb && ptCach[1] == 0xaa)
    {

    }
    return;
}

void messagecollector::execute(VEHICLE_2_DATA::PLUSED_SWITCH_DATA ptopic, QByteArray &sending_data)
{
    const char* ptData = m_protcols_data;
    int offset,size;

    size=0;
    offset=2;
    memcpy((void *)(ptData), (void *)&ptopic, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (VEHICLE_2_DATA::PLUSED_SWITCH_DATA::m_mode);
    memcpy((void *)(ptData), (void *)&ptopic.m_mode, offset);
    ptData += offset;
    size+=offset;

    sending_data.setRawData(m_protcols_data,size);
}

void messagecollector::execute(VEHICLE_2_DATA::MOTIONCOMMAND ptopic, QByteArray &sending_data)
{
    const char* ptData = m_control_cmd;
    int offset,size;

    size=0;
    offset=2;
    memcpy((void *)(ptData), (void *)&ptopic, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (VEHICLE_2_DATA::MOTIONCOMMAND::linear);
    memcpy((void *)(ptData), (void *)&ptopic.linear, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (VEHICLE_2_DATA::MOTIONCOMMAND::angular);
    memcpy((void *)(ptData), (void *)&ptopic.angular, offset);
    ptData += offset;
    size+=offset;

    sending_data.setRawData(m_control_cmd,size);
}
