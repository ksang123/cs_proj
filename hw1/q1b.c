#include <stdio.h>
#include <stdbool.h>

int get_score(char current, char character, bool* has_shown) {
    if (current == character || current == character - 'a' + 'A'
        || current == character - 'A' + 'a') {
        //check if the current character is a cool letter
        if(*has_shown) { //check if the character has been before
            return 2; // add 2 points
        }
        *has_shown = true; // update that the character has shown
        return 1; // add 1 point
    }
    return 0; // the character isn't cool, add 0 points
}


int check_string(char cool_letter1, char cool_letter2, char cool_letter3) {
    int score = 0;//the score of the string
    char current = (char)getchar(); //the current character in the string
    bool letter1 = false, letter2 = false, letter3 = false;
    while(current != -1) { //loop until we get an EOF or \n
        score += get_score(current, cool_letter1, &letter1);
        //add score for 1st cool letter
        score += get_score(current, cool_letter2, &letter2);
        //add score for 2nd cool letter
        score += get_score(current, cool_letter3, &letter3);
        //add score for 3rd cool letter
        if (!(current == ' ' || (current >= 'a' && current <= 'z')
              || (current >= 'A' && current <= 'Z'))) {
            //check if the character is not a letter or space
            return -1; //invalid string, return -1.
        }
        current = (char)getchar(); //get to the next character
    }
    return score;
}

int main(void) {
    int score; //the score
    char cool_letter1, cool_letter2, cool_letter3; //the cool letters
    printf("Please Enter Cool Letters:\n");
    scanf("%c %c %c", &cool_letter1, &cool_letter2, &cool_letter3);
    //input the cool letters
    printf("Please Enter Text:\n");
    score = check_string(cool_letter1, cool_letter2, cool_letter3);
    //get the score from the string
    printf("The score is: %d\n", score);
    return 0;
}
