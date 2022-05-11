#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};
void push(struct Node **headref,int new_data){
    struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data= new_data;
    new_node->next = *headref;
    *headref = new_node;
    
}
void swap(struct Node **n,int a,int b){
    
    if(a==b)
        return;
        
    struct Node *prev_X=NULL, *curr_X= *n;
    while(curr_X!= NULL && curr_X->data != a){
        prev_X = curr_X;
        curr_X= curr_X->next;
    }
    
    struct Node *prev_Y=NULL, *curr_Y= *n;
    while(curr_Y!= NULL && curr_Y->data != b){
        prev_Y = curr_Y;
        curr_Y= curr_Y->next;
    }
    
    if(curr_X==NULL||curr_Y==NULL)
        return;
    
    // If x is not head of linked list
    if (prev_X != NULL)
        prev_X->next = curr_Y;
    else // Else make y as new head
        *n = curr_Y;
 
    // If y is not head of linked list
    if (prev_Y != NULL)
        prev_Y->next = curr_X;
    else // Else make x as new head
        *n = curr_X;
        
    struct Node *temp=curr_Y->next;
    curr_Y->next= curr_X->next;
    curr_X->next = temp;
    
    

}
void printList(struct Node *n){
    int count=0;
    while(n!=NULL){
        printf("%d->",n->data);
        n= n->next;
        count++;
    }
    printf("\n Count is %d\n",count);
}
int main()
{
    struct Node *head=NULL;
 
    printf("The List:\n");
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    
    
    printList(head);
    swap(&head,30,20);
    printList(head);
    
    }