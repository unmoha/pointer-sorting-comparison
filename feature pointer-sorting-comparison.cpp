#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Print the values pointed to by a pointer array
void printPointerArray(const vector<int*>& ptrArr) {
    for (const int* ptr : ptrArr)
        cout << *ptr << " ";
    cout << endl;
}

// Bubble Sort (Pointer-based)
void bubbleSort(vector<int*>& ptrArr) {
    int n = ptrArr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*ptrArr[j] > *ptrArr[j + 1])
                swap(ptrArr[j], ptrArr[j + 1]);
}

// Selection Sort (Pointer-based)
void selectionSort(vector<int*>& ptrArr) {
    int n = ptrArr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (*ptrArr[j] < *ptrArr[min_idx])
                min_idx = j;
        }
        swap(ptrArr[min_idx], ptrArr[i]);
    }
}

// Insertion Sort (Pointer-based)
void insertionSort(vector<int*>& ptrArr) {
    int n = ptrArr.size();
    for (int i = 1; i < n; i++) {
        int* key = ptrArr[i];
        int j = i - 1;
        while (j >= 0 && *ptrArr[j] > *key) {
            ptrArr[j + 1] = ptrArr[j];
            j--;
        }
        ptrArr[j + 1] = key;
    }
}

// Quick Sort Helper (Pointer-based)
void quickSort(vector<int*>& ptrArr, int low, int high) {
    if (low < high) {
        int pivot = *ptrArr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (*ptrArr[j] < pivot) {
                i++;
                swap(ptrArr[i], ptrArr[j]);
            }
        }
        swap(ptrArr[i + 1], ptrArr[high]);
        int pi = i + 1;

        quickSort(ptrArr, low, pi - 1);
        quickSort(ptrArr, pi + 1, high);
    }
}

// Create a vector of pointers from a data vector
vector<int*> makePointerArray(vector<int>& data) {
    vector<int*> ptrs;
    for (int& val : data)
        ptrs.push_back(&val);
    return ptrs;
}

// Verify if pointer array is sorted
bool isSorted(const vector<int*>& ptrArr) {
    for (size_t i = 1; i < ptrArr.size(); ++i)
        if (*ptrArr[i - 1] > *ptrArr[i])
            return false;
    return true;
}

int main() {
    vector<int> original = {9, 4, 7, 3, 2, 8, 5};

    // Bubble Sort
    vector<int> bubbleData = original;
    vector<int*> ptrBubble = makePointerArray(bubbleData);
    bubbleSort(ptrBubble);
    cout << "Bubble Sort: ";
    printPointerArray(ptrBubble);

    // Selection Sort
    vector<int> selectionData = original;
    vector<int*> ptrSelection = makePointerArray(selectionData);
    selectionSort(ptrSelection);
    cout << "Selection Sort: ";
    printPointerArray(ptrSelection);

    // Insertion Sort
    vector<int> insertionData = original;
    vector<int*> ptrInsertion = makePointerArray(insertionData);
    insertionSort(ptrInsertion);
    cout << "Insertion Sort: ";
    printPointerArray(ptrInsertion);

    // Quick Sort
    vector<int> quickData = original;
    vector<int*> ptrQuick = makePointerArray(quickData);
    quickSort(ptrQuick, 0, ptrQuick.size() - 1);
    cout << "Quick Sort: ";
    printPointerArray(ptrQuick);

    return 0;
}
