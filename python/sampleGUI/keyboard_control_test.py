# -*- coding: utf-8 -*-

# keyboard echo
from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

# initialize state
WIDTH = 200
HEIGHT = 200

ball_radius = 20
ball_pos = [WIDTH/2, HEIGHT/2]
color = "White"
velocity = [0.01, 0.02]

# event handlers
def key_down(key):
    global color, ball_radius
    offset = 3
    if key == simplegui.KEY_MAP["left"]:
        ball_pos[0] = (ball_pos[0] + WIDTH - offset) % WIDTH
    elif key == simplegui.KEY_MAP["right"]:
        ball_pos[0] = (ball_pos[0] + offset) % WIDTH
    elif key == simplegui.KEY_MAP["up"]:
        ball_pos[1] = (ball_pos[1] + HEIGHT - offset) % HEIGHT
    elif key == simplegui.KEY_MAP["down"]:
        ball_pos[1] = (ball_pos[1] + offset) % HEIGHT
    elif key == simplegui.KEY_MAP["b"]:
        if ball_radius < 35:
            ball_radius += offset
    elif key == simplegui.KEY_MAP["s"]:
        if ball_radius > 5:
            ball_radius -= offset
    color = "Gray"

def key_up(key):
    global color
    color = 'White'

def draw(canvas):
    ball_pos[0] += velocity[0]
    ball_pos[1] += velocity[1]
    canvas.draw_circle(ball_pos, ball_radius, 2, "Red", color)

# create a frame
frame = simplegui.create_frame("echo", WIDTH, HEIGHT)

# register event handlers
frame.set_keydown_handler(key_down)
frame.set_keyup_handler(key_up)
frame.set_draw_handler(draw)

# start frame
frame.start()