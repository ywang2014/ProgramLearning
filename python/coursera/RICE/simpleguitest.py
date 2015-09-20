# -*- coding: utf-8 -*-

# SimpleGUI

	# Program Structure
	
		# globals (state)
		# helper functions
		# classes 
		# Define event handlers
		# create a frame
		# register event handlers
		# start frame & timers
	# 遵循固定的程序结构会使得程序容易编写、维护、理解
	
# simpleGUI program template

# import the module
import simplegui

#define global variables (program state)
counter = 0

# define "helper" functions 
def increment():
	global counter 
	counter = counter + 1
	
# define event handler functions
def tick():
	increment()
	print(counter)
	
# create a frame
frame = simplegui.create_frame("SimpleGUI Test", 100, 100)

# register event handlers
timer = simplegui.create_timer(1000, tick)

# Start frame and timers
frame.start()
timer.start()

# 2ed Edition
# import the module
import simplegui

#define global variables (program state)
counter = 0

# define "helper" functions 
def increment():
	global counter 
	counter = counter + 1
	
# define event handler functions
def tick():
	increment()
	print(counter)
	
# create a frame
frame = simplegui.create_frame("SimpleGUI Test", 100, 100)

# register event handlers
timer = simplegui.create_timer(1000, tick)
frame.add_button("Click me!", tick)

# Start frame and timers
frame.start()
timer.start()

# 3rd Edition
# import the module
import simplegui

#define global variables (program state)
counter = 0

# define "helper" functions 
def increment():
	global counter 
	counter = counter + 1
	
# define event handler functions
def tick():
	increment()
	print(counter)
	
def buttonpress():	# reset
	global counter
	counter = 0
	
# create a frame
frame = simplegui.create_frame("SimpleGUI Test", 100, 100)

# register event handlers
timer = simplegui.create_timer(1000, tick)
frame.add_button("Click me!", buttonpress)

# Start frame and timers
frame.start()
timer.start()