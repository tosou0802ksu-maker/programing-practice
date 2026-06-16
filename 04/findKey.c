//2554709 黒田蒼史　2026年4月23日作成
//findKey.c
//IDを入力すると、そのIDの人の鍵の番号を表示するプログラム
//入力したIDの人がいない場合は、見つからないというメッセージを表示せよ。
//必ず繰り返しを使うこと。IDと鍵のデータは配列の初期化子を使ってよい

/*実行結果
soshi@soshinoMacBook-Air 04 % ./findKey
IDを入力してください: 9
IDが見つかりません
soshi@soshinoMacBook-Air 04 % ./findKey
IDを入力してください: 19
ID 19 の鍵の番号は 634 です
*/

#include<stdio.h>

int main(void){
    int n,i;
    int keynum[] = {114,194,223,315,326,404,514,634,777,819};
    int ID[] = {2,3,5,7,11,13,17,19,23,29};
    int found = 0;

    printf("IDを入力してください: ");
    scanf("%d", &n);

    for(i = 0; i < 10; i++){
        if(n == ID[i]){
            printf("ID %d の鍵の番号は %d です\n", n, keynum[i]);
            found = 1;
            break;}}

    if(found == 0){
        printf("IDが見つかりません\n");}

    return 0;
}