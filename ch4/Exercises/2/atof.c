#include <ctype.h>
#include "conv.h"
#include <stdio.h>

/* atof: converts the string s to its double-precision 
         floating-point equivalent */
double _atof(char s[]) {
        double val, power;
        int i, sign;

        for (i = 0; isspace(s[i]); i++)
                ;

        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;
        
        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');
        
        if (s[i] == '.')
                i++;

        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10;
        }

        if (s[i] == tolower('e'))
                i++;
        else 
                return sign * val / power;
        
        int exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;

        int exp_val;
        for (exp_val = 0.0; isdigit(s[i]); i++) 
                exp_val = 10.0 * exp_val + (s[i] - '0');

        double j, exp;
        for (j = 0, exp = 1.0; j < exp_val; j++)
                exp = exp * 10.0;

        if (exp_sign == 1)
                return (sign * val / power) * exp;
        else if (exp_sign == -1)
                return (sign * val / power) / exp;

        return -1.0;
}