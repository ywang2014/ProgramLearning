# -*- coding: utf-8 -*-

#import SimpleGUICS2Pygame.simpleguics2pygame as simplegui
#import simplegui
#import SimpleGUICS2Pygame

#try:
#    import simplegui
#except ImportError:
#    import SimpleGUICS2Pygame.simpleguics2pygame as simplegui

from SimpleGUICS2Pygame import simpleguics2pygame

name = "Welcome"
counter = 0

def greet():
    global name
    global counter
    counter = counter + 1

def tick():
    greet()
    print(counter)
    print("Welcome " + name)

def buttonpress():
    global name
    name = "man"

frame = simpleguics2pygame.create_frame("Hello", 100, 100)

timer = simpleguics2pygame.create_timer(500, tick)
frame.add_button("Click me!", buttonpress)

frame.start()
timer.start()