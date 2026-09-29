// ============================================================================
// Problem 6: Heap Sort
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


void siftDown(int arr[], int root, int size, int &swaps) {
    while (true) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest == root)
            return;

        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        swaps++;
        root = largest;
    }
}

void heapSort(int arr[], int n, int &swaps) {
    swaps = 0;

    // Build phase: the leaves are already heaps, so start one level above.
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(arr, i, n, swaps);

    cout << "Heap: ";
    printArray(arr, n);

    // Sorting phase: move the root to the end, shrink, restore the heap.
    for (int end = n - 1; end >= 1; end--) {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;

        siftDown(arr, 0, end, swaps);

        cout << "end = " << end << ": heap: ";
        printArray(arr, end);
        cout << "          sorted: ";
        printArray(arr + end, n - end);
    }
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int swaps;

    cout << "Original: ";
    printArray(A, n);

    heapSort(A, n, swaps);

    cout << "Sorted: ";
    printArray(A, n);
    cout << "Swaps in siftDown: " << swaps << endl;

    return 0;
}