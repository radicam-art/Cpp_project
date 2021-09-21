#include <iostream>

namespace A //名前空間A
{
    struct S    //名前空間Aの構造体S
    {
        int a;
    };

    void foo()  //名前空間Aの関数foo()
    {
        std::cout << "A::foo()" << std::endl;
    }
}

namespace B
{
    struct S
    {
        int b;
    };

    void foo()
    {
        std::cout << "B::foo()" << std::endl;
    }
}

int main()
{
    A::foo();   //名前空間Aにある関数foo()の呼び出し
    B::foo();

    A::S as;
    B::S bs;

    //  as = bs;    //エラー。名前空間が異なるので別の型として扱われる
}