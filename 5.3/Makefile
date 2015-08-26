CC = gcc
CFLAGS  = -g -o

gcd:gcd.o 
	$(CC) $(CFLAGS)  $@ $^
gcd.o:gcd.c
	gcc -g -c gcd.c
clean:
	rm -f gcd  *.o
