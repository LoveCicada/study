#include <QtCore/QCoreApplication>
#include <QWaitCondition>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <iostream>

const int DataSize = 100;
const int BufferSize = 1;
char buffer[BufferSize];

QWaitCondition QWCIsNotFull;
QWaitCondition QWCIsNotEmpty;
QMutex mutex;
int usedSpace = 0;

class Producer : public QThread
{
protected:
	void run()
	{
		for (int i = 0; i < DataSize; ++i)
		{
			QMutexLocker lk(&mutex);
			while (usedSpace == BufferSize)
			{
				QWCIsNotFull.wait(&mutex);
			}
			++usedSpace;
			qDebug() << "Producer = " << usedSpace;
			QWCIsNotEmpty.wakeAll();
		}
	}
};

class Consumer : public QThread
{
protected:
	void run()
	{
		for (int i = 0; i < DataSize; ++i)
		{
			QMutexLocker lk(&mutex);
			while (0 == usedSpace)
			{
				QWCIsNotEmpty.wait(&mutex);
			}
			--usedSpace;
			qDebug() << "Consumer = " << usedSpace;
			QWCIsNotFull.wakeAll();
		}
		qDebug() << "end";
	}
};

void test()
{
	Producer pd;
	Consumer cs;
	pd.start();
	cs.start();
	pd.wait();
	cs.wait();
}

int main(int argc,char* argv[])
{
	QCoreApplication a(argc, argv);

	test();

	return a.exec();
}
