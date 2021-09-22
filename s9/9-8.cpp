#include <iostream>

template <typename T>
class S
{
public:
    static int value;
};

// たとえstaticメンバ変数の型がテンプレートのパラメータに全く依存していなくてもテンプレートの記述は必要
template <typename T>
int S<T>::value = 0;

int main()
{
    //初期値はどちらも0を与えている
    std::cout << "S<int>::value: " << S<int>::value << std::endl;
    std::cout << "S<float>::value: " << S<float>::value << std::endl;

    //それぞれのstaticメンバ変数のアドレスを表示
    std::cout << "&S<int>::value: " << &S<int>::value << std::endl;
    std::cout << "&S<float>::value: " << &S<float>::value << std::endl;

    S<int>::value = 42; //int型で作ったstaticメンバ変数を変更する

    //staticメンバ変数自体がそれぞれのクラスの実体ごとに作られるので、S<float>::valueは変更されない
    std::cout << "S<int>::value: " << S<int>::value << std::endl;
    std::cout << "S<float>::value: " << S<float>::value << std::endl;
}