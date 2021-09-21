#include <iostream>

class product
{
    int id; //商品ID

public:
    int get_id();   //商品IDのgetter
    void set_id(int new_id);    //商品IDのsetter
};

//getterは何も変更しない
int product::get_id()
{
    return id;
}

//setterはメンバ変数を変更する
void product::set_id(int new_id)
{
    id = new_id;
}

int main()
{
    product p;
    p.set_id(42);   //ok. pはconstではない。
    std::cout << p.get_id() << std::endl;   //OK

    const product cp{}; //{}の意味については5章5節

    //ERROR. constなインスタンスのメンバを変更できてしまうと困る。
    //cp.set_id(42);

    //ERROR. しかしget_id()は何も変更しないのでOKであってほしい、、、
    //std::cout << cp.get_id() << std::endl;
}