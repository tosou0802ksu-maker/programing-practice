//2554709 黒田蒼史 6月10日作成
//charCount3
//最後の'\n'を入力直後に除いて、また、
//Ctrl-Dでの入力終了に対応するように修正したプログラム

/*実行結果
soshi@soshinoMacBook-Air 09 % ./charCount3                  
文字列？ 
数字    : 0
英文字  : 0
 大文字 : 0
 小文字 : 0
スペース: 0
その他  : 0
トータル: 0

*/

#include <stdio.h>
#include <string.h> // strlen()などを使うため
#include <ctype.h>  // isdigit()やisupper()などを使うため

#define MAX_LEN 1000    // 入力文字の最大数

int main(void)
{
    char str[MAX_LEN];  // 入力用文字配列
    char *p;
    size_t len, i;      // 文字列の長さ、ループカウンタ
    int digits = 0;     // 数字の数
    int alphabets = 0;  // アルファベットの数
    int uppercase = 0;  // 小文字の数
    int lowercase = 0;  // 大文字の数
    int spaces = 0;     // スペース,TABの数
    int others = 0;     // その他の文字の数
    int total = 0;      // 全体の数

    printf("文字列？ ");
    if(fgets(str, MAX_LEN, stdin) == NULL){
        return 0;
    }  // 1行の入力を取得
    
    len = strlen(str);

    if(len > 0&& str[len-1] == '\n'){
        str[len -1] = '\0';
    }
        p = str;    // 文字列の先頭アドレス

    while (*p != '\0'){
        total++;
        if (isdigit(*p)) {
            digits++;}
        else if (isalpha(*p)){
            alphabets++;
            if (isupper(*p)){
                uppercase++;}
            else if (islower(*p)){
                lowercase++;}}
        else if (isspace(*p)){
            spaces++;}
        else{
            others++;}
        p++;    // 次の文字へ
    }


    // 結果を出力
    printf("数字    : %d\n", digits);
    printf("英文字  : %d\n", alphabets);
    printf(" 大文字 : %d\n", uppercase);
    printf(" 小文字 : %d\n", lowercase);
    printf("スペース: %d\n", spaces);
    printf("その他  : %d\n", others);
    printf("トータル: %d\n", total);

    return 0;
}
