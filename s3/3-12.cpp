#include <iostream>

// 基底となるクラス
class Base
{
public:
    void foo();
};

void Base::foo(){
    std::cout << "foo()" <<std::endl;
}

class Derived:public Base
{
    //Baseのメンバを継承
public:
    void bar(); //派生クラスで追加した機能
};

void Derived::bar()
{
    std::cout << "bar()" << std::endl;
}

int main()
{
    Base base;
    base.foo();

    Derived derived;
    derived.bar();
    //派生元の関数が存在
    derived.foo();
}