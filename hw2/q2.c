#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(long num);
int sum_digits(int num);

int isDoublePalindrome(int num) {
    // the function returns 2 if the number is a double palindrome,
    // 1 if the number is a palindrome,
    // and 0 if the number is not a palindrome
    if (is_palindrome((long)num)) {
        if (sum_digits(num) % 2 == 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

int main(void){
    int num;
    printf("Please enter a number:\n");
    if(scanf("%d", &num) != 1){
        return 0;
    }
    if(isDoublePalindrome(num) == 1){
        printf("The number %d is palindrome", num);
    } else if (isDoublePalindrome(num) == 2){
        printf("The number %d is double palindrome", num);
    } else{
        printf("The number is not palindrome");
    }
}

bool is_palindrome(long num) {
    //the function checks if a number is a palindrome
    if (num < 0) {//negative numbers are not palindromes
        return false;
    }
    long opp = 0, dup = num;//make an oppesite number, duplicate the number
    while (num != 0) {//for every digit of the number
        opp *= 10;//make place for the next digit
        opp += num % 10;//add the next digit
        num /= 10;//remove digit from number
    }
    return dup == opp;//check if the oppesite number is equal to the original
}

int sum_digits(int num) {
    //sum the digits of the number
    int sum = 0;//the sum of the digits
    while (num != 0) {//loop through every digit of the number
        sum += num % 10;//add the digit to the sum
        num /= 10;//remove the digit from the number
    }
    return sum;
}
