#include <iostream>
#include <iomanip>
using namespace std;

class S
{
public:
    //宣言と同時に定義も与える場合
    template <typename T>
    void foo(T value)
    {
        cout << value << endl;
    }

    template <typename T>
    void bar(T value);
};

//普通のメンバ関数定義にtemplateが付いただけ
template <typename T>
void S::bar(T value)
{
    cout << setprecision(2) << value << endl;
}

int main()
{
    S s;
    s.foo<int>(0);

    s.bar<float>(0.154f);
}