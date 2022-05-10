#include <stdio.h>

int CountDistinct(int *arr, int n,int k){
    int i,j;
    for(i=0;i<k;i++){
        
        for(j=0;j<i;j++){
            if (arr[i]==arr[j])        
                break;
        }
            if(i==j)
                printf("%d",arr[i]);
            
    
    }
}

int main()
{
    int n,k,i,arr[50];
   printf("No of elements:");
   scanf("%d",&n);
   printf("Enter elements:");
   for(i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   printf("Enter window:");
   scanf("%d",&k);
   CountDistinct(arr,n,k);
   return 0;
}
