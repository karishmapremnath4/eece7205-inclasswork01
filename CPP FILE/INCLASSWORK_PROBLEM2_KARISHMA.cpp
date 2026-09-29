// ============================================================================
// Problem 2: Insertion Sort
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

void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = i - 1;

        // The test sits here, not in the while condition, so the failing
        // comparison that ends the scan is counted too.
        while (pos >= 0) {
            comparisons++;

            if (arr[pos] <= key)
                break;

            arr[pos + 1] = arr[pos];
            shifts++;
            pos--;
        }

        arr[pos + 1] = key;

        cout << "i = " << i << ", key = " << key << ": ";
        printArray(arr, n);
    }
}

// Sorts one ordering and hands the totals back so main() can report them.
void runCase(const char *label, int arr[], int n, int &comparisons, int &shifts) {
    cout << label << endl;
    cout << "Original: ";
    printArray(arr, n);

    insertionSort(arr, n, comparisons, shifts);

    cout << "Sorted: ";
    printArray(arr, n);
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int up[] = {4, 5, 6, 7, 9, 12, 22, 32};
    int down[] = {32, 22, 12, 9, 7, 6, 5, 4};

    int n = sizeof(A) / sizeof(A[0]);

    int comparisons;
    int shifts;

    runCase("=== Run 1: array A ===", A, n, comparisons, shifts);
    cout << "Comparisons: " << comparisons << "   Shifts: " << shifts << endl;

    cout << endl;
    runCase("=== Run 2: increasing order (fewest shifts) ===", up, n,
            comparisons, shifts);
    cout << "Comparisons: " << comparisons << "   Shifts: " << shifts << endl;

    cout << endl;
    runCase("=== Run 3: decreasing order (most shifts) ===", down, n,
            comparisons, shifts);
    cout << "Comparisons: " << comparisons << "   Shifts: " << shifts << endl;

    return 0;
}