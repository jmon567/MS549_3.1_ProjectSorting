
#include "sorting.h"
#include <iostream>
#include <chrono>
#include <ctime>

void fillArray(vector<int>& arr) {
    srand(time(NULL));
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rand() % 1000;
    }
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    // ... implementation of merge operation ...
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j]
        = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
        int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    // ... implementation of merge sort recursive calls ...
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

double measureTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count() / 1000.0;

}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int sizes[] = { 100, 1000, 10000, 100000 };

    for (int size : sizes) {
        vector<int> arr(size);
        fillArray(arr);

        double bubbleTime = measureTime([&] { bubbleSort(arr); });
        double mergeTime = measureTime([&] { mergeSort(arr, 0, size - 1); });

        sort(arr.begin(), arr.end()); // C++ built-in sort
        double cppSortTime = measureTime([&] { sort(arr.begin(), arr.end()); });

        cout << "Size: " << size << endl;
        cout << "Bubble Sort Time: " << bubbleTime << " ms" << endl;
        cout << "Merge Sort Time: " << mergeTime << " ms" << endl;
        cout << "C++ Built-in Sort Time: " << cppSortTime << " ms" << endl << endl;
    }

    return 0;
}







