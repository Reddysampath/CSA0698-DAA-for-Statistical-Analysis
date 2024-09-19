#include <stdio.h>
void copyRec(char str1[], char str2[])
{
    static int i = 0;

    str1[i] = str2[i];

    if (str2[i] == '\0')
        return;
    i = i + 1;
    copyRec(str1, str2);
}
int main()
{
    char str1[60];
    char str2[60];

    printf("Enter string: ");
    scanf("%[^\n]s", str1);

    copyRec(str2, str1);
    printf("Copied string: %s\n", str2);

    return 0;
}

