#include <iostream>
#include <string>
#include <random>

using namespace std;

//クラス宣言
class player_value;

//プロトタイプ関数
int set_roop();
int set_roop(int roop);
void get_input(player_value *p1, player_value *p2);
void get_name(player_value *p);
int get_command(int player, int a_or_d);
void game_start(player_value *p1, player_value *p2);
int check_zero_one(int i);
int roop_check(int roop);
int get_roop_input();
bool check_winner(int player1, int player2);
int get_random(int min,int max);

//テンプレート
template
<
    typename TYPE,
    std::size_t SIZE
>
//配列の要素数を返す関数
std::size_t array_length(const TYPE (&)[SIZE])
{
    return SIZE;
}

//プレーヤーの情報を格納するためのクラス
class player_value
{
    int p; //playerの選択した値
    string p_name; //playerの名前

public:
    //それぞれの値を0で初期化
    player_value() : p(0){}

    //playerのsetterとgetter
    void set_p(string p_name){
        this->p_name = p_name;
    }
    void set_int(int p){
        this->p = p;
    }
    string get_p() const{
        return p_name;
    }
    int get_int(){
        return p;
    }
    
};

string pitching[] = {
    "course_auto",
    "outside",
    "inside",
    "below",
    "close",
    "make_them_hit",
    
};

string batting[] = {
    "free_hitting",
    "right_hitting",
    "left_hitting",
    "center_hitting",
    "ground",
    "wait",
    
    //ランナーがいる時,,,
    "hit_and_run",
    "squeeze",
    "safety_b",
    "send_b",
};

int order_number[] = {0, 1, 2, 3, 4, 5};



//プレーヤー名を受け取り、クラス変数に格納する関数
void get_name(player_value *p)
{
    //プレーヤー名
    string p_name;
    //プレーヤー番号(static)
    static int player = 1;
    
    cout << "Player" << player << "'s name: ";
    cin >> p_name;
    p->set_p(p_name);

    //プレーヤー番号をインクリメント
    ++player;
}

//roopの入力を受け付ける関数
int get_roop_input()
{
    int roop = 0;
    cin >> roop;
    return roop;
}

//回数を設定する為の関数
int set_roop(){
    
    int roop;
    
    //1-9の間の整数を受け取るまでループ
    do{
        cout << "Set roop number 1-9: ";
        roop = get_roop_input();
        if (roop == 0){
            cin.clear();
            cin.ignore(10000,'\n');
            return 1;
            //break;
        }
    } while (roop <= 0 || roop > 9);

    return roop;
}

//引き分け時に追加のループを追加する関数(オーバーロード)
int set_roop(int roop)
{
    ++roop;
    return roop;
}

//入力を受ける関数
void get_input(player_value *p1, player_value *p2){
    
    //入力された文字列を受け取る
    get_name(p1);
    get_name(p2);

    //対戦カードを出力
    cout << p1->get_p() << " VS " << p2->get_p() << endl;
}

//コマンドを受け取る関数(実際のゲーム部分)
void game_start(player_value *p1, player_value *p2)
{
    random_device rand;
    mt19937 mt(rand());
    mt.seed(rand());
    
    int roop = set_roop();
    int first_player = get_random(1, 3);
    //int first_player = 1 + mt() % 2;

    int command_t, command_b, a_or_d = 1;

    cout << "Player" << first_player << " is Top!" << endl << endl;
    for (int i = 0; i < roop; i++)
    {
        //攻撃
        command_t = get_command(first_player, a_or_d);
        cout << "player" << first_player << " choose: " << command_t << endl;
        a_or_d = check_zero_one(a_or_d);
        first_player = check_zero_one(first_player);
        
        //守備
        command_b = get_command(first_player, a_or_d);
        cout << "player" << first_player << " choose: " << command_b << endl;
        a_or_d = check_zero_one(a_or_d);
        first_player = check_zero_one(first_player);

        //勝敗判断(暫定的な処理)
        if (check_winner(command_t, command_b))
        {
            static int count = 1;
            cout << endl << "Player" << first_player << " win!" << endl;
            p1->set_int(count);
            ++count;
        }
        else{
            static int count = 1;
            int scope_player = check_zero_one(first_player);
            cout << endl << "Player" << scope_player << " win!" << endl;
            p2->set_int(count);
            ++count;
        }

        //最終的な勝敗判断
        if (p1->get_int() > (roop_check(roop) / 2)){
            cout << "Player" << first_player << " win!!!!" << endl;
            break;
        }
        else if (p2->get_int() > (roop_check(roop) / 2)){
            int scope_player = check_zero_one(first_player);
            cout << "Player" << scope_player << " win!!!!" << endl;
            break;
        }
    }

}

int get_random(int min,int max)
{
	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

//結果を判定する関数 trueが攻撃成功、falseが失敗
bool check_winner(int player1, int player2)
{
    //乱数生成の準備
    random_device rand;
    mt19937 mt(rand());
    uniform_int_distribution<> rand10(0, 99);        // [0, 99] 範囲の一様乱数(関数呼び出しでは使えない？)
    int fin = get_random(0, 99);

    if (player1 == player2 && player1 < 4 && player2 < 4)
    {
        //int fin = rand100(mt);
        cout << fin << endl;
        if (fin < 25)
        {
            cout << endl << "i! HIT !" << endl;
            return true;
        }
        else if (fin < 30)
        {
            cout << endl << "i!!!! HOME RUN !!!!" << endl;
            return true;
        }
        else 
        {
            cout << endl << "i...OUT..." << endl;
            return false;
        }
    }

    else if ((player1 == 2 || player1 == 3) && (player2 == 2 || player2 == 3))
    {
        //int fin = rand100(mt);
        if (fin < 10)
        {
            cout << endl << "ei! HIT !" << endl;
            return true;
        }
        else if (fin < 12)
        {
            cout << endl << "ei!!!! HOME RUN !!!!" << endl;
            return true;
        }
        else 
        {
            cout << endl << "ei...OUT..." << endl;
            return false;
        }
    }

    else
    {
        //int fin = rand100(mt);
        if (fin < 15)
        {
            cout << endl << "e! HIT !" << endl;
            return true;
        }
        else if (fin < 22)
        {
            cout << endl << "e!!!! HOME RUN !!!!" << endl;
            return true;
        }
        else 
        {
            cout << endl << "e...OUT..." << endl;
            return false;
        }
    }
}

//引数が1の時2を、2の時1を返す関数
int check_zero_one(int i){
    if (i == 1)
    {
        return 2;
    }

    else if (i == 2)
    {
        return 1;
    }

    else
    {
        cout << "error" << endl;
        return 0;
    }
}

//勝利条件ループの奇数偶数場合分け処理
int roop_check(int roop)
{
    //2の倍数なら返す
    if(roop % 2 == 0){
        return roop;
    }

    //それ以外なら1を足して返す
    else if (roop != 1){
        return roop - 1;
    }

    else{
        return roop;
    }
}


//player番号, 攻撃 = 1 / 守備 = 2;
int get_command(int player, int a_or_d)
{
    
    int command;
    cout << "This is player" << player << "'s turn!" << endl;
    cout << endl;
    
    if (a_or_d == 1){
        for (int i = 0; i < array_length(order_number); i++)
        {
            cout << order_number[i] << ": " << batting[i] << endl;
        }
    }
    
    if (a_or_d == 2){
        for (int i = 0; i < array_length(order_number); i++)
        {
            cout << order_number[i] << ": " << pitching[i] << endl;
        }
    }
    
    
    do{
        cout << endl << "Put in command!: ";
        cin >> command;
        if (command < 0 || command > array_length(order_number))
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
    }while (command < 0 || command > array_length(order_number));

    return command;
}

int main()
{
    //player1とplayer2のオブジェクトを取得
    player_value p1;
    player_value p2;
    
    //名前の入力
    get_input(&p1, &p2);

    //ゲームの開始
    game_start(&p1, &p2);

    return 0;
}