#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <assert.h>

Position list_find_last(List L)
{
	Position p = L;

	assert(L != NULL);
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

List list_insert_after(item_type value, Position p, List L)
{
	struct node *new =  malloc(sizeof(struct node));
	if (new == NULL) return;
	new->item = value;
	
	new->next = p->next;
	p->next = new;
	return L;
}

List list_insert_tail(item_type value, List L)
{
	Position p = L;
	p = list_find_last(L);
	list_insert_after(value,p,L);
	return L;
}

List list_insert_node_after(struct node *new, Position p, List L)
{
	Position tmp;
	
	assert(new != NULL);
	assert(p != NULL);
	
	new->next = p->next;
	p->next = new;
	return L;
}

int list_is_empty(List L)
{
	assert(L != NULL);
	return L->next == NULL;
}

void list_print(List L)
{
	int cnt = 0;
	Position p = L->next;
	
	assert(L != NULL);
	if (list_is_empty(L)) {
		printf("List is empty.\n");
		return;
	}
	while (p != NULL) {
		printf("%4d ",p->item);
		if ( (++cnt % 20) == 0)
			printf("\n");
		p = p->next;
	}
	printf("\n");
}

void list_destroy(List L)
{
	Position p = L->next;
	Position tmp;
	
	assert(L != NULL);
	L->next = NULL;

	while (p != NULL) {	
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

List  list_reverse(List L)
{
	Position tmp,p; 
	Position reversed_front = NULL;

	assert(L != NULL);
	if (list_is_empty(L)) return L;

	p = L->next;
	while (p != NULL) {
		tmp	= p->next;
		p->next = reversed_front;
		reversed_front = p;
		p = tmp;
	}
	L->next = reversed_front;
	return L;
}


Position list_find_first_bigger_node(List L, item_type key_value)
{
	Position p = L;
	
	while (p->next != NULL) {
		if (p->next->item > key_value)
			break;
		p = p->next;
	}
	return p;
}

Position list_remove_first_node(List L)
{
	Position tmp,p;

	if (list_is_empty(L)) return NULL;
	tmp = L->next;
	L->next = L->next->next;
	return tmp;
}






