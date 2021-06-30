/**
 * Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */
#include <stdio.h>
#include "strrindex.h"

#define MAX_TEXT	4096

char pattern[MAX_TEXT] = "good spot";

/* main: a testing function for strrindex */
int main(void)
{        
	char text[MAX_TEXT] = "As they rounded a bend in the path that ran" 
                              "beside the river, Lara recognized the silhouette" 
                              "of a fig tree atop a nearby hill. The weather" 
                              "was hot and the days were long. The fig tree was" 
                              "in full leaf, but not yet bearing fruit.\n"
                              "Soon Lara spotted other landmarks—an outcropping" 
                              "of limestone beside the path that had a" 
                              "silhouette like a man’s face, a marshy spot" 
                              "beside the river where the waterfowl were easily" 
                              "startled, a tall tree that looked like a man" 
                              "with his arms upraised. They were drawing near" 
                              "to the place where there was an island in the" 
                              "river. The island was a good spot to make camp." 
                              "They would sleep on the island tonight.";
	int index;
	index = strrindex(text, pattern);

	if (index != -1) {
		printf("Pattern occurs with shift %d\n", index);
	} else {
		printf("\aNo match.\n");
	}

	return 0;
}
