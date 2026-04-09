import pygame
import random
import os
from settings import *

class Obstacle:
    def __init__(self, speed):
        self.image = pygame.image.load(
            os.path.join("images", "obstacle.png")
        ).convert_alpha()
        self.image = pygame.transform.scale(self.image, (30, 30))

        x = random.randint(0, WIDTH - 30)
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = -30

        self.speed = speed

    def move(self):
        self.rect.y += self.speed

    def draw(self, screen):
        screen.blit(self.image, self.rect)
