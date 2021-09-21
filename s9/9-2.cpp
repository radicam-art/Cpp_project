#include <iostream>

//関数テンプレートでの積和演算

template <typename T>
T fused_mult_add(T a, T b, T c)
{
    T r = a * b + c;
    return r;
}

int main()
{
    std::cout << fused_mult_add<int>(1, 2, 3) << std::endl;
}