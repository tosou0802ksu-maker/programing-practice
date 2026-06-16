// 2554709 黒田蒼史　5月19日作成
// strUpper.c
// 入力された文字列に含まれる英小文字を全て大文字に変換する

/*実行結果
soshi@soshinoMacBook-Air 06 % ./strUpper
文字列 ?
abcDE12xyz
文字列「ABCDE12XYZ」
*/

#include <stdio.h>
#define MAX_LEN 100

// 文字が英小文字かどうか判定する
int isLower(char c){
    return c >= 'a' && c <= 'z';}

// 英小文字を大文字に変換して返す（英小文字かどうかのチェックはしない）
int toUpper(char c){
    return c - ('a' - 'A');}
// 
void strUpper(char str[]){
    int i = 0;

    while (str[i] != '\0'){
        if (isLower(str[i])){
            str[i] = toUpper(str[i]);}
        i++;}}


int main(void){
    char str[MAX_LEN];

    printf("文字列 ?\n");
    scanf("%s", str);
    strUpper(str);

    printf("文字列「%s」\n", str);

    return 0;}