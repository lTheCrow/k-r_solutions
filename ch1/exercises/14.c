/**
 * Write a program to print a histogram of the frequencies of different
 * characters in its input
 */
#include <stdio.h>

#define EXTENDED_ASCII_SIZE 256

int main(void)
{
    size_t ext_ascii[EXTENDED_ASCII_SIZE] = {0};
    int input;

    while ((input = getchar()) != '\n') {
        if (input != ' ' || input != '\t')
            ext_ascii[input]++;
    }

    int i;
    for (i = 0; i < EXTENDED_ASCII_SIZE; i++) {
        if (ext_ascii[i] > 0) {
            printf("%c: ", i);
            int j;
            for (j = 0; j < ext_ascii[i]; j++)
                printf("*");
            printf("\n");
        }
            
    }

}