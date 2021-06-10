/**
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */
#include <stdio.h>

int main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;              /* lower limit of temperatuire scale */ 
    upper = 300;            /* upper limit */ 
    step = 20;              /* step size */

    printf("\n");
    printf("------------------------------------\n");
    printf("|    Fahrenheit    |    Celsius    |\n");
    printf("------------------------------------\n");
    celsius = lower;
    while(celsius <= upper){
        fahr = (celsius * (9/5)) + 32;
        printf("|\t%3.0f\t   | \t%6.1f     |\n", fahr, celsius);
        celsius = celsius + step;
    }
    printf("------------------------------------\n");

    return 0;
}