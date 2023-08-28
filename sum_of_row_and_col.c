#include <stdio.h>

#define row 3
#define col 3
int main()
{
    int arr[row][col]={{1,2,3},{4,5,6},{6,7,8}},row_sum=0,col_sum=0;

    int i,j;
    for(i=0;i<row;i++)
    {
        row_sum=0;
        col_sum=0;
        for(j=0;j<col;j++)
        {
            row_sum+=arr[i][j];
            col_sum+=arr[j][i];
        }
        printf("\nSum of row %d: %d",i+1,row_sum);
        printf("\nSum of col %d: %d\n",i+1,col_sum);
    }
    return 0; 
}