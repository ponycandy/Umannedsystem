#include "listen_thread.h"
#include "ros/ros.h"
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QtDebug>
listen_thread::listen_thread(QObject *parent) : QObject(parent)
{

}
void listen_thread::startlisten()
{
   // ros::Rate loop_rate(1);
    on_listening=1;
    while(on_listening==1)
    {

        QElapsedTimer et;
        et.start();
        ros::spinOnce();

        while(et.elapsed()<100)//ms
        {
             QCoreApplication::processEvents();
        }
    }


}

void listen_thread::stoplisten()
{
    on_listening=0;
}
