#include <iostream>

class A
{
    int m_v;

public:
    A(int);

    int v() const;
};

//引数付きコンストラクタ
A::A(int v) : m_v(v)
{
    //初期化処理がされている
}

int A::v() const
{
    return m_v;
}

int main()
{
    A x = 42;   //A::A(int v)を呼び出している

    if (x.v() == 42)
    {
        std::cout << "A.v()は42です" << std::endl;
    }
    else
    {
        std::cout << "A.v()は42ではありません" << std::endl;
    }
}