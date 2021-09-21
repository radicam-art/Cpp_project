#include <iostream>

int main()
{
    int *p = new int(42);   //動的確保時の初期値

    std::cout <<
        "生命、宇宙、そして万物についての究極の答え: " <<
        *p << std::endl;

    delete p;   //delete演算子は通常のまま
}