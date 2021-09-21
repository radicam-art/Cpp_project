#include <iostream>

enum class Category {
    Value1, //0
    Value2, //1
    Value3 = 100,   //100
    Value4, //101
};

int main(){
    //列挙体の変数を宣言し、Value3で初期化
    Category cat = Category::Value3;

    //列挙体の値に対応した変数を得る
    std::cout << static_cast<int>(cat) << std::endl;

    return 0;
}