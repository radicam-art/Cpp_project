#include <iostream>

class Base
{
//被保護メンバー
protected:
    void protected_member()
    {
        std::cout << "Base::protected_member()" << std::endl;
    }
};

class Derived : private Base
{
public:
    void member_test();
};

void Derived::member_test()
{
    //OK・基底クラスの被保護メンバには派生クラスからアクセスできる
    protected_member();
}

int main()
{
    Derived derived;
    derived.member_test();
}