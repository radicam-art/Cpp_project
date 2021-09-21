//オブジェクトの値渡しと参照渡し
#include <iostream>

class Marker
{
public:
    Marker();
    ~Marker();
};

Marker::Marker()
{
    std::cout << "コンストラクタ: " << this << std::endl;
}

Marker::~Marker()
{
    std::cout << "デストラクタ: " << this << std::endl;
}

void copy(Marker m)
{
    std::cout << "copy: " << &m << std::endl;
}

void reference(const Marker &m)
{
    std::cout << "reference: " << &m << std::endl;
}

int main()
{
    Marker m;
    std::cout << "値渡し前" << std::endl;
    copy(m);
    std::cout << "値渡し後" << std::endl;

    std::cout << "参照渡し前" << std::endl;
    reference(m);
    std::cout << "参照渡し後" << std::endl;
}