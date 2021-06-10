/**
 * Verify that the expression getchar() != EOF
 * is 0 or 1
 */
#include <stdio.h>

int main(void)
{
    if ((getchar() != EOF) == 1)
        printf("getchar is not equal EOF");
    else if((getchar() != EOF) == 0)
        printf("getchar is equal EOF"); 

    return 0;
}