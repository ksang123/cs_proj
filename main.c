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
//void releaseMemory(char *songLyrics[], int songSize);
//int* findSwiftyWordIndexes(char *songLyrics[], int songSize, int k);
//void encryptSwiftyWord(char *songLyrics[], int wordIdxs[], int k,
//unsigned char taylorCipherKey[ABC_SIZE]);


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
//    unsigned char taylorCipherKey[ABC_SIZE] = {
//            '@', '4', '(', '8', '3', '/', '6', 'H', '!', '}', '&', '1', '+',
//            '^', '0', '5', '9', 'R', '$', '#', '<', '>', 'w', '*', '~', 'z'
//    };

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
//    int *wordIdxs = findSwiftyWordIndexes(songLyrics, songSize, k);
//    encryptSwiftyWord(songLyrics, wordIdxs, k, taylorCipherKey);

    // Print the result
    printSong(songLyrics, songSize);

    // Release all dynamically allocated memory
//    free(wordIdxs);
//    releaseMemory(songLyrics, songSize);

    return 0;
}

/* Your Implementation: */
int readSongLyrics(char* songLyrics[], int songMaxSize, int wordMaxLen) {
    int word_counter = 0;
    char* word = (char *)malloc(wordMaxLen * sizeof(char));
    if (word == NULL) {
        printf("memory allocation failed");
    }
    while (word_counter < songMaxSize && scanf("%s", word) != -1) // || add empty input)
    {
        songLyrics[word_counter] = (char *)malloc(wordMaxLen * sizeof(char));
        strcpy(songLyrics[word_counter], word);
        word_counter++;
    }
    free(word);
    return word_counter;
}
