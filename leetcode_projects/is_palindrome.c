#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    long x1 = (long)x;
    long opp = 0;
    while (x1 != 0) {
        opp *= 10;
        opp += x1 % 10;
        x1 /= 10;
    }
    return x == opp;
}

int main(void) {
    printf("%s", isPalindrome(1212121) ? "true" : "false");
    return 0;
}
