#include "InPlaceMergeSort.hpp"

/**
 * @post: Sorts the array using InPlaceMergeSort
 * @param: Array of integers
 * @param: Integer to store the duration of the sort
 * @return: Median of the array
 */
int inPlaceMergeSort ( std::vector<int>& nums, int& duration ){
    auto start_time = std::chrono::high_resolution_clock::now();
    // Iterators
    auto start = nums.begin();
    auto mid = nums.begin()+ nums.size() / 2;
    auto end = nums.end(); // Check this later, may be wrong bc of even/odd arr
    auto start2 = mid + 1;

    while ( start <= mid && start2 <= end ){
        if ( *start < *start2 ){
            start++;
        }
        else{
            auto value = *start2;
            auto index = start2;

            while ( index != start ){
                *index = *(index - 1);
                index--;
            }
            *start = value;

            start++;
            mid++;
            start2++;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();    return nums[mid];
};
