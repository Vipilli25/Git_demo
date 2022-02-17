#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*head=NULL;

void push(struct node** head,int val) // de-referencing pointer in order to utilize the edited contents of head pointer globally 
{                                     // changing contents here will result changes globally (recap swap function)//
	struct node* n;                               
   	n=(struct node*)malloc(sizeof(struct node)); //a node is created and the address of node(address of data block) gets stored in n pointer//
   	n->data=val;                                   
   	n->next=*head;
   	
   	*head=n;	
}

struct node* reverse_k(struct node* head, int k)
{
	struct node* prevptr=NULL;
	struct node* currptr=head;
	struct node* nextptr;
	int count=0;
	while(currptr!=NULL&& count<k)
	{
		nextptr=currptr->next;
		currptr->next=prevptr;
		
		prevptr=currptr;
		currptr=nextptr;
		count++;
	}
	if(nextptr!=NULL)
	{
		head->next=reverse_k(nextptr,k);
	}
	return prevptr;	
}
void printlist(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d->",head->data);
        head=head->next;
	}
	if(head==NULL)
	{
		printf("\nlist has no contents now\n");
	}
}
int main()
{
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	printlist(head);
	struct node* newhead=reverse_k(head,2);
	printlist(newhead);
}
