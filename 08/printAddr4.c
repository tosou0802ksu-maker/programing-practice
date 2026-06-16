//2554709　黒田蒼史　5月28日作成
// printAddr4.c
//メモリを直接書き換えて、「int型 変数 a」の値を 1234567890（10進数の数値） にするプログラム

/*実行結果
soshi@soshinoMacBook-Air 08 % ./printAddr4
int型変数aの値 = 1234567890
int型変数aのアドレス = 0x16ee03348、サイズ = 4

char型変数cの値 = 'A'
char型変数cのアドレス = 0x16ee03347、サイズ = 1

double型変数dの値 = 1.230000
double型変数dのアドレス = 0x16ee03338、サイズ = 8

文字列sの値 = moji
文字列sのアドレス = 0x16ee03330、サイズ = 5
*/

#include <stdio.h>

int main(void){
    int a = 5;
    char c = 'A';
    double d = 1.23;
    char s[5] = "moji";

    s[24] = 0xD2;
    s[25] = 0x02;
    s[26] = 0x96;
    s[27] = 0x49;

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