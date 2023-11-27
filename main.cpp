#include <iostream>
#include <vector>
#include "HalfSelectionSort.hpp"

int main() {
    HalfSelectionSort s;
    std::vector<int> arr = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    int duration = 5;
    std::cout<<s.halfSelectionSort(arr, duration)<<std::endl;
    return 0;
}