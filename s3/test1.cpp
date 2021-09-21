#include <iostream>
using namespace std;

char checkS(int m, int d);
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    int m, d;
    cin >> m >> d;
    //cout << m << " " << d << endl;
    if (checkS(m, d)){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    
    return 0;
}

char checkS(int m, int d){
    switch(m){
        case 1:
            if(d == 1 || d == 11){
                return 1;
            }
            else
                return 0;
            break;
        case 2:
            if(d == 2 || d == 22){
                return 1;
            }
            else
                return 0;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if(m == d){
                return 1;
            }
            else
                return 0;
            break;
        case 11:
            if(d == 1 || d == 11){
                return 1;
            }
            else
                return 0;
            break;
        default:
            return 0;
            break;
    }
}