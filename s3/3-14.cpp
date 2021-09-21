//名前の隠匿
#include <iostream>

class Base
{
public:
    void foo();
};

void Base::foo()
{
    std::cout << "foo()" << std::endl;
}

class Derived : public Base
{
public:
    using Base::foo;  //基底クラスのfoo()を呼び出せるようにしている
    void foo(int i);    //派生クラスで追加したオーバーロード
};

void Derived::foo(int i)
{
    std::cout << "Derived::foo(" << i << ")" << std::endl;
}

int main()
{
    Derived derived;
    derived.foo();  //基底クラスのfoo()が呼ばれる
    derived.foo(42);    //派生クラスのオーバーロードを呼び出し
}