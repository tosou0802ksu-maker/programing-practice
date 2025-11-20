import pygame
import sys

# ---------- 設定 ----------
SCREEN_W, SCREEN_H = 800, 600
FPS = 60

# プレイヤー設定
PLAYER_W, PLAYER_H = 40, 50
PLAYER_COLOR = (50, 150, 255)
GRAVITY = 0.8
JUMP_V = -25
MOVE_SPEED = 5

# 色
BG_COLOR = (135, 206, 100)
PLATFORM_COLOR = (100, 50, 20)
ENEMY_COLOR = (200, 30, 30)
COIN_COLOR = (255, 215, 0)

# ---------- クラス ----------
class Player:
    def __init__(self, x, y):
        self.rect = pygame.Rect(x, y, PLAYER_W, PLAYER_H)
        self.vx = 0
        self.vy = 0
        self.on_ground = False
        self.score = 0

    def handle_input(self, keys):
        self.vx = 0
        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            self.vx = -MOVE_SPEED
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            self.vx = MOVE_SPEED
        if (keys[pygame.K_SPACE] or keys[pygame.K_UP] or keys[pygame.K_w]) and self.on_ground:
            self.vy = JUMP_V
            self.on_ground = False

    def apply_gravity(self):
        self.vy += GRAVITY
        if self.vy > 30:
            self.vy = 30

    def update(self, platforms):
        # 移動（x方向）
        self.rect.x += self.vx
        # x方向の衝突判定
        for p in platforms:
            if self.rect.colliderect(p.rect):
                if self.vx > 0:
                    self.rect.right = p.rect.left
                elif self.vx < 0:
                    self.rect.left = p.rect.right

        # y方向の移動
        self.rect.y += self.vy
        self.on_ground = False
        for p in platforms:
            if self.rect.colliderect(p.rect):
                # 落下中に上に衝突したら地面に立つ
                if self.vy > 0:
                    self.rect.bottom = p.rect.top
                    self.vy = 0
                    self.on_ground = True
                elif self.vy < 0:
                    self.rect.top = p.rect.bottom
                    self.vy = 0

class Platform:
    def __init__(self, x, y, w, h):
        self.rect = pygame.Rect(x, y, w, h)

class Enemy:
    def __init__(self, x, y, w=40, h=40, left_bound=None, right_bound=None, speed=2):
        self.rect = pygame.Rect(x, y, w, h)
        self.speed = speed
        self.left_bound = left_bound if left_bound is not None else x - 100
        self.right_bound = right_bound if right_bound is not None else x + 100

    def update(self):
        self.rect.x += self.speed
        if self.rect.x < self.left_bound or self.rect.right > self.right_bound:
            self.speed *= -1

class Coin:
    def __init__(self, x, y, r=8):
        self.rect = pygame.Rect(x - r, y - r, r*2, r*2)
        self.collected = False

# ---------- レベル作成 ----------
def make_level():
    platforms = []
    # 床
    platforms.append(Platform(0, SCREEN_H - 40, SCREEN_W, 40))
    # 足場
    platforms.append(Platform(60, 450, 120, 20))
    platforms.append(Platform(240, 370, 120, 20))
    platforms.append(Platform(420, 300, 120, 20))
    platforms.append(Platform(600, 220, 120, 20))
    platforms.append(Platform(320, 520, 150, 20))
    platforms.append(Platform(520, 480, 100, 20))

    enemies = [
        Enemy(200, SCREEN_H - 80, left_bound=160, right_bound=360, speed=2),
        Enemy(560, 440, left_bound=520, right_bound=640, speed=1.5),
    ]

    coins = [
        Coin(120, 410),
        Coin(300, 330),
        Coin(480, 260),
        Coin(650, 180),
        Coin(370, 480),
    ]

    return platforms, enemies, coins

# ---------- メイン ----------
def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_W, SCREEN_H))
    pygame.display.set_caption("Mini Mario (Python + Pygame)")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont(None, 28)

    # 初期化
    player = Player(50, SCREEN_H - 100)
    platforms, enemies, coins = make_level()

    running = True
    while running:
        dt = clock.tick(FPS)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False

        keys = pygame.key.get_pressed()
        player.handle_input(keys)
        player.apply_gravity()
        player.update(platforms)

        # 敵更新
        for e in enemies:
            e.update()

        # 敵との当たり判定（踏む or 接触）
        for e in enemies[:]:
            if player.rect.colliderect(e.rect):
                # プレイヤーが上から落ちていて敵の頭に当たったら倒す
                if player.vy > 0 and player.rect.bottom - e.rect.top < 15:
                    enemies.remove(e)
                    player.vy = JUMP_V / 2  # ちょっとはねる
                else:
                    # ダメージ（とりあえずリスタート）
                    player = Player(50, SCREEN_H - 100)
                    platforms, enemies, coins = make_level()
                    break

        # コイン取得判定
        for coin in coins:
            if (not coin.collected) and player.rect.colliderect(coin.rect):
                coin.collected = True
                player.score += 100

        # 描画
        screen.fill(BG_COLOR)

        # プラットフォーム
        for p in platforms:
            pygame.draw.rect(screen, PLATFORM_COLOR, p.rect)

        # コイン
        for coin in coins:
            if not coin.collected:
                pygame.draw.ellipse(screen, COIN_COLOR, coin.rect)

        # 敵
        for e in enemies:
            pygame.draw.rect(screen, ENEMY_COLOR, e.rect)

        # プレイヤー
        pygame.draw.rect(screen, PLAYER_COLOR, player.rect)

        # HUD
        score_s = font.render(f"Score: {player.score}", True, (0,0,0))
        screen.blit(score_s, (10, 10))

        # 小さな説明
        instr = font.render("Arrow keys / A D: move, Space / Up: jump, Esc: quit", True, (0,0,0))
        screen.blit(instr, (10, 40))

        pygame.display.flip()

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()