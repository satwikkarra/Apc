#include "apc.h"

Status dl_insert_first(Dlist **head,data_t data, Dlist **tail)
{
	Dlist *new = malloc(sizeof(Dlist));
	if (new == NULL)
	{
		return failure;
	}
	new->data = data;
	new->prev = NULL;
	new->next = *head;
	if (*head == NULL)
	{
		*head = new;
		*tail = new;
		return success;
	}
    (*head)->prev  = new;
    *head = new;
    return success;
}
