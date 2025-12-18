import pygame as pg
import sys

def fit_to_square(img,length = 100):
    (w, h) = img.get_size()# 元の画像の大きさを取得する。
    if w == 0 or h == 0 or length <= 0:
        return img
    scale =  min(length/w,length/h)  # 倍率を求める。
    new_size = (int(w * scale), int(h * scale))# 倍率をもとに変換後の画像サイズを求める。
    return pg.transform.scale(img, new_size)

# 1. ゲームの準備をする。
pg.init()
screen = pg.display.set_mode((800, 600))
orig = pg.image.load(sys.argv[1]) # 画像をロードする。
length = 100                      # スケール後の画像の大きさ
if len(sys.argv) == 3:            # 大きさがコマンドライン引数で指定されていれば
    length = int(sys.argv[2])     # その大きさを用いる。
img = fit_to_square(orig, length) # 指定の大きさにスケールした画像を得る。

# 2. メインループ
while True:
    # 2-1 画面を初期化する。
    screen.fill(pg.Color("WHITE"))

    # 2-3. 絵を描いたり、判定したりする。
    screen.blit(orig, (10, 10))  # 元の画像を描画する。
    screen.blit(img, (10 + orig.get_width() + 10, 10)) # 元の画像の横に変換後の画像を描画する。

    # 2-4. 画面を表示する。
    pg.display.update()

    # 2-5. 閉じるボタンが押されたら終了する。
    for event in pg.event.get():  # イベント一覧を取得して、各イベントを調べる。
        if event.type == pg.QUIT: # もし、閉じるボタンが押されたら。
            pg.quit()             # PyGame を終了する。これだけではウィンドウは閉じない。
            sys.exit()            # ウィンドウを閉じて、プログラムを終了する。
            