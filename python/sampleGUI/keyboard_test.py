# -*- coding: utf-8 -*-

# keyboard echo
from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

# initialize state
current_key = ' '

# event handlers
def key_down(key):
    global current_key
    current_key = chr(key)

def key_up(key):
    global current_key
    current_key = 'UP'

def draw(canvas):
    canvas.draw_text(current_key, [20, 30], 15, "White")

# create a frame
frame = simplegui.create_frame("echo", 50, 50)

# register event handlers
frame.set_keydown_handler(key_down)
frame.set_keyup_handler(key_up)
frame.set_draw_handler(draw)

# start frame
frame.start()