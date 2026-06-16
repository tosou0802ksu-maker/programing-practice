//2554709 黒田蒼史 6月10日作成
//wordLength.c
//1行を入力して、それをスペースやTAB（以下、スペース関連文字と呼ぶ）
//で区切られた複数の単語に分解し、それらの単語の中で、長さが一番長いものと、
//一番短いものを、それぞれの長さと共に出力するようなプログラム
//なお、最長・最短の単語が複数あるときは、最初に出現したものだけの表示。

/*実行結果
単語列？
 this  is a  pen
最長の単語(4): this
最短の単語(1): a
soshi@soshinoMacBook-Air 09 % ./wordLength
単語列？
漢字や 記号など $#&.() も入力はできるが	単にスペースが あるかを見ているだけ
最長の単語(30): あるかを見ているだけ
最短の単語(6): $#&.()

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 100

int main(void)
{
    char input[MAX_LENGTH];
    char *words[MAX_WORDS];
    int wcount = 0;
    int inWord = 0;
    char *pt;

    printf("単語列？\n");
    fgets(input, MAX_LENGTH, stdin);

    input[strcspn(input, "\n")] = '\0';

    /* 単語を切り出す */
    for (pt = input; *pt != '\0'; pt++) {
        if (isspace(*pt)) {
            if (inWord){
                *pt = '\0';
                inWord = 0;}} 
            else {
            if (!inWord) {
                words[wcount] = pt;
                wcount++;
                inWord = 1;}}}

    if (wcount == 0) {
        printf("単語がありません\n");
        return 0;}

    char *longest = words[0];
    char *shortest = words[0];
    
    for (int i = 1; i < wcount; i++) {

        if (strlen(words[i]) > strlen(longest)) {
            longest = words[i];
        }

        if (strlen(words[i]) < strlen(shortest)) {
            shortest = words[i];
        }}

    printf("最長の単語(%lu): %s\n",
           strlen(longest), longest);

    printf("最短の単語(%lu): %s\n",
           strlen(shortest), shortest);

    return 0;
}