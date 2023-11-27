#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <iostream>
#include <vector>
#include <chrono>


class InPlaceMergeSort{
public:
    /**
     * @post: Sorts the array using InPlaceMergeSort
     * @param: Array of integers
     * @param: Integer to store the duration of the sort
     * @return: Median of the array
     */
    int inPlaceMergeSort ( std::vector<int>& nums, int& duration );
};

#endif