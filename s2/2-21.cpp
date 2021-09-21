#include <iostream>

int main(){
    int a = 0;

    auto lambda = [a](){
        // OK! 変数aのコピーがラムだ式内部に存在
        std::cout << a << std::endl;
    };

    lambda();   //コピーしたときのaの中身が表示される
    
    //ラムダ式はコピーを持っているので、元の変数が変更されてもコピーの中身は変わらない
    a = 42;

    lambda();
}