//2554709 黒田蒼史　５月19日作成
// fourCircles.c
// 4色の円を描く

#include <stdio.h>
#include <handy.h>

int main()
{
    HgOpen(400, 400);

    HgSetFillColor(HG_BLUE);
    HgCircleFill(120, 280, 100, 1);

    HgSetFillColor(HG_GREEN);
    HgCircleFill(280, 280, 100, 1);

    HgSetFillColor(HG_RED);
    HgCircleFill(120, 120, 100, 1);

    HgSetFillColor(HG_YELLOW);
    HgCircleFill(280, 120, 100, 1);

    HgGetChar();
    HgClose();

    return 0;
}