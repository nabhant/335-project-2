#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>

// Helper function to swap the pivot into position
void selectPivot(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto mid = low + (high - low) / 2;
    if (*mid < *low) std::iter_swap(mid, low);
    if (*high < *low) std::iter_swap(high, low);
    if (*high < *mid) std::iter_swap(high, mid);
    std::iter_swap(mid, high); // Move the pivot to the end
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    int pivot = *high;
    auto i = low - 1;
    auto j = high;

    while (true) {
        do { i++; } while (*i < pivot);
        do { j--; } while (*j > pivot);
        if (i >= j) return i;
        std::iter_swap(i, j);
    }
}

int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int k) {
    if (high - low <= 10) {
        std::sort(low, high + 1);
        return *(low + k);
    }

    selectPivot(nums, low, high);
    auto pivotIndex = hoarePartition(nums, low, high - 1);

    int pivotDist = pivotIndex - nums.begin();
    if (pivotDist == k) {
        return *pivotIndex;
    } else if (pivotDist > k) {
        return quickSelectHelper(nums, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelper(nums, pivotIndex, high, k);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    int k = (nums.size() - 1) / 2; // Find the median
    auto start = std::chrono::high_resolution_clock::now();
    int result = quickSelectHelper(nums, nums.begin(), nums.end() - 1, k);
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return result;
}