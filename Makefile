CFLAGS=-Wall -g

all:
	make ex1
	make ex3

clean:
	ls | grep -vE  "*.c|Makefile*" | xargs rm

