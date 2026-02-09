#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);
    int length = strlen(str);
    int i = 0, j = length - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
    printf("Reversed string: %s", str);
    return 0;
}
