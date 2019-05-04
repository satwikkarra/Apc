#include "apc.h"

void print_list(Dlist *head)
{
	if(head == NULL)
	{
		printf("List empty\n");
	}
	else
	{
		printf ("%c", head->c);
		while(head)
		{
			printf("%d->",head -> data);
			head = head -> next;
		}
		putchar('\n');
	}
	putchar('\n');
}

