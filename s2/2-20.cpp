#include <iostream>

int main(){
    //変数showにラムダ式を代入する
    auto show = [](int i) -> void{
        std::cout << "iの値: " << i << std::endl;
    };

    show(42);
}