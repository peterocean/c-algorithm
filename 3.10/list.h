#ifndef _LIST_H_
#define _LIST_H_

typedef int item_type;

struct node {
	item_type item;
	struct node *next;
};

typedef struct node *List;
typedef struct node *Position;


/*
 * list operator interface
 */
extern List list_insert_after(item_type value, Position p, List L);
extern List list_insert_tail(item_type value, List L);
extern List list_insert_node_after(struct node *new, Position p, List L);
extern int list_is_empty(List L);
extern void list_print(List L);
extern void list_destroy(List L);
extern List  list_reverse(List L);
extern Position list_find_first_bigger_node(List L, item_type key_value);
Position list_remove_first_node(List L);

#endif
