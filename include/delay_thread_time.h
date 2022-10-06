#include <QElapsedTimer>
#include <QCoreApplication>

void MyDelay_ms(int timer)
{
    QElapsedTimer et;  //QElapsedTimer常用于计算两个事件之间经过的时间
    et.start();

    while(et.elapsed()<timer)
    {
        QCoreApplication::processEvents(); //根据指定的标志处理调用线程的所有挂起事件，直到不再有要处理的事件为止。
    }
}
