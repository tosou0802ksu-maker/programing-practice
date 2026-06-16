//2554709　黒田蒼史　5月28日作成
// funcParam4.c
// 5人のテストの点数を入力し、その平均点と標準偏差を表示する
// 入力は配列に格納し、その計算は関数で処理する
// ★ポインタで処理するバージョン

/*実行結果
5人のテストの点数を入力してください。
1 3 4 7 8
5人の平均点は 4.60点です。
最高点: 8
最低点: 1
標準偏差: 2.58
soshi@soshinoMacBook-Air 08 % ./funcParam4
5人のテストの点数を入力してください。
77 63 59 92 81
5人の平均点は 74.40点です。
最高点: 92
最低点: 59
標準偏差: 12.06
*/

#include <stdio.h>
#include <math.h>

// 与えられた整数の配列の平均値を返す
double average(int *scoreP, int size){
    int i;
    double sum;

    // まず合計を求める
    sum = 0.0;
    for (i = 0; i < size; i++) {
        sum += *scoreP++;   // scoreP[i] や *(scoreP + i)とも書ける
    }

    return sum / size;
}

#define N   5   // データの数

double stddev(int *scoreP, int size){
    int j;
    double avg;
    double sum = 0.0;

    avg = average(scoreP, size);

    for(j = 0; j < size; j++){
        sum += pow(scoreP[j] - avg, 2);
    }

    return sqrt(sum / size);}

// メイン
int main(void){
    int data[N];    // 入力データ
    int *dp;        // データへのポインタ
    int i;
    double result;  // 結果を入れる
    double sd;

    int max=0,min=100;

    printf("%d人のテストの点数を入力してください。\n", N);
    dp = data;

    for(i = 0; i < N; i++){

        scanf("%d", dp);

        if(*dp > max){
            max = *dp;}

        if(*dp < min){
            min = *dp;}

        dp++;}

    result = average(data, N);
    sd = stddev(data,N);

    printf("%d人の平均点は %.2lf点です。\n", N, result);
    printf("最高点: %d\n最低点: %d\n",max , min);
    printf("標準偏差: %.2lf\n",sd);

    return 0;
}
