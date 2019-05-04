#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_atoi.c"

typedef enum
{
	success,
	failure,
	list_empty,
	data_found,
	data_not_found
}Status;
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	char c;
	struct node *next;
}Dlist;

#include "dl_insert_first.c"
#include "print_list.c"
#include "addition.c"
#include "subtraction.c"
#include "compare_links.c"
#include "multiplication.c"


/* Include the prototypes here */
Status dl_insert_first(Dlist **head,data_t data, Dlist **tail);

void print_list(Dlist *head);

long int my_atoi(const char *s1);

Status addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, data_t len1, data_t len2);

Status subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, data_t len1, data_t len2);

Status multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,data_t len1,data_t len2);

void compare_links(Dlist **head1,Dlist **tail1, Dlist **head2,Dlist **tail2, data_t len1, data_t len2);

#endif
