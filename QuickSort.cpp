#include <bits/stdc++.h>
using namespace std;

// Function to partition the array and place the pivot element at its correct position
int partition(int arr[], int s, int e) {
    int pivot = arr[s]; // Choose the first element as the pivot
    int count = 0;

    // Count the number of elements less than or equal to the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]); // Place the pivot at its correct position

    int i = s;
    int j = e;

    // Partition the elements around the pivot
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= arr[pivotIndex]) {
            i++;
        }
        while (arr[j] > arr[pivotIndex]) {
            j--;
        }

        // Swap elements to move smaller elements to the left and larger elements to the right
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex; // Return the index of the pivot element
}

// Recursive function to perform QuickSort
void QuickSort(int arr[], int s, int e) {
    if (s >= e) {
        return; // Base case: If the array has 0 or 1 element, it's already sorted
    }

    int p = partition(arr, s, e); // Find the pivot element and partition the array

    // Recursively sort the subarrays on the left and right of the pivot
    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {2, 4, 1, 6, 9, 2, 2, 2, 2, 9, 9, 9, 9};
    int n = 13;
    int s = 0, e = n - 1;

    // Call the QuickSort function to sort the array
    QuickSort(arr, s, e);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
