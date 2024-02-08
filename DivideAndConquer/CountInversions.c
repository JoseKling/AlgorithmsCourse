/*
Third programming assigment

This program counts the number of inversions in an array of integers.
The implementation uses merge sort, and the inversions are counted
during the merge step.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int merge_count(int left[], int left_copy[], int len_l, int right[], int right_copy[], int len_r) {
    int inversions = 0;
    int idx_l = 0, idx_r = 0, idx_sorted = 0;
    int sorted[len_l + len_r];
    while ((idx_l < len_l) && (idx_r < len_r)) {
        if (left_copy[idx_l] <= right_copy[idx_r]) {
            left[idx_sorted] = left_copy[idx_l];
            idx_l++;
            idx_sorted++;
        } else {
            left[idx_sorted] = right_copy[idx_r];
            idx_r++;
            idx_sorted++;
            inversions = inversions + (len_l + idx_r - idx_sorted);
        }
    }
    if (idx_l == len_l) {
        while (idx_r < len_r) {
            left[idx_sorted] = right_copy[idx_r];
            idx_r++;
            idx_sorted++;
            inversions = inversions + (len_l + idx_r - idx_sorted);
        } 
    } else {
        while (idx_l < len_l) {
            left[idx_sorted] = left_copy[idx_l];
            idx_l++;
            idx_sorted++;
        }
    }
    for (idx_sorted = 0; idx_sorted < len_l + len_r; idx_sorted++) {
        left_copy[idx_sorted] = left[idx_sorted];
    }
    return inversions;
}

int count_inversions_copy(int array[], int copy[], int length, int inversions) {
    if (length == 1) {
        return 0;
    } else {
        int* left = array;
        int* left_copy = copy;
        int len_l = length / 2;
        int* right = array + (length / 2);
        int* right_copy = copy + (length / 2);
        int len_r  = length - (length / 2);
        inversions = inversions + count_inversions_copy(left, left_copy, len_l, inversions);
        inversions = inversions + count_inversions_copy(right, right_copy, len_r, inversions);
        return inversions + merge_count(left, left_copy, len_l, right, right_copy, len_r);
    }
}

int count_inversions(int array[], int length) {
    int i;
    int copy[length];
    for (i = 0; i < length; i++) {
        copy[i] = array[i];
    }
    return count_inversions_copy(array, copy, length, 0);
}

int main() {
    int length;
    int range;
    int inversions;
    srand(time(NULL));
    printf("Type the length of the array to be sorted.\n");
    scanf("%d", &length);
    printf("Array will contain integers from 0 to M. Choose M.\n");
    scanf("%d", &range);
    int array[length];
    int i;
    for (i = 0; i < length; i++) {
        array[i] = rand() % (range + 1);
    }
    printf("Original array: [%d", array[0]);
    for (i = 1; i < length; i++) {
        printf(" %d", array[i]);
    }
    printf("].\n");
    inversions = count_inversions(array, length);
    printf("Number of inversions: %d\n", inversions);
    return 0;
}
