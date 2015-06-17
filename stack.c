/*
*	/queue.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
	unsigned char	priority;
	int 	data;
	char	*desc;	
	struct node	*prev;
} node;

node* createNode(unsigned char _priority, int _data, char *_desc, struct node *_prev)
{
	struct node *ndTmp = (struct node*) malloc(sizeof (struct node));

	ndTmp->priority = _priority;
	ndTmp->data = _data;
	ndTmp->desc = (unsigned char*) malloc(strlen(_desc) + 1);
	strcpy(ndTmp->desc, _desc);
	ndTmp->prev = _prev;

	return ndTmp;
}

void display(struct node *_top)
{
	while (_top != NULL) {
		printf("\n----------------------------\n");
		printf("Priority: %d\n", _top->priority);
		printf("Data: %d\n", _top->data);
		printf("Description: %s\n", _top->desc);
		printf("----------------------------\n");
		_top = (node*) _top->prev;
	}
}

int main()
{	
	node	*top = NULL;
	top = createNode(1, 123, "Niraj Ramoliya", top);
	display(top);
	return 0;
}
