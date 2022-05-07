
#include <iostream>
#include <memory>

using namespace std;

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
    test();


    return 0;
}