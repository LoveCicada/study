
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
#include <string>
using namespace std;


//////////////////////////////////////////////////////////
void testInt()
{
    int nSize1 = sizeof(unsigned long);
    int nSize2 = sizeof(unsigned long int);
    int nSize3 = sizeof(unsigned long long);
    int nSize4 = sizeof(unsigned int);
    int nSize5 = sizeof(int32_t);

    cout << "unsigned long: " << nSize1 << endl;
    cout << "unsigned long int: " << nSize2 << endl;
    cout << "unsigned long long: " << nSize3 << endl;
    cout << "unsigned int: " << nSize4 << endl;
    cout << "int32_t: " << nSize5 << endl;
}



//////////////////////////////////////////////////////////

struct Rect
{
    int nW;
    int nH;
};

void CalcResultionRectSize(const Rect& src, Rect& dst, int resW = 1680, int resH = 1050)
{
    double wRate = (double)src.nW / (double)resW;
    double hRate = (double)src.nH / (double)resH;

    //double minRate = wRate < hRate ? wRate : hRate;
    if (wRate > hRate)
    {
        //! dst.nH = src.nH / resH * resH = src.nH;
        dst.nH = hRate * resH;
        
        //! dst.nW = resW * resH / resH;
        dst.nW = (resW * dst.nH / resH);
    }
    else
    {
        //! dst.nW = src.nW / resW * resW = src.nW;
        dst.nW = wRate * resW;

        //! 
        dst.nH = (resH * dst.nW / resW);
    }

    cout << "src: w= " << src.nW << " h= " << src.nH
        << " dst: w= " << dst.nW << " h= " << dst.nH
        << endl;
}

void CalcResultionRectSizeEx(const Rect& src, Rect& dst, int resW = 1680, int resH = 1050)
{
    double wRate = (double)src.nW / (double)resW;
    double hRate = (double)src.nH / (double)resH;

    //double minRate = wRate < hRate ? wRate : hRate;
    if (wRate > hRate)
    {
        dst.nH = src.nH;
        dst.nW = (resW * src.nH / resH);
    }
    else
    {
        dst.nW = src.nW;
        dst.nH = (resH * src.nW / resW);
    }

    cout << "src: w= " << src.nW << " h= " << src.nH
        << " dst: w= " << dst.nW << " h= " << dst.nH
        << endl;
}

void RenderRect(const QRect& resRt, const QRect& srcRt, QRect& dstRt)
{
    double wRate = (double)srcRt.width() / (double)resRt.width();
    double hRate = (double)srcRt.height() / (double)resRt.height();

    if (wRate > hRate)
    {
        dstRt.setHeight(srcRt.height());
        dstRt.setWidth(resRt.width() * srcRt.height() / resRt.height());
    }
    else
    {
        dstRt.setWidth(srcRt.width());
        dstRt.setHeight(resRt.height() * srcRt.width() / resRt.width());
    }

    qDebug() << "srcRt: " << srcRt;
    qDebug() << "dstRt: " << dstRt;

    //! vertical
    if (dstRt.height() < srcRt.height())
    {
        int nYoffset = (srcRt.height() - dstRt.height()) / 2;
        dstRt.setTop(dstRt.top() + nYoffset);
        dstRt.setBottom(dstRt.bottom() - nYoffset);
    }

    //! horizon
    if (dstRt.width() < srcRt.width())
    {
        int nXoffset = (srcRt.width() - dstRt.width()) / 2;
        dstRt.setLeft(dstRt.left() + nXoffset);
        dstRt.setRight(dstRt.right() - nXoffset);
    }

    qDebug() << "srcRt: " << srcRt;
    qDebug() << "dstRt: " << dstRt;

}

void testRectSize()
{
    Rect src, dst;
    src.nW = 1339;
    src.nH = 799;
    CalcResultionRectSizeEx(src, dst);

    src.nW = 1593;
    src.nH = 963;
    CalcResultionRectSizeEx(src, dst);
}

void testRenderRect()
{
    QRect resRt;
    resRt.setWidth(1680);
    resRt.setHeight(1050);
    QRect srcRt(0, 0, 1920, 1080);
    QRect dstRt;
    RenderRect(resRt, srcRt, dstRt);
}

void testRect2()
{
    qDebug() << "---------------------";
    QRect rt(0, 0, 1680, 1050);
    qDebug() << "rt: " << rt;

    int nXoffset = 20;
    rt.adjust(nXoffset, 0, -nXoffset, 0);
    qDebug() << "rt: " << rt;
}

//////////////////////////////////////////////////////

std::map<std::string, std::string> ParseCliParam(int argc, char* argv[])
{
    std::map<std::string, std::string> ret;

    std::vector<std::string> vecArgs(argv, argv + argc);
    std::string currentKey;

    for (auto strArg : vecArgs)
    {
        if (strArg._Starts_with("-"))
        {
            currentKey = strArg.substr(1, strArg.length() - 1);
            ret[currentKey] = "";
        }
        else
        {
            auto it = ret.find(currentKey);
            if (it != ret.end())
            {
                if (it->second.empty())
                {
                    ret[currentKey] = strArg;
                }
            }
        }
    }

    return ret;
}


void funParseCliParam()
{



    //std::map<std::string, std::string> cli = ParseCliParam(argc, argv);
}



///////////////////////////////////////////////////////

class VXLoginUserInfo
{
public:

    VXLoginUserInfo()
    {
        Init();
    }
    ~VXLoginUserInfo() {}

    void Init()
    {
        serverName = "";
        serverPassword = "";
    }

    bool operator==(const VXLoginUserInfo& _v)
    {
        if ((this->serverName == _v.serverName) && (this->serverPassword == _v.serverPassword))
        {
            return true;
        }

        return false;
    }

public:
    string serverName;
    string serverPassword;

};

typedef vector<VXLoginUserInfo> VXLoginUserInfoVec;

void findMatch()
{
    VXLoginUserInfoVec vec;
    VXLoginUserInfo info;
    info.serverName = "cicada";
    info.serverPassword = "love0309";
    vec.push_back(info);

    info.serverName = "test";
    info.serverPassword = "love0309";
    //vec.push_back(info);

    bool bMatch = false;
    auto _itor = std::find(vec.begin(), vec.end(), info);
    if (_itor != vec.end())
    {
        //! found
        bMatch = true;
        std::cout << "found" << std::endl;
    }
    else
    {
        //! not found
        bMatch = false;
        std::cout << "not found" << std::endl;
    }

}

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

    //Getresolution();

    ////Match(1680, 1050);
    ////Match(1920, 1080);
    //Match(1440, 1080);


    //cout << "----------------" << endl;
    //fun();
    //f1();
    //f2();

    //testRectSize();

    //testRenderRect();
    //testRect2();
    //findMatch();

    //! resolution.exe -username {aaa} -ip {172.16.200.199} -port {5600} -password {bbb}

    testInt();
    cout << "________________________" << endl;

    {
        std::map<std::string, std::string> cli = ParseCliParam(argc, argv);


        while (true)
        {

        }

        //!
        auto itor = cli.find("ip");
        if (itor != cli.end())
        {
            std::cout << "ip: " << itor->second << std::endl;
        }

        itor = cli.find("password");
        if (itor != cli.end())
        {
            std::cout << "password: " << itor->second << std::endl;
        }

        itor = cli.find("port");
        if (itor != cli.end())
        {
            std::cout << "port: " << itor->second << std::endl;
        }

        itor = cli.find("username");
        if (itor != cli.end())
        {
            std::cout << "username: " << itor->second << std::endl;
        }


        std::cout << endl;
    }

    return a.exec();
}
