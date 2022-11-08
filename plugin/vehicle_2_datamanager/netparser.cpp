#include "netparser.h"
#include "vehicle1_datamanagerActivator.h"

bool Netparser::execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO &ptTopic)
{
    bool rslt = false;
//    qDebug("%X",data[2]);
//    vehicle_1_1Datamanageservice *m_sercice=vehicle1_datamanagerActivator::getService<vehicle_1_1Datamanageservice>("vehicle_1_1Datamanageservice");

////    vehicle_1_1Datamanageservice
//    V1DATA::DOWNSTREAM_INFO_ISSUED rawTopic;
////    Xtzkx::CoorperativeTaskIssued rawTopic;
////    memset((void *)&rawTopic, 0x00, sizeof(Xtzkx::CoorperativeTaskIssued));
//    if(rslt = execute(data, len, rawTopic))
//    {
//        m_sercice->setrecievedata(rawTopic);
//    }

////    }

    return rslt;
}

bool Netparser::execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO_ISSUED &ptTopic)
{

}
