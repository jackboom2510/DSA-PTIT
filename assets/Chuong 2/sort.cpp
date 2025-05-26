#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace chrono;
#define COL_WIDTH 12
#define SIZE_WIDTH 6
// Selection Sort
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

// Insertion Sort
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Measure time for a function that sorts a vector<int>
template <typename Func>
double measure(Func sortFunc, const vector<int>& original) {
    vector<int> arr = original;
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count();
}

int main() {
    vector<int> sizes = {100, 500, 1000, 2000, 3000, 5000, 7000, 10000};
    mt19937 rng(42);  // seed cố định để tái lập kết quả

    // Mở file output.out để ghi kết quả
    ofstream fout("output.out");
    if (!fout) {
        cerr << "Không thể mở file output.out\n";
        return 1;
    }

    // Thiết lập định dạng số
    cout << fixed << setprecision(6);
    fout << fixed << setprecision(6);

    // In header
    cout << left << setw(SIZE_WIDTH) << "Size" << right << setw(COL_WIDTH) << "Selection"
         << setw(COL_WIDTH) << "Insertion" << setw(COL_WIDTH) << "Bubble" << setw(COL_WIDTH)
         << "Quick" << setw(COL_WIDTH) << "Merge" << setw(COL_WIDTH) << "Heap" << "\n";

    fout << left << setw(SIZE_WIDTH) << "Size" << right << setw(COL_WIDTH) << "Selection"
         << setw(COL_WIDTH) << "Insertion" << setw(COL_WIDTH) << "Bubble" << setw(COL_WIDTH)
         << "Quick" << setw(COL_WIDTH) << "Merge" << setw(COL_WIDTH) << "Heap" << "\n";

    for (int size : sizes) {
        vector<int> data(size);
        for (int& x : data) x = rng() % (size * 2);

        double t1 = measure(selectionSort, data);
        double t2 = measure(insertionSort, data);
        double t3 = measure(bubbleSort, data);
        double t4 = measure([&](vector<int>& a) { quickSort(a, 0, a.size() - 1); }, data);
        double t5 = measure([&](vector<int>& a) { mergeSort(a, 0, a.size() - 1); }, data);
        double t6 = measure(heapSort, data);

        cout << left << setw(SIZE_WIDTH) << size << right << setw(COL_WIDTH) << t1
             << setw(COL_WIDTH) << t2 << setw(COL_WIDTH) << t3 << setw(COL_WIDTH) << t4
             << setw(COL_WIDTH) << t5 << setw(COL_WIDTH) << t6 << "\n";

        fout << left << setw(SIZE_WIDTH) << size << right << setw(COL_WIDTH) << t1
             << setw(COL_WIDTH) << t2 << setw(COL_WIDTH) << t3 << setw(COL_WIDTH) << t4
             << setw(COL_WIDTH) << t5 << setw(COL_WIDTH) << t6 << "\n";
    }

    fout.close();
    return 0;
}
