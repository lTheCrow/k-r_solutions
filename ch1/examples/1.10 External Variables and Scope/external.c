#include <stdio.h>

#define LIMIT 1000  

char longest[LIMIT], line[LIMIT];
int max;

int get_line(void);
void copy(void);

/**
 * gets string lines from stdin and store the longest string if the length is 
 * less or equal than 1, it will stop and show the longest string line
 **/
int main(void)
{
    int len;
    /* extern int max;
    extern char longest[]; */
 
    max = 0;
    while ((len = get_line()) > 1) {
        if (len > max) {
            max = len;
            copy();
        }
    }                          

    if (max > 0)
        printf("Longest Line (%d): %s\n", max, longest);

    return 0;
}

/**
 * get string line from stdin and store it in line[] buffer
 * 
 * return the length of input as an integer
 **/
int get_line(void)
{
    int c, i;
    /* extern char line[]; */

    /*
     * Gets each character from stdin
     * 
     * It will stop if input is:
     *      - EOF
     *      - '\n'
     *      - Reach buffer limit 
     */
    for (i = 0; (c = getchar()) != EOF && c != '\n' && (i < LIMIT-1); i++)
        line[i] = c;
 
    if (c == '\n') 
        line[i++] = c;      /* it will add the \n character to the string */
    
    line[i] = '\0';         /* add \0 character to mark
                               the char array as a string */
    return i;
}


/**
 * copy the line[] buffer (obtained from get_line() function) 
 * to longest[] buffer
 **/
void copy(void)
{
    int i;
    /* extern char line[], longest[]; */

    
    /* 
     * char-to-char copy and it evaluate the final expression
     * if expression is the end of string ('\0'), it will stop 
     */
    i = 0;
    while ((longest[i] = line[i]) != '\0')      
        ++i;
}

        