/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char option, operator;
	
	char *p = argv[1];
	char *p1 = argv[1];
	int count = 0,t_len,i,len1,len2;
	while(*p)
	{
		count++;
		if (*p == '+' || *p == '-' || *p == '/' || *p == '*')
		{
			count--;
			operator = *p;
			break;
		}
		p++;
	}
	t_len = strlen(argv[1]);
	len1 = count;
	len2 = t_len-count-1;
	char *num1 = malloc(count*sizeof(char));
	char *num2 = malloc((t_len-count-1)*sizeof(char));
	for (i = 0; i < count; i++)
	{
		num1[i] = *(p1 + i);
	}
	p1 = p1 + count + 1;
	for (i = 0; i < t_len-count-1; i++)
	{
		num2[i] = *(p1 + i);
	}
	/*p = num1;
	printf ("num1 last digit: %c\n", *p);
	p = p + count;
	printf ("num1 last digit: %c\n", *p);
	p1 = num2;
	p1 = p1 + t_len-count-1;*/
	long int a = 0, b = 0;
	a = my_atoi(num1);
	b = my_atoi(num2);
	long int n1,n2;
	n1 = a;
	n2 = b;
	int temp = 0, n = 3;
	/*p = p - 4;
	temp = my_atoi(p);
	printf ("temp : %d\n",temp);
	*p = '\0';
	p = p - 4;
	temp = my_atoi(p);
	printf ("temp : %d\n",temp);*/
	while (a)
	{
		/*p = p - 3;
		while (n--)
		{	
			temp = temp*10 + (*p - '0');
			p++;
		}
		p = p - 3;
		//temp = my_atoi(p);
		printf ("temp : %d\n",temp);
		if (p != num1)
		{
			*p = '\0';
		}*/
		temp = a % 10000;
		a = a/10000;
		if (dl_insert_first(&head1,temp,&tail1) == success)
		{
			printf ("node linked\n");
		}
	}
	printf ("num1: ");
	print_list(head1);
	while (b)
	{
		/*p1 = p1 - 4;
		temp = my_atoi(p1);
		printf ("temp : %d\n",temp);
		if (p1 != num2)
		{
			*p1 = '\0';
		}*/
		temp = b % 10000;
		b = b/10000;
		if (dl_insert_first(&head2,temp,&tail2) == success)
		{
			printf ("node linked\n");
		}
	}
	printf ("num2: ");
	print_list(head2);
	printf ("operator: %c\n", operator);
	do
	{			
		switch (operator)
		{
			case '+':
				// call the function to perform the addition operation 
				if (addition(&head1, &tail1, &head2, &tail2, &headR,&tailR, len1, len2) == success)
				{
					printf ("Addition completed\n");
					print_list(headR);
				}
				break;
			case '-':	
				// call the function to perform the subtraction operation 
				if(subtraction(&head1, &tail1, &head2, &tail2, &headR,&tailR, len1, len2) == success)
				{
					printf ("Subtraction completed\n");
					if (n1 < n2)
					{
						printf ("-");
						print_list(headR);
					}
					else
					{
						print_list(headR);
					}
				}
				break;
			case '*':	
				// call the function to perform the multiplication operation 
				if (multiplication(&head1, &tail1, &head2, &tail2, &headR,&tailR, len1, len2) == success)
				{
					printf ("Multiplication completed\n");
					print_list(headR);
				}
				break;
			case '/':	
				// call the function to perform the division operation 
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}
	while (option == 'y' || option == 'Y');
	return 0;
}
