#ifndef MQTTPUBLISHER_H
#define MQTTPUBLISHER_H
#include <QObject>
#include <service/eventservice.h>
#include "event/eventype.h"
#include "pubthread.h"
#include <QThread>
#include <subthread.h>
class mqttpublisher : public QObject,public EventService
{
    Q_OBJECT
    QThread upload_thread;
    QThread download_thread;

public:
    explicit mqttpublisher(QObject *parent = nullptr);
    void EventTriggeres(XTLevent event) override;
     char* topicname;
     subthread *n_thread;
     pubthread *m_thread;

signals:
    void sig_setNet(XTLevent event);
    void sig_start_node();
   void sig_stop_node();
private slots:
    void slot_setNet(XTLevent event);

};

#endif // MQTTPUBLISHER_H
