#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>


std::vector<int> worstCaseQuickSelect (void){
    std::vector<int> nums;
    for (int i = 20000; i >=1; i--){
        nums.push_back(i);
    }
    return nums;
}
  // worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.