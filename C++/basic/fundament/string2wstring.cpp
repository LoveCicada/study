
#include <iostream>
#include <memory>
#include <string>
using namespace std;

std::wstring string2wstring(const std::string& str)
{
    if(str.empty()){
        return L"";
    }

    unsigned int char_size = sizeof(char);
    unsigned int uiLen = str.size() * char_size + 1;
    setlocale(LC_CTYPE, "en.US.UTF-8");
    std::unique_ptr<wchar_t> p(new wchar_t[uiLen]);
    mbstowcs(p.get(), str.c_str(), uiLen);
    std::wstring wstr(p.get());
    return wstr;
}

std::string wstring2string(const std::wstring& wstr)
{
    if(wstr.empty()){
        return "";
    }

    unsigned int wchar_t_size = sizeof(wchar_t);
    std::cout << "wchar_t_size = " << wchar_t_size << std::endl;
    unsigned int uiLen = wstr.size() * wchar_t_size + 1;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    std::unique_ptr<char[]> p(new char[uiLen]);
    wcstombs(p.get(), wstr.c_str(), uiLen);
    std::string str(p.get());
    return str;
}


void test(char* argv)
{
    std::string strSrc, strDst;
    strSrc = "D:\\中文路径Path\\ebook.string";

    std::wstring wstrSrc, wstrDst;
    wstrSrc = L"D:\\中文路径Path\\ebook.wstring";

    wstrDst = string2wstring(strSrc);
    std::cout << "wstrDst ";
    std::wcout << wstrDst << std::endl;

    strDst = wstring2string(wstrSrc);
    std::cout << "strDst "; 
    std::cout << strDst << std::endl;

}

int main(int argc, char* argv[])
{
    test(argv[1]);

    return 0;
}