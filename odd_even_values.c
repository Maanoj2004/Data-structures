#include<stdio.h>

int main()
{
    int arr[]={1,2,3,4,5},i;

    printf("Even elements: ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(arr[i]%2==0)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\nOdd elements : ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(arr[i]%2!=0)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}