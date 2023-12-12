#include <iostream>
#include <fstream>
#include <sstream>
#include<chrono>
#include <vector>
#include <algorithm>
#include <cmath>

#include "HalfSelectionSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "StandardSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"

int main() {
    std::string filepath = "inputs/input4.txt";

    std::ifstream inputFile(filepath);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Vector to store the numbers
    std::vector<int> numbers;

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Use a stringstream to parse the numbers from the line
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            // Add the number to the vector
            numbers.push_back(num);
        }
    }

    // Close the file
    inputFile.close();

    // Check if numbers were read successfully
    if (numbers.empty()) {
        std::cerr << "No numbers found in the file!" << std::endl;
        return 1;
    }

    int duration = 0;

    // Call quickSelect function
    int median = halfSelectionSort(numbers, duration);

    std::cout<<"************************************************************************************************"<<std::endl;
    // Print the results
    std::cout << "Median: " << median << std::endl;
    std::cout << "Duration: " << duration << " microseconds" << std::endl;


    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    

    // int duration1 = 0, duration2 = 0;
    // std::vector<int> nums = {3, 1, 2, 4, 5, 7, 7, 6, 9};    // Expected output 1 2 3 4 5 6 7 7 9, median = 5
    // std::vector<int> nums2 = {10, 7, 3, 2, 5, 6, 8, 4, 9, 1}; // Expected output 1 2 3 4 5 6 7 8 9 10, median = 5

    
    // int median1 = inPlaceMergeSort(nums, duration1);

    // std::cout << "Sorted Array 1: ";
    // for (int num : nums) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Median 1: " << median1 << std::endl;
    // std::cout << "Duration 1: " << duration1 << " microseconds" << std::endl;

    return 0;
}
