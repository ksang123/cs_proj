#include <stdio.h>
#include "leetcode.h"

int main(void) {
    char* str = "abc abc bc";
    printf("\"%s\": %d",str, lengthOfLongestSubstring(str));
    return 0;
}
