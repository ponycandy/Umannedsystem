#ifndef NETPARSER_H
#define NETPARSER_H
#include <QObject>
#include <defines/Vehicle1_data.h>
class Netparser: public QObject
{
     Q_OBJECT
public:
    explicit Netparser(QObject *parent = nullptr);
    static bool execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO &ptTopic);
    static bool execute(const char *data, int len, V1DATA::DOWNSTREAM_INFO_ISSUED &ptTopic);

//    static Xtzkx::TaskSystemTimeTrans execute(Xtzkx::TaskSystemTime *ptTopic);
//    static Xtzkx::TaskSystemTimeTrans execute(Xtzkx::TaskSystemTime_t2 *ptTopic);
};

#endif // NETPARSER_H
