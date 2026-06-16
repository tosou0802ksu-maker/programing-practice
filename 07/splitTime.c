//2554709 黒田蒼史　5月21日作成
//splitTime.c
//秒から時分秒に変換する処理を行う

/*実行結果
soshi@soshinoMacBook-Air 07 % ./splitTime
秒数？
132783
132783は36時間53分3秒です
*/

#include <stdio.h>

void splitTime(
    int totalSeconds,
    int *hours,
    int *minutes,
    int *seconds
){
    *hours = totalSeconds / 3600;
    *minutes = (totalSeconds % 3600) / 60;
    *seconds = totalSeconds % 60;
}
int main(void){
    int totalSeconds;
    int hours;
    int minutes;
    int seconds;
    printf("秒数？\n");
    scanf("%d",&totalSeconds);
    
        splitTime(totalSeconds,
              &hours,
              &minutes,
              &seconds);

    printf("%dは%d時間%d分%d秒です",totalSeconds,hours,minutes,seconds);
    
    return 0;
}