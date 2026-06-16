//2554709 黒田蒼史　5月14日作成
// strCopy.c
// 文字列を色々と処理してみる
// (1)文字列の長さ、(2)文字列をコピー、(3)文字列を連結（追加）

/*　実行結果
soshi@soshinoMacBook-Air 06 % ./strCopy
文字列1 ?
abc
文字列2 ?
ddd
文字列1「abc」の長さ: 3
文字列2「ddd」の長さ: 3
コピー後の文字列1「abc」,文字列2「abc」
連結後の文字列1「abcabc」,文字列2「abc」
*/

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数
int strLength(char str[]){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
// 文字列strを文字列newにコピーする関数
void strCopy(char new[], char str[]){
    int i = 0;
    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
}
// 文字列strに文字列addを連結する関数
void strAppend(char str[], char add[]){
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        i++;}
    while (add[j] != '\0') {
        str[i] = add[j];
        i++;
        j++;}
    str[i] = '\0';
}
// メイン
int main(void)
{
    char str1[MAX_LEN];  // 入力文字列1
    char str2[MAX_LEN];  // 入力文字列2

    // データの入力
    printf("文字列1 ?\n");
    scanf("%s", str1);
    printf("文字列2 ?\n");
    scanf("%s", str2);

    // 処理と結果出力
    printf("文字列1「%s」の長さ: %d\n", str1, strLength(str1));
    printf("文字列2「%s」の長さ: %d\n", str2, strLength(str2));

    strCopy(str2, str1);
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strAppend(str1, str2);
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
