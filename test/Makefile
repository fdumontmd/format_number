CC=c99
CFLAGS=-I../include

all: test

test_format_number: test_format_number.o ../src/format_number.o
	$(CC) test_format_number.o ../src/format_number.o -lcheck \
		-o test_format_number

test: test_format_number
	./test_format_number
