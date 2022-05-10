/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int i,j;
int print_array(int arr[],int n){
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

int swap(int *arr,int *arr1){
    int temp;
    temp= *arr;
    *arr=*arr1;
    *arr1=temp;
}

int main()
{
    int arr[50],n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter the ELements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n-1;i++){
        int min;
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
            
        }
        swap(&arr[i],&arr[min]);
    }
    printf("sorted array is:");
    print_array(arr,n);
    
    return 0;
}
