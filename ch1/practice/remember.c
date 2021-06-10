#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int bin2dec(int bin)
{
    int rem, decimal = 0;

    int i;
    for (i = 0; bin != 0; i++) {
        rem = bin % 10;
        bin = bin / 10;
        decimal = decimal + (rem) * (pow(2, i));
    }

    return decimal;
}

long long dec2bin(int n) {
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}


int main(void)
{

    int numbers[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int binary_number, actual_number;

    while (true) {
        srand(time(NULL));
        actual_number = numbers[rand() % ((16) - 0) + 0];
        printf("[+] Enter the binary number of %d (type -1 to exit): ", actual_number);
        scanf("%d", &binary_number);
        if (binary_number == -1) 
            exit(0);

        if (bin2dec(binary_number) == actual_number)
            printf("Right Answer !!\n");
        else
            printf("Wrong Answer.\n\t=> %02d = %04d\n", actual_number, dec2bin(actual_number));
    }

    return 0;
}