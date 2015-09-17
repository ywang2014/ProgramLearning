# -*- coding: utf-8 -*-

# socket_UDPclient.py 客户端程序

from socket import *

HOST = ''
PORT = 9999
BUFSIZE = 1024
ADDR = (HOST, PORT)

udpClientSock = socket(AF_INET, SOCK_DGRAM)

while True:
	data = raw_input('>')
	if not data:
		break

	udpClientSock.sendto(data, ADDR)
	data, ADDR = udpClientSock.recv(BUFSIZE)
	if not data:
		break
	print data
	
udpClientSock.close()


