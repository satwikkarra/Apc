#include "apc.h"

Status multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, data_t len1, data_t len2)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	unsigned int c = 0, i, var;
	int pos=0;

	Dlist *head = NULL;
	Dlist *tail =NULL;

	while(temp2 != NULL)
	{
		for(i = 0; i < pos; i++)
		{
				//head->data  = c;
				//call insert last fun and pass 0
			dl_insert_first(&head, 0,&tail);
		}
		while(temp1 != NULL)
		{
			var = ((temp1->data) * (temp2->data)) + c;
			c =  var / 10000;
			var = var % 10000;
			dl_insert_first(&head, var,&tail);
			temp1 = temp1->prev;
		}
		if(c != 0)
		{
			dl_insert_first(&head,c,&tail);
		}
		if(*headR == NULL)
		{
			dl_insert_first(headR,0,tailR);
		}

		compare_links(&head,&tail,headR,tailR,len1,len2);
		
		if (addition(&head, &tail,headR,tailR,headR,tailR,len1,len1) == success)
		{
			printf ("zeroes appended\n");
		}
		head = NULL;
		tail = NULL;
		temp1 = *tail1;
		temp2 = temp2->prev;
		pos++;
		c = 0;
	}
	return success;
}
