//2554709 黒田蒼史　4月16日作成
//shopping.c
//手持ちの金額と、ある品物1個の値段（単価）と、買いたい個数を入力させ、
//買える場合は「買える。おつりは○○円。」、買えない場合は「買えない。××個までなら買える。」と表示するプログラム


/*実行結果
soshi@soshinoMacBook-Air 03 % ./shopping
手持ちの金額：12000
単価：32
個数：350
買える。おつりは800円。%                                                                                                           
soshi@soshinoMacBook-Air 03 % ./shopping
手持ちの金額：12000
単価：38
個数：350
買えない.315個までなら買える。
*/


#include <stdio.h>

int main(void){
    int a,b,c;

    printf("手持ちの金額：");
    scanf("%d",&a);

    printf("単価：");
    scanf("%d",&b);

    printf("個数：");
    scanf("%d",&c);

    if(a >= b * c){
        printf("買える。おつりは%d円。",a - b * c);
    }
    else {
        printf("買えない.%d個までなら買える。",a / b);
    }
}
