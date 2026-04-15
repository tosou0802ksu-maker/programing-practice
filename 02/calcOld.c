//2554709 黒田蒼史//　4月14日作成

//calcOld.c
//年齢を入力して65歳からの差を求める。


/*soshi@soshinoMacBook-Air 02 % ./calcOld
あなたは何歳ですか？：
19
あなたは 19 歳です。
65歳まではあと46年あります。
*/


#include <stdio.h>

int main(void)
{
    int inum;
    
    // 入力（整数）
    printf("あなたは何歳ですか？：\n");
    scanf("%d",&inum);
    printf("あなたは %d 歳です。\n",inum);
    printf("65歳まではあと%d年あります。\n" , 65 - inum);

    return 0;

}
