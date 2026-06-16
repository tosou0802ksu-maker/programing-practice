// 2554709 黒田蒼史　5月19日作成
// strNumber.c
// 入力文字列を10進数の数字列として数値に変換する

/*実行結果
soshi@soshinoMacBook-Air 06 % ./strNumber
文字列 ?
123
文字列「123」,10進数: 123
*/

#include <stdio.h>

#define MAX_LEN 100

// 文字列を数値に変換
int strNumber(char str[]){
    int i = 0;
    int num = 0;

    while (str[i] != '\0'){
        num = num * 10 + (str[i] - '0');
        i++;}

    return num;
}

int main(void){
    char str[MAX_LEN];

    printf("文字列 ?\n");
    scanf("%s", str);

    printf("文字列「%s」,10進数: %d\n", str, strNumber(str));
    return 0;
}