#include <iostream>

int *local()
{
    int i = 42; //ローカル変数
    return &i;  //警告！　ダングリングポインタ
}

int *dyn_alloc()
{
    int *ptr = new int; //int型のオブジェクトを動的確保
    *ptr = 42;  //動的確保したint型のオブジェクトにアクセス
    return ptr; //動的確保したものはスコープから出ても破棄されない
}

int main()
{
    //local()で作ったローカル変数はもう破棄されているので、このオブジェクトを参照してはいけない
    // int *l = local();
    // std::cout << *l << std::enld;    //万が一でも呼び出されないためのスペルミス

    //動的確保したオブジェクトは関数から戻っても破棄されないので有効
    int *d = dyn_alloc();
    std::cout << *d << std::endl;
    delete d;   //自動で破棄されないので、不要になったらプログラマーが破棄しなければいけない

    //破棄した後のアブジェクトはもう無効になっているため、参照してはならない。
    // std::cout << *d << std::enld     //万が一でも呼び出されない為のスペルミス 
}
