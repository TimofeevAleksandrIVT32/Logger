CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
LIBS = -L. -llog_lib

OBJS = main.o test.o log_lib.o

all: liblog_lib.a $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(CFLAGS) -o res

main.o: main.c test.h
	$(CC) $(CFLAGS) -c main.c

test.o: test.c test.h
	$(CC) $(CFLAGS) -c test.c

liblog_lib.a: log_lib.o
	ar rcs liblog_lib.a log_lib.o

log_lib.o: log_lib.c
	$(CC) $(CFLAGS) -c log_lib.c

clean:
	rm -f $(OBJS) liblog_lib.a res
