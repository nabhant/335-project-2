#include <iostream>
#include <vector>
#include <chrono>

    /**
     * @post: Sorts the array until the median, a halfway SelectionSort
     * @param: Array of integers
     * @param: Integer to store the duration of the sort
     * @return: Median of the array
     */
int halfSelectionSort(std::vector<int>& nums, int& duration) {
    int elements_Sorted = 0;
    auto start = std::chrono::high_resolution_clock::now();

    if (nums.size() > 50000) {
        std::cout << "The array is too large to sort.";
    } else {
        for (auto i = nums.begin(); i != nums.end() && elements_Sorted < (nums.size()/2) + (nums.size()%2); ++i) {
            auto min = i; // min is the current minimum element
            for (auto j = i + 1; j != nums.end(); ++j) {
                if (*j < *min) {
                    min = j;
                }
            }
            std::swap(*i, *min);
            elements_Sorted++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    duration = static_cast<int>(difference.count() * 1000); // Convert to milliseconds

    if (nums.size() % 2 == 0) {
        return *std::next(nums.begin(), (nums.size() / 2) - 1);
    } else {
        return *std::next(nums.begin(), nums.size() / 2);
    }
}
