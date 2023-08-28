#include <stdio.h>

int main()
{
    int arr[]={1,3,5,3,5,5};
    int count,flag=0,i,j;

    printf("Element repeated twice: ");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        count=0;
        for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
            if(arr[i]==arr[j])
            {
                count+=1;
                if(count==2)
                {
                    flag=1;
                    printf("%d",arr[i]);
                }
            }
        }
    }
    if(!flag)
    {
        printf("No elements repeated twice");
    }
    return 0;
}