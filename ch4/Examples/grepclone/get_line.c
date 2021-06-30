#include <stdio.h> 

/* get_line: get line into line, return length */
int get_line(char line[], int max) {
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