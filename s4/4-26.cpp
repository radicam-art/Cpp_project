//プリプロセッサを使ったプログラムの条件分岐
#include <iostream>

#define HOGE

int main()
{
#if defined(HOGE)
    std::cout << "defined(HOGE) is true" << std::endl;
#else
    std::cout << "defined(HOGE) is false" << std::endl;
#endif
}