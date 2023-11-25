#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>

class HalfSelectionSort{
public:
    /**
     * @post: Sorts the array until the median, a halfway SelectionSort
     * @param: Array of integers
     * @param: Size of the array
     * @return: Median of the array
     */
    int halfSelectionSort ( std::vector<int>& nums, int& duration );

};
#endif