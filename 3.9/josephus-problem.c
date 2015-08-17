#include <stdlib.h>
#include <stdio.h>

typedef int item_type;

struct node {
	item_type item;
	struct node *next;
};

struct node * create_list(int N)
{
	int i = 0;
	struct node *temp = NULL;
	struct node *cur = NULL;

	struct node *head = malloc(sizeof(struct node));
	if (node == NULL) return NULL;
	head->item = 1;
	head->next = NULL;
	cur = head;	
	for ( int i = 2; i <= N; i++) {
		temp = malloc(sizeof(struct node));			
		/*
		 * memory alloc failed handle
		 */
		temp->item = i;
		temp->next = head;
		cur->next = temp;
		cur = cur->next;
	}
	return head;
}

void print_list(struct node *head)
{
	struct node *next = head;
	do {
		printf("Item(%d)-->",next->item);
		next = next->next;
	}while(next != head);
}


struct node * josephus_circlue(struct node *head,int M)
{
	struct node *next = head->next;
	while (next != head) {

	}
	
}
