#include <iostream>

class Integer
{
    int value;

public:
    //  組み込みの整数型のように扱いたいので、explicitは付けない
    Integer(int value) : value{value} {};

    Integer add (const Integer &other) const;   //加算
    Integer sub (const Integer &other) const;   //減算
    Integer mul(const Integer &other) const;
    Integer div(const Integer &other) const;

    void show() const;
};

Integer Integer::add(const Integer &other) const
{
    return Integer{value + other.value};
}

void Integer::show() const
{
    std::cout << "Integer.value = " << value << std::endl;
}

int main()
{
    Integer x = 10;
    Integer y = 2;

    auto v = x.add(y);

    v.show();
}