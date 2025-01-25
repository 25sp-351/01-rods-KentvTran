CC = clang
CFLAGS = -g -Wall

all: assignment-1

assignment-1: assignment-1.o
	$(CC) -o assignment-1 $(CFLAGS) assignment-1.o

assignment-1.o: assignment-1.c
	$(CC) -c $(CFLAGS) assignment-1.c

clean:
	rm -f assignment-1 *.o

