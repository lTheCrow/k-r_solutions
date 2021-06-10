/** 
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion
 */
#include <stdio.h>

#define TABLE_LIMIT     300
#define TABLE_STEP       20

float fahr_to_celsius(float fahr);

/* testing fahr_to_celsius */
int main(void)
{
    float fahr, celsius;

    for (fahr = 0.0; fahr < TABLE_LIMIT; fahr += TABLE_STEP)    
        printf("%6.2f\t%6.2f\n", fahr, fahr_to_celsius(fahr));      /* very clean and readable */

    return 0;
}

/* Converts fahrenheit notation to celsius notation */
float fahr_to_celsius(float fahr)
{
    return  5 * (fahr-32) / 9;
}
