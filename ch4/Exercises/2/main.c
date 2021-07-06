#include <stdio.h>
#include "conv.h"

int main(void) {
        double sum;
        char line[MAXLINE];

        sum = 0;
        if (_getline(line, MAXLINE) > 0)
                printf("Value: %.15f\n", _atof(line));

	return 0;
}
