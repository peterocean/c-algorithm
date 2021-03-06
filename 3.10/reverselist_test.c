#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[])
{
	int i = 0;
	Position p;

	List L = malloc(sizeof(struct node));
	assert(L != NULL);
	L->next = NULL;

	for (i = 0; i < 20; i++) {
		list_insert_tail(rand()%1000,L);
	}
	list_print(L);
	
	printf("List reverse:\n");
	L = list_reverse(L);
	list_print(L);

	list_destroy(L);
	free(L);
	return 0;
}
