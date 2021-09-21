#include <iostream>

class A
{
    int i;

public:
    A() : i(0)
    {
        std::cout << "コンストラクタ" << std::endl;
    }
    ~A()
    {
        std::cout << "デストラクタ" << std::endl;
    }
};

int main()
{
    A *a = new A;
    std::cout << "deleteの前" << std::endl;
    delete a;

    return 0;
}