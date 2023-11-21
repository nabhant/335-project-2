#include "HalfSelectionSort.hpp"

/**
     * @post: Sorts the array until the median, a halfway SelectionSort
     * @param: Array of integers
     * @param: Size of the array
     * @return: Median of the array
     */
    int halfSelectionSort ( std::vector<int>& nums, int& duration){
        if (nums.size() > 50000){
            std::cout <<"Input too large for selection sort"<<std::endl;
        }
        else if (nums.size() <= 1){
            std::cout <<"Input too small for selection sort"<<std::endl;
        }
        int i = 0, j = 0, min = 0, median = 0;

        if (nums.size() % 2 == 0){
            median = nums.size() / 2;
        }
        else{
            median = (nums.size() / 2) + 1;
        }
        auto start = std::chrono::high_resolution_clock::now();
        auto median_it = nums.begin() + median;
        for (auto it = nums.begin(); it != median_it; ++it) {
            auto min_it = it;
            for (auto it2 = it + 1; it2 != nums.end(); ++it2) {
                if (*it2 < *min_it) {
                    min_it = it2;
                }
            }
            if (min_it != it) {
                std::swap(*it, *min_it);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        return nums[nums.size()/2];
    }
