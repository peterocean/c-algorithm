#include <stdlib.h>
#include <stdio.h>

typedef int item_type;

struct node {
	item_type item;
	struct node *next;
};

struct node * create_list(int N)
{
	int i;
	struct node *temp = NULL;
	struct node *cur = NULL;

	struct node *head = malloc(sizeof(struct node));
	if (head == NULL) return NULL;
	head->item = 1;
	head->next = NULL;
	cur = head;	
	for (i = 2; i <= N; i++) {
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

void free_list(struct node *head)
{
	struct node *cur = head;
	struct node *p = cur->next;

	printf("Delete list:");
	while (cur != cur->next) {
		p = cur->next;	
		cur->next = cur->next->next;
		printf("item %d  ",p->item);
		free(p);
	}
	printf("item %d  ",cur->item);
	free(cur);
	printf("\n");
}
void print_list(struct node *head)
{
	struct node *next = head;
	do {
		printf("Item(%d)-->",next->item);
		next = next->next;
	}while(next != head);
	printf("\n");
}


struct node * josephus_circlue(struct node *head,int M)
{
	int i;
	struct node *next = head;
	while (next != next->next) {
		for (i = 1; i < M; i++) 
			next = next->next;
	}
	print_list(head);
}

int main(int argc, char *argv[])
{
	int M, N;
	struct node *head;
	if(argc != 3) return -1;
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	printf("N=%d,M=%d.\n",N,M);
	head = create_list(N);
	print_list(head);
	free_list(head);
	return 0;
}
