import pygame
import time
from random import randint

def distance_from_line(point, a, b):
    A = b[1] - a[1]
    B = a[0] - b[0]
    C = a[1] * b[0] - a[0] * b[1]
    return abs(A * point[0] + B * point[1] + C) / ((A ** 2 + B ** 2) ** 0.5)


def is_left_of_line(point, a, b):
    return (b[0] - a[0]) * (point[1] - a[1]) - (b[1] - a[1]) * (point[0] - a[0]) > 0


def quick_hull(points, screen):
    if len(points) <= 1:
        return points

    leftmost = min(points, key=lambda x: x[0])
    rightmost = max(points, key=lambda x: x[0])
    pygame.draw.line(screen, 'green', leftmost, rightmost, 2)
    pygame.display.flip()
    
    def find_hull(points, a, b):
        if not points:
            return []
        
        farthest = max(points, key=lambda x: distance_from_line(x, a, b))
        
        time.sleep(2)
        pygame.draw.line(screen, 'red', a, farthest, 2)
        pygame.draw.line(screen, 'red', farthest, b, 2)
        pygame.display.flip()

        time.sleep(2)

        left_of_af = [p for p in points if is_left_of_line(p, a, farthest)]
        left_of_fb = [p for p in points if is_left_of_line(p, farthest, b)]

        return find_hull(left_of_af, a, farthest) + [farthest] + find_hull(left_of_fb, farthest, b)

    above = [p for p in points if is_left_of_line(p, leftmost, rightmost)]
    below = [p for p in points if is_left_of_line(p, rightmost, leftmost)]

    upper_hull = find_hull(above, leftmost, rightmost)
    lower_hull = find_hull(below, rightmost, leftmost)

    return [leftmost] + upper_hull + [rightmost] + lower_hull


pygame.init()
screen = pygame.display.set_mode((1000, 1000))

points = [(randint(50, 950), randint(50, 950)) for _ in range(20)]

polygon = []

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((255, 255, 255))

    for point in points:
        pygame.draw.circle(screen, 'black', point, 5)

    if not polygon:
        polygon = quick_hull(points, screen)

    pygame.draw.polygon(screen, 'blue', polygon, 2)

    pygame.display.flip()

pygame.quit()
