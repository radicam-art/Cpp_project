#include <iostream>

class Base
{
public:
    void method_Base();
};

void Base::method_Base()
{
    std::cout << "Base::method_Base()" << std::endl;
}

class Derived : public Base
{
public:
    void method_Derived();
};

void Derived::method_Derived()
{
    std::cout << "Derived::method_Base()" << std::endl;
}

int main()
{
    Derived derived;

    //OK。
    derived.method_Base();

    //基底クラスへの参照は派生クラスからも作れる
    Base& base = derived;

    //OK。Baseのメンバ関数へはBaseの参照からたどることが出来る
    base.method_Base();
}