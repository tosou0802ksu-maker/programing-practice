//2554709　黒田蒼史　5月21日作成
//module1.c
//問題を解くための、solve8Queens()関数、is_safe()関数
//dispCount()関数は、module1.c に置く。

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "module1.h"

extern int board[SIZE][SIZE];
static int count = 0;

// 指定場所に置けるか判定
static int is_safe(int row, int col){
    int x, y;

    for (y = 0; y < row; y++){
        if (board[y][col]){
            return 0;}}

    for (y = row, x = col; y >= 0 && x >= 0; y--, x--){
        if (board[y][x]){
            return 0;}}

    for (y = row, x = col; y >= 0 && x < SIZE; y--, x++) {
        if (board[y][x]){
            return 0;}}

    return 1;
}

// 再帰関数
int solve8Queens(int row){
    int cols[SIZE];
    int x, y, temp;

    count++;

    if (row >= SIZE){
        return 1;}

    for (y = 0; y < SIZE; y++){
        cols[y] = y;}

    for (y = 0; y < SIZE; y++){
        x = random() % SIZE;
        temp = cols[y];
        cols[y] = cols[x];
        cols[x] = temp;}

    for (y = 0; y < SIZE; y++){
        int col = cols[y];

        if (is_safe(row, col)){
            board[row][col] = 1;

            if (solve8Queens(row + 1) == 1){
                return 1;}

            board[row][col] = 0;}}

    return 0;
}

void dispCount(void){
    printf("count=%d\n", count);
}