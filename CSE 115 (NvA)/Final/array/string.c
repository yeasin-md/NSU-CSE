#include <stdio.h>

int main()
{
    char sent[100];
    int charCount = 0, i;
    puts("Enter sentence: ");
    gets(sent);

    while (sent[i] != '\0')
    {

        sent[i] == 'a' ? sent[i] = 'A' : sent[i] == 'e' ? sent[i] = 'E'
                                     : sent[i] == 'i'   ? sent[i] = 'I'
                                     : sent[i] == 'o'   ? sent[i] = 'O'
                                     : sent[i] == 'u'   ? sent[i] = 'U'
                                                        : sent[i];

        charCount++;
        i++;
    }
    printf("\n");
    printf("Total Characcter: %d\n\n", charCount);
    puts(sent);
    return 0;
}