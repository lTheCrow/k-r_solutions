/**
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't
 * nest.
 */
#include <stdio.h>
#include <string.h>

#define SOURCE_SIZE     4096
#define START_COMM      "/*"
#define END_COMM        "*/"

void remove_comments(void);
int get_source_code(void);

char code[SOURCE_SIZE];
char rem_comment[SOURCE_SIZE];
int size = -1;

int main(void)
{
        size = get_source_code();
        remove_comments();
        printf("%s", rem_comment);
        return 0;
}

void remove_comments(void) {
        int i, j, comment_flag;
        for (i = 0, j = 0, comment_flag = 0; i < size; i++) {
                if (code[i+1] == '/' && code[i+2] == '*')
                        comment_flag = 1;
                        
                if (code[i-1] == '/' && code[i-2] == '*')
                        comment_flag = 0;

                if (comment_flag == 0)
                        putchar(code[i]);
                        
        }
}



int get_source_code(void)
{
        int i = 0, c;
        while ((code[i] = (c = getchar())) != EOF && i++ < SOURCE_SIZE);

        return i;
}