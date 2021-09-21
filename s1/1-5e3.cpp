#include <iostream>

int main(){
    //キャスト演算子を用いたキャスト
    char c = 99;

    std::cout << c << std::endl;
    std::cout << static_cast<int>(c) << std::endl;
}