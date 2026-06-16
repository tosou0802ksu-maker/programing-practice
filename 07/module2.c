//2554709 黒田蒼史　5月21日作成
// module2.c
//結果を出力する、printBoard()関数は、module2.c に置く。

#include <stdio.h>
#include "common.h"
#include "module2.h"

extern int board[SIZE][SIZE];

// 盤面表示
void printBoard(void)
{
    int x, y;

    printf("  ");

    for (x = 0; x < SIZE; x++) {
        printf("%2d", x+1);
    }

    printf("\n");

    for (y = 0; y < SIZE; y++) {

        printf("%2d ", y+1);

        for (x = 0; x < SIZE; x++) {
            printf("%c ", board[y][x] ? 'Q' : '.');
        }

        printf("\n");
    }
}