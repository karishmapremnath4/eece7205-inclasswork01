// ============================================================================
// Problem 5: Merge Sort
// ============================================================================

#include <iostream>

using namespace std;

void printArray(const int arr[], int n) {
    for (int k = 0; k < n; k++) {
        cout << arr[k];

        if (k < n - 1)
            cout << " ";
    }

    cout << endl;
}


void merge(int arr[], int low, int mid, int high, int &comparisons, int &lastMerge) {
    int before = comparisons;
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int left[16], right[16];

    for (int k = 0; k < leftSize; k++)
        left[k] = arr[low + k];

    for (int k = 0; k < rightSize; k++)
        right[k] = arr[mid + 1 + k];

    int i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize) {
        comparisons++;

        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];

        k++;
    }

    while (i < leftSize)
        arr[k++] = left[i++];

    while (j < rightSize)
        arr[k++] = right[j++];

    lastMerge = comparisons - before;

    cout << "merged: ";
    printArray(arr + low, high - low + 1);
}

void mergeSort(int arr[], int low, int high, int &comparisons, int &lastMerge) {
    if (low >= high)
        return;

    cout << "split: ";
    printArray(arr + low, high - low + 1);

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid, comparisons, lastMerge);
    mergeSort(arr, mid + 1, high, comparisons, lastMerge);
    merge(arr, low, mid, high, comparisons, lastMerge);
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int up[] = {4, 5, 6, 7, 9, 12, 22, 32};
    int down[] = {32, 22, 12, 9, 7, 6, 5, 4};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0, lastMerge = 0;

    cout << "=== Run 1: array A ===" << endl << "Original: ";
    printArray(A, n);
    mergeSort(A, 0, n - 1, comparisons, lastMerge);
    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons
         << " (final merge: " << lastMerge << ")" << endl;

    comparisons = 0;

    cout << endl << "=== Run 2: sorted copy ===" << endl << "Original: ";
    printArray(up, n);
    mergeSort(up, 0, n - 1, comparisons, lastMerge);
    cout << "Sorted: ";
    printArray(up, n);
    cout << "Comparisons: " << comparisons
         << " (final merge: " << lastMerge << ")" << endl;

    comparisons = 0;

    cout << endl << "=== Run 3: reversed copy ===" << endl << "Original: ";
    printArray(down, n);
    mergeSort(down, 0, n - 1, comparisons, lastMerge);
    cout << "Sorted: ";
    printArray(down, n);
    cout << "Comparisons: " << comparisons
         << " (final merge: " << lastMerge << ")" << endl;

    return 0;
}