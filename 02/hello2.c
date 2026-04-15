// hello2.c
// 変数の値や文字列を表示してみる

#include <stdio.h>

int main(void) {
	int inum;    // int型（整数型）の変数を宣言
	double fval; // double型（浮動小数点型）の変数を宣言

    inum = (9 + 3) * 4;
    fval = (1.2 + 4) * 3.5;

    printf("Hello!\n");
    printf("計算式1: (9 + 3) * 4 = %d\n", inum);
    printf("計算式2: (1.2 + 4) * 3.5 = %f\n", fval);

    printf("文字列: %s\n", "私の名前");

    printf("\\nがないと最後は改行しません。");
    printf("途中で\n改行\nすることもできます\n");
}
