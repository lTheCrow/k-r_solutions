/**
 * Modify the temperature conversion program to print a heading above the table.
 */
#include <stdio.h>

int main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;          /* lower limit of temperatuire scale */ 
    upper = 300;        /* upper limit */ 
    step = 20;           /* step size */

    printf("\n");
    printf("------------------------------------\n");
    printf("|    Celsius    |    Fahrenheit    |\n");
    printf("------------------------------------\n");
    fahr = lower;
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("|\t%3.0f\t| \t%6.1f\t   |\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("------------------------------------\n");

    return 0;
}