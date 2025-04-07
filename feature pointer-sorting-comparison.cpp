#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Utility function to print pointer-sorted array
void printPointerArray(vector<int*>& ptrArr) {
    for (int* ptr : ptrArr)
        cout << *ptr << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int*>& ptrArr) {
    int n = ptrArr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*ptrArr[j] > *ptrArr[j + 1])
                swap(ptrArr[j], ptrArr[j + 1]);
}

// Selection Sort
void selectionSort(vector<int*>& ptrArr) {
    int n = ptrArr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (*ptrArr[j] < *ptrArr[min_idx])
                min_idx = j;
        swap(ptrArr[min_idx], ptrArr[i]);
    }
}

// Insertion Sort
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

// Quick Sort
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

int main() {
    vector<int> data = {9, 4, 7, 3, 2, 8, 5};

    // Bubble Sort
    vector<int*> ptrBubble;
    for (int& val : data) ptrBubble.push_back(&val);
    bubbleSort(ptrBubble);
    cout << "Bubble Sort: ";
    printPointerArray(ptrBubble);

    // Selection Sort
    vector<int*> ptrSelection;
    for (int& val : data) ptrSelection.push_back(&val);
    selectionSort(ptrSelection);
    cout << "Selection Sort: ";
    printPointerArray(ptrSelection);

    // Insertion Sort
    vector<int*> ptrInsertion;
    for (int& val : data) ptrInsertion.push_back(&val);
    insertionSort(ptrInsertion);
    cout << "Insertion Sort: ";
    printPointerArray(ptrInsertion);

    // Quick Sort
    vector<int*> ptrQuick;
    for (int& val : data) ptrQuick.push_back(&val);
    quickSort(ptrQuick, 0, ptrQuick.size() - 1);
    cout << "Quick Sort: ";
    printPointerArray(ptrQuick);

    return 0;
}
