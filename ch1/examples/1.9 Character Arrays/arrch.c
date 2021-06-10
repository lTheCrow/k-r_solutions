#include <stdio.h>
#include <string.h>

#define LIMIT 256  

int get_line(char string[], int limit);
int copy(char source[], size_t src_lim, char destination[], size_t dest_lim);

int main(void)
{
    char max[LIMIT], string[LIMIT];
    int len, max_len = 0;
 
    while ((len = get_line(string, LIMIT)) > 0)             /* there's another line */
        if (len > max_len)                                  /* it's longer than the previous longest */
            max_len = copy(string, LIMIT, max, LIMIT);                        

    if (max_len)
        printf("Longest Line (%d): %s\n", max_len, max);
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

int copy(char src[], size_t src_lim, char dest[], size_t dest_lim)
{
    size_t lim = (src_lim < dest_lim) ? src_lim : dest_lim;

    int i;
    for (i = 0; src[i] != '\n' && i < lim-1; i++)               /* while i < lim-1 and src[i] is not EOF */
        dest[i] = src[i];                                       /* copy src and dest */
    
    dest[i] = '\0';
    return i;                                                   /* return copied char */
}