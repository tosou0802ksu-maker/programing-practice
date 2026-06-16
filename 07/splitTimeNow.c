// 2554709 黒田蒼史 5月27日作成
// splitTimeNow.c
//splitTime.cを修正して現在時刻の時・分・秒を表示するプログラム

/*実行結果
soshi@soshinoMacBook-Air 07 % ./splitTimeNow                    
現在時刻（1779890758秒）は 23時 5分 58秒 です
*/

#include <stdio.h>
#include <time.h>

void splitTime(
    int totalSeconds,
    int *hours,
    int *minutes,
    int *seconds){

    *hours = ((totalSeconds / 3600)+9) % 24;
    *minutes = (totalSeconds % 3600) / 60;
    *seconds = totalSeconds % 60;}

int main(void){
    int hours;
    int minutes;
    int seconds;
    time_t totalSeconds;

    totalSeconds = time(NULL);

    splitTime(totalSeconds,
              &hours,
              &minutes,
              &seconds);

    printf("現在時刻（%ld秒）は %d時 %d分 %d秒 です\n",totalSeconds,hours,minutes,seconds);

    return 0;}