#include <iostream>
#include <vector>
#include <chrono>

    /**
     * @post: Sorts the array until the median, a halfway SelectionSort
     * @param: Array of integers
     * @param: Integer to store the duration of the sort
     * @return: Median of the array
     */
    int halfSelectionSort ( std::vector<int>& nums, int& duration )
    {
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
        std::chrono::duration<double> difference = end - start;
        duration = static_cast<int>(difference.count() * 1000);
        return nums[nums.size()/2];
    }
