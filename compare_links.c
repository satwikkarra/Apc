#include "apc.h"

void compare_links(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, data_t len1, data_t len2)
{
//	printf("link1 : %d  link2 : %d\n", count1, count2);
	if(len1  >= len2)
	{		
		while(len1 != len2)
		{
			dl_insert_first(head2,0,tail2);
			len2++;			
		}
	}
	else
	{	
		while(len1 != len2)
		{
			dl_insert_first(head1,0,tail1);
			len1++;			
		}
		//return 3;
	}
}
