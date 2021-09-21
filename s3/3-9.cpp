//explicit指定子

#include <iostream>

class A
{
    int m_v;

public:
    //コンストラクタ
    explicit A(int);    //explicitキーワードを追加することで、暗黙のコンストラクタ呼び出しを禁止できる

    //getter
    int v() const;
};

A::A(int x) : m_v(x)
{

}

int A::v() const
{
    return m_v;
}

int main()
{
    //A x = 0;    //エラー。暗黙のコンストラクタ呼び出しが禁止されている

    A y(42);
    if (y.v() == 42)
    {
        std::cout << "True" << std::endl;
    }
}