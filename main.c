#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ABC_SIZE 'z' - 'a' + 1
#define WORD_MAX_LEN 12
#define SONG_MAX_SIZE 50

/* Function Declarations */
void printSong(char *songLyrics[], int songSize);
int readSongLyrics(char *songLyrics[], int songMaxSize, int wordMaxLen);
void releaseMemory(char *songLyrics[], int songSize);
int* findSwiftyWordIndexes(char *songLyrics[], int songSize, int k);
void encryptSwiftyWord(char *songLyrics[], int wordIdxs[], int k,
unsigned char taylorCipherKey[ABC_SIZE]);
int find_word_k(char *songLyrics[], int songSize, int k);


// DO NOT TOUCH
void printSong(char *songLyrics[], int songSize) {
    for (int i = 0; i < songSize; i++) {
        if (songLyrics[i] != NULL) {
            printf("%s", songLyrics[i]);
        }
    }
    printf("\n");
}

// DO NOT TOUCH
int main(void)
{
    unsigned char taylorCipherKey[ABC_SIZE] = {
            '@', '4', '(', '8', '3', '/', '6', 'H', '!', '}', '&', '1', '+',
            '^', '0', '5', '9', 'R', '$', '#', '<', '>', 'w', '*', '~', 'z'
    };

    char *songLyrics[SONG_MAX_SIZE] = { NULL };

    // Get k input
    int k;
    printf("Enter k:\n");
    scanf("%d", &k);

    // Get song lyrics input
    printf("Enter your song lyrics:\n");
    int songSize = readSongLyrics(songLyrics, SONG_MAX_SIZE, WORD_MAX_LEN);

    // Find the word that appears k times in the song,
    // and encrypt it using the key
    int *wordIdxs = findSwiftyWordIndexes(songLyrics, songSize, k);
    encryptSwiftyWord(songLyrics, wordIdxs, k, taylorCipherKey);

    // Print the result
    printSong(songLyrics, songSize);

    // Release all dynamically allocated memory
    free(wordIdxs);
    releaseMemory(songLyrics, songSize);

    return 0;
}

/* Your Implementation: */
int readSongLyrics(char* songLyrics[], int songMaxSize, int wordMaxLen) {
    int word_counter = 0, len;
    char* word = (char *)malloc(wordMaxLen * sizeof(char));
    while (word_counter < songMaxSize && scanf("%s", word) != -1) // || add empty input)
    {
        len = (int)strlen(word);
        word[len] = ' ';
        word[len+1] = '\0';
        songLyrics[word_counter] = (char *)malloc((len+2) * sizeof(char));
        strcpy(songLyrics[word_counter], word);
        word_counter++;
    }
    free(word);
    return word_counter;
}

void releaseMemory(char *songLyrics[], int songSize) {
    for (int i = 0; i < songSize; i++) {
        free(songLyrics[i]);
    }
}

int* findSwiftyWordIndexes(char *songLyrics[], int songSize, int k) {
    int *wordIdxs = (int *) malloc(sizeof(int) * k),
    idx = find_word_k(songLyrics, songSize, k), counter = 0;
    for (int i = 0; i< songSize; i++) {
        if (strcmp(songLyrics[i], songLyrics[idx]) == 0) {
            wordIdxs[counter] = i;
            counter++;
        }
    }
    return wordIdxs;
}

int find_word_k(char *songLyrics[], int songSize, int k) {
    int counter;
    for (int i = 0; i < songSize; i++) {
        counter = 0;
        for (int j = 0; j < songSize; j++) {
            if (strcmp(songLyrics[i], songLyrics[j]) == 0) {
                counter++;
            }
        }
        if (counter == k) {
            return i;
        }
    }
    printf("whoopsy poopsy word not found\n");
    return -1;
}

void encryptSwiftyWord(char *songLyrics[], int wordIdxs[], int k,
                       unsigned char taylorCipherKey[ABC_SIZE]) {
    for (int i = 0; i < k; i++) {
        int len = (int)strlen(songLyrics[wordIdxs[i]]);
        for (int j = 0; j < len; j++) {
            songLyrics[wordIdxs[i]][j] = (char)taylorCipherKey[
                    songLyrics[wordIdxs[i]][j] - 'a' + 1];
        }
    }
}
