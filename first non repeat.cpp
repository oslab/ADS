#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

int firstUniqChar(char* s) {
    int freq[MAX_CHAR] = {0};

    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    char s1[] = "leetcode";
    printf("Example 1 Output: %d\n", firstUniqChar(s1));

    char s2[] = "loveleetcode";
    printf("Example 2 Output: %d\n", firstUniqChar(s2));

    char s3[] = "aabb";
    printf("Example 3 Output: %d\n", firstUniqChar(s3));

    return 0;
}

