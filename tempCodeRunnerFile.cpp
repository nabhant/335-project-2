#include <iostream>
#include <vector>
#include "SelectionSort.hpp"

int main() {
    SelectionSort s;
    std::vector<int> arr = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    s.selectionSort(arr, 5);
    s.printArray(arr, 9);
    return 0;
}