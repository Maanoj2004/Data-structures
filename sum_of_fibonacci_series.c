#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter the number of terms of fibonacci series: ");
    scanf("%d",&n);
    
    int t1=0,t2=1,nextterm=t1+t2,sum=0;

    sum+=nextterm;

    for(i=3;i<=n;i++)
    {
        sum+=nextterm;
        t1=t2;
        t2=nextterm;
        nextterm=t1+t2;
    }

    printf("%d",sum);
    return 0;
}