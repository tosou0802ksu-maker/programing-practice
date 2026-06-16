// constFunc.c
// const修飾子を使った例

#include <stdio.h>

void func(const int *px)
{
    printf("*px = %d\n", *px); // 読み出しはできる
    px++;      // ポインタ自体の値は変更できる
    *px = 10;  // 書き込みはコンパイルエラーになる
}

int main(void)
{
    int a = 5;

    func(&a);

    return 0;
}
