
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

void Push(struct Node **headref,int new_data){
    struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data= new_data;
    new_node->next = *headref;
    *headref = new_node;
    
}


void Display(struct Node *n){
    int count=0;
    while(n!=NULL){
        printf("%d->",n->data);
        n= n->next;
    }

}


int Pop(struct Node **headref){
    struct Node *temp=*headref;
    int ele;
    if (temp == NULL){
        printf("Stack Underflow");
        return -99;
        
    }

        *headref= temp->next;
        ele=temp->data;
        free(temp);
        return ele;

}

void Peek(struct Node **headref){
    struct Node *temp=*headref;
    if (temp == NULL){
        printf("Stack Underflow");
        return;
}
    printf("%d",temp->data);
}

int main()
{
    int ch,ele;
    struct Node *head=NULL;
do{
    printf("\nStack Operation:\n");
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n \nEnter your Choice:\n");
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("\nEnter an Element:\n");
                scanf("%d",&ele);
                Push(&head,ele);
                break;

        case 2: printf("\nElement Popped= %d",Pop(&head));
                break;

        case 3: Peek(&head);
                break;

        case 4: printf("\nStack Elements:\n");
                Display(head);
                break;

        case 5: exit(0);
        default:
                printf("Invalid Input");

    }}while(1);
    }
