//2554709 黒田蒼史　4月14日作成

//exam.c
//点数を入力して点数ごとに評価を分ける


/*soshi@soshinoMacBook-Air 02 % ./exam
点数を入力してください:
73
良 
*/


#include <stdio.h>

int main(void) {
    int score;

    printf("点数を入力してください:\n");
    scanf("%d",&score);

    if(score >= 90){
        printf("秀");}
    else if(score >= 80){
        printf("優");}
    else if(score >=70){
        printf("良");}
    else if(score >= 60){
        printf("可");}
    else {printf("不可");}

    return 0;
    
}