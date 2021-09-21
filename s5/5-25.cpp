//所有権の移動
#include <iostream>
#include <utility>

//家を表すクラス
class home
{
    int *m_land;    //土地

public:
    explicit home(std::size_t size)
        : m_land(new int[size]) {}
    
    ~home(){ delete [] m_land; }

    home(home &&other);

    int *land() const { return m_land; }
};

home::home(home &&other)
    : m_land(other.m_land)  //まずムーブ元のポインタをコピーする
{
    //ムーブ元のポインタを空にする
    //これでこのポインタを持っているのはこのオブジェクトのみになる(所有権の移動)
    other.m_land = nullptr;
}

int main()
{
    home A{100};

    std::cout << "Aの土地のアドレス: " << A.land() << std::endl;

    //Aはもう使わなくなったので、AからBに所有権を移動
    home B{std::move(A)};

    std::cout << "Bの土地のアドレス: " << B.land() << std::endl;
    std::cout << "移動後のAのアドレス: " << A.land() << std::endl;
}