#include <stdio.h>

int main()
{
    int arr[]={1,1,5,7},i,j,temp;

    printf("Ascending order: ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        printf("%d ",arr[i]);
    }
    
    printf("\nDescending order: ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        printf("%d ",arr[i]);
    }
    return 0;
}
