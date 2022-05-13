#include<stdio.h>
#include<stdlib.h>
 struct Node{
     int data;
     struct Node *next;
     struct Node *prev;
 };


void push(struct Node **headref,int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*headref);
    if((*headref)!=NULL){
        (*headref)->prev=new_node;
    }
    *headref= new_node;
    }
 
 void insertAfter(struct Node *prev_node,int new_data){
     struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));
     if(prev_node==NULL){
        printf("Cannot Insert");
        return;
     }
     new_node->data = new_data;
     new_node->next = prev_node->next; 
     prev_node->next= new_node;
     new_node->prev = prev_node;

     

     if(new_node->next!= NULL)
        new_node->next->prev= new_node;

     
     
    }
void insertBefore(struct Node **headref,struct Node *next_node,int new_data){
    if(next_node==NULL)
        return;
    
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(next_node->prev==NULL)
        (*headref)=new_node;
    if(next_node->prev!=NULL)
        next_node->prev->next=new_node;

    new_node->data = new_data;
    new_node->next = next_node;
    new_node->prev = next_node->prev;
    next_node->prev= new_node;
    
    //if not first position

    //if first position

       
    
}

void delete_ele(struct Node **head_ref, int x){
    struct Node *prev_node=NULL,*temp=*head_ref,*next_node = NULL;
    //Deletion if First ELement
    if(temp->data==x){
        *head_ref=temp->next;
        temp->next->prev =NULL;
        free(temp);
        return;
    }
    //
    while(temp!=NULL && temp->data!=x){
        prev_node= temp;
        temp= temp->next;
    }
    if(temp==NULL)
        return;
// Deletion if Last element
    if(temp->next==NULL){
        prev_node->next=NULL;
        free(temp);
        return;
    }
//Deletion if Middle Element
    next_node= temp->next;
    prev_node->next= next_node;
    next_node->prev = prev_node;
    free(temp);
}
 
// }
void Insert_end(struct Node **n,int new_data){
    struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev_node=*n;
    if(*n==NULL)
        return;
    new_node->data= new_data;
    new_node->next= NULL;
    while((prev_node)->next!=NULL){
        (prev_node)=(prev_node)->next;
    }
    new_node->prev =(prev_node);
    (prev_node)->next = new_node;
}

void printList(struct Node *n){
    struct Node *last=NULL;
    printf("\nForward Traversing:\n");
    while(n!=NULL){
        printf("%d->",n->data);
        last =n;
        n=n->next;
        }
    printf("\nBackward traversing:\n");
    while((last!=NULL)){
        printf("%d->",last->data);
        last = last->prev;
        }
        

    }


 int main(){
     struct Node *head=NULL;
     push(&head,10);
     push(&head,20);
     push(&head,30);
     push(&head,40);
     push(&head,50);
    //  insertAfter(head->next,25);
    //  Insert_end(&head,60);
     insertBefore(&head, head,45);
    // delete_ele(&head,10);
     printList(head);
     return 0;
 }
 