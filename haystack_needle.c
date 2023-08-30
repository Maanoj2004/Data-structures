#include <stdio.h>
#include <string.h>

int main() {

    char haystack[100],needle[100];
    printf("Enter the sentence for haystack: ");
    scanf("%[^\n]s",&haystack);
    printf("Enter the word to be searched for needle:");
    scanf("%s",&needle);

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    int i,j;
    for (i = 0; i <= haystack_len - needle_len; i++)
    {
        for (j = 0; j < needle_len; j++) 
        {
            if (haystack[i + j] != needle[j]) 
            {
                break; 
            }
        }
        if (j == needle_len) {
            printf("Needle found at position: %d\n", i);
            return 0; 
        }
    }

    printf("Needle not found in haystack.\n");

    return 0;
}
