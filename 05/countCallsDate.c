//2554709 黒田蒼史　4月30日作成
// countCalls.c
// 関数が呼び出された回数を記録する（staticを使う）

/*　実行結果
soshi@soshinoMacBook-Air 05 % ./countCallsDate
関数呼出し回数:1 経過時間:1777513557秒 時刻:Thu Apr 30 10:45:57 2026

関数呼出し回数:2 経過時間:2秒 時刻:Thu Apr 30 10:45:59 2026

関数呼出し回数:3 経過時間:2秒 時刻:Thu Apr 30 10:46:01 2026

関数呼出し回数:4 経過時間:0秒 時刻:Thu Apr 30 10:46:01 2026

関数呼出し回数:5 経過時間:1秒 時刻:Thu Apr 30 10:46:02 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void countCalls(void) 
{
    static int count = 0;  // static変数: 関数が終了しても値を保持する
    static time_t lastTime = 0;  // 同上: 前回呼ばれた時刻(通算秒)
    time_t now = time(NULL);
    int diff = now - lastTime;  // 前回との差分を計算

    count++;
    printf("関数呼出し回数:%d 経過時間:%d秒 時刻:%s\n", count, diff,ctime(&now));
    lastTime = now;
}

int main(void) 
{   int i;

    srandom(time(NULL));

    for (i = 0; i < 5; i++) {   // 適当な回数繰り返す
        countCalls();           // 関数呼出し
        sleep(random() % 4);    // 0～3秒待つ
    }

    return 0;
}
