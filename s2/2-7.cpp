#include <iostream>

class product
{
    //デフォルトではアクセスできない
    int id;
    int price;
    int stock;

public:
    int get_id();
    void set_id(int new_id);

    int get_price();
    void set_price(int new_price);
    
    int get_stock();
    void set_stock(int new_stock);

    void set_product(int new_id, int new_price, int new_stock);
};

int product::get_id(){
    //メンバ関数の内側ではメンバ変数に直接アクセスできる
    return id;
}

void product::set_id(int new_id){
    id = new_id;
}

int product::get_price(){
    return price;
}

void product::set_price(int new_price){
    if (new_price < 0){
        std::cout << "エラー: 単価は0以上にしてください" << std::endl;
        return;
    }

    price = new_price;
}

int product::get_stock(){
    return stock;
}

void product::set_stock(int new_stock){
    if (new_stock < 0){
        std::cout << "在庫は0以上にしてください" << std::endl;
        return;
    }
    stock = new_stock;
}

void product::set_product(int new_id, int new_price, int new_stock){
    id = new_id;

    if (new_price < 0){
        std::cout << "エラー: 単価は0以上にしてください" << std::endl;
        return;
    }

    price = new_price;

    if (new_stock < 0){
        std::cout << "在庫は0以上にしてください" << std::endl;
        return;
    }
    
    stock = new_stock;
}

int main(){
    product pen;    //ペンに関するデータを持つ変数

    //メンバ変数は非公開なので、setterを使って値を格納していく
    pen.set_product(0, 100, 200);

    product *ptr = &pen;

    //アロー演算子を使ってgetterから値を取得
    std::cout << "商品ID: " << ptr -> get_id() << std::endl;
    std::cout << "商品価格: " << (*ptr).get_price() << std::endl;
    std::cout << "商品在庫: " << ptr->get_stock() << std::endl;
}

