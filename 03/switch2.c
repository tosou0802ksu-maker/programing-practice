//2554709 黒田蒼史　4月16日作成
//switch2.c
//上記のプログラムで抜けているbreak文、3ヶ所を追加して、正しく動くように修正し、動作を確認する。


/*実行結果
soshi@soshinoMacBook-Air 03 % ./switch2 
整数を入力してください：
2
2が入力されました。
soshi@soshinoMacBook-Air 03 % ./switch2
整数を入力してください：
4
1でも2でもありません。
soshi@soshinoMacBook-Air 03 % ./switch2
整数を入力してください：
1
1が入力されました。
*/


#include <stdio.h>

int main(void) 
{
    int res; 

    printf("整数を入力してください：\n");
    scanf("%d", &res);

    switch(res){
        case 1:
            printf("1が入力されました。\n");
            break;
        case 2:
            printf("2が入力されました。\n");
            break;
        default:
            printf("1でも2でもありません。\n");
            break;
    }

    return 0;
}

