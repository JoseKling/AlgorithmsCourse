/*
Second programming assigment

This is an impleentation of merge sort. It asks the user for
the length of the array to be sorted and the range of values
allowed in the array. The script prints the original array,
sorts it and prints it after sorting.
The sorting occurs in place, but still in every iteration a
new array has to be created, therefore it needs O(n) memory.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int left[], int len_l, int right[], int len_r) {
    int idx_l = 0, idx_r = 0, idx_sorted = 0;
    int sorted[len_l + len_r];
    while ((idx_l < len_l) && (idx_r < len_r)) {
        if (left[idx_l] <= right[idx_r]) {
            sorted[idx_sorted] = left[idx_l];
            idx_l++;
            idx_sorted++;
        } else {
            sorted[idx_sorted] = right[idx_r];
            idx_r++;
            idx_sorted++;
        }
    }
    if (idx_l == len_l) {
        while (idx_r < len_r) {
            sorted[idx_sorted] = right[idx_r];
            idx_r++;
            idx_sorted++;
        } 
    } else {
        while (idx_l < len_l) {
            sorted[idx_sorted] = left[idx_l];
            idx_l++;
            idx_sorted++;
        }
    }
    for (idx_sorted = 0; idx_sorted < len_l + len_r; idx_sorted++) {
        left[idx_sorted] = sorted[idx_sorted];
    }
    return;
}

void merge_sort(int array[], int length) {
    if (length == 1) {
        return;
    } else {
        int* left = array;
        int len_l = length / 2;
        int* right = array + (length / 2);
        int len_r  = (length / 2) + (length % 2);
        merge_sort(left, len_l);
        merge_sort(right, len_r);
        merge(left, len_l, right, len_r);
        return;
    }
}

int main() {
    int length;
    int range;
    printf("Type the length of the array to be sorted.\n");
    scanf("%d", &length);
    printf("Array will contain integers from 0 to M. Choose M.\n");
    scanf("%d", &range);
    int array[length];
    int i;
    for (i = 0; i < length; i++) {
        array[i] = rand() % (range + 1);
    }
    printf("Original array: %d", array[0]);
    for (i = 1; i < length; i++) {
        printf(", %d", array[i]);
    }
    printf(".\n");
    merge_sort(array, length);
    printf("Sorted array: %d", array[0]);
    for (i = 1; i < length; i++) {
        printf(", %d", array[i]);
    }
    printf(".\n");
    return 0;
}