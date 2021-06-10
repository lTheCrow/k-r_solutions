#include <stdio.h>

/* power: raise base to n-th power; n >= 0; version 2 */
void power(int *result, int base, int n)
{
    int p = 1;

    while (n-- > 0)
        p = p * base;

    *result = p;
}

int main(void)
{
    int result;
    power(&result, 5, 2);
    printf("3^2 = %d\n", result);
    return 0;
}