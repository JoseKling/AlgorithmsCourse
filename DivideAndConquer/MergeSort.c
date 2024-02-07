/*
Second programming assigment

This is an impleentation of merge sort. It asks the user for
the length of the array to be sorted and the range of values
allowed in the array. The script prints the original array,
sorts it and prints it after sorting.
Instead of creating new arrays every time 'merge_sort' is recursively
called, the operations are done in place by manipulationg pointers. Also,
in the 'merge' function, instead of creating copies of the left and right
sides of the array, only one copy of the original array is created in the
beginning of the algorithm, and the 'left_copy' and 'right_copy' arrays
in 'merge' are just pointers to this first copy.
In this way, there is no need to create copies of the 'left' and 'right'
arrays in 'merge', we just use the original copy and keep it updated.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int left[], int left_copy[], int len_l, int right[], int right_copy[], int len_r) {
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
        }
    }
    if (idx_l == len_l) {
        while (idx_r < len_r) {
            left[idx_sorted] = right_copy[idx_r];
            idx_r++;
            idx_sorted++;
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
    return;
}

void merge_sort_copy(int array[], int copy[], int length) {
    if (length == 1) {
        return;
    } else {
        int* left = array;
        int* left_copy = copy;
        int len_l = length / 2;
        int* right = array + (length / 2);
        int* right_copy = copy + (length / 2);
        int len_r  = length - (length / 2);
        merge_sort_copy(left, left_copy, len_l);
        merge_sort_copy(right, right_copy, len_r);
        merge(left, left_copy, len_l, right, right_copy, len_r);
        return;
    }
}

void merge_sort(int array[], int length) {
    int i;
    int copy[length];
    for (i = 0; i < length; i++) {
        copy[i] = array[i];
    }
    merge_sort_copy(array, copy, length);
    return;
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