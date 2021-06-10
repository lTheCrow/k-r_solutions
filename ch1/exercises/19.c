/**
 * Write a function reverse(s) that reverse the character string s. Use it to
 * write a program that reverses its input a line at a time. 
 */
#include <stdio.h>
#include <string.h>

#define LIMIT   1024

int get_line(char string[], int limit);
void rem_blnk(char src[], int dst_lim, char dst[]);
void reverse(char s[]);

int main(void)
{
    char in[LIMIT];
    char out[LIMIT];
    int len;

    while ((len = get_line(in, LIMIT)) > 0) {
        rem_blnk(in, LIMIT, out);
        reverse(out);
        printf("Resultado: %s\n", out);
    }
    
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
        if (*src != '\n')
            dst[i++] = *src;
    }
    dst[i] = '\0';
}

void reverse(char s[])
{
    int i, lim = strlen(s);
    int last_index = lim-1;

    for (i = 0; i < lim/2; i++) {
        char t = s[last_index - i];         
        s[last_index - i] = s[i];                
        s[i] = t;
    }
}