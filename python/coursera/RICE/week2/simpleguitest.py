# -*- coding: utf-8 -*-


# program structure
	# global (state)
	# helper functions
	# classes(later)
	# define event handlers
	# create a frame
	# register event handlers
	# start frame & timers


import SimplGUICS2Pygame as simplegui

name = "Welcome"

def greet():
	global name
	name = input("Your name:")
	
def tick():
	greet()
	print "Welcome " + name
	
def buttonpress():
	global name
	name = "man"
	
frame = simplegui.create_frame("Hello", 100, 100)

timer = simplegui.create_timer(1000, tick)
frame.add_button("Click me!", buttonpress)

frame.start()
timer.start()