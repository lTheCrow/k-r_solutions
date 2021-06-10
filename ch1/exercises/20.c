/**
 * Write a program detab that replaces tabs in the input with the proper 
 * number of blanks to space to the next tab stop. Assume a fixed set of tabs 
 * stops, say every n columns. Should n be a variable or a symbolic parameter?
 */
#include <stdio.h>

#define MAX_LENGTH      1024
#define TAB_WIDTH          8
#define RESET              0

char line[MAX_LENGTH];
char tabb[MAX_LENGTH];
int length;

void detab(char line[]);
void copy(char source[], char destination[], int limit);
int get_line(void);

int main(void)
{  
        
        while ((length = get_line()) > 0) {
                detab(line);
                printf("%s\n", line);
        }
                
        return 0;
}

/**
 * Copy line array to tabb array but, if it finds a \t char
 * it will set blank characters to fill the TAB_WIDTH
 **/
void detab(char line[])
{
        int i = 0;      /* index for line string array */
        int j = 0;      /* index for tabb string array */
        int wlen = 0;   /* word length */

        /*
         * Loops through the line array and stops if:
         *      - line[i] == '\0'
         *      - j or i reach the limit
         */
        for (; line[i] && j < MAX_LENGTH && i < MAX_LENGTH; i++) {
                if (line[i] == '\t') {
                        /* 
                         * make the blank loop limit 
                         */
                        int limit = j + TAB_WIDTH - (wlen % TAB_WIDTH);
                        while (j < limit)
                                tabb[j++] = ' ';

                        wlen = RESET;
                } else {
                        tabb[j++] = line[i];
                        wlen++;
                }       
        }

        copy(tabb, line, MAX_LENGTH);
}

/**
 * copy the source[] buffer to destination[] buffer
 **/
void copy(char source[], char destination[], int limit)
{
        int i;
        
        /* 
         * char-to-char copy and it evaluate the final expression
         * if expression is the end of string ('\0'), it will stop
         * and if expression reach the limit, it will stop 
         */
        for (i = 0; (destination[i] = source[i]) != '\0' && i < limit; ++i);
}

/**
 * get string line from stdin and store it in line[] buffer
 * 
 * return the length of input as an integer
 **/
int get_line(void)
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
        for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAX_LENGTH; i++)
                line[i] = c;
 
        if (c == '\n') 
                line[i++] = c;      /* it will add the \n character 
                                       to the string */
    
        line[i] = '\0';         /* add \0 character to mark
                                   the char array as a string */
        return i;
}