CC = gcc
CFLAGS  = -g -o

list_test:main.o list.o
	$(CC) $(CFLAGS)  $@ $^
list.o:list.h
	gcc -g -c list.c
main.o:list.h
	gcc -g -c reverselist_test.c -o main.o	
	#gcc -g -c joinlist_test.c -o main.o
clean:
	rm -f  list_test *.o
