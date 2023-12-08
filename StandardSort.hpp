
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
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);  // Convert to milliseconds        

    if (nums.size() % 2 == 0){
        return nums[nums.size()/2 - 1];
    }
    return nums[nums.size()/2];
}
