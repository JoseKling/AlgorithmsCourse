/*
Fourth programming assigment

This is an implementation of quick sort which compares the
number of comparisons the algorithm does for three different
strategies to choose the pivot element.
1 - First element of the array.
2 - Last element of the array.
3 - The median of the first, last, and middle elements.
It generates a random integer array and sorts it using all
three stategies and finally prints how many comparisons were
needed in each of them.
This algorithm work in place.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Prints an array on the terminal. Uncomment below
// if want to see the unsorted and then sorted array.
void printarray(int* array, int length) {
    int i;
    printf("[%d", array[0]);
    for (i = 1; i < length; i++) {
        printf(", %d", array[i]);
    }
    printf("]\n");
}

void swap(int* array, int idx1, int idx2) {
    int temp;
    temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
    return;
}

int quick_sort(int* array, int length, int choice) {
    int n;
    if (length <= 1) { // Base case
        return 0;
    }
    if (choice == 2) { // Pivot is the last element
        swap(array, 0, length - 1);
    } else if (choice == 3) { // Pivot is the median of the first, last and middle elements
        if ((array[0] <= array[length / 2] && array[length / 2] <= array[length - 1]) || (array[length - 1] <= array[length / 2] && array[length / 2] <= array[0])) {
            swap(array, 0, length / 2); // Median is the middle element
        } else if ((array[length / 2] <= array[0] && array[0] <= array[length - 1]) || (array[length - 1] <= array[0] && array[0] <= array[length / 2])) {
            // Median is the first element, so there is nothing to be done
        } else {
            swap(array, 0, length - 1); // Median is the last element
        }
    } // End choice of pivot
    int idx_left = 0; // Keeps track of last element of left partition
    int idx_right = 0; // Keeps track of last element of right partition
    int i;
    for (i = 1; i < length; i++) {
        if (array[idx_right + 1] > array[0]) { // Next element we encounter is larger than pivot
            idx_right++;
        } else { // Next element we encounter is smaller than pivot
            swap(array, idx_left + 1, idx_right + 1);
            idx_left++;
            idx_right++;
        }
    }
    swap(array, 0, idx_left);
    n = quick_sort(array, idx_left, choice);
    n += quick_sort(array + idx_left + 1, length - idx_left - 1, choice);
    return n + length - 1;
}

int main() {
    int length;
    int range;
    int choice;
    srand(time(NULL));
    printf("Type the length of the array to be sorted.\n");
    scanf("%d", &length);
    printf("Array will contain integers from 0 to M. Choose M.\n");
    scanf("%d", &range);
    //printf("Choose what the pivot will be:\n1 - First element\n2 - Last element\n3 - Median-of-three\n");
    //scanf("%d", &choice);
    int array[length];
    int copy1[length];
    int copy2[length];
    int i;
    for (i = 0; i < length; i++) {
        array[i] = rand() % (range + 1);
        copy1[i] = array[i];
        copy2[i] = array[i];
    }
    //printf("Original array: ");
    //printarray(array, length);
    int n1 = quick_sort(copy1, length, 1);
    int n2 = quick_sort(copy2, length, 2);
    int n3 = quick_sort(array, length, 3);
    //printf("Sorted array: ");
    //printarray(array, length);
    printf("Number of comparisons\n");
    printf("First element: %d - Last element: %d - Median-of-three: %d\n", n1, n2, n3);
    return 0;
}