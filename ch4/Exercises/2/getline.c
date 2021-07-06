#include <stdio.h>
#include "conv.h"

/* getline: get line into line, return length */
int _getline(char line[], int max) {
	int c, i;

	for (i = 0; i < max && (c = getchar()) != EOF; i++) {
		if (c != '\n') {
			line[i] = c;
		} else {
			line[i] = 0;
			break;
		}
	}

	return i;
}