#include <iostream>

union U
{
    //デフォルトのアクセス指定はpublic
    float f;

private:
    int i;

public:
    U();    //コンストラクタやデストラクタも定義できる

    int get_i() const;
};

//コンストラクタでは先頭以外のメンバ変数で初期化できる
U::U() : i(0xdeadbeef)
{
    //メンバのアドレスを列挙
    std::cout << "&f: " << &f << std::endl
        << "&i: " << &i << std::endl;
}

int U::get_i() const
{
    return this->i; //共用体のメンバ関数もthisポインタが使える
}

int main()
{
    U u;    //デフォルトコンストラクタがint型で初期化する
    std::cout << std::hex << u.get_i() <<std::endl;
    u.f = 2.17828f; //float型の値を代入
    std::cout << std::hex << u.get_i() << std::endl;
}