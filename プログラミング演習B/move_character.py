import pygame as pg
import sys

# 1. ゲームの準備をする。
pg.init()
screen = pg.display.set_mode((800, 600))
clock = pg.time.Clock()
player = pg.image.load(sys.argv[1])

ix, iy = 1, 0
GW, GH = (player.get_rect().width / 3, player.get_rect().height / 4)
dx, dy = 0, 0
rect = pg.Rect(0, 0, 32, 32)

# 2. メインループ
while True:
    # 2-1 画面を初期化する。
    screen.fill(pg.Color("WHITE"))

    # キー入力を取得
    keys = pg.key.get_pressed()

    # 矢印キー or h j k l で移動
    if keys[pg.K_UP] or keys[pg.K_k]:
        dx, dy, iy = 0, -1, 3
    elif keys[pg.K_DOWN] or keys[pg.K_j]:
        dx, dy, iy = 0, 1, 0
    elif keys[pg.K_LEFT] or keys[pg.K_h]:
        dx, dy, iy = -1, 0, 1
    elif keys[pg.K_RIGHT] or keys[pg.K_l]:
        dx, dy, iy = 1, 0, 2
    else:
        dx, dy = 0, 0

    # Shiftキーで5倍速
    if keys[pg.K_LSHIFT] or keys[pg.K_RSHIFT]:
        dx *= 5
        dy *= 5

    # 移動処理（画面外に出ないようにする）
    nbox = rect.move(dx, dy)
    if screen.get_rect().contains(nbox):
        rect = nbox

    # キャラ描画
    screen.blit(player, rect, (ix * GW, iy * GH, GW, GH))

    # 2-4. 画面を表示する。
    pg.display.update()
    clock.tick(60)

    # 2-5. イベント処理
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()

        # 右クリックした位置にワープ
        if event.type == pg.MOUSEBUTTONDOWN:
            if event.button == 1:  # 右クリック
                rect.center = event.pos
                