#include <iostream>
#include <sstream>
using namespace std;

#define STRING_TYPE(c1, c2, c3, c4)                 \
        ( (static_cast<uint32_t>(c1))<<24 )     |   \
        ( (static_cast<uint32_t>(c2))<<16 )     |   \
        ( (static_cast<uint32_t>(c3))<<8 )      |   \
        ( (static_cast<uint32_t>(c4)) )     

const uint32_t uiftyp = STRING_TYPE('f','t','y','p'); 

uint32_t& string2uint32_t(char c1, char c2, char c3, char c4, uint32_t& v)
{
    v = ( (static_cast<uint32_t>(c1))<<24 )     |   \
        ( (static_cast<uint32_t>(c2))<<16 )     |   \
        ( (static_cast<uint32_t>(c3))<<8 )      |   \
        ( (static_cast<uint32_t>(c4)) );

     return v;   
}

stringstream& print_type(stringstream& ss, uint32_t v)
{
    ss << char(v>>24) << char(v>>16) << char(v>>8) << char(v);
    return ss;
}

int main(int argc, char* argv[])
{
    stringstream ss;
    print_type(ss, uiftyp);
    cout << "uiftyp: " << uiftyp << endl;
    cout << "ss: " << ss.str().c_str() << endl;

    uint32_t v;
    string2uint32_t('f', 't', 'y', 'p', v);
    
    //! 清空流状态
    ss.clear();
    //! 清空流内容
    ss.str("");
    
    print_type(ss, v);
    cout << "v: " << v << endl;
    cout << "ss: " << ss.str().c_str() << endl;

    return 0;
}

/**
 * @brief result
 * uiftyp: 1718909296
 * ss: ftyp
 * v: 1718909296
 * ss: ftyp
 * 
 */