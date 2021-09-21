#include <iostream>

class product
{
    int id; //商品ID
public:
    int get_id() const;
    void set_id(int new_id);
};

//getterはconstメンバ関数となっていた方が都合がよい
int product::get_id() const
{
    return id;
}

//setterはconstメンバ関数にしない
void product::set_id(int new_id)
{
    id = new_id;
}

int main()
{
    const product cp{};

    std::cout << cp.get_id() << std::endl;
}