#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int *compute_prefix(const char p[]) {
	int m = strlen(p);                              /* pattern length */
	int *lps = (int *) malloc(m * sizeof(int));     /* allocate memory */
	lps[0] = 0;                                     /* lps[0] is always 0 */
	int len = 0;

	int i = 1;
        /* iterate over p */
	while (i < m) {
                if (p[i] == p[len]) {
                        lps[i++] = ++len;
                } else {
                        if (len != 0) {
                                len = lps[len - 1];
                        } else {
                                lps[i++] = 0;
                        }
                }
        }
	return lps;
}


/* strrindex: find the rightmost occurrence, return the 
              index or -1 if didn't find */
int strrindex(const char t[], const char p[]) {
	int n = strlen(t);
	int m = strlen(p);

	int *lps = compute_prefix(p);

        int index = -1;
	
        int i = 0, j = 0;
        while (i < n) {
                if (p[j] == t[i]) {
                        i++;
                        j++;
                }
                if (j == m) {
                        index = i - j;
                        j = lps[j - 1];
                } else if (i < n && p[j] != t[i]) {
                        if (j != 0)
                                j = lps[j - 1];
                        else
                                i++;
                }
        }

	return index;
}
