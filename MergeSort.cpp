#include <iostream>
using namespace std;

void conquer(int arr[], int s, int mid, int e) {
    int n1 = mid - s + 1, n2 = e - mid; // Sizes of the subarrays

    int* first = new int[n1];  // Dynamic array for the first half
    int* second = new int[n2]; // Dynamic array for the second half

    // Copying values into the first subarray
    for (int i = 0; i < n1; i++) {
        first[i] = arr[s + i];
    }

    // Copying values into the second subarray
    for (int i = 0; i < n2; i++) {
        second[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = s; // Indices for first, second, and main array
    while (i < n1 && j < n2) {
        if (first[i] < second[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = second[j++];
        }
    }

    // Copying remaining elements from first subarray
    while (i < n1) {
        arr[k++] = first[i++];
    }

    // Copying remaining elements from second subarray
    while (j < n2) {
        arr[k++] = second[j++];
    }

    // Free dynamically allocated memory
    delete[] first;
    delete[] second;
}

void divide(int arr[], int s, int e) {
    if (s >= e) return; // Base case: Single element

    int mid = s + (e - s) / 2; // Calculate the middle index

    divide(arr, s, mid);    // Sort the first half
    divide(arr, mid + 1, e); // Sort the second half

    conquer(arr, s, mid, e); // Merge the sorted halves
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 9, 8, 4, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, n - 1); // Sort the array

    show(arr, n); // Display the sorted array

    return 0;
}
