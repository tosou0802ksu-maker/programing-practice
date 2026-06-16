//2554709 黒田蒼史　5月19日作成
//fishFunc1.c
//サンプルプログラムを修正して魚の描画を完成させる

#include <stdio.h>
#include <math.h>
#include <handy.h>

void fish(double x,double y,double size);
void fish(double x, double y, double size){
    // 1. 頭（225度から495度までの円弧を描く）
    HgFan(x, y, size,225.0 * M_PI / 180.0,495.0 * M_PI / 180.0); 

    // 2. 目
    HgCircle(x - size / 3.0,y + size / 2.0,size / 4.0);

    // 3. 背骨
    double bone_x = x + size;
    double bone_y = x + size * 3.0;
    HgLine(bone_x, y, bone_y, y);

    // 4. 小骨（5本）
    double interval = (size * 2.0) / 6.0;
    for (int i = 1; i <= 5; i++){
        double bone_X = bone_x + i * interval;
        HgLine(bone_X, y - size / 2.0, bone_X, y + size / 2.0);}

    // 5. 尾ひれ
    double tail_x = x + size * 4.0;
    HgLine(bone_y, y, tail_x, y + size); // 上側
    HgLine(bone_y, y, tail_x, y - size);} // 下側

int main(void) 
{
    double x, y, size, dx, dy;

    // 初期化
    HgOpen(400.0, 400.0);

    x = 200.0;         // x, y 座標の初期設定
    y = 200.0;
    size = 10.0;       // アタマの半径
    dx = -0.9 * size;  // x 方向の移動速度
    dy = 0.5 * size;   // y 方向の移動速度

    while (1) { // 無限ループにつき、グラフィックのウィンドウを閉じて終了
        HgClear();        // 画面を消去

        fish(x, y, size); // 魚を描く

        // 左右方向の壁との衝突判定と移動処理
        if(x + dx < size || x + dx > 400.0 - size * 4.0) {
            dx = -dx;
        }
        x += dx;

               // 上下方向の壁との衝突判定と移動処理
        if(y + dy < size || y + dy > 400.0 - size * 4.0) {
            dy = -dy;
        }
        y += dy;

        HgSleep(0.1);  // 少し待つ
    }
}
