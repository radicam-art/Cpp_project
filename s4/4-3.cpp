//関数スコープについて
#include <iostream>

class A
{
public:
    ~A();
};

A::~A()
{
    std::cout << "デストラクタ呼び出し" << std::endl;
}

void func_scope(int i)
{
    A a;    //関数スコープから抜けるとデストラクタが呼ばれる
    std::cout << "関数スコープ" << std::endl;

    if (i > 0)
    {
        return; //関数の処理がここから呼び出し元に戻る
    }

    std::cout << "if文の後" << std::endl;
}

int main()
{
    //if文の条件がtrueとなるのでreturn文で戻ってくる
    func_scope(10);

    std::cout << std::endl;

    //if文の条件がfalseとなるので関数スコープの終わりにたどり着く
    func_scope(-10);
}