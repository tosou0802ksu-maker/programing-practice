//2554709 黒田蒼史　4月19日作成
//wcount.c
//入力された複数の行からなるテキスト文について、含まれる単語の数を数えるプログラム
//単語とは、スペース、タブ、改行で区切られた文字の集まりとする。入力の最後は「改行のみ」からなる行とする。
//入力された文字数（改行文字を含む）と行数（最後の行も含める）も出すこと.

/*実行結果
soshi@soshinoMacBook-Air 03 % ./wcount
The quick brown fox jump over the lazy dog.
this is a pen.

単語数: 13
文字数: 59
行数: 3
*/

#include <stdio.h>

int main(void){
    int c;                 // getcharの戻り値はint型
    int in_word = 0;       // 単語中かどうかのフラグ
    int word_count = 0;    // 単語数
    int char_count = 0;    // 文字数
    int line_count = 0;    // 行数
    int prev = 0;          // 直前の文字

    while (1) {
        c = getchar();

        // 改行のみの行で終了
        if (c == '\n' && prev == '\n') {
            line_count++;  // 最後の空行もカウント
            break;
        }

        char_count++;

        // 行数のカウント
        if (c == '\n') {
            line_count++;
        }

        // 単語の判定（空白・タブ・改行で区切る）
        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0;
        } else {
            if (in_word == 0) {
                word_count++;
                in_word = 1;
            }
        }

        prev = c;
    }

    printf("単語数: %d\n", word_count);
    printf("文字数: %d\n", char_count);
    printf("行数: %d\n", line_count);

    return 0;
}