#include <iostream>
#include <string>

class person
{
    std::string m_name;
    int         m_age;
    person(int age);

public:
    person();
    person(std::string name, int age);

    void set_name(std::string name);
    void set_age(int age);

    std::string name() const;
    int         age() const;
};

//共通な初期化処理が書かれたコンストラクタ
person::person(int age) : m_age(age)
{
    //複数のコンストラクタで共通なおおもとの処理をprivateなコンストラクタに用意し、
    //委譲コンストラクタを使うことで、一貫した(漏れのない）初期化手段を提供できる
    std::cout << "共通コンストラクタ呼び出し" << std::endl;
}

//委譲元コンストラクタ(引数なし)
person::person()
    : person(-1)    //委譲先コンストラクタ
{
    std::cout << "引数なしコンストラクタ呼び出し" << std::endl;
}

//委譲元コンストラクタ(名前と年齢を与えて初期化する)
person::person(std::string name, int age)
    :person(age)    //委譲先コンストラクタ
{
    std::cout << "引数付きコンストラクタ呼び出し" << std::endl;

    //初期化中にメンバ関数を呼び出すこともできる
    set_name(name);
}

void person::set_name(std::string name)
{
    m_name = name;
}

void person::set_age(int age)
{
    m_age = age;
}

std::string person::name() const
{
    return m_name;
}

int person::age() const
{
    return m_age;
}

int main()
{
    person alice("alice", 15); //コンストラクタ呼び出しによる初期化が行われる
    std::cout << alice.name() << std::endl;     //aliceと表示される
}