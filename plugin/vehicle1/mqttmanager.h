#ifndef MQTTMANAGER_H
#define MQTTMANAGER_H

#include <QObject>

class mqttmanager : public QObject
{
    Q_OBJECT
public:
    explicit mqttmanager(QObject *parent = nullptr);

signals:

};

#endif // MQTTMANAGER_H
