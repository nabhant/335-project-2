#include "MergeSort.hpp"

int MergeSort::MergeSort ( std::vector<int>& nums, int& duration ) {
    auto start = std::chrono::high_resolution_clock::now();
    int size = nums.size();
    if ( size == 1 ) {
        return nums[0];
    }
    int mid = size / 2;
    std::vector<int> left;
    std::vector<int> right;
    for (auto it = nums.begin(); it != nums.begin() + mid; it++ ) {
        left.push_back(nums[i]);
    }
    for ( auto it = nums.begin() + mid; it != nums.end(); it++) {
        right.push_back(nums[i]);
    }
    MergeSort(left, duration);
    MergeSort(right, duration);
    auto it_left = left.begin();
auto it_right = right.begin();
auto it_nums = nums.begin();

while (it_left != left.end() && it_right != right.end()) {
    if (*it_left < *it_right) {
        *it_nums = *it_left;
        ++it_left;
    } else {
        *it_nums = *it_right;
        ++it_right;
    }
    ++it_nums;
}

while (it_left != left.end()) {
    *it_nums = *it_left;
    ++it_left;
    ++it_nums;
}

while (it_right != right.end()) {
    *it_nums = *it_right;
    ++it_right;
    ++it_nums;
}
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return nums[mid];
}