#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Baseデフォルトコンストラクタ" << std::endl;
    }

    explicit Base(int i)
    {
        std::cout << "Base引数付きコンストラクタ" << std::endl;
    }
};

class Derived : public Base
{
public:
    explicit Derived(int i) : Base {i}{}
};

int main()
{
    Derived derived{42};
}