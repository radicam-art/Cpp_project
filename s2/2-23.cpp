#include <iostream>

int main(){
    int a = 0;

    //aを参照でキャプチャする
    auto lambda = [&a]()
    {
        std::cout << "キャプチャした変数: " << a << std::endl;
        ++a;    //参照でキャプチャした変数を変更(mutableの指定は不要)
    };

    lambda();

    //ラムダ式の中で変更が加えられている
    std::cout << "元の変数: " << a << std::endl;

    a = 42; //キャプチャ元の変数を変更する

    lambda();

    std::cout << "aを表示: " << a << std::endl;
}