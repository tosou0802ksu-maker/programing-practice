//2554709 黒田蒼史　2026年4月23日作成

// reverse2.c
// 5つの整数を入力させ、逆順に表示する
// 配列を単純に使った（繰り返しは使っていない）

/*　実行結果
soshi@soshinoMacBook-Air 04 % ./reverce2                
input No.0: 1
input No.1: 2
input No.2: 3
input No.3: 4
input No.4: 5
No.4 = 5
No.3 = 4
No.2 = 3
No.1 = 2
No.0 = 1
*/


#include <stdio.h>
#define N 5

int main(void){
    int a;
    int array[N];

    a = 0;

    while (a < N){
        printf("input No.%d: ", a);
        scanf("%d", &array[a]);
        a ++;}
    a = 4;
    while(a >= 0){
        printf("No.%d = %d\n", a, array[a]);
        a --;}
    return 0;
}
