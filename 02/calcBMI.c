//2554709　黒田蒼史　4月14日作成

//calcBMI.c
//身長と体重を入力しBMIを計算する


/*soshi@soshinoMacBook-Air 02 % ./calcBMI
身長をmで、小数点以下2桁まで入力してください。: 
1.77
体重をkgで、小数点以下1桁まで入力してください。:
51.4
身長は 1.770000 メートルです。
体重は 51.400000 キログラムです。
BMIは 16.406524 です。
*/


#include <stdio.h>

int main(void)
{
    double a1, a2;

    //入力(浮動小数点)
    printf("身長をmで、小数点以下2桁まで入力してください。: \n");
    scanf("%lf" , &a1);
    printf("体重をkgで、小数点以下1桁まで入力してください。:\n");
    scanf("%lf" , &a2);

    //出力
    printf("身長は %f メートルです。\n",a1);
    printf("体重は %f キログラムです。\n",a2);
    printf("BMIは %f です。\n",a2 / (a1 * a1));

    return 0;

}
