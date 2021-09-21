//コンパイル不可
#include <iostream>

int foo(int value)
{
    //何か複雑な処理
    std::cout << "foo: " << value << std::endl;
    return value;
}

bool is_even(int value) //偶数ならtrueを返す関数
{
    return value % 2 == 0;
}

bool is_zero(int value)
{
    return value == 0;
}

int main()
{
    //初期化構文付きif文で変数宣言とif文を1行で書く
    if (int result = foo(42); is_even(result) && !is_zero(result))
    {
        std::cout << "OK" << std::endl;
    }
}