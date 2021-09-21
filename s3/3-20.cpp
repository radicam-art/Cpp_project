#include <iostream>

class A
{
    union //型名なし
    {
        int i;
        float f;
    };  //変数も作らない

    long l; //無名共同体の範囲外のメンバ変数

public:
    A();

    int get_i() const;
    void set_f(float);
    long get_l() const;
};

A::A() : i(0xdeadbeef), l(0xc0ffee){
    //クラスのメンバ変数のようにアクセスできる
    std::cout << "&f: " << &f << std::endl
        << "&i: " << &i << std::endl
        << "&l: " << &l << std::endl;
}

int A::get_i() const
{
    return i;
}

void A::set_f(float f)
{
    this->f = f;
}

long A::get_l() const
{
    return l;
}

int main()
{
    A a;    //デフォルトコンストラクタがint型で初期化する
    std::cout << "i: " << std::hex << a.get_i() << std::endl;
    a.set_f(2.71828f);
    std::cout << "i: " << std::hex << a.get_i() << std::endl;
    std::cout << "l: " << std::hex << a.get_l() << std::endl;
}