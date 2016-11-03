# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

message = "Welcome!"

def click():
    '''
    Change message on mouse click.
    '''
    global message
    message = " Good job!"

def click2():
    global message
    message = "Hi, Girls!"

def draw(canvas):
    canvas.draw_text(message, [50, 112], 30, "White")

frame = simplegui.create_frame("Home", 200, 200)
frame.add_button("Good", click)
frame.add_button("Hi", click2)
frame.set_draw_handler(draw)    # canvas must be setted.

frame.start()   # frame must be start!