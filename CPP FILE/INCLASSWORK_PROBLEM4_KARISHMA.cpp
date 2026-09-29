// ============================================================================
//Problem 4: Quick Sort (Lomuto, last element as pivot)
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


void indent(int depth) {
    for (int k = 0; k < depth; k++)
        cout << "  ";
}


int partition(int arr[], int low, int high, int &comparisons, bool trace) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;

        if (arr[j] <= pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            if (trace) {
                cout << "  i = " << i << ", j = " << j << " -> ";
                printArray(arr + low, high - low + 1);
            }
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    if (trace) {
        cout << "  pivot " << pivot << " lands at index " << i + 1 << " -> ";
        printArray(arr + low, high - low + 1);
    }

    return i + 1;
}

void quickSort(int arr[], int low, int high, int depth, int &comparisons) {
    if (low >= high)
        return;

    indent(depth);
    cout << "pivot = " << arr[high] << ": ";
    printArray(arr + low, high - low + 1);

    int split = partition(arr, low, high, comparisons, depth == 0);

    quickSort(arr, low, split - 1, depth + 1, comparisons);
    quickSort(arr, split + 1, high, depth + 1, comparisons);
}

int main() {
    int A[] = {22, 6, 4, 32, 7, 9, 12, 5};
    int B[] = {4, 5, 6, 7, 9, 12, 22, 32};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0;

    cout << "=== Run 1: array A ===" << endl;
    cout << "Original: ";
    printArray(A, n);

    quickSort(A, 0, n - 1, 0, comparisons);

    cout << "Sorted: ";
    printArray(A, n);
    cout << "Comparisons: " << comparisons << endl;

    comparisons = 0;

    cout << endl << "=== Run 2: the same values already sorted ===" << endl;
    cout << "Original: ";
    printArray(B, n);

    quickSort(B, 0, n - 1, 0, comparisons);

    cout << "Sorted: ";
    printArray(B, n);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}