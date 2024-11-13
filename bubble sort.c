#include <stdio.h>
// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
// Flag to optimize and check if a swap was made
int swapped = 0;
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
// Swap adjacent elements if they are in the wrong order
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swapped = 1;
}
}
// If no elements were swapped, the array is already sorted
if (swapped == 0) {
break;
}
}
}
// Function to print an array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function to test the bubbleSort implementation
int main() {
int arr[] = {64, 34, 25, 12, 22, 11, 90};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: \n");
printArray(arr, n);
bubbleSort(arr, n);
printf("Sorted array: \n");
printArray(arr, n);
return 0;
}