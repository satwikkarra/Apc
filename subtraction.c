/*******************************************************************************************************************************************************************
 *Title			: Subtraction
 *Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
 *Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

Status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, data_t len1,data_t len2)
{
	/* Definition goes here */
	int temp = 0,borrow,rem;
	Dlist **temp1 = tail1,**temp2 = tail2;
	if (len1 == len2)
	{
		if ((*head1)->data > (*head2)->data)
		{
			while (*tail1 && *tail2)
			{
				if ((*tail1)->data < (*tail2)->data)
				{
					temp = ((10000 + (*tail1)->data) - (*tail2)->data);
					(*tail1)->prev->data = ((*tail1)->prev->data) - 1;
				}	
				else
				{	
					temp = ((*tail1)->data) - ((*tail2)->data);
				}
				if (dl_insert_first(headR,temp,tailR) == success)
				{
					printf ("ok\n");
				}
				*tail1 = (*tail1)->prev;
				*tail2 = (*tail2)->prev;
			}
		}
		else
		{
			while (*tail1 && *tail2)
			{
				if ((*tail2)->data < (*tail1)->data)
				{
					temp = ((10000 + (*tail2)->data) - (*tail1)->data);
					(*tail2)->prev->data = ((*tail2)->prev->data) - 1;
				}	
				else
				{	
					temp = ((*tail2)->data) - ((*tail1)->data);
				}
				if (dl_insert_first(headR,temp,tailR) == success)
				{
					printf ("ok\n");
				}
				*tail1 = (*tail1)->prev;
				*tail2 = (*tail2)->prev;
			}
		}
	}
	*tail1 = *temp1;
	*tail2 = *temp2;
	if (len1 > len2)
	{
		while (*tail1 && *tail2)
		{
			if ((*tail1)->data < (*tail2)->data)
			{
				temp = ((10000 + (*tail1)->data) - (*tail2)->data);
				(*tail1)->prev->data = ((*tail1)->prev->data) - 1;
			}	
			else
			{	
				temp = ((*tail1)->data) - ((*tail2)->data);
			}
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("ok\n");
			}
			*tail1 = (*tail1)->prev;
			*tail2 = (*tail2)->prev;
		}
		while (*tail1)
		{
			temp = (*tail1)->data;
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("ok\n");
			}
			*tail1 = (*tail1)->prev;
		}
	}
	*tail1 = *temp1;
	*tail2 = *temp2;
	if (len1 < len2)
	{
		while (*tail1 && *tail2)
		{
			if ((*tail2)->data < (*tail1)->data)
			{
				temp = ((10000 + (*tail2)->data) - (*tail1)->data);
				(*tail2)->prev->data = ((*tail2)->prev->data) - 1;
			}	
			else
			{	
				temp = ((*tail2)->data) - ((*tail1)->data);
			}
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("ok\n");
			}
			*tail1 = (*tail1)->prev;
			*tail2 = (*tail2)->prev;
		}
		while (*tail2)
		{
			temp = (*tail2)->data;
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("ok\n");
			}
			*tail2 = (*tail2)->prev;
		}
	}
	return success;
}



