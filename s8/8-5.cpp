#include <iostream>
#include <iomanip>

int main()
{
    // std::hexマニピュレータによって、16進数での表示に切り替える
    std::cout << std::hex << 1234 << std::endl;

    //マニピュレータで浮動小数点数の精度を変更する
    std::cout << std::setprecision(6) << 1234.5678f << std::endl;

    //フラグをセットしても、マニピュレータでクリアできる
    std::cout.setf(std::ios::boolalpha);
    std::cout << true << std::endl;
    std::cout << std::noboolalpha << true << std::endl;
}