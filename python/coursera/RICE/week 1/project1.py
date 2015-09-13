# -*- coding: utf-8 -*-

# Rock-paper-scissors-lizard-Spock

	# 0 — rock
    # 1 — Spock
    # 2 — paper
    # 3 — lizard
    # 4 — scissors

	#  each choice wins against the preceding two choices and loses against the following two choices

import random

# helper functions
def number_to_name(number):
	'''
	converts a number in the range 0 to 4 into its corresponding name as a string
	including a final else clause that catches cases when number is not in the correct range
	'''
	if not isinstance(number, int):
		raise TypeError
	else:
		if number == 0:
			return "rock"
		elif number == 1:
			return "Spock"
		elif number == 2:
			return "paper"
		elif number == 3:
			return "lizard"
		elif number == 4:
			return "scissors"
		else:
			print "The number is invalid!"
			
	
def name_to_number(name):
	'''
	converts the string name into a number between 0 and 4
	including a final else clause that catches cases when name does not match any of the five correct input strings and prints an appropriate error message
	'''
	if not isinstance(name, str):
		raise TypeError
	else:
		if name == "rock":
			return 0
		elif name == "Spock":
			return 1
		elif name == "paper":
			return 2
		elif name == "lizard":
			return 3
		elif name == "scissors":
			return 4
		else:
			print "The name is invalid"

# main function 
def rpsls(name):
	print ""
	print "Player choose " + name
	player_number = name_to_number(name)
	
	comp_number = random.randrange(0, 5)
	comp_choice = number_to_name(comp_number)
	print "Computer chooses " + comp_choice
	
	if player_number == (comp_number + 1) % 5 or player_number == (comp_number + 2) % 5:
		print "Player wins!"
	elif player_number == (comp_number - 1) % 5 or player_number == (comp_number - 2) % 5:
		print "Computer wins!"
	else:
		print "Ended in a draw"
	
# test
rpsls("rock")
rpsls("Spock")
rpsls("paper")
rpsls("lizard")
rpsls("scissors")
input('pause!')