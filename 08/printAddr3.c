//2554709　黒田蒼史　5月28日作成
//printAddr3.c
//メモリを直接書き換えて、「int型 変数 a」の値を 123（10進数の数値） にするプログラム

/*実行結果
soshi@soshinoMacBook-Air 08 % ./printAddr3
int型変数aの値 = 123
int型変数aのアドレス = 0x16eeb7348、サイズ = 4

char型変数cの値 = 'A'
char型変数cのアドレス = 0x16eeb7347、サイズ = 1

double型変数dの値 = 1.230000
double型変数dのアドレス = 0x16eeb7338、サイズ = 8

文字列sの値 = moji
文字列sのアドレス = 0x16eeb7330、サイズ = 5
*/

#include <stdio.h>

int main(void){
    int a = 5;
    char c = 'A';
    double d = 1.23;
    char s[5] = "moji";

    s[24] = 123;   // ←1行追加（オフセットは自分の環境で確認）

    printf("int型変数aの値 = %d\n", a);
    printf("int型変数aのアドレス = %p、サイズ = %zd\n", &a, sizeof(a));
    printf("\n");

    printf("char型変数cの値 = '%c'\n", c);
    printf("char型変数cのアドレス = %p、サイズ = %zd\n", &c, sizeof(c));
    printf("\n");

    printf("double型変数dの値 = %lf\n", d);
    printf("double型変数dのアドレス = %p、サイズ = %zd\n", &d, sizeof(d));
    printf("\n");

    printf("文字列sの値 = %s\n", s);
    printf("文字列sのアドレス = %p、サイズ = %zd\n", s, sizeof(s));

    return 0;
}