#include <stdio.h>

int main()
{
    int arr[]={1,3,5,3,5};
    int flag=0,i,j;

    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
            if(arr[i]==arr[j])
            {
                flag=1;
                if(flag)
                {
                    printf("Duplicate element %d: %d\n",i,arr[i]);
                }
            }
        }
    }
    if(!flag)
    {
        printf("No duplicates found");
    }
    return 0;
}