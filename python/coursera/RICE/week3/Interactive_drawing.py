# -*- coding: utf-8 -*-

# interactive application to convert a floar in dollars and cents

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

# define global value
value = 3.14

# Handle single quantity
def convert_units(val, name):
    if val > 1:
        return str(val) + " " + name + "s"
    return str(val) + " " + name

# convert xx.yy to xx dollars and yy cents
def convert(val):
    # Split into dollars and cents
    dollars = int(val)
    cents = int(round(100 * (val - dollars)))
    # Convert to string
    dollars_string = convert_units(dollars, "dollar")
    cents_string = convert_units(cents, "cent")

    #return composite string
    if dollars == 0 and cents == 0:
        return "Broke!"
    elif dollars == 0:
        return cents_string
    elif cents == 0:
        return dollars_string
    else:
        return dollars_string + " and " + cents_string

# define draw handler
def draw_test(canvas):
    canvas.draw_text("Hello!", [100, 100], 24, "White")
    canvas.draw_text(str(value), [100, 140], 24, "White")

def draw(canvas):
    canvas.draw_text(convert(value), [90, 100], 24, "White")

# define an input field handler
def input_handler(text):
    global value
    value = float(text)

# create frame
frame = simplegui.create_frame("Converter", 400, 200)

# register event handlers
frame.set_draw_handler(draw)
frame.add_input("Enter value", input_handler, 100)

# start frame
frame.start()
