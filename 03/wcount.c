//2554709 黒田蒼史　4月22日作成
//wcount.c
//入力された複数の行からなるテキスト文について、含まれる単語の数を数えるプログラム
//単語とは、スペース、タブ、改行で区切られた文字の集まりとする。入力の最後は「改行のみ」からなる行とする。
//入力された文字数（改行文字を含む）と行数（最後の行も含める）も出すこと.

/*実行結果
soshi@soshinoMacBook-Air 03 % ./wcount
The quick brown fox jumps over the lazy dog.
this is a pen.

文字数: 61
単語数: 13
行数: 3
*/

#include <stdio.h>

int main(void) {
    int c;                  
    int chars = 0;          // 文字数
    int words = 0;          // 単語数
    int lines = 0;          // 行数
    int in_word = 0;        //現在単語の中にいるか
    int empty_line = 0;     //直前が改行だけの行かどうか


    while ((c = getchar()) != EOF) {
        chars++;            //文字を読むとカウンと

        if (c == '\n') {    //改行が入力された場合
            lines++;        //行数を増やす

            if (empty_line) {
                break;      //直前も改行なら終了
            }
            empty_line = 1; //改行のみ＋１
        } else {
            empty_line = 0; //文字だと空行でない
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0;    //単語の外に出る
        } else {
            if (!in_word) { //新しい語が来たとき
                words++;    //新しい単語をカウント
                in_word = 1;//単語の中に入る
            }
        }
    }

    printf("文字数: %d\n", chars);
    printf("単語数: %d\n", words);
    printf("行数: %d\n", lines);

    return 0;
}