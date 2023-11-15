.PHONY: all test

all: extname

extname: extname.o
	cc -I. extname.o cli.c -o extname

extname.o:
	cc -c extname.c -o extname.o

test: extname
	hopic test.yml
