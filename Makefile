CFLAGS=-Wall -g

all:
	make ex1 
	# Skip ex2
	make ex{3..18}

clean:
	ls | egrep -v "*\.c|Makefile|README.md|tb*" | xargs rm
