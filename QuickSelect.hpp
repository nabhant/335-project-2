#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>

// Helper function to find the median of three numbers
std::vector<int>::iterator medianOfThree(std::vector<int>::iterator a, std::vector<int>::iterator b, std::vector<int>::iterator c) {
    if (*a < *b) {
        if (*b < *c)
            return b;
        else if (*a < *c)
            return c;
        else
            return a;
    } else {
        if (*a < *c)
            return a;
        else if (*b < *c)
            return c;
        else
            return b;
    }
}

// Hoare partition scheme
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *high;
    auto i = low - 1;
    auto j = high + 1;

    while (true) {
        do {
            ++i;
        } while (*i < pivot);

        do {
            --j;
        } while (*j > pivot);

        if (i >= j)
            return j;

        std::iter_swap(i, j);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    int k = nums.size() / 2;
    auto low = nums.begin();
    auto high = nums.end() - 1;

    while (true) {
        if (std::distance(low, high) <= 10) {
            std::sort(low, high + 1);
            auto end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            return *(low + k);
        }

        auto mid = low + std::distance(low, high) / 2;
        auto pivotIter = medianOfThree(low, mid, high);
        std::iter_swap(pivotIter, high);

        auto pivotIndex = hoarePartition(nums, low, high);

        if (k < std::distance(low, pivotIndex)) {
            high = pivotIndex;
        } else if (k > std::distance(low, pivotIndex)) {
            low = pivotIndex + 1;
        } else {
            auto end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            return *pivotIndex;
        }
    }
}
