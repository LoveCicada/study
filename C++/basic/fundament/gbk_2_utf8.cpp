
#include <iostream>
#include <locale>
#include <codecvt>

static std::wstring gbk_2_utf8_wstring(const std::string& gbk_str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wsz = converter.from_bytes(gbk_str);
    return wsz;
}

static std::string gbk_2_utf8(const std::string& gbk_str) 
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wsz = converter.from_bytes(gbk_str);
    return converter.to_bytes(wsz);
}

int main()
{

    return 0;
}