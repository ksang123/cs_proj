#define CHARACTERS 'z'-'a'+1

int longest_sequence(int a[], int n, int k) {
    //moving window
    return 0;
}

int shotest_substring(char *str) {
    int hist[CHARACTERS] = {0};
    char *p1 = str;
    while (*p1 != '\0') {
        hist[*p1-'a']++;
        p1++;
    }
    int counter = 0;
    for(int i = 0; i < CHARACTERS; i++) {
        if (hist[i] != 0) {
            counter++;
        }
    }
    return counter;
}
