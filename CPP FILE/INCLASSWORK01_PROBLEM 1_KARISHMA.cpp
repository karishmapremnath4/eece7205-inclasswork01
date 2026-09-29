// ============================================================================
// Problem 1: Bubble Sort
//============================================================================

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

// Copies src into dest so that Run 2 can start from its own array.
void copyArray(const int src[], int dest[], int n) {
    for (int k = 0; k < n; k++)
        dest[k] = src[k];
}

void bubbleSort(int arr[], int n, int &passes, int &comparisons, int &swaps) {
    passes = 0;
    comparisons = 0;
    swaps = 0;

    for (int pass = 0; pass <= n - 2; pass++) {
        bool swapped = false;

        // The last "pass" values are already in place.
        for (int i = 0; i <= n - pass - 2; i++) {
            comparisons++;

            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        passes++;

        cout << "Pass " << passes << ": ";
        printArray(arr, n);

        if (swapped == false)
            break;
    }
}

// Sorts one array and reports the three totals.
void runCase(const char *label, int arr[], int n,
             int &passes, int &comparisons, int &swaps) {
    cout << label << endl;
    cout << "Original: ";
    printArray(arr, n);

    bubbleSort(arr, n, passes, comparisons, swaps);

    cout << "Sorted:   ";
    printArray(arr, n);
    cout << "Passes: " << passes
         << "   Comparisons: " << comparisons
         << "   Swaps: " << swaps << endl;
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int B[8];
    int n = sizeof(A) / sizeof(A[0]);

    int passes;
    int comparisons;
    int swaps;

    runCase("=== Run 1: original array A ===", A, n, passes, comparisons, swaps);

    // A is sorted now, so B is the already sorted copy.
    copyArray(A, B, n);

    cout << endl;
    runCase("=== Run 2: already sorted copy of A ===", B, n,
            passes, comparisons, swaps);

    return 0;
}
