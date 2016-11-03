# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

size = 10
radius = 10

# define event gandlers
def incr_button_handler():
    '''
    Increment the size.
    '''
    global size
    size += 1
    label.set_text("Value: " + str(size))

def decr_button_handler():
    '''
    Decrement the size.
    '''
    global size
    size -= 1
    # add if size < 0 reset size = 0
    if (size < 0):
        size = 0
    label.set_text("Value: " + str(size))

def change_radius(text):
    '''
    Modify the radius directly
    :param text:
    '''
    global size
    size = int(text)
    if size < 0 :
        size = 0
    label.set_text("Value: " + str(size))

def change_circle_handler():
    '''
    Change the circle radius.
    '''
    global radius
    radius = size
    radiuslabel.set_text("Radius: " + str(radius))

def draw_handler(canvas):
    '''
    Draw the canvas
    :param canvas:
    '''
    canvas.draw_circle((100, 100), radius, 2, "Blue")

# Create a frame and assign callbacks to event handlers.
frame = simplegui.create_frame("Home", 200, 200)

label = frame.add_label("Value: " + str(size))
frame.add_button("Increse", incr_button_handler)
frame.add_button("Decrease", decr_button_handler)
text = frame.add_input("", change_radius, 100)
radiuslabel = frame.add_label("Radius: " + str(radius))
frame.add_button("Change circle", change_circle_handler)
frame.set_draw_handler(draw_handler)

frame.start()