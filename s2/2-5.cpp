//構造体の初期化について

#include <iostream>

union U {
    int a;
    int b;
    int c;
} ;

int main(){
    U u = { 42 };   //先頭のメンバで初期化

    std::cout << u.b << std::endl;

    u.c = 1024;

    std::cout << u.a << std::endl;

    return 0;
}