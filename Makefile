CC = gcc
CFLAGS = -W -Wall -std=c99 -lreadline

OBJECTS = askiirym.o

all: askiirym

askiirym: $(OBJECTS)
	$(CC) $(CFLAGS) -o bin/askiirym $(OBJECTS)

askiirym.o: askiirym.c askiirym.h
	$(CC) $(CFLAGS) -c askiirym.c

clean:
	rm -rf *.o

distclean: clean
	rm bin/askiirym

