#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int size=5;
int stack[5],top1=-1,top2= 5;

void Push1(int ele){
    if(top2 == top1-1){
        printf("Stack Overflow");
        return;
    }

    stack[++top1]= ele;
    
}


void Push2(int ele){
    if( top1 == top2+1){
        printf("Stack Overflow");
        return;
    }
    stack[--top2]= ele;
    
}


int Pop1(){
    int ele;
    if(top1== -1){
        printf("Stack Underflow");
        return INT_MIN;
    }
    ele=stack[top1--];
    return ele;
}


int Pop2(){
    int ele;
    if(top2 == size){
        printf("Stack Underflow");
        return INT_MIN;
    }
    ele=stack[top2++];
    return ele;
}


void Peek1(){
    if(top1== -1){
        printf("Stack is Empty");
        return;
    }
    printf("%d",stack[top1]);
}


void Peek2(){
    if(top2 == size){
        printf("Stack is Empty");
        return;
    }
    printf("%d",stack[top2]);
}

void Display1(){
    int i;
    if(top1== -1){
        printf("Stack is Empty");
        return;
    }
    for(i=top1;i>=0;i--)
        printf("%d\t",stack[i]);
}

void Display2(){
    int i;
    if(top1== size){
        printf("Stack is Empty");
        return;
    }
    for(i=top2;i<=size-1;i++)
        printf("%d\t",stack[i]);        

}

int main(){
    int ch,ele;
    do{
    printf("\nStack 1 Operation:\n");
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n");
    printf("\nStack 2 Operation:\n");
    printf("\n5.PUSH\n6.POP\n7.PEEK\n8.DISPLAY\n9.EXIT\n \nEnter your Choice:\n");
    scanf("%d",&ch);


    switch(ch){
        case 1: printf("\nEnter an Element:\n");
                scanf("%d",&ele);
                Push1(ele);
                break;

        case 2: printf("\nElement Popped= %d",Pop1());
                break;

        case 3: Peek1();
                break;

        case 4: printf("\nStack Elements:\n");
                Display1();
                break;
        case 5: printf("\nEnter an Element:\n");
                scanf("%d",&ele);
                Push2(ele);
                break;

        case 6: printf("\nElement Popped= %d",Pop2());
                break;

        case 7: Peek2();
                break;

        case 8: printf("\nStack Elements:\n");
                Display2();
                break;

        case 9: exit(0);
        default:
                printf("Invalid Input");
                


   }}while(1);

}
