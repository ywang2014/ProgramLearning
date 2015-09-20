# -*- coding: utf-8 -*-

# "guess the number mini_project

from SimpleGUICS2Pygame import simpleguics2pygame as simplegui
import random
import math

# initialize global variable used in your code
num_range = 100
secret_number = 0
guess_number = 0
times = 7

# helper function to initial game
def new_game():
    global num_range, secret_number, guess_number, times
    if num_range == 100:
        secret_number = random.randrange(0, 100)
    else:
        secret_number = random.randrange(0, 1000)

    times = 7

    print "New game. Range is from 0 to ", num_range
    print "Number of remaining guesses is ", times
    print ""

# define event handlers for control panel
def range100():
    # button that changes range to range[0,100) and restarts
    global num_range, times
    num_range = 100
    times = 7

    new_game()

def range1000():
    # button that changes rangee to range[0,1000) and restarts
    global num_range, times
    num_range = 1000
    times = 10

    new_game()

def get_input(input_str):
    # main game logic goes here
    global secret_number, guess_number, times
    times = times - 1
    guess_number = int(input_str)
    print "Guess was ", guess_number
    print "Number of remaining guesses is ", times

    if secret_number == guess_number:
        print "Correct!"
        print ""
        new_game()
    else:
        if secret_number > guess_number:
            print "Higher!"
            print ""
        else:
            print "Lower!"
            print ""

        if times == 0:
            print "You ran out of guesses. The number is ", secret_number
            print ""
            new_game()

# create frame
frame = simplegui.create_frame("Guess the number", 200,200)

# register event handlers for control elements
# create control element for window
frame.add_button("Range is [0, 100)", range100, 200)
frame.add_button("Range is [0, 1000)", range1000, 200)
frame.add_input("Enter a guess", get_input, 200)

new_game()

# start frame
frame.start()

# always remenber to check your completed program against
