#include <stdio.h>
#include "conv.h"

int main(void) {
        double sum;
        char line[MAXLINE];

        sum = 0;
        while (_getline(line, MAXLINE) > 0)
                printf("\t%f\n", sum += _atof(line));

	return 0;
}
