#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int* i;
    while(1) { i = (int *) malloc(100);}
    printf("%d", *i);
    return 0;
}
