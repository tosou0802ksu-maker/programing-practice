//2554709　黒田蒼史　5月11日作成
// selectSortRand.c

/*実行結果
soshi@soshinoMacBook-Air 05 % ./selectSortRand
ソート前: 3 6 7 5 3 5 
ソート後: 7 6 5 5 3 3 
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6  
void randData(int len, int data[]){
    int k;

    for (k = 0; k < len; k++) {
        data[k] = random() % 10;}
}

void dispData(int len, int data[]){
    int k;

    for (k = 0; k < len; k++) {
        printf("%d ", data[k]);}

    printf("\n");}

void bubbleSort(int len, int data[]){
    int k, j;
    int tmp;

    for (k = 1; k < len; k++) {
        for (j = len - 1; j >= k; j--) {

            if (data[j] < data[j - 1]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;}} }
}

void selectSort(int len, int test[])
{
    int i, j;
    int max;
    int tmp;

    for (i = 0; i < len - 1; i++) {
        max = i;

        for (j = i + 1; j < len; j++) {
            if (test[j] > test[max]) {
                max = j;}}

        tmp = test[i];
        test[i] = test[max];
        test[max] = tmp;}}

int main(void)
{
    int data[SIZE];

    randData(SIZE, data);

    printf("ソート前: ");
    dispData(SIZE, data);

    selectSort(SIZE, data);

    printf("ソート後: ");
    dispData(SIZE, data);

    return 0;}