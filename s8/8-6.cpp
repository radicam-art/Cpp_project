#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out;  //ファイル出力用のオブジェクトを作成する
    out.open("hello_file.txt"); //ファイルをオープンする

    out << "Hello, File IO" << std::endl;   //ファイルに文字列を出力
    out << std::setprecision(4) << std::scientific << 12.34567f << std::endl;

    out.close();

    //入力用のオブジェクトを作成するのと同時にオープンもできる
    std::ifstream in{"hello_file.txt"};

    std::string line;
    std::getline(in, line); //ファイルから1行入力する
    float f;
    in >> f;

    std::cout << line << std::endl; //ファイルから読み込んだ1行を画面に出力する
    std::cout << f << std::endl;    //読み込んだ浮動小数点を出力

    // in.close(); を呼ばなくても、デストラクタが自動でクローズする
}