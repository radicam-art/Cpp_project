#include <iostream>

int main()
{
    auto dephault = std::cout.flags();  //デフォルトのフラグを保存

    std::cout.setf(std::ios::scientific);

    //basefieldをクリア、つまり基数に関するフラグをクリア
    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::cout << 123.456f << std::endl; //科学技術表記
    std::cout << 123456 << std::endl;   //16進数表記

    std::cout.flags(dephault);

    std::cout << 123.456f << std::endl; //浮動小数点表記
    std::cout << 123456 << std::endl;   //10進数表記
}