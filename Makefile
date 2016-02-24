CFLAGS = -Wall -g -std=c++11
LDFLAGS = -lcurses
CC = gcc
OUTFILE = ncurses-breakout

all:
	$(CC) $(CFLAGS) -c
