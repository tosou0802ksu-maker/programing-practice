//2554709 黒田蒼史　4月30日作成
//loopFunc3.c
//loopFunc2.c を改造して、次のような出力を出すプログラム loopFunc3.c を作成

/* 実行結果
soshi@soshinoMacBook-Air 05 % ./loopFunc3
C: start
max = 1, num = -1
max = 10, num = 2
max = 100, num = -22
max = 1000, num = 48
max = 10000, num = 182
max = 100000, num = -310
max = 1000000, num = -2114
max = 10000000, num = -3162
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXCOUNT 10000000

void init(void) {   
    srandom(time(NULL));
    printf("C: start\n");}

int upDown(long max) {
    int count = 0;
    long i;

    for (i = 0; i < max; i++) {
        if (random() % 2 == 0){
            count -= 1;}
        else {count += 1;}
    }
    return count;
}

void dispResult(long max, int result){
    printf("max = %ld, num = %d\n", max, result);
}

int main(void) {
    long max;
    int result;

    init();

    for (max = 1; max <= MAXCOUNT; max *= 10) {
        result = upDown(max);
        dispResult(max, result);}

    return 0;}