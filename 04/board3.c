//2554709 黒田蒼史　4月27日作成
//board3.c
//9x9のマス目のゲーム盤を2次元配列で表現する
//それぞれのマス目にコマが無い状態を0、黒コマがある状態を1、白コマがある状態を2 で表す

/*実行結果
soshi@soshinoMacBook-Air 04 % ./board3              
1 0 2 0 2 0 2 0 1 
0 1 0 2 0 2 0 1 0 
2 0 1 0 2 0 1 0 2 
0 2 0 1 0 1 0 2 0 
2 0 2 0 1 0 2 0 2 
0 2 0 1 0 1 0 2 0 
2 0 1 0 2 0 1 0 2 
0 1 0 2 0 2 0 1 0 
1 0 2 0 2 0 2 0 1 
*/
#include <stdio.h>

int main(void) {
    int board[9][9];
    int a, b;
    //配列を初期化する
    for(a = 0; a < 9; a++) {
        for(b = 0; b < 9; b++) {
            if(a == b || a + b == 8){
                board[a][b] = 1;}//黒コマを表示
            else if((a + b) % 2 == 0){
                board[a][b] = 2;}//白コマを表示
            else {board[a][b] = 0;}}//何も表示しない
    }

    // 表示する
    for(a = 0; a < 9; a++){
        for(b = 0; b < 9; b++){
            printf("%d ", board[a][b]);}
        printf("\n");}

    return 0;
}