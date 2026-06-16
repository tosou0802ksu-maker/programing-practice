//2554709　黒田蒼史　6月9日作成
// charCount2.c
// 1行を入力して、その中に含まれる文字種別をカウントする
// 配列版

/*実行結果
文字列？ The eruption, which began overnight, produced explosions
 heard as far away as Taormina and Catania, which are about 50 kilometers
  and 40 kilometers (31 miles and 25 miles) away, respectively,
   according to　several people who posted footage on social media.
数字    : 8
英文字  : 200
 大文字 : 3
 小文字 : 197
スペース: 40
その他  : 8
トータル: 256
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
    fgets(str, MAX_LEN, stdin);  // 1行の入力を取得
    
  
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
