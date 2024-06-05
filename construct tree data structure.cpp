#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *newNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode *root, char *key) {
    struct TrieNode *current = root;
    int len = strlen(key);
    for (int level = 0; level < len; level++) {
        int index = key[level] - 'a';
        if (!current->children[index]) {
            current->children[index] = newNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void displayTrie(struct TrieNode *root, char str[], int level) {
    if (root->isEndOfWord) {
        str[level] = '\0';
        printf("%s\n", str);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            str[level] = i + 'a';
            displayTrie(root->children[i], str, level + 1);
        }
    }
}

int main() {
    struct TrieNode *root = newNode();
    char keys[][8] = {"hello", "world", "hi", "apple", "bye"};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }
    char output[50];
    displayTrie(root, output, 0);
    return 0;
}

