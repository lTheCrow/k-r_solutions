#include <stdio.h>
#include <string.h>

/*
#include <stdlib.h>

int *compute_prefix(char p[]) {
	int m = strlen(p);
	int *pi = (int *) malloc(m * sizeof(int));
	pi[0] = 0;
	int k = 0;

	int q;
	for (q = 1; q < m; q++) {
		while (k > 0 && p[k + 1] != p[q]) {
			k = pi[k];
		}

		if (p[k + 1] == p[q]) {
			k++;
		}

		pi[q] = k;
	}
	return pi;
}

int kmp_matcher(char t[], char p[]) {
	int n = strlen(t);
	int m = strlen(p);
	int *pi = compute_prefix(p);
	int q = 0;
	int index = -1;

	int i;
	for (i = 0; i < n; i++) {
		while (q > 0 && p[q + 1] != t[i]) {
			q = pi[q];
		}
		if (p[q + 1] == t[i]) {
			q++;
		}

		if (q == m) {
			printf("Pattern occurs with shift %d\n", i - m);
			index = i - m;
			q = pi[q];
		}
	}

	return index;
}*/


/* strrindex: find the rightmost occurrence, return the index or -1 if didn't find */
int strrindex(const char t[], const char p[]) {
	

	int n = strlen(t); /* strlen("Hello world") -> 11 */
	int m = strlen(p); /* strlen("or")  		-> 2 */
	int right = -1;

	int s;
	for (s = 0; s < n - m; s++) { 		/* while s < 9 */
		int j;
		for (j = 0; j < m; j++) { 		/* while j < 2 */
			if (t[s + j] != p[j]) {     /* if t[] */
				break;
			}
		}

		if (j == m)
			right = s;
	}

	return right;

}