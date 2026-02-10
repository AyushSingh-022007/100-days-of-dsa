// Problem: Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int left, right, length, flag = 1;
    printf("Enter a string: ");
    scanf("%s", str);
    length = strlen(str);
    left = 0;
    right = length - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            flag = 0;
            break;
        }
        left++;
        right--;
    }
    if (flag)
        printf("Palindrome");
    else
        printf("Not a Palindrome");
    return 0;
}
