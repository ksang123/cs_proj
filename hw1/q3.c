#include <stdio.h>

int number_len(int number) {
    int len = 0;
    while(number != 0) {
        len++;
        number /= 10;
    }
    return len;
}

int pow_10(int n) {
    int num = 1;
    for (int i = n; i > 0; i--) {
        num *= 10;
    }
    return num;
}

int switch_digits(int number, int pos_a, int pos_b) {
    if (pos_a == pos_b) {
        return number;
    }
    int len = number_len(number), digit_a, digit_b;
    //the len of the number, the digit in pos_a, the digit in pos_b
    if (pos_a > len || pos_b > len) {
        printf("position outside number..\n");
        return 0;
    }
    digit_a = number % pow_10(pos_a) / pow_10(pos_a - 1);
    digit_b = number % pow_10(pos_b) / pow_10(pos_b - 1);
    number -= (digit_a * pow_10(pos_a-1) + digit_b * pow_10(pos_b-1));
    number += digit_a * pow_10(pos_b-1) + digit_b * pow_10(pos_a-1);
    return number;
}

int main(void) {
    int number, pos_a, pos_b;
    printf("Please enter the number:\n");
    scanf("%d", &number);
    printf("Please enter the positions:\n");
    scanf("%d %d", &pos_a, &pos_b);
    number = switch_digits(number, pos_a, pos_b);
    printf("The new number is: %d\n", number);
    return 0;
}
