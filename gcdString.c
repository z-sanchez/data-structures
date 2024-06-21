#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gcdOfStrings(char *str1, char *str2);
int getGCDLength(int a, int b);

int main()
{
    char strOne[] = "ABCABC";
    char strTwo[] = "ABC";

    printf("%s_\n", gcdOfStrings(strOne, strTwo));

    return 0;
}

char *gcdOfStrings(char *str1, char *str2)
{

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *concat1 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    char *concat2 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

    strcpy(concat1, str1);
    strcat(concat1, str2);

    strcpy(concat2, str2);
    strcat(concat2, str1);

    if (strcmp(concat1, concat2) != 0)
    {
        return (char *)"";
    }

    int gcdLen = getGCDLength(len1, len2);

    char *gcd = (char *)malloc(sizeof(char) * (gcdLen + 1));

    strncpy(gcd, str1, gcdLen);
    gcd[gcdLen] = '\0';

    return gcd;
}

int getGCDLength(int a, int b)
{
    int temp = b;
    while (b != 0)
    {
        temp = b;
        b = a % b;
    }

    return temp;
}