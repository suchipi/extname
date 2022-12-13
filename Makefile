.PHONY: all test

all: extname

extname:
	cc extname.c -o extname

test: extname
	./test.sh
