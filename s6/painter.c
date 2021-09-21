#include <stdio.h>

#define CELL_START 3
#define CELL_END 8
int main(void)
{
    int a[8][8];

    //全マスを0で初期化
    for (int y = 0; y < CELL_END; y++) {
        for (int x = 0; x < CELL_END; x++) {
            a[y][x] = 0;
        }
    }

    //最下段のa[7][2]からa[7][7]までを1で初期化
    for (int x = CELL_START; x < CELL_END; x++) {
        a[7][x] = 1;
    }

    //以下2の形を作ろうの会
    a[3][4] = 1;
    a[3][5] = 1;
    a[3][6] = 1;
    a[4][3] = 1;
    a[4][7] = 1;
    a[5][5] = 1;
    a[5][6] = 1;
    a[6][4] = 1;

    for (int y = CELL_START; y < CELL_END; y++) {
        int cnt = 0;
        for (int x = CELL_START; x < CELL_END; x++) {
            if (a[y][x] == 1) {
                cnt++;
            } 
            else if (cnt > 0) {
                for (int x2 = 0; x2 < CELL_START; x2++) {
                    if (a[y][x2] == 0) {
                        a[y][x2] = cnt;
                        cnt = 0;
                        break;
                    }
                }
            }
        }
        //最右辺が1だった場合の処理
        if (cnt > 0) {
            for (int x2 = 0; x2 < CELL_START; x2++) {
                if (a[y][x2] == 0) {
                    a[y][x2] = cnt;
                    cnt = 0;
                    break;
                }
            }
        }
    }

    for (int x = CELL_START; x < CELL_END; x++) {
        int cnt = 0;
        for (int y = CELL_START; y < CELL_END; y++) {
            if (a[y][x] == 1) {
                cnt++;
            } else if (cnt > 0) {
                for (int y2 = 0; y2 < CELL_START; y2++) {
                    if (a[y2][x] == 0) {
                        a[y2][x] = cnt;
                        cnt = 0;
                        break;
                    }
                }
            }
        }
        if (cnt > 0) {
            for (int y2 = 0; y2 < CELL_START; y2++) {
                if (a[y2][x] == 0) {
                    a[y2][x] = cnt;
                    cnt = 0;
                    break;
                }
            }
        }
    }

    //数字の移動(該当する数字が無ければ9を代入)
    for (int y = CELL_START; y < CELL_END; y++) {
        int cnt = 0;
        while (a[y][CELL_START - 1] == 0) {
            
            for (int x = CELL_START - 2; x >= 0; x--) {
                a[y][x + 1] = a[y][x];
            }
            a[y][0] = 0;
            cnt++;
            if (cnt > CELL_START && a[y][CELL_START - 1] == 0)
            {
                a[y][CELL_START - 1] = 9;
                break;
            }
        }
    }

    for (int x = CELL_START; x < CELL_END; x++) {
        int cnt = 0;
        while (a[CELL_START - 1][x] == 0) {
            for (int y = CELL_START - 2; y >= 0; y--) {
                a[y + 1][x] = a[y][x];
            }
            a[0][x] = 0;
            cnt++;
            if (cnt > CELL_START && a[CELL_START - 1][x] == 0)
            {
                a[CELL_START - 1][x] = 9;
                break;
            }
        }
    }

    //記述
    for (int y = 0; y < CELL_END; y++) {
        for (int x = 0; x < CELL_END; x++) {
            if (y < CELL_START || x < CELL_START) {
                if (a[y][x] > 0) {
                    printf(" %d", a[y][x]);
                } else {
                    printf("  ");
                }
                continue;
            }

            if (a[y][x] == 1) {
                printf(" 0");
            } else {
                printf("  ");
            }
        }
        putchar('\n');
    }

    return 0;
}