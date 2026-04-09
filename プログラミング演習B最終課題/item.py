import pygame
import random
import os
from settings import *

class Item:
    def __init__(self, item_type):
        self.type = item_type

        if self.type == "heal":
            img = "item.png"
        else:
            img = "invincible.png"

        self.image = pygame.image.load(
            os.path.join("images", img)
        ).convert_alpha()
        self.image = pygame.transform.scale(self.image, (25, 25))

        x = random.randint(0, WIDTH - 25)
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = -25
        self.speed = 3

    def move(self):
        self.rect.y += self.speed

    def draw(self, screen):
        screen.blit(self.image, self.rect)


def spawn_item():
    # 無敵は回復よりも少なく出るようにする
    if random.randint(1, 10) == 1:
        return Item("invincible")
    else:
        return Item("heal")
