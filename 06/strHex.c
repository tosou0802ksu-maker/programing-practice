// 2554709 黒田蒼史　5月19日作成
// strHex.c
// 入力文字列を16進数の数字列として数値に変換する

/*実行結果
soshi@soshinoMacBook-Air 06 % ./strHex
文字列 ? 7ff
文字列「7ff」,16進数: 0x7FF (2047)
soshi@soshinoMacBook-Air 06 % ./strHex
文字列 ? 123
文字列「123」,16進数: 0x123 (291)
soshi@soshinoMacBook-Air 06 % ./strHex
文字列 ? BEeF
文字列「BEeF」,16進数: 0xBEEF (48879)
*/
#include <stdio.h>

#define MAX_LEN 100

// 16進数1文字を数値に変換する関数
int hexDigit(char c){
    if ('0' <= c && c <= '9'){
        return c - '0';}
    else if ('A' <= c && c <= 'F'){
        return c - 'A' + 10;}
    else if ('a' <= c && c <= 'f'){
        return c - 'a' + 10;}

    return 0;
}

int strHex(char str[]){
    int i = 0;
    int v = 0;

    while (str[i] != '\0') {
        v = v * 16 + hexDigit(str[i]);
        i++;
    }

    return v;
}

int main(void){
    char str[MAX_LEN];
    int num;

    printf("文字列 ? ");
    scanf("%s", str);

    num = strHex(str);

    printf("文字列「%s」,16進数: 0x%X (%d)\n", str, num, num);

    return 0;
}