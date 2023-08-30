#include <stdio.h>

int main() {
   int array[10];
   int even[5] = {0, 2, 4, 6, 8};
   int odd[5]  = {1, 3, 5, 7, 9};
   
   int i, index;
   index = 0;
 
   for(i = 0; i < sizeof(even)/sizeof(even[0]); i++) 
   {
      array[index] = even[i];
      index++;
   }
   printf("%d",index);
   for(i = 0; i < sizeof(odd)/sizeof(odd[0]); i++) 
   {
      array[index] = odd[i];
      index++;
   }

   printf("Even -> ");
   
   for(i = 0; i < sizeof(even)/sizeof(even[0]); i++)
      printf(" %d", even[i]);
   
   printf("\nOdd  -> ");
   
   for(i = 0; i < sizeof(odd)/sizeof(odd[0]); i++)
      printf(" %d", odd[i]);

   printf("\nConcat -> ");
   
   for(i = 0; i < 10; i++)
      printf(" %d", array[i]);

   return 0;
}
