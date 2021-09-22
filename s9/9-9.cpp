#include <iostream>

struct S_shared
{
    static int value;
};

//クラステンプレート間で共有できる変数
int S_shared::value = 0;

template <typename T>
class S : public S_shared
{
};

int main()
{
    std::cout << "S<int>::value: " << S<int>::value << std::endl;
    std::cout << "S<float>::value: " << S<float>::value << std::endl;

    //それぞれのstaticメンバ変数のアドレスを表示
    std::cout << "&S<int>::value: " << &S<int>::value << std::endl;
    std::cout << "&S<float>::value: " << &S<float>::value << std::endl;

    S<int>::value = 42; //int型の実体（インスタンス）を通してstaticメンバ変数を変更

    //クラステンプレートの実体は異なるが、たいていの基底クラスはただ一つなので変数が共有される
    std::cout << "S<int>::value: " << S<int>::value << std::endl;
    std::cout << "S<float>::value: " << S<float>::value << std::endl;
}