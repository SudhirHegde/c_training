
#include <stdio.h>

int main()
{   char str[200];
    int count[256]={0},i=0,status=0;
    gets(str);
    // printf("%s",str);
    
    for(;str[i];i++)
    {
        count[str[i]]+=1;
    }
    for(i=97;i<=122;i++)
    {
        if(!count[i]){
            printf("\nIs not a Panagram");
            status=1;
            break;
        }
            
    }
    if(!status)
        printf("\nIs a Panagram");
    return 0;
}
//the quick brown fox jumps over the lazy dog
