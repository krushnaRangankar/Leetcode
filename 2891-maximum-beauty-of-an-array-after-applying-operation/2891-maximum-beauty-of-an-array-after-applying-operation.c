#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maximumBeauty(int* nums, int numsSize, int k) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxBeauty = 0;
    int left = 0; // Sliding window's left pointer
    
    // Sliding window to find maximum overlap
    for (int right = 0; right < numsSize; ++right) {
        // Maintain the window where all elements fit in the range
        while (nums[right] - nums[left] > 2 * k) {
            left++;
        }
        // Update the maximum beauty
        maxBeauty = (right - left + 1 > maxBeauty) ? (right - left + 1) : maxBeauty;
    }
    
    return maxBeauty;
}
