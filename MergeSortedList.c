/*
SCT221-0207/2023 -- Marylyne Nashipae
SCT221-0181/2023 -- Brian Kyalo Kimanzi
SCT221-0522/2022 -- Kaguchia Kago 
 */
#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void mergeSortedArray(int Array1[], int size1, int array2[], int size2, int mergedList[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and compare elements
    while (i < size1 && j < size2) {
        if (Array1[i] <= array2[j]) {
            mergedList[k++] = Array1[i++];
        } else {
            mergedList[k++] = array2[j++];
        }
    }

    // Append remaining elements of list1
    while (i < size1) {
        mergedList[k++] =Array1[i++];
    }

    // Append remaining elements of list2
    while (j < size2) {
        mergedList[k++] = array2[j++];
    }
}

int main() {
    int size1, size2;

    // Get size and elements of the first array from user
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    int array1[size1];
    printf("Enter the elements of the first array in sorted order :\n");
    for (int i = 0; i < size1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    // Get size and elements of the second array from user
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    int array2[size2];
    printf("Enter the elements of the second array in sorted error:\n");
    for (int i = 0; i < size2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    int mergedList[size1 + size2];

    // Call the merge function
    mergeSortedArray(array1, size1, array2, size2, mergedList);

    // Print the merged sorted array
    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    return 0;
}


