//2554709 黒田蒼史　2026年4月23日作成
//height2
//身長が 163cm、157cm、176cm、180cm、166cmの5人がいて、0〜4までの番号を付けているとする。
//この5人の身長の値を配列に格納し（上述の初期化子を使えばよい）
//入力値の正当性チェックを追加し、配列の要素番号の範囲外の値が入力された場合は番号を再入力させよ。

/*　実行結果
soshi@soshinoMacBook-Air 04 % ./height2  
番号？6   
番号？5
番号？4
4番の身長は166cmです。
*/

#include <stdio.h>

int main(void) {
    int highdata[5] = {163,157,176,180,166};
    int n;
    while(1){
        printf("番号？");
        scanf("%d",&n);
        if(n<=4 && n>=0){
            break;
        }
    }

    printf("%d番の身長は%dcmです。\n",n,highdata[n]);

    return 0;
}
