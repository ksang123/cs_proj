#include <stdio.h>
#include <stdbool.h>

int check_string(char cool_letter) {
    int score = 0; //the score of the string
    char current = (char)getchar(); //the current character in the string
    while(current != '\n' && current != -1) { //loop until we get an EOF or \n
        if (current == cool_letter || current == cool_letter - 'a' + 'A'
            || current == cool_letter - 'A' + 'a') {
            //check if the current character is a cool letter
            score++; //increase the score
        }
        if (!(current == ' ' || (current >= 'a' && current <= 'z')
              || (current >= 'A' && current <= 'Z'))) {
            //check if the character is not a letter or space
            return -1; //invalid string, return -1.
        }
        current = (char)getchar(); //get to the next char
    }
    return score;
}

int main(void) {
    int score; //the score
    char cool_letter; //the cool letter
    printf("Please Enter Cool Letter:\n");
    cool_letter = (char)getchar();//get the cool letter
    printf("Please Enter Text:\n");
    score = check_string(cool_letter);//get the score from the string
    printf("The score is: %d\n", score);
    return 0;
}
