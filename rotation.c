#include<stdio.h>
int i,n;

int k_shifted(int arr[],int k,int n){
    int b[50],temp,j;

    for(i=0;i<=k;i++){
        temp=arr[0];
        for(j=0;j<n-1;j++)
        {
        arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
}}

int print_array(int arr[],int n){
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}


int main(){
    int arr[50],k;

    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter the ELements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter shift amount:");
    scanf("%d",&k);

    k_shifted(arr, k, n);

    print_array(arr,n);

    return 0;
}
