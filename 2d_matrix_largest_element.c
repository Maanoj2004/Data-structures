#include <stdio.h>
#define ROW 2
#define COL 2

int main()
{
    int arr[ROW][COL]={{1,2},{3,4}};
    int i,j;
    int max_element=arr[0][0];
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(arr[i][j]>max_element)
            {
                max_element=arr[i][j];
            }
        }
    }
    printf("The largest element is: %d",max_element);
}