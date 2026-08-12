#include "header.h"
extern int negative_flag;
status do_multiplication(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** headR,Dlist** tailR)
{
	int result = 0,count= 0,mult = 0,carry = 0;
	Dlist* temp1 = tail1;
	Dlist* temp2 = tail2;

	Dlist* result_head1 = NULL;
	Dlist* result_tail1 = NULL;
	Dlist* result_head2 = NULL;
	Dlist* result_tail2 = NULL;
	while(temp2)
	{
		carry=0;
		temp1 = tail1;
		while(temp1)
		{
			mult =  carry;
			for(int i = 0;i<temp2->data;i++) //run loop temp2 data times 
			{
				mult = mult + temp1->data; // add temp1 data upto temp2 data times
			}
			carry = mult / 10; //for carry first digit
			mult = mult % 10; // adding list to last digit
			if(count == 0)
			{
				add_result(&result_head1,&result_tail1,mult);
			}
			else
			{
				add_result(&result_head2,&result_tail2,mult);
			}

			temp1 = temp1->prev;
		}
		if(carry > 0 && count > 0) // it works after 1st digit
		{
			add_result(&result_head2,&result_tail2,carry);
		}
		if(count==0) // for leftover carry after exting from loop for one digit
		{
			if(carry > 0)
			{
				add_result(&result_head1,&result_tail1,carry);
			}
			add_result(&result_head1,&result_tail1,0); // adding dummy zero
		}
		if(count >= 1)
		{
			for(int i = 1;i<=count;i++) // adding zero for list 
			{
				insert_last(&result_head2,&result_tail2); // adding zero to head2 list
			}
			if(count%2 == 1)
			{
				//odd block
				do_addition(result_head1,result_tail1,result_head2,result_tail2,headR,tailR);
				free_node(&result_head2,&result_tail2);
				free_node(&result_head1,&result_tail1);
				add_result(headR,tailR,0); // Add dummy zero to result
			}
			else
			{
				//even block
				do_addition(*headR,*tailR,result_head2,result_tail2,&result_head1,&result_tail1);
				free_node(headR,tailR);
				free_node(&result_head2,&result_tail2);
				add_result(&result_head1,&result_tail1,0);
			}
		}
		temp2 = temp2->prev;
		count++;
	}
	if (count % 2)
    {
        free_first(&result_head1);
        *headR = result_head1;
        *tailR = result_tail1;
    }
    else
    {
        free_first(headR);
    }
	free_node(&result_head1,&result_tail1);
	free_node(&result_head2,&result_tail2);
	return SUCCESS;
}
void insert_last(Dlist** head,Dlist** tail)
{
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		new->data = 0;
		new->prev = *tail;
		(*tail)->next = new;
		new->next = NULL;
		*tail = new;
	}
}
void free_first(Dlist** head)
{
	Dlist* temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}