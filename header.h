 #ifndef HEADER_FILE
 #define HEADER_FILE
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 
typedef struct node
{
   struct node* prev;
   int data;
   struct node* next;
}Dlist;

typedef enum
{
    FAILURE,
    SUCCESS,
}status;

//header functions

/* function to check wheather string is numeric or not*/
status is_numeric(char *num);

/*function to validate the arguments*/
status validate_arguments(int argc , char *argv[]);

/*Function to insert at last*/
status insert_at_last(Dlist** head, Dlist** tail, char* argv);

/*Function to free all nodes*/
status free_all(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** head3 ,Dlist** tail3);

/*function to free a single doubly linked list*/
void free_node(Dlist** head , Dlist** tail);

/*function to perform addition*/
status do_addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);

/*function to insert result digit into result*/
status add_result(Dlist **head3,Dlist **tail3,int sum);

/*function to insert command line arguments intotwo lists*/
status insert_arguments (Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv1 , char *argv2);

/*function to compare two number which returns bigger */
int find_bigger(Dlist** head1,Dlist** head2);


/*function to perform subtraction */
status do_subtraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);

/*function to print the result   */
void print_result(Dlist** head,Dlist** tail);

/*function to find length of input string*/
int find_length(char* argv);

/*function to perform division */
status do_division(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** head3,Dlist** tail3);

/*function to check if nodes exit or not */
int check_node(Dlist** head1,Dlist** head2);

/*function to perform multiplication*/
status do_multiplication(Dlist* head1,Dlist* tail1,Dlist* head2,Dlist* tail2,Dlist** head3,Dlist** tail3);

/*function to insert node at last */
void insert_last(Dlist** head,Dlist** tail);

/*function to insert node at first */
void insert_first(Dlist** head, Dlist** tail, int data);

/*function to delete first node of list */
void free_first(Dlist** head);

/* Function to check if number (list) is zero */
int is_zero(Dlist *head);

/* Function to perform modulus operation (remainder) */
status do_modulus(Dlist* head1, Dlist* tail1, Dlist* head2, Dlist* tail2, Dlist** headRem, Dlist** tailRem);


#endif