//2554709 黒田蒼史　4月14日作成

//fizzbuzz.c
//正の整数を入力
//0以下の場合はやり直しができる
//１からその数まで順に１行ずつ数値を表示するが、３の倍数のときは値の代わりにfizz,
//5の倍数はbuzzと表示するプログラム
//3の倍数かつ5の倍数の場合はfizzbuzzと表示する。


/*soshi@soshinoMacBook-Air 02 % ./fizzbuzz
number?
16
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
16
*/


#include <stdio.h>

int main(void)
{
    int inum,i;

    printf("number?\n");
    scanf("%d",&inum);

    while (inum <= 0){
        printf("number?\n");
        scanf("%d",&inum);  }

    for (i = 1; inum >= i; i = i+1){

         if(i % 15 == 0){
            printf("fizzbuzz\n");}
        else if(i % 5 == 0){
            printf("buzz\n");}
        else if(i % 3 == 0){
            printf("fizz\n");}
        else {
            printf("%d\n",i);}
        }
    return 0;
    
}