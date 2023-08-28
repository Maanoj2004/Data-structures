#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", str);

    int flag = 0,i;

    if (!(isalpha(str[0])||str[0]=='_'))
    {
        flag = 1;
    }
    else
    {
        for (i = 1; i < strlen(str); i++)
        {
            if (!(isalpha(str[i]) || isdigit(str[i])))
            {
                flag = 1;
                break;
            }
        }
    }

    if (!flag)
    {
        printf("It's a valid string");
    }
    else
    {
        printf("It's not a valid string");
    }

    return 0;
}