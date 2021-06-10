#include <stdio.h>

int main(void)
{

    int i;
    for (i = 0; i <= 255; i++)
        printf("| %6d | %6d |\n", i, i*i);

    return 0;
}