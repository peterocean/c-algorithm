#include <stdlib.h>
#include <stdio.h>

//#define EG24_TEST 1
#define EG25_TEST 1

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
	struct node *temp = NULL;

	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	printf("Delete list:");

	while (cur != cur->next) {
		temp = cur->next;	
		cur->next = cur->next->next;
		printf("item %d  ",temp->item);
		free(temp);
	}
	printf("item %d  ",cur->item);
	free(cur);
	printf("\n");
}

void print_list(struct node *head)
{
	struct node *next = head;
	
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	do {
		printf("Item(%d)-->",next->item);
		next = next->next;
	}while(next != head);
	printf("\n");
}

int list_sizes(struct node *pos)
{
	int len =  0;
	struct node *next = pos->next;

	if (pos == NULL) return 0;

	while (next != pos) {
		next = next->next;
		len++;
	}
	len++;
	return len;
}

int list_gap(struct node *pos1, struct node *pos2)
{
	int len = 0;

	if (pos1 == NULL || pos2 == NULL)
		return 0;
	if (pos1 == pos2) return 0;

	while (pos1->next != pos2) {
		pos1 = pos1->next;
		len++;
	}
	return len;
}





struct node * josephus_circlue(struct node *head,int M)
{
	int i = 0;
	struct node *cur = head;
	struct node *temp = NULL;

	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	while (cur != cur->next) {
		for (i = 1; i < M-1; i++) 
			cur = cur->next;
		printf("Item(%d) is out.\n",cur->next->item);
		temp = cur->next;
		cur->next = cur->next->next;
		free(temp);
		print_list(cur);
		cur = cur->next;
	}
	printf("Item(%d) is out.\n",cur->next->item);
	free(cur);
	return NULL;
}

#ifdef EG24_TEST
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
	printf("List size is:%d.\n",list_sizes(head));
	free_list(head);
	return 0;
}
#elif EG25_TEST
int main(int argc, char *argv[])
{
	int M, N;
	struct node *head;
	struct node *pos1;
	struct node *pos2;
	int i = 0;

	if(argc != 3) return -1;

	N = atoi(argv[1]);
	M = atoi(argv[2]);
	printf("N=%d,M=%d.\n",N,M);

	head = create_list(N);
	print_list(head);
	
	pos1 = head;
	for (i = 0; i < 2; i++)
		pos1 = pos1->next;
	pos2 = head;
	for (i = 0; i < 5; i++)
		pos2 = pos2->next;
	printf("pos:%d,pos:%d.\n",pos1->item,pos2->item);
	printf("Gap between pos1 and pos2 is:%d.\n",list_gap(pos1,pos2));
	free_list(head);
	return 0;
}
#else
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
	head = josephus_circlue(head,M);
	free_list(head);
	return 0;
}
#endif
