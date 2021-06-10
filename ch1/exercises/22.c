/**
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */
#include <stdio.h>

#define MAX_SIZE        1024

void fold(char line[], int len);
int get_line(char line[], int len);

int main(void)
{
        char input[MAX_SIZE];
        int length;
        while ((length = get_line(input, MAX_SIZE)) > 0) {
                fold(input, MAX_SIZE);
                printf("%s\n", input);
        }
        return 0;
}

void fold(char line[], int len)
{
        int counter = 0;

        int i;
        for (i = 0; line[i] != '\0' && i < len; i++, counter++) {
                switch(line[i]) {
                        case ' ':
                        case '\t':
                                if (counter >= 10) {
                                        counter = 0;
                                        line[i] = '\n';
                                } 
                }
        } 
}

/**
 * get string line from stdin and store it in line[] buffer
 * 
 * return the length of input as an integer
 **/
int get_line(char line[], int len)
{
        int c, i;

        /*
         * Gets each character from stdin
         * 
         * It will stop if input is:
         *      - EOF
         *      - '\n'
         *      - Reach buffer limit 
         */
        for (i = 0; (c = getchar()) != EOF && c != '\n' && i < len; i++)
                line[i] = c;
 
        if (c == '\n') 
                line[i++] = c;      /* it will add the \n character 
                                       to the string */
    
        line[i] = '\0';         /* add \0 character to mark
                                   the char array as a string */
        return i;
}
