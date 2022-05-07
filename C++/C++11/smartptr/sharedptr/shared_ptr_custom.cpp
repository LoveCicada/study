
#include <iostream>
#include <memory>

using namespace std;

template<class T>
class SmartArry
{
public:

    SmartArry()
    {
        m_nWidth = 0;
        m_nHeight = 0;
        m_pData = nullptr;
    }

    SmartArry(int nWidth = 0, int nHeight = 0)
    {
        Init(nWidth, nHeight);
    }

    void Init(int nWidth = 0, int nHeight = 0)
    {
        m_nWidth = nWidth;
        m_nHeight = nHeight;
        m_pData = new T[m_nWidth * m_nHeight];
    }

    void UnInit()
    {
        m_nWidth = 0;
        m_nHeight = 0;
        if (m_pData) {
            delete[] m_pData;
        }
    }

    void Resize(int nWidth, int nHeight)
    {
        if (nWidth == m_nWidth && nHeight == m_nHeight) {
            return;
        }

        UnInit();
        Init(nWidth, nHeight);
    }

    float* GetData()
    {
        return m_pData;
    }

    ~SmartArry()
    {
        UnInit();
    }

private:
    int m_nWidth;
    int m_nHeight;
    T* m_pData;
};

void test2()
{
    int nWidth = 16;
    int nHeight = 9;
    SmartArry<float> sf(nWidth, nHeight);
    float* p = sf.GetData();

    //! init
    for (int i = 0; i < nHeight; ++i) {
        for (int j = 0; j < nWidth; ++j) {
            p[i * nWidth + j] = i * nWidth + j + 0.02;
        }
    }

    //! print
    for (int i = 0; i < nHeight; ++i) {
        for (int j = 0; j < nWidth; ++j) {
            cout << p[i * nWidth + j] << ' ';
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

void test()
{

    int nWidth = 16;
    int nHeight = 9;
    shared_ptr<float[]> p(new float[nWidth*nHeight], [](float* p){delete p;});
    
    //! init
    for(int i = 0; i < nHeight; ++i){
        for(int j = 0; j < nWidth; ++j ){
            p[i*nWidth + j] = i*nWidth + j + 0.02;
        }
    }

    //! print
    for(int i = 0; i < nHeight; ++i){
        for(int j = 0; j < nWidth; ++j ){
            cout << p[i*nWidth + j] << ' ';
        }
        cout << endl;
    }
    cout << "----------------" << endl;

    shared_ptr<float[]> p2(p);
    for(int i = 0; i < nHeight; ++i){
        for(int j = 0; j < nWidth; ++j ){
            cout << p2[i*nWidth + j] << ' ';
        }
        cout << endl;
    }

}

int main()
{
    test2();


    return 0;
}