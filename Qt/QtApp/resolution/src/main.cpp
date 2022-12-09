
#include <QApplication>
#include <QScreen>
#include <QSize>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>
#include <fstream>
using namespace std;


void f2()
{
    std::string str = "D:/code/remote-control/remotedesktop/build/output/Debug/img/2022-12-07T11:05:35.873_1920x1080.yuv";
    //G:\worknote\note\20221207\img
    std::string str2 = "G:\\worknote\\note\\20221207\\img\\2022-12-07T110535873_1920x1080.yuv";
    char p[1024] = { 0 };
    ofstream ofs;
    ofs.open(str2, std::ios::binary);
    bool bOpen =  ofs.is_open();
    if (!bOpen)
    {
        std::cout << "";
    }
    ofs.write(p, 1024);
    ofs.close();

    //
    std::wstring wstr;

    ofs.open(wstr);

}

void f1()
{
#ifdef DEBUG


#elif DEBUG2

#else


#endif // DEBUG


}

void fun()
{
    stringstream ss;
    int i = 123;
    string str = "987";
    ss << i;
    ss << str;
    string strDst;
    strDst = ss.str().c_str();
    cout << strDst << endl;

    std::stringstream ssLog;
    ssLog << str << " BasicSerialize : UnSupportVersion : " << i
        << ", dwBlockSize " << i << ", beginPos: " << i
        << " , endpos: " << i;
    cout << ssLog.str().c_str() << endl;

}


//根据first的值升序排序,如果first值相等，则根据second排序
bool CompareByFirst(pair<int, int> l, pair<int, int> r)
{
    if (l.first != r.first)
        return l.first < r.first;
    else if (l.first == r.first && l.second != r.second)
        return l.second < r.second;
    else
        return r.first < l.first;
}

//根据second的值升序排序
bool CompareBySecond(pair<int, int> l, pair<int, int> r)
{
    return l.second < r.second;
}


bool Equal(pair<int, int> l, pair<int, int> r)
{
    return (l.first == r.first && l.first == r.first);
}

class IsEqualALL {
public:
    explicit IsEqualALL(int UserVal) : User(UserVal) {}
    bool operator() (const std::pair<int, int>& element) const {
        return element.second == User;
    }
private:
    const int User;
};

void Getresolution()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QSize qSize = screen->size();
    qDebug() << qSize;
    QSizeF qSizeF = screen->physicalSize();
    qDebug() << qSizeF;

    /////////////////////////////
    //返回与应用程序所连接的窗口系统相关联的所有屏幕的列表。
    QList<QScreen*> screen_list = QGuiApplication::screens();
    for (int i = 0; i < screen_list.count(); i++)
    {
        qDebug() << screen_list.at(i)->size(); //此属性保存屏幕的像素分辨率
    }


}

void Match(int w = 1920, int h = 1080)
{
    (void)w;
    (void)h;

    vector<pair<int, int>> vec;
    vec.emplace_back(make_pair<int, int>(800, 600));
    vec.emplace_back(make_pair<int, int>(1024, 768));
    vec.emplace_back(make_pair<int, int>(1152, 864));
    vec.emplace_back(make_pair<int, int>(1280, 720));
    vec.emplace_back(make_pair<int, int>(1280, 768));
    vec.emplace_back(make_pair<int, int>(1280, 800));
    vec.emplace_back(make_pair<int, int>(1280, 960));
    vec.emplace_back(make_pair<int, int>(1280, 1024));
    vec.emplace_back(make_pair<int, int>(1360, 768));
    vec.emplace_back(make_pair<int, int>(1366, 768));
    vec.emplace_back(make_pair<int, int>(1440, 900));
    vec.emplace_back(make_pair<int, int>(1600, 900));
    vec.emplace_back(make_pair<int, int>(1600, 1024));
    vec.emplace_back(make_pair<int, int>(1600, 1200));
    vec.emplace_back(make_pair<int, int>(1680, 1050));

    {
        int nWDiff = -1, nHDiff = -1;
        for (const auto& item : vec)
        {
            if (item.first == w && item.second == h)
            {
                nWDiff = 0;
                nHDiff = 0;
                break;
            }

            nWDiff = std::abs(item.first - w);
            nHDiff = std::abs(item.second - h);


        }

    }

    std::sort(vec.begin(), vec.end(), CompareByFirst);
    cout << "根据first的值升序排序:" << endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ")" << endl;
    }

    qDebug() << "w: " << w << " h: " << h;

    {
        int nWW = -1, nHH = -1;
        int nWDiff = 9999, nHDiff = 9999;
        for (const auto& item : vec)
        {
            if (item.first == w && item.second == h)
            {
                nWDiff = 0;
                nHDiff = 0;
                nWW = item.first;
                nHH = item.second;
                break;
            }

            int nTmpDiff = std::abs(item.first - w);
            if (nTmpDiff < nWDiff)
            {
                nWDiff = nTmpDiff;
                nWW = item.first;
                nHH = item.second;
            }

        }

        qDebug() << "nWW: " << nWW << " nHH: " << nHH;
    }


}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Getresolution();

    //Match(1680, 1050);
    //Match(1920, 1080);
    Match(1440, 1080);


    cout << "----------------" << endl;
    fun();
    f1();
    f2();


    return a.exec();
}
