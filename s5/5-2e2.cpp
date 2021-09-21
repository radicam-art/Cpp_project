#include <iostream>
#include <vector>

class product
{
    int id;
    std::string name;
    int price;

public:
    explicit product(int id, std::string name, int price)
        : id(id), name(name), price(price){}
    product()
        : id(0), name("NULL"), price(0){}
    void show()
    {
        std::cout << id << std::endl;
        std::cout << name << std::endl;
        std::cout << price << std::endl;
    }
};

int main()
{
    std::vector<product> p = {
        product{1, "sf", 60000},
        product {2, "tl", 35000},
    };

    for (int i = 0; i < p.size(); i++){
        p[i].show();
    }
}