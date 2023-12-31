#include <iostream>
#include <vector>
#include <chrono> 
#include <algorithm>

void recursiveCall(std::vector<int>& nums, std::vector<int>& sorted) {
    int size = nums.size();

    if (size <= 1) {
        sorted = nums;  
        return;
    }
    int middle = size / 2;
    std::vector<int> left(nums.begin(), nums.begin() + middle);
    std::vector<int> right(nums.begin() + middle, nums.end());
    std::vector<int> sortedLeft, sortedRight;

    recursiveCall(left, sortedLeft);
    recursiveCall(right, sortedRight);
    sorted.clear(); 
    std::merge(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), std::back_inserter(sorted));

    nums.clear();  // Clear the original vector
    // Merge the 2 halves into one vector
    std::merge(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), std::back_inserter(nums));
}


int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> temp(nums.size());
    recursiveCall(nums,temp);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    duration = static_cast<int>(difference.count() * 1000);
    if (temp.size() % 2 == 0 ){
        return temp[(temp.size() / 2) -1];
    }
    else{
        return temp[temp.size() / 2];
    }
}

