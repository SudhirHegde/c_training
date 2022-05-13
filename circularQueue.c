#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int size=5;
int stack[5],top=-1;


int isFull(){
    if(top == size-1)
        return 1;
    else 
        return 0;
}

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

void Push(int ele){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    stack[++top]= ele;
    
}
int Pop(){
    int ele;
    if(isEmpty()){
        printf("Stack Underflow");
        return INT_MIN;
    }
    ele=stack[top--];
    return ele;
}

void Display(){
    int i;
    if(isEmpty()){
        printf("Stack is Empty");
        return;
    }
    for(i=top;i>=0;i--)
        printf("%d\t",stack[i]);

}
int main(){
    int ch,ele;
    do{
    printf("\nStack Operation:\n");
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n \nEnter your Choice:\n");
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("\nEnter an Element:\n");
                scanf("%d",&ele);
                Push(ele);
                break;

        case 2: printf("\nElement Popped= %d",Pop());
                break;

        case 3: Peek();
                break;

        case 4: printf("\nStack Elements:\n");
                Display();
                break;

        case 5: exit(0);
        default:
                printf("Invalid Input");

    }}while(1);
}