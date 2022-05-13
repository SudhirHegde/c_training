#include<stdio.h>

#include<string.h>
int size=8,top=-1;
char stack[100];


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

void Palindrome(int len){
    int i=0,j=len-1;
    while(i!=j && i<j){
        if(stack[i]!=stack[j]){
            printf("Not a Palindrome");
            return;
        }
        i++;
        j--;

    }
    printf("Is a palindrome");
}

void Display(){
    int i;
    if(isEmpty()){
        printf("Stack is Empty");
        return;
    }
    for(i=top;i>=0;i--)
        printf("%c",stack[i]);

}
int main(){
    int i,length;
    char str[50];
    printf("Enter a string:");
    scanf("%s",str);
    length=strlen(str);
    for(i=0;i<length;i++)
        Push(str[i]);
    Palindrome(length);
    return 0;








}