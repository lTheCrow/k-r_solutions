/**
 * Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */
#include <stdio.h>
#include "strrindex.h"

#define MAX_TEXT	4096

char pattern[MAX_TEXT] = "orl";

/* main: a testing function for strrindex */
int main(void)
{        
	char text[MAX_TEXT] = "Hello world";
	int index;
	index = kmp_matcher(text, pattern);

	if (index != -1) {
		printf("Pattern occurs with shift %d\n", index);
	} else {
		printf("\aNo match.\n");
	}

	return 0;
}