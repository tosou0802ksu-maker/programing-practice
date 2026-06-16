//2554709 黒田蒼史　5月11日作成
// bubbleSortRand.c
// バブルソート（乱数版）

/*実行結果

soshi@soshinoMacBook-Air 05 % ./bubbleSortRand
ソート前: 3 6 7 5 3 5 
5 4 3 2 1 5 4 3 2 5 4 3 5 4 5 
ソート後: 3 3 5 5 6 7 

*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6  // ソート対象データの数

void randData(int len, int data[])
{
    int k;

    for (k = 0; k < len; k++) {
        data[k] = random() % 10;}  // 0～9の乱数
}

void dispData(int len, int data[]){
    int k;

    for (k = 0; k < len; k++) {
        printf("%d ", data[k]);
    }
    printf("\n");}

void bubbleSort(int len, int data[]){
    int k, j;
    int tmp;

    for (k = 1; k < len; k++) {
        for (j = len - 1; j >= k; j--) {
            printf("%d ", j);

            if (data[j] < data[j - 1]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;}}        }

    printf("\n"); 
}

int main(void)
{
    int data[SIZE];

    randData(SIZE, data);

    printf("ソート前: ");
    dispData(SIZE, data);

    bubbleSort(SIZE, data);

    printf("ソート後: ");
    dispData(SIZE, data);

    return 0;}