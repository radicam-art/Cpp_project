#include <iostream>

void hello()
{
    std::cout << "hello, macro" << std::endl;
}

#define id(name) name  //引数で受け取ったものにそのまま置き換える

int main()
{
    id(hello)();
}