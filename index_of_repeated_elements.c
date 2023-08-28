#include <stdio.h>

int main()
{
    int arr[]={1,3,5,3,5};
    int flag=0,i,j;

    printf("Index of repeated element: ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
            if(arr[i]==arr[j])
            {
                flag=1;
                if(flag)
                {
                    printf("\n%d repeated at index %d ",arr[i],j+1);
                }
            }
        }
    }
    if(!flag)
    {
        printf("No repeated elements");
    }
    return 0;
}