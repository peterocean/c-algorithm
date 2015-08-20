#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[])
{
	int i = 0;
	Position old;
	Position find;
	struct node input_list_node;
	struct node sort_list_node;
	List input_list;
	List sort_list;

	input_list_node.next = NULL;
	sort_list_node.next = NULL;
	input_list = &input_list_node;
	sort_list = &sort_list_node;	
	

	for (i = 0; i < 20; i++) {
		p = list_find_last(input_list);
		list_insert_after(rand()%1000,p,input_list);
	}
	printf("Original input list:\n");
	list_print(input_list);

  	old = input_list->next;
	while (old != NULL) {
		find = list_find_first_larger_node(sort_list);
		list_node_insert_after(old,find,sort_list);
	}
	
	
	list_destroy(input_list);
	list_destroy(sort_list);

	return 0;
}
