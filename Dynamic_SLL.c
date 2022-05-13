#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int capacity;
    int top;
    int *array;
};

struct stack *initialize(int c){
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
    temp->top =-1;
    temp->capacity=c;
    temp->array= (int*)malloc(sizeof(int)*temp->capacity);
    return temp;
}

void Push(struct stack *s,int ele){
    if(s->top ==s->capacity-1){
        printf("Stack Overflow");
        return;
    }
    s->array[++s->top]=ele;
}

int Pop(struct stack *s){
    int ele;
    if(s->top == -1){
        printf("Stack Underflow");
        return INT_MIN;
    }
    ele= s->array[s->top--];
    return ele;
}

void Display(struct stack *s){
    int i;
    if(s->top == -1){
        printf("Stack Underflow");
        return;
    }
    for(i=(s->top);i>=0;i--){
        printf("%d\t",s->array[i]);

    }
}

void Peek(struct stack *s){
    if(s->top == -1){
        printf("Stack Underflow");
        return;
    }
    printf("Peek element:");
    printf("%d",s->array[s->top]);
}

int main(){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
     int ch,ele;
    s = initialize(5);


    do{
    printf("\nStack Operation:\n");
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n \nEnter your Choice:\n");
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("\nEnter an Element:\n");
                scanf("%d",&ele);
                Push(s,ele);
                break;

        case 2: printf("\nElement Popped= %d",Pop(s));
                break;

        case 3: Peek(s);
                break;

        case 4: printf("\nStack Elements:\n");
                Display(s);
                break;

        case 5: exit(0);
        default:
                printf("Invalid Input");

    }}while(1);
}