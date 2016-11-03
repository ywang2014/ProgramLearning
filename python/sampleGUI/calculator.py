# -*- coding: utf-8 -*-

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui

store = 1
operand = 2

def output():
    print "Store = ", store
    print "Operand = ", operand
    print ""

def swap():
    global store, operand
    store, operand = operand, store
    output()

def add():
    global store, operand
    store = store + operand
    output()

def sub():
    global store, operand
    store = store - operand
    output()

def multiple():
    global store, operand
    store = store * operand
    output()

def divid():
    global store, operand
    if operand != 0:
        store = float(store / operand)
        output()
    else :
        print "DividByZero!"

def remainder():
    global store, operand
    if (operand != 0 and isinstance(store, int) and isinstance(operand, int)):
        store = store % operand
        output()
    else :
        print "is not integer!"

def enter(input_str):
    global operand
    operand = float(input_str)
    output()

frame = simplegui.create_frame("Calculator", 200, 400)

frame.add_button("Print", output, 100)
frame.add_button("Swap", swap, 100)
frame.add_button("Add", add, 100)
frame.add_button("Sub", sub, 100)
frame.add_button("Multiple",multiple, 100)
frame.add_button("Divid", divid, 100)
frame.add_button("Remainder", remainder, 100)

frame.add_input("Enter operand", enter, 100)

frame.start()