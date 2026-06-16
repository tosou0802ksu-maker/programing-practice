//2554709 黒田蒼史　5月14日作成
//strPrint2.c
//ある文字列の中身を表示するプログラム 
//関数の戻り値は無しでよい

/*　実行結果
soshi@soshinoMacBook-Air 06 % ./strPrint2
This is test.
漢字も表示できる。
It is a sunny day.
0123456789
*/
#include <stdio.h>
void outStr(char str[]){
    printf("%s", str);}

int main(void) 
{
    char str[100] = "This is test.\n漢字も表示できる。\n";
    outStr(str);
    outStr("It is a sunny day.\n0123456789\n");
    return 0;
}
