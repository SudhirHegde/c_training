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
void reverse(struct Node **headref){
    struct Node *prev_node=NULL, *curr_node= *headref, *next=NULL;
    while(curr_node!= NULL){
        next= curr_node->next;
        curr_node->next = prev_node;
        
        prev_node= curr_node;
        curr_node= next;
        
    }
    *headref= prev_node;
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
    reverse(&head);
    printf("After Reversing:\n");
    printList(head);
    
    
    }