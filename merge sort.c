#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head,int val) 
{                                    
	struct node* n;                               
   	n=(struct node*)malloc(sizeof(struct node)); 
   	n->data=val;                                   
   	n->next=*head;
   	
   	*head=n;	
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
		printf("\n list has no contents now\n");
	}
}
  void FindMiddle(struct node* cur, struct node** first, struct node **second)
  {
      struct node* fast;
      struct node* slow;
      slow = cur;
      fast = cur ->next;
      
      while(fast != NULL){
          fast = fast ->next;
          if(fast != NULL)
          {
              slow = slow ->next;
              fast = fast -> next;
          }
      }
      *first = cur;
      *second = slow -> next;
      slow -> next = NULL;
    }
 struct node* MergeBoth(struct node* first, struct node* second)
  {
      struct node* answer= NULL;
      
      if(!first)
	  {
	    return second;	
	  } 
      else if(!second)
	  {
	  	return first;
	  } 
	  
      if(first->data <= second->data)
      {
          answer = first;
          answer -> next = MergeBoth(first->next, second);
      }
      else 
	  {
          answer = second;
          answer -> next = MergeBoth(first, second -> next);
      }
      return answer;
  }
   void MergeSorting(struct node** head)
  {
      struct node *cur = *head;
      struct node *first;
      struct node *second;
      
      if(!cur || !cur->next) 
      {
      	return;
	  }
	  
      FindMiddle(cur, &first, &second);
      
      MergeSorting(&first);
      MergeSorting(&second);
      *head = MergeBoth(first, second);
  }
   
    struct node* mergeSort(struct node* head) 
	{
        
        MergeSorting(&head);
        return head;
    }
  


int main()
{
	struct node* head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,12);
	push(&head,9);
	push(&head,5);
	push(&head,7);
	
	printlist(head);
	printlist(mergeSort(head));
	
}

