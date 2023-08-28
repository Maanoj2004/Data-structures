#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,9};
    
    int i,flag=0;

    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(i==4)
        {
            flag=1;
            if(flag)
            {
                printf("The 5th itereated element is %d",arr[i]);
            }
        }
    }
    if(!flag)
    {
       printf("There is no 5th element!"); 
    }
}