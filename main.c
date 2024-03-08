#include <stdio.h>

//the function gets a non-negative number
//the function returns its finite digit sum
int midterm_q1(int num);

//the function gets a non-negative number and returns the sum of its digits
int sum_digits(int num);

//the function gets an array and the length of the array
//the function returns the 2nd smallest number in the array
double midterm_q2(double arr[], int n);

//the function gets an array, the length of the array and an index
//the function calculates the sliding sum of the array at the index
double midterm_q3(double arr[], int n, int idx);

/* the function gets an array, the length of the array,
 * the index of the sliding mean, the current index,
 * and the points that this index is worth.
 * the function returns how much should the sliding sum increase from
 * the specific index
 * */
double add_to_sum(double arr[], int n, int idx, int index, double points);

int main(void) {
    int num = 0;
    printf("%d\n", midterm_q1(num));
    double arr[] = {-5.5, 0.0, 6.0};
    printf("%f\n", midterm_q2(arr, 3));
    return 0;
}

int midterm_q1(int num) {
    if (num < 0) { //make sure that the number is non-negative
        printf("ERROR: negative number inserted");
        return -1;
    }
    int sum = sum_digits(num); //the sum of the digits
    while (sum >= 10) { //while the sum has 2 or more digits
        //calculate the sum of the new number
        sum = sum_digits(sum);
    }
    return sum;
}

int sum_digits(int num) {
    int sum = 0; //the sum of the digits
    while (num > 0) { //loop while the num still has digits left
        sum += num % 10; //add the last digit to the sum
        num /= 10; //remove the last digit
    }
    return sum;
}

double midterm_q2(double arr[], int n) {
    //set the smallest and 2nd smallest numbers in the array
    double smallest = arr[0], second_smallest = arr[0];
    //loop through the array and find the smallest number
    for (int i =1; i < n; i++) {
        if (smallest > arr[i]) {
            smallest = arr[i];
        }
    }
    //loop through the array and find the smallest number that is
    //different from the true smallest number
    //that would be the 2nd smallest number
    for (int i = 0; i < n; i++) {
        //if smallest equals to the 2nd smallest, switch the 2nd smallest
        if ((arr[i] != smallest && second_smallest > arr[i]) ||
            smallest == second_smallest) {
            second_smallest = arr[i];
        }
    }
    return second_smallest;
}

double midterm_q3(double arr[], int n, int idx) {
    double sum = 0; //the sliding sum
    //add the items in the sliding sum, with their specific worth
    sum += add_to_sum(arr, n, idx, -2, 0.1);
    sum += add_to_sum(arr, n, idx, -1, 0.2);
    sum += add_to_sum(arr, n, idx, 0, 0.4);
    sum += add_to_sum(arr, n, idx, 1, 0.2);
    sum += add_to_sum(arr, n, idx, 2, 0.1);
    return sum;
}

double add_to_sum(double arr[], int n, int idx, int index, double points) {
    //check that the index is in the array
    if (idx + index >= 0 && idx + index < n) {
        return arr[idx + index] * points; //return the value of the index
    }
    return 0.0; //the index was not in the array
}
