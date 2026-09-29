// ============================================================================
//Problem 3: Selection Sort
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

void selectionSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i <= n - 2; i++) {
        int minPos = i;

        for (int j = i + 1; j <= n - 1; j++) {
            comparisons++;

            if (arr[j] < arr[minPos])
                minPos = j;
        }

        // Skipped when the smallest value already sits in slot i.
        if (minPos != i) {
            int temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;

            swaps++;
        }

        cout << "Pass " << i + 1 << ": min = " << arr[i]
             << " at index " << minPos << " -> ";
        printArray(arr, n);
    }
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons;
    int swaps;

    cout << "Original: ";
    printArray(A, n);

    selectionSort(A, n, comparisons, swaps);

    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << "   Swaps: " << swaps << endl;

    return 0;
}