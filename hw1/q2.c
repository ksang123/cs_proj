#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int index = 1, current, result;
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
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
        //shift the window and insert the new number
        num1 = num2;
        num2 = num3;
        num3 = num4;
        num4 = num5;
        num5 = current;
        if (current % 5 == 0) { //check if the current number is divisible by 5
            if (index >= 5) { //check if there are enough items in the window
                printf("%.2lf",
                       (double)(num1 + num2 + num3 + num4 + num5)/5);
                //calculate the average of the last 5 items in the window
            } else {
                printf("%.2lf", (double)current);
                //print the current number
            }
        } else {
            if (index >= 3) { //chcek if there are enough items in the window
                printf("%.2lf", (double)(num3 + num4 + num5)/3);
                //calculate the average of the last 3 items in the window
            } else {
                printf("%.2lf", (double)current);
                //print the current number
            }
        }
        result = scanf("%d", &current);//scan the new number
        index++;//increment the index
    }
    return 0;
}
