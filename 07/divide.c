// divide.c
// 複数の値を返す関数の例

#include <stdio.h>

// shou ← div1 / div2
// amari ← div1 % div2 を入れて返す関数
// また、割り算ができない場合は1を返す
int divide(int div1, int div2, int *shou, int *amari)  // *の有無に注意！
{
    if (div2 == 0) {
        return 1;    // 割り算できない（エラー）
    }

    *shou = div1 / div2;    // *に注意
    *amari = div1 % div2;   // *に注意

    return 0;    // 正常終了
}

// divide関数のテスト用メイン
int main(void)
{
    int a;  // 割られる数
    int b;  // 割る数
    int c;  // 商
    int d;  // 余り

    // 割られる数と、割る数を入力
    printf("割られる数と割る数の2つの数値を入力：\n");
    scanf("%d %d", &a, &b);

    // 割り算を実行
    if (divide(a, b, &c, &d)) {  // &の有無に注意！
        printf("0で割ることはできません\n");
        return 1;  // エラー終了
    }

    // 結果を出力
    printf("%dを %dで割ると\n", a, b);
    printf("商: %d\n", c);
    printf("余り: %d\n", d);

    return 0;
}
