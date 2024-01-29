#include <stdio.h>
#include <stdbool.h>

#define WINDOW_SIZE 5

void shift_window(int* window, int new) {
    //the shifts the window to the next int and removes the last 1
    for(int i = 0; i < WINDOW_SIZE - 1; i++) {
        //iterate over every value in the window
        window[i] = window[i+1]; //move it to the spot before it
    }
    window[WINDOW_SIZE-1] = new; // insert the new value
}

double k_window_avg(const int* window, int k) {
    //calculates the average of the last k items in the window
    double sum = 0; //the sum of the items
    for (int i = WINDOW_SIZE - 1; i > WINDOW_SIZE - 1 - k; i--) {
        // iterate over the k last items in the window
        sum += (double)window[i]; //sum the k last items in the window
    }
    return sum / k; //calculate the average
}

void print_num(int* window, int current, int index) {
    if (current % 5 == 0) { //check if the current number is divisible by 5
        if (index >= 5) { //check if there are enough items in the window
            printf("%.2lf", k_window_avg(window, 5));
            //calculate the average of the last 5 items in the window
        } else {
            printf("%.2lf", (double)current);//print the current number
        }
    } else {
        if (index >= 3) { //chcek if there are enough items in the window
            printf("%.2lf", k_window_avg(window, 3));
            //calculate the average of the last 3 items in the window
        } else {
            printf("%.2lf", (double)current);//print the current number
        }
    }
}


int main(void) {
    int window[WINDOW_SIZE] = {0}, index = 1, current, result;
    /*creating the window, index (amount of numbers inserted),
     * the current number and the scanf result*/
    bool first = true;
    //a boolean to tell us if the number we are printing is the first one
    printf("Please Enter Input Signal:\n");
    printf("The Clean Signal Is: ");
    result = scanf("%d", &current); //scan the current number
    while(result == 1) {
        if (first) {//check if it's the first number
            first = false;
        } else {
            printf(", "); //if the number isn't the first, print a comma
        }
        shift_window(window, current);
        //shift the window and insert the new number
        print_num(window, current, index); //print the number or the average
        result = scanf("%d", &current);//scan the new number
        index++;//increment the index
    }
    return 0;
}
