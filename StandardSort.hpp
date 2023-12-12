
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
    std::chrono::duration<double> difference = end - start;
    duration = static_cast<int>(difference.count() * 1000);    

    if (nums.size() % 2 == 0){
        return nums[nums.size()/2 - 1];
    }
    return nums[nums.size()/2];
}
