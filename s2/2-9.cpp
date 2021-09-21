#include <iostream>

int one(){
    return 1;
}

int main(){
    auto d = 3.14;

    d = 2.71f;  //dはdouble型に推論され、float型も問題なく代入できる

    std::cout << d << std::endl;

    //型推論は関数呼び出しや、数値計算などの式の結果からも行える

    auto i = one();

    i = 42.195;

    std::cout << i << std::endl;   
}