#include <stdio.h>
#include <stdlib.h>

struct NumFreq {
    int num;
    int freq;
};

int compare(const void *a, const void *b) {
    struct NumFreq *numFreqA = (struct NumFreq *)a;
    struct NumFreq *numFreqB = (struct NumFreq *)b;
    
    if (numFreqA->freq == numFreqB->freq) {
        return numFreqB->num - numFreqA->num;
    }
    
    return numFreqA->freq - numFreqB->freq;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int freqMap[201] = {0};
    
    for (int i = 0; i < numsSize; ++i) {
        ++freqMap[nums[i] + 100];
    }
    
    struct NumFreq numFreqs[numsSize];
    
    for (int i = 0; i < numsSize; ++i) {
        numFreqs[i].num = nums[i];
        numFreqs[i].freq = freqMap[nums[i] + 100];
    }
    
    qsort(numFreqs, numsSize, sizeof(struct NumFreq), compare);
    
    int *result = (int *)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; ++i) {
        result[i] = numFreqs[i].num;
    }
    
    *returnSize = numsSize;
    
    return result;
}

void printArray(int *arr, int size) {
    printf("[");
    
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    
    printf("]\n");
}

int main() {
    int nums1[] = {1, 1, 2, 2, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int *sortedNums1 = frequencySort(nums1, numsSize1, &returnSize1);
    printf("Example 1 Output: ");
    printArray(sortedNums1, returnSize1);
    free(sortedNums1);
    
    int nums2[] = {2, 3, 1, 3, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int *sortedNums2 = frequencySort(nums2, numsSize2, &returnSize2);
    printf("Example 2 Output: ");
    printArray(sortedNums2, returnSize2);
    free(sortedNums2);
    
    return 0;
}

