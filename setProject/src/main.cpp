#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStyleFactory>
#include <QDebug>
#include <QMutex>

class Count{
public:
    Count() {
        m_Index = 0;
    }

    void Increment() {
        QMutexLocker locker(&m_Mutex);
        ++m_Index;
    }

    void Decrement() {
        QMutexLocker locker(&m_Mutex);
        --m_Index;
    }

    int Value() const {
        QMutexLocker locker(&m_Mutex);
        return m_Index;
    }

    ~Count() {

    }

private:
    mutable QMutex m_Mutex;
    int m_Index;
};

void testMutex()
{
    Count cc;
    

}

void test()
{
    //output support style
    foreach (const QString mFactory, QStyleFactory::keys()) {
       qDebug() << mFactory;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile data("output.txt");
    if(data.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream out(&data);
        out<<"Result: "<<qSetFieldWidth(10)<<left<<3.14<<2.7;
    }

    test();
    return a.exec();
}
