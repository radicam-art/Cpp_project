#include <iostream>

class Triangle
{
    int m_height;   //高さ
    int m_base_length;  //底辺の高さ

public:
    explicit Triangle(int height, int base_length);

    int get_height() const;
    int get_base_length() const;
};

//コンストラクタ
Triangle::Triangle(int height, int base_length)
    : m_height(height), m_base_length(base_length)
{
}

int Triangle::get_height() const
{
    return m_height;
}

int Triangle::get_base_length() const
{
    return m_base_length;
}

int main()
{
    Triangle triangles[] = 
    {
        //配列のコンストラクタにそれぞれの引数を渡している
        Triangle{10, 20},
        Triangle{20,30},
        Triangle{40, 50},
    };

    for (auto& tri : triangles)
    {
        std::cout << "面積: " << (tri.get_base_length() * tri.get_height() / 2)
            << std::endl;
    }
}