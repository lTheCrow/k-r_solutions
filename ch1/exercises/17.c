/** 
 * Write a program to print all input lines that are longer than 80 characters 
 */
#include <stdio.h>

#define LIMIT   256

int get_line(char string[], int limit);

int main(void)
{
    char input[LIMIT] = {0};
    int len, counter = 0;
    while ((len = get_line(input, LIMIT)) > 0)
        if (len > 80)
            printf("[%d] %s\n", ++counter, input);
            
    return 0;
}

int get_line(char string[], int limit)
{
    int c, i;
    for (i = 0, c = 0; (c = getchar()) != EOF && c != '\n' && (i < limit-1); i++)
        string[i] = c;

    if (c == '\n') 
        string[i++] = c;
    
    string[i] = '\0';
    return i;
}