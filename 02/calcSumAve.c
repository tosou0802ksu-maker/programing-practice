//2554709 黒田蒼史　4月14日作成

//calcSumAve.c
//合計値と同時に平均値も表示する


/*soshi@soshinoMacBook-Air 02 % ./calcSumAve
87
62
55
32
1
22
0
合計は259, 平均は43
*/


#include <stdio.h>

int main(void){
    int num,i=0,count=0;
    
    while(1){
        scanf("%d",&num);

        if(num == 0){
            break;
        }

        i = i + num;
        count = count + 1;

    }

    printf("合計は%d, 平均は%d\n",i,i/count);

    return 0;

}
