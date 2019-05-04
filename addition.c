/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

Status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, data_t len1, data_t len2)
{
	int temp = 0,carry,rem;
	while (*tail1 && *tail2)
	{
		carry = temp/10000;
		//printf ("carry:%d\n", carry);
		temp = carry + ((*tail1)->data) + ((*tail2)->data);		
		//printf ("temp:%d\n", temp);
		rem = temp % 10000;
		if (dl_insert_first(headR,rem,tailR) == success)
		{
			printf ("New result node linked\n");
		}
		*tail1 = (*tail1)->prev;
		*tail2 = (*tail2)->prev;
	}
	carry = temp/10000;
	if (len1 > len2)
	{
		(*tail1)->data = (*tail1)->data + carry;
		while (*tail1)
		{
			temp = (*tail1)->data;
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("New result node linked\n");
			}
			*tail1 = (*tail1)->prev;
		}
	}
	else if (len1< len2)
	{
		(*tail2)->data = (*tail2)->data + carry;
		while (*tail2)
		{
			temp = (*tail2)->data;
			if (dl_insert_first(headR,temp,tailR) == success)
			{
				printf ("New result node linked\n");
			}
			*tail2 = (*tail2)->prev;
		}
	}
	else
	{
		if (carry && dl_insert_first(headR,carry,tailR) == success)
		{
			printf ("New result node linked\n");
		}
	}
	return success;
}
