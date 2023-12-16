#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>

/**
 * Selects the median of three elements (first, middle, last) in the given range.
 * 
 * @param low Iterator pointing to the first element.
 * @param high Iterator pointing to the last element.
 * @post The median of the first, middle, and last elements is moved to the position of 'high'.
 */
void medianOfThree(std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto center = std::distance(low, high) / 2 + low;

    // Swap logic to ensure median of three is at the 'high' position
    if (*low == *high || *low == *center || *center == *high) {
        std::iter_swap(low, high);
    }
    else {
        if ((*low < *center && *center < *high) || (*low > *center && *center > *high)) {
            std::iter_swap(center, high);
        }
        if ((*low < *high && *center < *low) || (*low > *high && *center > *low)) {
            std::iter_swap(low, high);
        } 
    }
}

/**
 * Partitions the array around a pivot element chosen using the medianOfThree strategy.
 * 
 * @param nums The vector of integers to be partitioned.
 * @param low Iterator pointing to the start of the range to partition.
 * @param high Iterator pointing to the end of the range to partition.
 * @return Iterator pointing to the partition pivot.
 * @post Elements are rearranged so that elements less than the pivot come before it, and elements greater come after.
 */
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    medianOfThree(low, high);  // Choose pivot using median of three strategy
    auto pivot = high;
    auto left = low;
    auto right = pivot - 1;

    // Partitioning loop
    while (true) {
        while (*left < *pivot) {
            ++left;
        }
        while (*right > *pivot) {
            --right;
        }
        if (std::distance(left, right) > 0) {
            std::iter_swap(left, right);
            ++left;
            --right;
        } else {
            break;
        }
    }

    std::iter_swap(left, pivot);
    return left;
}

/**
 * Helper function for the Quick Select algorithm. It recursively selects the median element.
 * 
 * @param nums The vector of integers.
 * @param low Iterator pointing to the start of the range.
 * @param high Iterator pointing to the end of the range.
 * @param comp Iterator pointing to the position of the desired element (median).
 * @return The value of the median element.
 * @post The array is partially sorted such that the median is placed in its correct position.
 */
int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator target) {
    if (high <= low + 9) {
        std::sort(low, high + 1);  // Use simple sort for small arrays
        return *target;
    }

    auto pivot = hoarePartition(nums, low, high);

    // Recursive calls to find the median
    if (pivot > target) {
        return quickSelectHelper(nums, low, pivot - 1, target);
    } else if (pivot == target) {
        return *target;
    }
    return quickSelectHelper(nums, pivot + 1, high, target);
}

/**
 * Finds the median of the given vector using the Quick Select algorithm.
 * 
 * @param nums The vector of integers.
 * @param duration Reference to store the duration of the computation.
 * @return The median of the vector.
 * @post The median value of the vector is returned, and the computation duration is recorded.
 */
int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();
    int medianIndex = (std::distance(nums.begin(), nums.end()) % 2 == 0) ? (std::distance(nums.begin(), nums.end()) / 2) : ((std::distance(nums.begin(), nums.end()) / 2) + 1);

    auto comp = nums.begin() + medianIndex - 1;
    int median = quickSelectHelper(nums, nums.begin(), nums.end() - 1, comp);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    duration = static_cast<int>(difference.count() * 1000);
    return median;
}