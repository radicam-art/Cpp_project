#include <iostream>

int main(){
    //型
    char c;
    int i;
    signed int si;
    unsigned int ui;
    short s;
    long l;
    long long ll;
    float f;
    double d;
    
    std::cout << "char: " << sizeof(c) << std::endl;
    std::cout << "int: " << sizeof(i) << std::endl;
    std::cout << "signed int: " << sizeof(si) << std::endl;
    std::cout << "unsigned int: " << sizeof(ui) << std::endl;
    std::cout << "short: " << sizeof(s) << std::endl;
    std::cout << "long: " << sizeof(l) << std::endl;
    std::cout << "long long: " << sizeof(ll) << std::endl;
    std::cout << "float: " << sizeof(f) << std::endl;
    std::cout << "double: " << sizeof(d) << std::endl;
}