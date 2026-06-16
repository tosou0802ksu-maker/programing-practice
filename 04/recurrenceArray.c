//2554709 黒田蒼史　2026年4月23日作成
//recurrenceArray.c
//要素数15の整数型の配列を用意し、要素番号0から順に以下の漸化式の項を代入する。
//次に、この配列の要素の逆順に（要素番号の大きい方から小さい方への順で）表示する

/*　実行結果
soshi@soshinoMacBook-Air 04 % ./recurrenceArray
9565937
3188645
1062881
354293
118097
39365
13121
4373
1457
485
161
53
17
5
1
*/

#include <stdio.h>

int main(void){
    int n;
    int i = 1;
    int a[15];  // 1個増やす

    a[0] = i;  // ← 初期値を保存

    for(n = 1; n < 15; n++){
        i = i * 3 + 2;
        a[n] = i;
    }

    // 逆順で出力
    for(n = 14; n >= 0; n--){
        printf("%d\n", a[n]);
    }

    return 0;
}