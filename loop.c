#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void make_loop(struct node* head,int pos)
{
	struct node* temp=head;
	struct node* startloop;
	
	while(temp->next!=NULL)
	{
		if(pos==1)
		{
			startloop=temp;
		}
		temp=temp->next;
		pos--;
	}
	temp->next=startloop;
}
void remove_loop(struct node* head)
{
	struct node* fast= head;
	struct node* slow= head;
	
    do 
    {
		slow=slow->next;
		fast=fast->next->next;	
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}

bool detect_loop (struct node* head)
{
	struct node* fast= head;
	struct node* slow= head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
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
		printf("\nhead has no contents now\n");
	}
}

int main()
{
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printlist(head);
	printf("%d\n",detect_loop(head));
    make_loop(head,4);
	printf("%d\n",detect_loop(head));
	remove_loop(head);
	printf("%d\n",detect_loop(head));
	
}
