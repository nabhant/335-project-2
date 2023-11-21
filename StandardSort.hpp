#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class StandardSort{
    public:
        /**
         * @post: Uses standard sort, and returns the duration of the sort and middle of the array
         * @param: Array of integers
         * @param: Size of the array
         * @return: Duration of the sort
         * @return: Middle of the array
         */
        int standardSort ( std::vector<int>& nums, int& duration );
};

#endif