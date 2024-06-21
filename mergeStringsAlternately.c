#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeWords(char *wordOne, char *wordTwo);

int main()
{

    char wordOne[] = "Violet";
    char wordTwo[] = "Idol";

    char *mergedWord = mergeWords(wordOne, wordTwo);

    printf("%s_\n", mergedWord);

    return 0;
}

char *mergeWords(char *wordOne, char *wordTwo)
{
    int len1 = strlen(wordOne);
    int len2 = strlen(wordTwo);
    int characterTotal = len1 + len2;

    char *mergedWord = (char *)malloc(sizeof(char) * (characterTotal + 1));

    int j = 0;

    for (int i = 0; i < characterTotal; i++)
    {
        if (i < len1)
        {
            mergedWord[j++] = wordOne[i];
        }

        if (i < len2)
        {
            mergedWord[j++] = wordTwo[i];
        }
    }

    mergedWord[j] = '\0';

    return mergedWord;
}
