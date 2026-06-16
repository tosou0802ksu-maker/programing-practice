//2554709 黒田蒼史　4月30日作成
// loopFunc1.c
// 実行時間の比較（C言語版）
// 処理毎に関数に分割したもの（結果表示以外）

/*　実行結果
soshi@soshinoMacBook-Air 05 % ./loopFunc1
C: start
num = -4082
*/

#include <stdio.h>      // printf()などを使うのに必要
#include <stdlib.h>     // random()などを使うのに必要
#include <time.h>       // time()などを使うのに必要

#define MAXCOUNT 10000000   // ループ回数

void init(void) {
    srandom(time(NULL));  // 乱数のシードを初期化

    printf("C: start\n");
}

// 乱数を使って処理
int upDown(long max) 
{
    int count = 0;  // 結果を入れる。0で初期化
    long i;         // ループ変数

    for (i = 0; i < max; i++) {
        if (random() % 2 == 0) { // 偶数の場合
            count -= 1;          // 1減らす
        } else {                 // 奇数の場合
            count += 1;          // 1増やす
        }
    }

    return count;       // 結果を返す
}

void dispResult(int result){
    printf("num = %d\n",result);}

// メイン
int main(void) 
{   int result;  // 結果を入れる

    init();                       // 初期化

    result = upDown(MAXCOUNT);    // 処理

   dispResult(result);

    return 0;}
