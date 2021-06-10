/**
 * Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a single blank 
 */
#include <stdio.h>

int main(void)
{
    int input, blank_count;

    blank_count = 0;
    while ((input = getchar()) != EOF) {
        if (input == ' ' && blank_count == 0) {
            putchar(input);
            ++blank_count;
        } else if (input != ' ') {
            putchar(input);
            blank_count = 0;
        }        
    }         

    return 0;
}