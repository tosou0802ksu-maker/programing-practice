//2554709 黒田蒼史　4月16日作成
//treasure2.c
//1～3以外の番号が入力された場合は終了せず、次のように再度番号の入力を促すように改造する。


/*実行結果
soshi@soshinoMacBook-Air 03 % ./treasure2
宝箱が3つある!どれを開けますか?(1か2か3):
4
その番号の箱はありません宝箱が3つある!どれを開けますか?(1か2か3):
3
宝箱は空っぽだった%                                                                                                                
soshi@soshinoMacBook-Air 03 % ./treasure2
宝箱が3つある!どれを開けますか?(1か2か3):
2
あなたは宝を手に入れた%                                                                                                            
soshi@soshinoMacBook-Air 03 % ./treasure2
宝箱が3つある!どれを開けますか?(1か2か3):
1
宝箱は罠だった
敵が現れた%        
 */

 
#include <stdio.h>

int main(void){

    int a;
    while (1) {
        printf("宝箱が3つある!どれを開けますか?(1か2か3):\n");
        scanf("%d",&a);

        switch(a){
            case 1:
                printf("宝箱は罠だった\n敵が現れた");
                return 0;
            case 2:
                printf("あなたは宝を手に入れた");
                return 0;
            case 3:
                printf("宝箱は空っぽだった");
                return 0;
            default:
                printf("その番号の箱はありません");

            
        }
    }
}