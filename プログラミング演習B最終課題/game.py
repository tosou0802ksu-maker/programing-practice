import pygame
import time
from settings import *
from player import Player
from obstacle import Obstacle
from item import spawn_item

class Game:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        pygame.display.set_caption("Avoid Game")
        self.clock = pygame.time.Clock()
        self.font = pygame.font.Font(None, 36)

        self.reset()

    def reset(self):
        self.player = Player()
        self.obstacles = []
        self.items = []

        self.score = 0
        self.time_count = 0
        self.game_over = False

        self.invincible = False
        self.invincible_start = 0

    def run(self):
        while True:
            self.clock.tick(FPS)
            self.handle_events()
            self.update()
            self.draw()

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()

            if self.game_over and event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    self.reset()

    def update(self):
        if self.game_over:
            return

        self.time_count += 1
        self.score += 1

        # 時間が経つにつれて難易度を上げていく
        obstacle_speed = 3 + self.time_count // 300
        spawn_num = 1 + self.time_count // 600
        spawn_num = min(spawn_num, 5)

        if self.time_count % 60 == 0:
            for _ in range(spawn_num):
                self.obstacles.append(Obstacle(obstacle_speed))

        if self.time_count % 300 == 0:
            self.items.append(spawn_item())

        keys = pygame.key.get_pressed()
        self.player.move(keys)

        self.update_obstacles()
        self.update_items()
        self.update_invincible()

    def update_obstacles(self):
        for obs in self.obstacles[:]:
            obs.move()

            if obs.rect.colliderect(self.player.rect):
                if not self.invincible:
                    self.player.hp -= 1
                self.obstacles.remove(obs)

                if self.player.hp <= 0:
                    self.game_over = True

            elif obs.rect.top > HEIGHT:
                self.obstacles.remove(obs)

    def update_items(self):
        for it in self.items[:]:
            it.move()

            if it.rect.colliderect(self.player.rect):
                if it.type == "heal" and self.player.hp < MAX_HP:
                    self.player.hp += 1
                elif it.type == "invincible":
                    self.invincible = True
                    self.invincible_start = time.time()

                self.items.remove(it)

            elif it.rect.top > HEIGHT:
                self.items.remove(it)

    def update_invincible(self):
        if self.invincible and time.time() - self.invincible_start >= 10:
            self.invincible = False

    def draw(self):
        self.screen.fill((255, 255, 255))

        self.player.draw(self.screen)

        for obs in self.obstacles:
            obs.draw(self.screen)

        for it in self.items:
            it.draw(self.screen)

        self.draw_ui()

        if self.game_over:
            self.draw_game_over()

        pygame.display.update()

    def draw_ui(self):
        self.screen.blit(
            self.font.render(f"Score: {self.score}", True, (0, 0, 0)),
            (10, 10)
        )
        self.screen.blit(
            self.font.render(f"HP: {self.player.hp}", True, (0, 0, 0)),
            (WIDTH - 120, 10)
        )

        if self.invincible:
            self.screen.blit(
                self.font.render("God Mode!", True, (255, 150, 0)),
                (10, 40)
            )

    def draw_game_over(self):
        self.screen.blit(
            self.font.render("GAME OVER", True, (255, 0, 0)),
            (WIDTH // 2 - 80, HEIGHT // 2 - 40)
        )
        self.screen.blit(
            self.font.render("Press R to restart the game.", True, (0, 0, 0)),
            (WIDTH // 2 - 120, HEIGHT // 2)
        )
