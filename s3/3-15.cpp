//純粋仮想関数
//図形の形状を扱うクラス

#include <iostream>

class Shape
{
public:
    virtual float area() const = 0; //面積を求める純粋仮想関数
    virtual float perimeter() const = 0;    //周囲長を求める純粋仮想関数
};

//純粋仮想関数自体は関数本体を持たないので、メンバ関数の定義はない

//長方形を扱うクラス
class Rectangle : public Shape
{
    float height;   //高さ
    float width;    //幅

public:
    //explicit: コンストラクタの暗黙的な呼び出しを禁止
    explicit Rectangle(float height, float width);
    float area() const override;
    float perimeter() const override;
};

//コンストラクタ
Rectangle::Rectangle(float height, float width)
    : height(height), width(width)
{
}

float Rectangle::area() const
{
    return height * width;
}

float Rectangle::perimeter() const
{
    return 2 * (height + width);
}

//円を扱うクラス
class Circle : public Shape
{
    float r;    //半径

public:
    explicit Circle(float r);
    float area() const override;
    float perimeter() const override;
};

//コンストラクタ
Circle::Circle(float r)
    : r(r)
{
}

float Circle::area() const
{
    return r * r * 3.14f;
}

float Circle::perimeter() const
{
    return 2 * r * 3.14f;
}

int main()
{
    Rectangle rect(10, 2);
    std::cout << "rect" << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    Circle circle(4);
    std::cout << "circle" << std::endl;
    std::cout << "Area: " << circle.area() << std::endl;
    std::cout << "Perimeter: " << circle.perimeter() << std::endl;
    
}