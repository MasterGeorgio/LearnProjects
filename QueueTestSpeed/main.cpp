#include <QCoreApplication>

#include <algorithm>
#include <queue>

#include <QQueue>
#include <QElapsedTimer>
#include <QDebug>

const size_t g_dwItem = 1000000;

std::queue<size_t> queueStl;

QQueue<size_t> queueQt;

QElapsedTimer timer;


void TestPush_queue() {
    qDebug() << "--- TestPush_QQueue() ---";

    timer.start();

    qDebug() << "TestPush_queue() begin: " << timer.elapsed();
    for (size_t i = 0; i < g_dwItem; i++)
        queueStl.push(i);
    QElapsedTimer timerRes = timer;

    // Conclusion
    qDebug() << "TestPush_queue() end, msec:" << timerRes.elapsed();
    qDebug() << "TestPush_queue() end, nsec:" << timerRes.nsecsElapsed() << endl;
}

void TestPush_QQueue() {
    qDebug() << "--- TestPush_QQueue() ---";

    timer.start();

    qDebug() << "TestPush_QQueue() begin:" << timer.elapsed();
    for (size_t i = 0; i < g_dwItem; i++)
        queueQt.enqueue(i);
    QElapsedTimer timerRes = timer;

    // Conclusion
    qDebug() << "TestPush_QQueue() end, msec:" << timerRes.elapsed();
    qDebug() << "TestPush_QQueue() end, nsec:" << timerRes.nsecsElapsed() << endl;
}

void TestPop_queue() {
    qDebug() << "--- TestPop_queue() ---";

    timer.start();

    qDebug() << "TestPop_queue() begin: " << timer.elapsed();
    for (size_t i = 0; i < g_dwItem; i++)
        queueStl.pop();
    QElapsedTimer timerRes = timer;

    // Conclusion
    qDebug() << "TestPop_queue() end, msec:" << timerRes.elapsed();
    qDebug() << "TestPop_queue() end, nsec:" << timerRes.nsecsElapsed() << endl;
}

void TestPop_QQueue() {
    qDebug() << "--- TestPop_QQueue() ---";

    timer.start();

    qDebug() << "TestPop_QQueue() begin:" << timer.elapsed();
    for (size_t i = 0; i < g_dwItem; i++)
        queueQt.dequeue();
    QElapsedTimer timerRes = timer;

    // Conclusion
    qDebug() << "TestPop_QQueue() end, msec:" << timerRes.elapsed();
    qDebug() << "TestPop_QQueue() end, nsec:" << timerRes.nsecsElapsed() << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestPush_queue();

    TestPush_QQueue();

    TestPop_queue();

    TestPop_QQueue();

    system("pause");
    return a.exec();
}
