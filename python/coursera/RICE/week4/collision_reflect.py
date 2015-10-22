# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

# Initialize globals
WIDTH = 600
HEIGHT = 600
RADIUS = 20

ball_pos = [WIDTH/2, HEIGHT/2]
ball_velocity = [2, 0.5]

#define event handlers
def draw(canvas):
    # update position
    ball_pos[0] += ball_velocity[0]
    ball_pos[1] += ball_velocity[1]

    # collide and reflect off of four sides of canvas
    if ball_pos[0] <= RADIUS or ball_pos[0] >= WIDTH - RADIUS:
        ball_velocity[0] = -ball_velocity[0]
    if ball_pos[1] <= RADIUS or ball_pos[1] >= HEIGHT - RADIUS:
        ball_velocity[1] = -ball_velocity[1]

    # Draw ball
    canvas.draw_circle(ball_pos, RADIUS, 2, "Red", "White")

# create a frame
frame = simplegui.create_frame("Ball physics", WIDTH, HEIGHT)

# register handlers
frame.set_draw_handler(draw)

# start frame
frame.start()