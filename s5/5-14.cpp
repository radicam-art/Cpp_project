//初期化のルール
#include <string>

class A
{
    int m_v;
    std::string m_n;

public:
    A(int, std::string);
    A(float);
};

A::A(int v, std::string n)
    :m_v(v), m_n{n} //1 OK。　メンバ初期化リストでも{}を使うことが出来る
{
}

A::A(float)
    : A{-1, "float"}    //2 OK。委譲コンストラクタでも{}を使うことが出来る
{
}

int main()
{
    A ap(42, "0");  //3 普通に()を使う
    A ab{42, "0"};  //4 ()の代わりに{}を使うことが出来る

    A bp = A(42, "0");  //5 OK。関数形式の明示的な型変換
    A bb = A{42, "0"};  //6 OK。bpの初期化と同等

    // A cp = (42, "0");   //7 エラー。A(int, std::string)の呼び出しにはならない
    A cb = {42, "0"};   //8 OK。bbの初期化と同様

    A dp = (42, 0.0);   //9 要注意。A(int, std::string)ではなく、A(float)が呼ばれる
    // A db = {42, 0.0};   //10 エラー。doubleからstd::stringへの変換はできない

    double pi = 3.141592653;
    A ep(pi);   //11 OKだが、doubleからfloatへの暗黙変換が行われる
    // A eb{pi};   //12 エラー。doubleからfloatへは安全に変換できない
}