//disptime.c
//現在時刻をHH:MM：SSの形式で、1秒ごとに表示する
//10秒おきに音を出し、1分ごとにメッセージを出す

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