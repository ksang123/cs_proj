#include <stdio.h>

int is_in(char* str, int size, char item) {
    for (int i = 0; i < size; i++) {
        if (item == *str) {
            return 1; //true
        }
        str++;
    }
    return 0; //false
}

int substring_len(char* s) {
    char *p = s;
    s++;
    int len = 1, size = 1;
    while (*s != '\0' && !is_in(p, size, *s)) {
        s++;
        len++;
        size++;
    }
    return len;
}

int lengthOfLongestSubstring(char* s) {
    if (s == NULL || *s == '\0') {
        return 0;
    }
    int max = substring_len(s), curr;
    s++;
    while (*s != '\0') {
        curr = substring_len(s);
        if (curr > max) {
            max = curr;
        }
        s++;
    }
    return max;
}
