//2554709 黒田蒼史　4月15日作成

// binary32.c
// 入力された整数の下位8ビット分を2進数で表示する


/*実行結果
soshi@soshinoMacBook-Air 03 % ./binary32                
整数を入力してください: 32
0000:0000:0000:0000:0000:0000:0010:0000
*/


#include <stdio.h>

int main(void) 
{
    int num;   // 入力値
    int data;  // 下位32ビット分
    int i;     // ループ変数

    printf("整数を入力してください: ");
    scanf("%d", &num);

    data = num & 0xFF;  // 下位32ビットだけにする
    for (i = 31; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(":");    // 区切り文字
        }
    }
    printf("\n");

    return 0;
}
