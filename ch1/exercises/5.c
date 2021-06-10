/**
 * Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0.
 */
#include <stdio.h>

int main(){
    float fahr = 0.0;
    float lower = 300.0, upper = 0.0, step = 20.0;

    printf("\n");
    printf("------------------------------------\n");
    printf("|    Celsius    |    Fahrenheit    |\n");
    printf("------------------------------------\n");

    for (fahr = lower; fahr >= upper; fahr -= step)
        printf("|\t%3.0f\t| \t%6.1f\t   |\n", fahr, (5.0/9.0) * (fahr-32.0));

    printf("------------------------------------\n");

    return 0;
}