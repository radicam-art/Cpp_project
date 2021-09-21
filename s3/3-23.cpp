//staticメンバ変数のカプセル化
#include <iostream>

class S
{
    static int count;   //インスタンスの数を数えるstaticメンバ変数

public:
    S();
    ~S();

    void show_count() const;
};

int S::count = 0;   //staticメンバ変数の実体を定義して0で初期化する

S::S()
{
    //インスタンスが作られたらインクリメント
    ++count;
}

S::~S()
{
    //破棄されたらデクリメントする
    --count;
}

void S::show_count() const
{
    std::cout << "S::count: " << count << std::endl;
}

void function()
{
    S a;
    a.show_count(); //インスタンスはmain()のaと、この関数内のaの2つがある

    //この関数内のaは関数が終了すると同時に破棄される
}

int main()
{
    S a;
    a.show_count(); //aのコンストラクタでインクリメントされるので0が出力される
    function();
    a.show_count(); //function()関数内のaは破棄されているので1となる
}
