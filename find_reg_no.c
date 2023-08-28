#include<stdio.h>

int main()
{
    int reg[]={192224285,192224265,192229245,192226485,192224280};
    int n,flag=0,i;
    printf("Enter the Registered number: ");
    scanf("%d",&n);
    for(i=0;i<sizeof(reg)/sizeof(reg[0]);i++)
    {
        if(reg[i]==n)
        {
            flag=1;
            if(flag==1)
            {
            printf("Found at Index: %d",i+1);
            }
        }
    }
    if(flag==0)
    {
        printf("Not found");
    }
    return 0;
}