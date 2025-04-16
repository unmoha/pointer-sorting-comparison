# pointer-sorting-comparison

## Overview

This program demonstrates the implementation of four classic sorting algorithms — **Bubble Sort**, **Selection Sort**, **Insertion Sort**, and **Quick Sort** — using pointers in C++. Each sorting algorithm sorts a list of integer pointers rather than the actual integer values, showcasing pointer manipulation and sorting logic.

## Features

- Sorting is performed **without modifying the original data**, using pointer arrays.
- Demonstrates understanding of pointer operations and custom sorting logic.
- Uses the following sorting algorithms:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Quick Sort

## How It Works

1. A fixed vector of integers is defined:  
   `data = {9, 4, 7, 3, 2, 8, 5}`

2. For each sorting algorithm:
   - A vector of pointers (`vector<int*>`) to the original data is created.
   - The corresponding sorting function is applied to the pointer vector.
   - The sorted values (via dereferencing pointers) are printed without altering the original data array.

## File Structure

- `main.cpp` - Contains all the sorting algorithms and the main function demonstrating their usage.

## Code Snippet

```cpp
vector<int> data = {9, 4, 7, 3, 2, 8, 5};
vector<int*> ptrBubble;
for (int& val : data) ptrBubble.push_back(&val);
bubbleSort(ptrBubble);
printPointerArray(ptrBubble);