#include <stdio.h>

int main()
{
    int arr1[]={1,2,3,4,5},arr2[]={6,7,8,9,10};
    int l1=sizeof(arr1)/sizeof(arr1[0]);
    int l2=sizeof(arr2)/sizeof(arr2[0]);

    int n=l1+l2,i,j,k;
    int merge[n];
    
    for(i=0;i<l1;i++)
    {
        merge[i]=arr1[i];
    }
    
    for(j=l1,i=0;j<n,i<l2;j++,i++)
    {
        merge[j]=arr2[i];
    }
    
    for(k=0;k<n;k++)
    {
        printf("%d ",merge[k]);
    }
    return 0;
}