CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
LIBS = -L. -llog_lib

OBJS = main.o test.o

all: $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(CFLAGS) -o res

main.o: main.c test.h
	$(CC) $(CFLAGS) -c main.c

test.o: test.c test.h
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f $(OBJS) res
