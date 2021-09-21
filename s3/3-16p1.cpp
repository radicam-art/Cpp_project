#include <string>
#include <iostream>

class Base
{
public:
    virtual std::string name() const;
    virtual std::string most_name() const = 0;
};

std::string Base::name() const
{
    return "Base";
}

class Derived : public Base
{
public:
    std::string name() const override;
};

std::string Derived::name() const
{
    return "Derived";
}

class MoreDerived : public Derived
{
public:
    std::string name() const override;
    std::string most_name() const override;
};

std::string MoreDerived::name() const
{
    return "More Derived";
}

std::string MoreDerived::most_name() const
{
    return "most_name() MoreDerived";
}

int main()
{
    ;
}