# -*- coding: utf-8 -*-

# socket_UDPserver.py 服务器端程序

from socket import *
from time import ctime

HOST = ''
PORT = 9999
BUFSIZE = 1024
ADDR = (HOST, PORT)

udpSerSock = socket(AF_INET, SOCK_DGRAM)
udpSerSock.bind(ADDR)

while True:
	print 'Waiting for message...'
	data, addr = udpSerSock.recvfrom(BUFSIZE)
	udpSerSock.sendto('[%s] %s' % (ctime(), data), addr)
	print '...received from and returned to:, addr'
	
udpSerSock.close()

