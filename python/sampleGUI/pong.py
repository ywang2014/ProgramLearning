# -*- coding: utf-8 -*-

# Implementation of classic arcade game Pong

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui
import random

WIDTH = 600
HEIGHT = 600
RADIUS = 15
PAD_WIDTH = 15
PAD_HEIGHT = 80
HALF_PAD_WIDTH = PAD_WIDTH / 2
HALF_PAD_HEIGHT = PAD_HEIGHT / 2
LEFT = False
RIGHT = True

pad_vel = 5
ball_pos = [0, 0]
ball_vel = [0, 0]
paddle1_lev = 0
paddle2_lev = 0
paddle1_pos = 0
paddle2_pos = 0

# initialize ball_pos and ball_vel for new ball in middle of table
# if direction is RIGHT, the ball's velocity is upper right, else upper left
def spawn_ball(direction):
    '''
    控制球刚开始的方向，LEFT RIGHT决定
    '''
    #global ball_pos, ball_vel   # there are vectors stored as lists
    ball_pos[0] = WIDTH / 2
    ball_pos[1] = HEIGHT / 2
    ball_vel[0] = random.randrange(120, 240) / 100
    ball_vel[1] = random.randrange(60, 180) / 100
    if not direction:
        ball_vel[0] = -ball_vel[0]

# define event handlers
def new_game():
    '''
    调用spawn_ball()函数
    '''
    global paddle1_pos, paddle2_pos, paddle1_vel, paddle2_vel # these are numbers
    global score1, score2   # these are ints
    spawn_ball(RIGHT)
    score1 = 0
    score2 = 0
    paddle1_pos = HEIGHT/2 - PAD_HEIGHT/2
    paddle2_pos = HEIGHT/2 - PAD_HEIGHT/2
    paddle1_vel = 0
    paddle2_vel = 0

# 加速模块，增加游戏难度,20%的增幅
def add_velocity():
    ball_vel[0] *= (1 + 0.2)
    ball_vel[1] *= (1 + 0.2)

# judge 判断小球接触边界的位置，是否被球拍接到，接到则继续游戏，否则赢的玩家得一分，重新新游戏
def judge():
    global score1, score2

    # collide and reflect off of four sides of canvas
    if ball_pos[1] <= RADIUS or ball_pos[1] >= HEIGHT - RADIUS:
        ball_vel[1] = -ball_vel[1]

    if ball_pos[0] <= RADIUS + PAD_WIDTH:
        if paddle1_pos - PAD_HEIGHT < ball_pos[1] < paddle1_pos:
            ball_vel[0] = -ball_vel[0]
            add_velocity()
        else:
            score2 += 1
            spawn_ball(RIGHT)
    elif ball_pos[0] >= WIDTH - RADIUS - PAD_WIDTH:
        if paddle2_pos - PAD_HEIGHT < ball_pos[1] < paddle2_pos:
            ball_vel[0] = -ball_vel[0]
            add_velocity()
        else:
            score1 += 1
            spawn_ball(LEFT)

def draw(canvas):
    global paddle1_pos, paddle2_pos  # ball_pos, ball_vel

    # draw mid line and qutters
    canvas.draw_line([WIDTH/2, 0], [WIDTH/2, HEIGHT], 1, "Gray")
    canvas.draw_line([PAD_WIDTH, 0], [PAD_WIDTH, HEIGHT], 1, "Gray")
    canvas.draw_line([WIDTH-PAD_WIDTH, 0], [WIDTH-PAD_WIDTH, HEIGHT], 1, "Gray")

    # update ball
    ball_pos[0] += ball_vel[0]
    ball_pos[1] += ball_vel[1]

    # judge the ball position
    judge()

    # draw ball
    canvas.draw_circle(ball_pos, RADIUS, 1, "Red", "White")

    # update paddle's vertical position, keep paddle on the screen
    paddle1_pos += paddle1_vel
    if paddle1_pos < PAD_HEIGHT:
        paddle1_pos = PAD_HEIGHT
    elif paddle1_pos > HEIGHT:
        paddle1_pos = HEIGHT

    paddle2_pos += paddle2_vel
    if paddle2_pos < PAD_HEIGHT:
        paddle2_pos = PAD_HEIGHT
    elif paddle2_pos > HEIGHT:
        paddle2_pos = HEIGHT

    # draw paddles
    canvas.draw_polygon([[0, paddle1_pos], [PAD_WIDTH, paddle1_pos], [PAD_WIDTH, paddle1_pos-PAD_HEIGHT],
                         [0, paddle1_pos-PAD_HEIGHT]], 1, "Blue", "White")
    canvas.draw_polygon([[WIDTH, paddle2_pos], [WIDTH-PAD_WIDTH, paddle2_pos],
                         [WIDTH-PAD_WIDTH, paddle2_pos-PAD_HEIGHT], [WIDTH, paddle2_pos-PAD_HEIGHT]],
                        1, "Blue", "White")

    # draw scores
    canvas.draw_text(str(score1), [100, 100], 32, "White")
    canvas.draw_text(str(score2), [500, 100], 32, "White")

def key_down(key):
    global paddle1_vel, paddle2_vel
    if key == simplegui.KEY_MAP["w"]:
        paddle1_vel = -pad_vel
    elif key == simplegui.KEY_MAP["s"]:
        paddle1_vel = pad_vel
    elif key == simplegui.KEY_MAP["up"]:
        paddle2_vel = -pad_vel
    elif key == simplegui.KEY_MAP["down"]:
        paddle2_vel = pad_vel

def key_up(key):
    global paddle1_vel, paddle2_vel
    paddle1_vel = 0
    paddle2_vel = 0

# create frame
frame = simplegui.create_frame("Pong", WIDTH, HEIGHT)
frame.set_draw_handler(draw)
frame.set_keydown_handler(key_down)
frame.set_keyup_handler(key_up)

# start frame
new_game()
frame.start()