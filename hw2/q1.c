#include <stdio.h>
#include <stdbool.h>
#define PRIMES {2, 3, 5, 7}
#define PRIMES_LEN 4

bool is_strong(unsigned int num);
unsigned int sum_digits(unsigned int num);

int main(void) {
    unsigned int num;
    printf("Please enter a number:\n");
    scanf("%u", &num);//get the number from the user
    if (is_strong(num)) {//check if the number is strong
        printf("The number %u is a strong prime number!\n", num);
    } else {
        printf("The number %u is not a strong prime number\n", num);
    }
}

bool is_strong(unsigned int num) {
    //the function returns true if the number is strong and false if it isn't
    int primes[] = PRIMES;//all the prime numbers between 0-9
    while (num > 9) {//recursively sum the digits until num has a single digit
        num = sum_digits(num);
    }
    for (int i = 0; i < PRIMES_LEN; i++) {
        //check if the recursive digit sum is equal to any of the prime
        if (primes[i] == num) {
            return true;
        }
    }
    //the recursive digit sum is not a prime number
    return false;
}

unsigned int sum_digits(unsigned int num) {
    //sum the digits of the number
    unsigned int sum = 0;//the sum of the digits
    while (num != 0) {//loop through every digit of the number
        sum += num % 10;//add the digit to the sum
        num /= 10;//remove the digit from the number
    }
    return sum;
}
