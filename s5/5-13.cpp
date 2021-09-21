#include <iostream>
#include <string>

class Object
{
    std::string name;

public:
    Object() : name("NO NAME"){ }
    explicit Object(std::string name) : name(name){}
    ~Object();

    void show_name() const;
};

Object::~Object()
{
    std::cout << "Objectのデストラクタ" << std::endl;
}

void Object::show_name() const
{
    std::cout << "object name: " << name << std::endl;
}

int main()
{
    //配列のnew演算子。戻り値の値がポインタであることに注意
    Object *obj = new Object[10]{
        Object{"first"},
        Object{"second"},
    };

    obj[0].show_name();
    obj[1].show_name();
    obj[2].show_name();

    //配列のdelete演算子。各要素のデストラクタがすべて呼ばれる
    delete [] obj;
}