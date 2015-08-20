CC = gcc

list_test:main.o list.o
	$(CC) $(CFLAGS) -o $@ $^
list.o:list.h
main.o:list.h
clean:
	rm -f  list_test *.o
