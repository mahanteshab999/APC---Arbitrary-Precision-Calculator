#include "header.h"

status do_addition(Dlist *head1, Dlist *tail1, Dlist *head2,Dlist *tail2,Dlist **head3 ,Dlist **tail3)
{
    int carry = 0, sum = 0, res = 0, car = 0;

    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    while(temp1 != NULL || temp2 != NULL)
    {
        int d1 = (temp1) ? temp1->data : 0;
        int d2 = (temp2) ? temp2->data : 0;

          res = d1 + d2 + carry;
          carry = res / 10;
          res = res % 10;

         add_result(head3, tail3, res);

         if (temp1) temp1 = temp1->prev;
         if (temp2) temp2 = temp2->prev;
    }
    {
		add_result(head3,tail3,carry);
	}

	return SUCCESS;
}
status add_result(Dlist **headR,Dlist **tailR,int sum)
{
	// INSERT AT FIRST methodology
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
		return FAILURE;
	}

	new->data = sum;
	new->prev = NULL;
	new->next = NULL;
	if( *headR == NULL)
	{
		*headR = new;
		*tailR = new;
	}
	else
	{
		new->next = *headR;
		(*headR)->prev = new;
		*headR = new;
	}
	return SUCCESS;
}
