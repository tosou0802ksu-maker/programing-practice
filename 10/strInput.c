//2554709　黒田蒼史 6月11日作成
// strInput.c
// 入力された文字列を配列で記憶する

/*実行結果
soshi@soshinoMacBook-Air 10 % ./strInput
1 行目？
1111 test 
2 行目？
22 aaa
3 行目？
3 bbb
4 行目？
44444
5 行目？
55
ポインタの配列:
0: "1111 test"
1: "22 aaa"
2: "3 bbb"
3: "44444"
4: "55"
2次元配列:
0: "1111 test"
1: "22 aaa"
2: "3 bbb"
3: "44444"
4: "55"

*/

#include <stdio.h>
#include <string.h>

#define SIZE 5      // 文字列の数
#define LENGTH 100  // 文字列の長さ

int main(void)
{
    int i;
    char input[LENGTH];  // 入力文字列

    // ポインタの配列の宣言
    char s0[LENGTH], s1[LENGTH], s2[LENGTH], s3[LENGTH], s4[LENGTH]; // 文字列を格納する配列
    char *strs[SIZE] = { s0, s1, s2, s3, s4 };  // ポインタの配列

    // 2次元配列の宣言
    char string[SIZE][LENGTH];

    // 1行ずつ入力して、それぞれの文字列領域に格納する
    for (i = 0; i < SIZE; i++) {
        printf("%d 行目？\n", i + 1);
        fgets(input, LENGTH, stdin);    // 1行の入力を取得
        input[strlen(input) - 1] = '\0';    // 最後の改行を取り除く

        // ポインタの配列が指す文字列に、入力された文字列を入れる
        strcpy(strs[i],input);
        // 2次元配列に、入力された文字列を入れる
        strcpy(string[i],input);}

    // 出力
    printf("ポインタの配列:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d: \"%s\"\n",i,strs[i]);
    }

    printf("2次元配列:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d: \"%s\"\n",i,string[i]);
    }

    return 0;
}
