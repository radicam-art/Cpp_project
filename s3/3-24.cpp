//staticメンバ関数
#include <iostream>

class S
{
    static int count;   //インスタンスの数を数えるstaticメンバ変数

public:
    S();
    ~S();

    static void show_count();   //staticメンバ関数の宣言
};

int S::count = 0;   //staticメンバ変数の実体を定義して0で初期化する

S::S()
{
    //インスタンスが作られたらインクリメント
    ++count;
}

S::~S()
{
    //インスタンスが破棄されたらデクリメント
    --count;
}

void S::show_count()
{
    std::cout << "S::count: " << count << std::endl;
}

int main()
{
    //どのインスタンスにも結びつかないのでインスタンスが無くても呼び出すことが出来る
    S::show_count();

    S a;
    a.show_count(); //インスタンスを使って呼び出すこともできる
}