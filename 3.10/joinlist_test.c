#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[])
{
	int i = 0;
	Position old;
	Position find;
	Position p = NULL;
	Position tmp;
	struct node input_list_node;
	struct node sort_list_node;
	List input_list;
	List sort_list;

	input_list_node.next = NULL;
	sort_list_node.next = NULL;
	input_list = &input_list_node;
	sort_list = &sort_list_node;	
	

	for (i = 0; i < 20; i++) {
		list_insert_tail(rand()%1000,input_list);
	}
	printf("Original input list:\n");
	list_print(input_list);

	while ( (old = list_remove_first_node(input_list)) != NULL) {
		
		find = list_find_first_bigger_node(sort_list,old->item);
		list_insert_node_after(old,find,sort_list);
		printf("Original list:\n");
		list_print(input_list);
		printf("Sorted list:\n");
		list_print(sort_list);
	}
	
	
	list_destroy(input_list);
	list_destroy(sort_list);

	return 0;
}
