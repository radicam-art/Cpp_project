#include <iostream>

int main(){
    int value = 42; //int型の変数

    std::cout << "valueのアドレス: " << &value << " 値: " << value << std::endl;

    int& reference = value; //変数referenceへの参照

    std::cout << "referenceのアドレス: " << &reference << " 値: " << reference << std::endl;

    reference = 0;

    std::cout << "valueのアドレス: " << &value << " 値: " << value << std::endl;
}