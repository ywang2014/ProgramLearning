# -*- coding: utf-8 -*-

# template for "Stopwatch: the Game"

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

# define global variables
current_time = 0
x = 0   # stop times
y = 0   # stop times when the is exactly full seconds

# define helper function format that converts integer
# counting tenths of seconds into formatted string A:BC.D
def format(t):
    decimals = t % 10
    t /= 10
    seconds = t % 60
    minutes = t / 60
    minutes %= 10  # 大于10分钟的值，舍弃

    if minutes < 10 and seconds < 10:
        return str(minutes) + "0:0" + str(seconds) + "." + str(decimals)
    elif minutes < 10:
        return str(minutes) + "0:" + str(seconds) + "." + str(decimals)
    elif seconds < 10:
        return str(minutes) + ":0" + str(seconds) + "." + str(decimals)
    else:
        return str(minutes) + ":" + str(seconds) + "." + str(decimals)

def draw(canvas):
    canvas.draw_text(format(current_time), [55,100], 32, "White")

def increment():
    global current_time
    current_time += 1

def score(x, y):
    return str(y) + "/" + str(x)

# define event handlers for buttons; "Start", "Reset"
def start():
    timer.start()

def stop():
    global x, y, current_time
    timer.stop()
    x += 1
    if current_time % 10 == 0:
        y += 1
    label.set_text("Scores" + score(x, y))

def reset():
    global current_time, x, y
    current_time = 0
    x = 0
    y = 0
    label.set_text("Scores" + score(x, y))
    timer.stop()

# define event handler for timer with 0.1 sec interval
timer = simplegui.create_timer(100, increment)

# create frame
frame = simplegui.create_frame("StopWatch", 200, 200)

# register event handlers
label = frame.add_label("Scores" + score(x, y))
frame.add_button("Start", start)
frame.add_button("Stop", stop)
frame.add_button("Reset", reset)
frame.set_draw_handler(draw)

# start timer and frame
frame.start()

# remember to review the grading rubric