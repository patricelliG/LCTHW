CFLAGS=-Wall -g

all:
	make ex1
	make ex3

clean:
	ls | egrep -v  "*.c|Makefile|README.md" | xargs rm
