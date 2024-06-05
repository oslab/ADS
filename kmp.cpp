#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pattern, int M, int lps[]) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0;
    int j = 0;

    while (i < N) {
        if (pattern[j] == text[i])
            j++;
        i++;
    }

    if (j == M) {
        printf("Pattern found at index %d\n", i - j);
        j = lps[j - 1];
    } else if (i < N && pattern[j] != text[i]) {
        if (j != 0)
            j = lps[j - 1];
        else
            i = i + 1;
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMPSearch(pattern, text);

    return 0;
}

