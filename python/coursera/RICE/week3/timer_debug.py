# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

def timer_handler1():
    print "Hello boys!"

def timer_handler2():
    print "Hello girls!"

timer1 = simplegui.create_timer(500, timer_handler1)
timer2 = simplegui.create_timer(1500, timer_handler2)

# timer must be started or it won't work!
timer1.start()
timer2.start()

