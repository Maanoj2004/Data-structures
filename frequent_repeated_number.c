#include <stdio.h>
#define max_size 100

int main()
{
    int arr[]={1,2,2,3,5,5,3,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    int frequentCount[max_size]={0};
    int i;
    for(i=0;i<size;i++)
    {
        frequentCount[arr[i]]++;
    }

    printf("Frequently repeated numbers and their count:\n");
    int flag=0;
    for(i=0;i<max_size;i++)
    {
        if(frequentCount[i]>1)
        {
            flag=1;
            printf("%d appears %d times\n",i,frequentCount[i]);
        }
    }
    if(!flag)
    {
        printf("No element appears frequently");
    }
    return 0;
}
