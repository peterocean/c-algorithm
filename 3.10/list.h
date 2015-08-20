#ifndef _LIST_H_
#define _LIST_H_

typedef int item_type;

struct node {
	item_type item;
	struct node *next;
};

typedef struct node *List;
typedef struct node *Position;

#endif
