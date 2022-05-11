
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
void InsertAfter(struct Node *prev_node,int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(prev_node==NULL)
        return;
    new_node->data= new_data;
    new_node->next = prev_node->next;
    prev_node->next =new_node;
}

void printList(struct Node *n){
    int count=0;
    while(n!=NULL){
        printf("%d->",n->data);
        n= n->next;
        count++;
    }
    printf("\n Count is %d",count);
}

void append(struct Node **n,int new_data){
    struct Node *new_node= (struct Node *)malloc(sizeof(struct Node));
    struct Node *last= *n;
    
    new_node -> next= NULL;
    new_node -> data= new_data;
    if(*n==NULL){
        return;
    }
    while(last->next!=NULL){
        last= last->next;
    }
    last->next=new_node;
}

void delete(struct Node **headref,int key){
    struct Node *temp=*headref, *prev_node=NULL;
    if(temp!=NULL && temp->data ==key){
        *headref= temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data != key){
        prev_node= temp;
        temp= temp->next;
    }
    if (temp==NULL)
        return;
    prev_node->next = temp->next;
    free(temp);
}
int main()
{
    struct Node *head=NULL;
    push(&head,5);
    push(&head,38);
    
    InsertAfter(head,6);
    printf("The List:");
    append(&head,90);
    delete(&head, 6);
    
    printList(head);
    
    }
