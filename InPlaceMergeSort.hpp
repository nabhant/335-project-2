
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

void inPlaceRecursiveCall(std::vector<int>& nums, std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (start < end - 1) {
        auto mid = start + std::distance(start, end) / 2;
        inPlaceRecursiveCall(nums, start, mid); 
        inPlaceRecursiveCall(nums, mid, end);   
        std::inplace_merge(start, mid, end);        
    }
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    inPlaceRecursiveCall(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

     if (nums.size() % 2 == 0 )
    {
        return nums[(nums.size() / 2) -1];
    }else{
        return nums[nums.size() / 2];
    } // Return the median
}