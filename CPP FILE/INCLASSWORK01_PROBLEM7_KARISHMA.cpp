// ============================================================================
// Problem 7: Comparing the Six Algorithms
// 
// The six sorts from Problems 1 to 6 with their step-by-step printing removed,
// each counting comparisons. Part 1 compares counts, Part 2 measures time.
// ============================================================================

#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// scratch space for merge, big enough for the largest test
int mergeLeft[10000];
int mergeRight[10000];

void printArray(const int arr[], int n) {
    for (int k = 0; k < n; k++) {
        cout << arr[k];

        if (k < n - 1)
            cout << " ";
    }

    cout << endl;
}

void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;

    for (int pass = 0; pass <= n - 2; pass++) {
        bool swapped = false;

        for (int i = 0; i <= n - pass - 2; i++) {
            comparisons++;

            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = i - 1;

        while (pos >= 0) {
            comparisons++;

            if (arr[pos] <= key)
                break;

            arr[pos + 1] = arr[pos];
            pos--;
        }

        arr[pos + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;

    for (int i = 0; i <= n - 2; i++) {
        int minPos = i;

        for (int j = i + 1; j <= n - 1; j++) {
            comparisons++;

            if (arr[j] < arr[minPos])
                minPos = j;
        }

        if (minPos != i) {
            int temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
        }
    }
}

int partition(int arr[], int low, int high, int &comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;

        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high, int &comparisons) {
    if (low >= high)
        return;

    int split = partition(arr, low, high, comparisons);

    quickSort(arr, low, split - 1, comparisons);
    quickSort(arr, split + 1, high, comparisons);
}

void merge(int arr[], int low, int mid, int high, int &comparisons) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    for (int k = 0; k < leftSize; k++)
        mergeLeft[k] = arr[low + k];

    for (int k = 0; k < rightSize; k++)
        mergeRight[k] = arr[mid + 1 + k];

    int i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize) {
        comparisons++;

        if (mergeLeft[i] <= mergeRight[j])
            arr[k] = mergeLeft[i++];
        else
            arr[k] = mergeRight[j++];

        k++;
    }

    while (i < leftSize)
        arr[k++] = mergeLeft[i++];

    while (j < rightSize)
        arr[k++] = mergeRight[j++];
}

void mergeSort(int arr[], int low, int high, int &comparisons) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid, comparisons);
    mergeSort(arr, mid + 1, high, comparisons);
    merge(arr, low, mid, high, comparisons);
}

void siftDown(int arr[], int root, int size, int &comparisons) {
    while (true) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < size) {
            comparisons++;

            if (arr[left] > arr[largest])
                largest = left;
        }

        if (right < size) {
            comparisons++;

            if (arr[right] > arr[largest])
                largest = right;
        }

        if (largest == root)
            return;

        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        root = largest;
    }
}

void heapSort(int arr[], int n, int &comparisons) {
    comparisons = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(arr, i, n, comparisons);

    for (int end = n - 1; end >= 1; end--) {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;

        siftDown(arr, 0, end, comparisons);
    }
}

// Runs one algorithm on work[0..n-1], which the caller has already filled
int runSort(int which, int work[], int n) {
    int c = 0;

    if (which == 0) bubbleSort(work, n, c);
    if (which == 1) insertionSort(work, n, c);
    if (which == 2) selectionSort(work, n, c);
    if (which == 3) quickSort(work, 0, n - 1, c);
    if (which == 4) mergeSort(work, 0, n - 1, c);
    if (which == 5) heapSort(work, n, c);

    return c;
}

// ---- printing helpers, so that main() holds no loops ----

void fillRandom(int big[], int m) {
    srand(1);

    for (int k = 0; k < m; k++)
        big[k] = rand() % 100000 + 1;
}

void printCountTable(const char *names[], const int A[], const int up[],
                     const int down[], int work[], int n) {
    for (int s = 0; s < 6; s++) {
        cout << names[s] << "\t";

        if (s == 0 || s >= 3)
            cout << "\t";

        for (int k = 0; k < n; k++) work[k] = A[k];
        cout << runSort(s, work, n) << "\t";

        for (int k = 0; k < n; k++) work[k] = up[k];
        cout << runSort(s, work, n) << "\t";

        for (int k = 0; k < n; k++) work[k] = down[k];
        cout << runSort(s, work, n) << endl;
    }
}

void measureTimes(int big[], int work[], const int sizes[],
                  long long micros[][3]) {
    for (int t = 0; t < 3; t++) {
        int m = sizes[t];

        fillRandom(big, m);

        for (int s = 0; s < 6; s++) {
            for (int k = 0; k < m; k++)
                work[k] = big[k];

            auto t0 = high_resolution_clock::now();
            runSort(s, work, m);
            auto t1 = high_resolution_clock::now();

            micros[s][t] = duration_cast<microseconds>(t1 - t0).count();
        }
    }
}

void printTimeTable(const char *names[], long long micros[][3]) {
    for (int s = 0; s < 6; s++) {
        cout << names[s] << "\t";

        if (s == 0 || s >= 3)
            cout << "\t";

        cout << micros[s][0] << "\t" << micros[s][1] << "\t"
             << micros[s][2] << endl;
    }
}

void printFirstTen(const char *names[], const int big[], int work[]) {
    for (int s = 0; s < 6; s++) {
        for (int k = 0; k < 10000; k++)
            work[k] = big[k];

        runSort(s, work, 10000);

        cout << names[s] << ":\t";

        if (s == 0 || s >= 3)
            cout << "\t";

        printArray(work, 10);
    }
}

int main() {
    const char *names[6] = {"Bubble", "Insertion", "Selection",
                            "Quick", "Merge", "Heap"};

    static int big[10000];
    static int work[10000];

    // ---- Part 1: comparisons on the eight values of A ----
    int A[]    = {22, 6, 4, 32, 7, 9, 12, 5};
    int up[]   = {4, 5, 6, 7, 9, 12, 22, 32};
    int down[] = {32, 22, 12, 9, 7, 6, 5, 4};
    int n = 8;

    cout << "=== Part 1: comparisons on the eight values of A ===" << endl;
    cout << "Algorithm\tA\tsorted\treversed" << endl;
    printCountTable(names, A, up, down, work, n);

    // ---- Part 2: time on random arrays ----
    int sizes[3] = {1000, 5000, 10000};
    long long micros[6][3];

    measureTimes(big, work, sizes, micros);

    cout << endl << "=== Part 2: time on random arrays (microseconds) ===" << endl;
    cout << "Algorithm\tn=1000\tn=5000\tn=10000" << endl;
    printTimeTable(names, micros);

    // ---- Part 3: first 10 of each sorted array ----
    cout << endl << "=== Part 3: first 10 of each sorted array (n = 10000) ==="
         << endl;

    fillRandom(big, 10000);
    printFirstTen(names, big, work);

    return 0;
}