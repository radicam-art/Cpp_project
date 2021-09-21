#include <iostream>

void show_value(int a){
    std::cout << a << std::endl;
}

//2つの整数を受け取ってそれらの和を返す関数sum()
int sum(int a, int b){
    int c = a + b;
    return c;
}

//3つの整数を受け取って全ての和を返す関数sum()のオーバーロード
int sum(int a, int b, int c){
    int d = a + b + c;
    return d;
}

int main(){
    int x = sum(10, 20);
    show_value(x);

    int y = sum(5, 15, 25);
    show_value(y);
}