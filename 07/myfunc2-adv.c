//2554709　黒田蒼史　5月21日作成
// myfunc2-adv.c
// 入力と出力の処理（改善版）

/*実行結果
soshi@soshinoMacBook-Air 07 % ./max
1番目の数値を入力してください。
abc
整数を入力してください。
1番目の数値を入力してください。
1 3
2番目の数値を入力してください。
2
最大値は2です。
*/
#include <stdio.h>

int inputValue(char str[]){
    int num;
    int ch;

    while (1){
        printf("%s", str);

        if (scanf("%d", &num) == 1){

            while ((ch = getchar()) != '\n' && ch != EOF);

            return num;}

        printf("整数を入力してください。\n");

        while ((ch = getchar()) != '\n' && ch != EOF);}
}

void outputMax(int ans){
    printf("最大値は%dです。\n", ans);
}
