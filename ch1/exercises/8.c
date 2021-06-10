/**
 * Write a program to count blanks, tabs, and newlines.
 */
#include <stdio.h>

int main(void)
{

    size_t spaces = 0;
    for (int c = 0; (c = getchar()) != EOF; ++c)
        if (c == '\t' || c == '\n' || c == ' ')
            spaces++;

    printf("Spaces: %ld\n", spaces);        

    return 0;
}