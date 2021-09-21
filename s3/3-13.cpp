#include <iostream>

class Base
{
public:
    virtual void foo();
};

void Base::foo()
{
    std::cout << "foo()" << std::endl;
}

class Derived : public Base
{
public:
    void foo() override;    //派生クラスでメンバ関数をオーバーライド
    //void foo(int i) override; //エラー。対応する仮想関数が基底クラスにない
    void foo(int i);    //単なるオーバーロードは追加できる
};

void Derived::foo() //適宜にはoverrideを書かない
{
    std::cout << "Derived::foo()" << std::endl;
}

void Derived::foo(int i)
{
    std::cout << "Derived::foo(int i)" << std::endl;
}

int main()
{
    Base base;
    base.foo();

    Derived derived;
    derived.foo();
    derived.foo(0);
}