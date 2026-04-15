//disptime.c
//現在時刻をHH:MM：SSの形式で、1秒ごとに表示する
//10秒おきに音を出し、1分ごとにメッセージを出す
//
//2554709 黒田蒼史 2026/4/9作成

/*soshi@soshinoMacBook-Air 01 % ./disptime
現在時刻: 01:26:31
現在時刻: 01:26:32
現在時刻: 01:26:33
現在時刻: 01:26:34
現在時刻: 01:26:35
現在時刻: 01:26:36
現在時刻: 01:26:37
現在時刻: 01:26:38
現在時刻: 01:26:39
現在時刻: 01:26:40
現在時刻: 01:26:41
^C
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    time_t t;
    int h, m, s;

    while (1) {
        t = time(NULL);
        t += 9 * 3600;


        h = (t / 3600) % 24;
        m = (t / 60) % 60;
        s = t % 60;

        printf("現在時刻: %02d:%02d:%02d\n",  h, m, s);

        if (s % 10 == 0) {
            printf("\a");
            fflush(stdout);
        }
        
        if (s == 0){
            printf("*** 1分経過! ***\n");
        }
        
        sleep(1);
    } 

    return 0;
}   
