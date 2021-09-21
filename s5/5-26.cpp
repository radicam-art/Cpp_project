//関数ポインタの宣言と指し示す関数の呼び出し
#include <iostream>

int identity(int v)
{
    return v;
}

int square(int v)
{
    return v * v;
}

int main()
{
    //関数ポインタを宣言し、identifyで初期化する
    int (*func)(int) = identity;

    //関数ポインタを経由してidentityを呼び出す
    std::cout << "func(4): " << func(4) << std::endl;

    //関数ポインタにsquareのアドレスを代入する
    func = &square;

    //関数ポインタを経由してsquareを呼び出す
    std::cout << "func(4): " << func(4) << std::endl;
}