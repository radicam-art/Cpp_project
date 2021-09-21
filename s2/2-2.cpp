#include <iostream>

struct product{
    int id;
    int price;
    int stock;
};

//引数として構造体変数を受け取る関数
void show_product(struct product product){
    std::cout << "商品ID : " << product.id << std::endl;
}

int main(){
    product pen = {
        0,
        100,
        200,
    };

    show_product(pen);

    return 0;
}