#include <iostream>

int x;
int &get_x()    // 参照を返す関数
{
    return x;   //参照を返す時であっても特別なことはしなくてもよい
}

int main()
{
    x = 10;
    int &y = get_x();   //返された参照をそのまま参照として受け取る
    y = 100;
    std::cout << x << std::endl;
}