#include <stdio.h>
// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right) {
int n1 = mid - left + 1; // Size of the left subarray
int n2 = right - mid; // Size of the right subarray
// Temporary arrays
int L[n1], R[n2];
// Copy data to temporary arrays L[] and R[]
for (int i = 0; i < n1; i++)
L[i] = arr[left + i];
for (int j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];
// Merge the temporary arrays back into arr[]
int i = 0; // Initial index of first subarray
int j = 0; // Initial index of second subarray
int k = left; // Initial index of the merged subarray
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
// Copy any remaining elements of L[]
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
// Copy any remaining elements of R[]
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
}
// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
if (left < right) {
int mid = left + (right - left) / 2; // Calculate the mid point to avoid overflow
// Recursively sort the first and second halves
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
// Merge the sorted halves
merge(arr, left, mid, right);
}
}
// Function to print an array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function to test the mergeSort implementation
int main() {
int arr[] = {12, 11, 13, 5, 6, 7};
int arr_size = sizeof(arr) / sizeof(arr[0]);
printf("Original array: \n");
printArray(arr, arr_size);
mergeSort(arr, 0, arr_size - 1);
printf("Sorted array: \n");
printArray(arr, arr_size);
return 0;
}