#include <stdio.h>

int number_len(int number) {
    //this function gets a number and returns the amount of digits it has
    int len = 0;//a counter for the digits
    while(number != 0) {//go through every digit
        len++;//count the digit
        number /= 10;//remove the digit from the number
    }
    return len;
}

long pow_10(int n) {
    //this function calculates 10^n
    long num = 1;//the result
    for (int i = n; i > 0; i--) {//multiply the number by 10 for every n
        num *= 10;
    }
    return num;
}

long switch_digits(long number, int pos_a, int pos_b) {
    //this function gets a number and 2 positions and switches the digits
    if (pos_a == pos_b) {
        //if the positions are the same the number doesn't change
        return number;
    }
    int digit_a, digit_b;
    //the len of the number, the digit in pos_a, the digit in pos_b
    digit_a = number % pow_10(pos_a) / pow_10(pos_a - 1);
    //get the digit in position a
    digit_b = number % pow_10(pos_b) / pow_10(pos_b - 1);
    //get the digit in position b
    number -= (digit_a * pow_10(pos_a-1) + digit_b * pow_10(pos_b-1));
    //remove the digits from their position
    number += digit_a * pow_10(pos_b-1) + digit_b * pow_10(pos_a-1);
    //add the digits in their new positions
    return number;
}

int main(void) {
    int number, pos_a, pos_b;
    printf("Please enter the number:\n");
    scanf("%d", &number);
    //get the number
    printf("Please enter the positions:\n");
    scanf("%d %d", &pos_a, &pos_b);
    //get the positions
    number = switch_digits((long)number, pos_a, pos_b);
    printf("The new number is: %d\n", number);
    return 0;
}
