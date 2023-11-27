#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <iostream>
#include <vector>
#include <chrono> 

class MergeSort{
    public:
        /**
         * @post: Sorts the array using MergeSort
         * @param: Array of integers
         * @param: Integer to store the duration of the sort
         * @return: Median of the array
         */
        int mergeSort ( std::vector<int>& nums, int& duration );
};

#endif