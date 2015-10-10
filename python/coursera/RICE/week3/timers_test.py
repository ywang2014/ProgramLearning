# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui
import random

# Global state
message = "Python is Fun!"
position = [50, 50]
width = 500
height = 500
interval = 2000

# Handler for text box
def update(text):
    global message
    message = text

# Handler for timer
def tick():
    global position
    x = random.randrange(0, width)
    y = random.randrange(0, height)
    position[0] = x
    position[1] = y

# Handler to draw on cnavas
def draw(canvas):
    canvas.draw_text(message, position, 36, "Red")

# Create a frame
frame = simplegui.create_frame("Home", width, height)

# Register event handlers
text = frame.add_input("Message: ", update, 150)
frame.set_draw_handler(draw)
timer = simplegui.create_timer(interval, tick)

# start frame
timer.start()   # timer should premise, So it should put before frame
frame.start()
