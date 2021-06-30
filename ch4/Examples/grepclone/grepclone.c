#include <stdio.h>

#include "grepclone.h"

#define MAXLINE		1000	/* maximum input line length */

char pattern[] = "ould"; /* pattern to search for */

int main(void) {
	char line[MAXLINE];
	int size = 0;
	int found = 0;

	while (get_line(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s\n", line);
			found++;
		}
	}

	return found;
}