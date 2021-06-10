/**
 * Experiment to find out what happens when prints's argument string contains \c, where c is some character not listed above.
 */
#include <stdio.h>

int main(){
    /**
     *  warning: unknown escape sequence: '\c'
     *  output: hello, cworld!
     */
    printf("hello, \cworld!\n");
    return 0;
}