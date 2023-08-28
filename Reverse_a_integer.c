#include<stdio.h>
#include<conio.h>

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int temp=n;
    int digit,sum=0;
    while(temp>0)
    {
        digit=temp%10;
        sum=sum*10+digit;
        temp=temp/10;
    }
    printf("%d",sum);
}