#include <stdio.h>
// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i]; // Element to be inserted
int j = i - 1;
// Move elements that are greater than `key` to one position ahead
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key; // Insert the `key` at the correct position
}
}
// Function to print an array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function to test the insertionSort implementation
int main() {
int arr[] = {12, 11, 13, 5, 6};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: \n");
printArray(arr, n);
insertionSort(arr, n);
printf("Sorted array: \n");
printArray(arr, n);
return 0;
}