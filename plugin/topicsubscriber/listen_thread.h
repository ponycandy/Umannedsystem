#ifndef LISTEN_THREAD_H
#define LISTEN_THREAD_H

#include <QObject>

class listen_thread : public QObject
{
    Q_OBJECT
public:
    explicit listen_thread(QObject *parent = nullptr);
    int on_listening=0;//make sure this type is atomic on your system
private slots:
    void startlisten();
    void stoplisten();

signals:

};

#endif // LISTEN_THREAD_H
