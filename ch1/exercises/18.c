/** 
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */
#include <stdio.h>

#define LIMIT   256

int get_line(char string[], int limit);
void rem_blnk(char src[], int dst_lim, char dst[]);

int main(void)
{
    char src[LIMIT] = "Hello world          test            test"; 
    char dst[LIMIT];
    rem_blnk(src, LIMIT, dst);
    printf("%s", dst);
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

void rem_blnk(char src[], int lim, char dst[])
{
    int i;
    for (i = 0; *src && i < lim-1; *src++) {
        if (*src != '\n' && *src != ' ' && *src != '\t' && *src != '\0')
            dst[i++] = *src;
    }
    dst[i] = '\0';
}