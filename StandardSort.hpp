
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

/**
 * @post: Uses standard sort, and returns the duration of the sort and middle of the array
 * @param: Array of integers
 * @return: Duration of the sort
 * @return: Middle of the array
*/
int standardSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(nums.begin(), nums.end());
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return nums[nums.size()/2];
}
