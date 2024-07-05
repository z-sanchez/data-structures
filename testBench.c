#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findGCDLength(int lengthOne, int lengthTwo);
char *findGCD(char *stringOne, char *stringTwo);

int main()
{

    char *gcd = findGCD((char *)"ABABAB", (char *)"ABAB");

    printf("%s\n", gcd);

    return 0;
}

int findGCDLength(int a, int b)
{
    int temp = b;

    while (b != 0)
    {
        temp = b;
        b = a % b;
    }

    return temp;
}

char *findGCD(char *stringOne, char *stringTwo)
{
    int lenOne = strlen(stringOne);
    int lenTwo = strlen(stringTwo);

    char *concatOne = (char *)malloc(lenOne + lenTwo);
    char *concatTwo = (char *)malloc(lenOne + lenTwo);

    strcpy(concatOne, stringOne);
    strcat(concatOne, stringTwo);

    strcpy(concatTwo, stringTwo);
    strcat(concatTwo, stringOne);

    if (strcmp(concatOne, concatTwo) != 0)
    {
        return (char *)"";
    }

    int gcdLength = findGCDLength(lenOne, lenTwo);
    char *gcd = (char *)malloc(gcdLength + 1);

    strncpy(gcd, stringOne, gcdLength);

    gcd[gcdLength + 1] = '\0';
    return gcd;
}
