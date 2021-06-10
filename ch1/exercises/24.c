/**
 * Write a program to check a C program for rudimentary syntax erros like 
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality). 
 */
#include <stdio.h>

#define MAX_SIZE        4096
#define TRUE               1
#define FALSE              0

#define SYNT_PARENT     -1
#define SYNT_BRACKT     -2
#define SYNT_BRACES     -3
#define SYNT_SINGLQ     -4
#define SYNT_DOUBLQ     -5
#define SYNT_ESCCHK     -6
#define SYNT_COMMNT     -7

int get_source_code(void);
int check_seq(char c);
void syntax_flags(char c);
int check_syntax(void);

char code[MAX_SIZE];

int parentheses         = 0;
int brackets            = 0;
int braces              = 0;
int single_quotes       = 0;
int double_quotes       = 0;

int esc_seq             = 0;
int comments            = 0; 

int main(void)
{
        int i = get_source_code();
        if (i > 0) 
                printf("Source (%d):\n\n%s", i, code);
}

int get_source_code(void)
{
        int syntax_code;
        int i = 0, c;
        while ((c = getchar()) != EOF && i < MAX_SIZE) {
                code[i] = c;
                syntax_flags(c);
                i++;
        }

        int j = 0;
        while (j <= i) {
                if (code[j] == '/' && code[j+1] == '*')
                        comments++;

                if (code[j] == '*' && code[j+1] == '/')
                        comments--;

                if (code[j] == '\\' && !check_seq(code[j+1]))
                        esc_seq++;
                j++;
        }
                
        if ((syntax_code = check_syntax()) == TRUE) {
                printf("All fine!\n");
                return i;
        } else {
                switch (syntax_code)
                {
                case SYNT_PARENT:
                        printf("Error de parentesis\n");
                        return SYNT_PARENT;

                case SYNT_BRACKT:
                        printf("Error de brackets\n");
                        return SYNT_BRACKT;
                
                case SYNT_BRACES:
                        printf("Error de llaves\n");
                        return SYNT_BRACES;
                
                case SYNT_SINGLQ:
                        printf("Error de comillas simples\n");
                        return SYNT_SINGLQ;
                
                case SYNT_DOUBLQ:
                        printf("Error de comillas dobles\n");
                        return SYNT_DOUBLQ;

                case SYNT_ESCCHK:
                        printf("Error de secuencia de escape\n");
                        return SYNT_ESCCHK;
                
                case SYNT_COMMNT:
                        printf("Error de comentario\n");
                        return SYNT_COMMNT;
                }
        }
}

int check_seq(char c)
{
        switch (c)
        {
        case 'a':
        case 'b':
        case 'e':
        case 'f':
        case 'n':
        case 'r':
        case 't':
        case 'v':
        case '\\':
        case '\'':
        case '\"':
        case '?':
               return TRUE;
        default:
                return FALSE;
        }
}

void syntax_flags(char c)
{
        switch (c)
        {
                /* OPEN */
                case '(':
                        parentheses++;
                        break;
                case '[':
                        brackets++;
                        break;
                case '{':
                        braces++;
                        break;
                case '\'':
                        if (single_quotes > 0)
                                single_quotes--;
                        else
                                single_quotes++;
                        break;
                case '\"':
                        if (double_quotes > 0)
                                double_quotes--;
                        else
                                double_quotes++;
                        break;

                /* CLOSE */
                case ')':
                        parentheses--;
                        break;
                case ']':
                        brackets--;
                        break;
                case '}':
                        braces--;
                        break;
                
        }
}



int check_syntax(void)
{
        int code = 0;

        if (parentheses != 0)
                return SYNT_PARENT;

        if (brackets != 0)
                return SYNT_BRACKT;
        
        if (braces != 0)
                return SYNT_BRACES;
        
        if (single_quotes != 0)
                return SYNT_SINGLQ;

        if (double_quotes != 0)
                return SYNT_DOUBLQ;

        if (esc_seq != 0)
                return SYNT_ESCCHK;

        if (comments != 0)
                return SYNT_COMMNT;

        return TRUE;
}