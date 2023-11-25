#include <iostream>
#include <vector>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"

int main() {
    StandardSort s;
    std::vector<int> arr = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    std::cout<<s.StandardSort(arr, 5);
    return 0;
}