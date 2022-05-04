
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int fibonacci(int first, int second, int i){
    if(i <= 0) {
        return 0;
    }
    if(i < 3) {
        return 1;
    }else if(i == 3) {
        return first + second;
    }else {
        return fibonacci(second, first + second, i - 1);
    }

}

void time_consumption(){
    int n;
    int result;
    while(cin >> n){
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );

        result = fibonacci(1, 1, n);

        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        cout << "result: " << result << " "
             << milliseconds(end_time).count() - 
                milliseconds(start_time).count()
             << " ms" << endl;

    }
}

int main()
{
    time_consumption();
    return 0;
}

/**
 * @result 
 *  40
    result: 102334155 548 ms
    40
    result: 102334155 533 ms
    10
    result: 55 0 ms
    20
    result: 6765 0 ms
    30
    result: 832040 7 ms
 */