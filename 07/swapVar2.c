//2554709　黒田蒼史　5月27日作成
// swapVar2.c
// 変数の値を入れ換える（正しく動く版）

/*実行結果
soshi@soshinoMacBook-Air 07 % ./swapVar2
変数num1の値は5です。
変数num2の値は10です。
値を交換します。
変数num1の値は10です。
変数num2の値は5です。
*/

#include <stdio.h>

// 正しいswap関数
void swap(int *px, int *py){
    int tmp;

    tmp = *px;// ポインタを使って値を交換
    *px = *py;
    *py = tmp;
}

int main(void){
    int num1 = 5;
    int num2 = 10;

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);
    printf("値を交換します。\n");

    // 変数のアドレスを渡す
    swap(&num1, &num2);

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);

    return 0;
}
