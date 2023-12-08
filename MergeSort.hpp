#include <iostream>
#include <vector>
#include <chrono> 
#include <algorithm>

// /**
//     * @post: Sorts the array using MergeSort
//     * @param: Array of integers
//     * @param: Integer to store the duration of the sort
//     * @return: Median of the array
// */
// int mergeSort ( std::vector<int>& nums, int& duration ){
//     auto start = std::chrono::high_resolution_clock::now();
//     int size = nums.size();
//     if ( size == 1 ) {
//         return nums[0];
//     }
//     int mid = size / 2;
//     std::vector<int> left;
//     std::vector<int> right;
//     for (auto it = nums.begin(); it != nums.begin() + mid; it++ ) {
//         left.push_back(*it);
//     }
//     for ( auto it = nums.begin() + mid; it != nums.end(); it++) {
//         right.push_back(*it);
//     }
//     mergeSort(left, duration);
//     mergeSort(right, duration);

//     // Merge the sorted halves
//     auto it_left = left.begin();
//     auto it_right = right.begin();
//     auto it_nums = nums.begin();

//     while (it_left != left.end() && it_right != right.end()) {
//         if (*it_left < *it_right) {
//             *it_nums = *it_left;
//             ++it_left;
//         } else {
//             *it_nums = *it_right;
//             ++it_right;
//         }
//         ++it_nums;
//     }

//     while (it_left != left.end()) {
//         *it_nums = *it_left;
//         ++it_left;
//         ++it_nums;
//     }

//     while (it_right != right.end()) {
//         *it_nums = *it_right;
//         ++it_right;
//         ++it_nums;
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

//     return nums[nums.size()/2]; 
//     }

void mergeRecursiveCall(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int>& sorted) {
    int size = std::distance(begin, end);

    if (size <= 1) {
        sorted = std::vector<int>(begin, end);
        return;
    }

    std::vector<int>::iterator middle = begin + size / 2;
    std::vector<int> sortedLeft, sortedRight;

    mergeRecursiveCall(begin, middle, sortedLeft);
    mergeRecursiveCall(middle, end, sortedRight);

    sorted.clear(); 
    std::merge(sortedLeft.begin(), sortedLeft.end(), sortedRight.begin(), sortedRight.end(), std::back_inserter(sorted));
}


int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> temp(nums.size());
    mergeRecursiveCall(nums.begin(), nums.end(), temp);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

    for (auto x : temp){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    if (temp.size() % 2 == 0 )
    {
        return temp[(temp.size() / 2) -1];
    }else{
        return temp[temp.size() / 2];
    }
}
