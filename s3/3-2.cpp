#include <iostream>

class product
{
    int id; //商品ID

public:
    int get_id();   //非constメンバ関数
    int get_id() const; //constメンバ関数
};

int product::get_id()
{
    std::cout << "非constメンバ関数のget_id()が呼ばれました。 " << std::endl;
    return id;
}

int product::get_id() const
{
    std::cout << "constメンバ関数のget_id()が呼ばれました。 " << std::endl;
    return id;
}

int main()
{
    product p;  
    p.get_id();     //非constメンバ関数

    const product cp{};
    cp.get_id();    //constメンバ関数
}