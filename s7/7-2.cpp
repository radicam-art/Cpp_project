#include <iostream>

class Base
{
public:
    Base(){std::cout << "Baseコンストラクタ" << std::endl;}
    ~Base(){std::cout << "Baseデストラクタ" << std::endl;}
};

class Derived : public Base
{
public:
    Derived(){std::cout << "Derivedコンストラクタ" << std::endl;}
    ~Derived(){std::cout << "Derivedデストラクタ" << std::endl;}
};

class MoreDerived : public Derived
{
public:
    MoreDerived(){std::cout << "MoreDerivedコンストラクタ" << std::endl;}
    ~MoreDerived(){std::cout << "MoreDerivedデストラクタ" << std::endl;}
};

int main()
{
    MoreDerived more_derived;
    std::cout << "オブジェクト構築完了" << std::endl;
}