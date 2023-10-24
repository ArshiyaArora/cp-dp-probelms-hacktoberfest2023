#include <bits/stdc++.h>
using namespace std;

// Merge two sorted subarrays back into the original array
void MergeArray(int arr[], int s, int e, int mid) {
    
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values of arr into first and second arrays
    int arrIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[arrIndex++];
    }
    arrIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[arrIndex++];
    }

    // Merge sorted arrays
    int index1 = 0, index2 = 0;
    arrIndex = s;
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[arrIndex++] = first[index1++];
        }
        else {
            arr[arrIndex++] = second[index2++];
        }
    }

    // Copy any remaining elements from first and second arrays
    while (index1 < len1) {
        arr[arrIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[arrIndex++] = second[index2++];
    }

    // Deallocate memory used for first and second arrays
    delete[] first;
    delete[] second;
}

// Recursive function to sort the array using Merge Sort
void MergeSort(int arr[], int s, int e) {

    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    
    // Recursively divide the array into two halves
    MergeSort(arr, s, mid);
    MergeSort(arr, mid + 1, e);

    // Merge the two sorted halves back into the original array
    MergeArray(arr, s, e, mid);
}

int main() {
    int arr[] = {10, 4, 2, 56, 78};
    int n = 5;
    int s = 0;
    int e = n - 1;

    // Call the MergeSort function to sort the array
    MergeSort(arr, s, e);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
