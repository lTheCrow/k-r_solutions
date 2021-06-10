/**
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical 
 * orientation is challenging.
 */
#include <stdio.h>

#define IN      1       /* inside a word */
#define OUT     0       /* outside a word */

int main(void)
{
    size_t word_length = 0;

    int state = OUT;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            int i;
            printf("%3d | ", word_length);
            for (i = 0; i < word_length; i++)
                putchar('*');
            printf("\n");
            word_length = 0;
        } else {
            word_length++;
        }
    }

}