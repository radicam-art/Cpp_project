//マクロ定義の取り消し
#include <iostream>

void hello()
{
    std::cout << "hello, macro" << std::endl;
}

void goodbye()
{
    std::cout << "goodbye, macro" << std::endl;
}

int main()
{
#define hello goodbye
    hello();

#undef hello
    hello();
}