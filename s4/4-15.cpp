#include <iostream>

class A
{
    int i;

public:
    //コンストラクタの宣言と定義
    A() : i(0) { }

    //メンバ関数の宣言と定義
    void set_t(int i)
    {
        this->i = i;
    }

    //constメンバ関数も定義できる
    void show() const
    {
        std::cout << i << std::endl;
    }
};

int main()
{
    A a;
    a.show();
    a.set_t(123);
    a.show();
}