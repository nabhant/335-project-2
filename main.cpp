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
#include "WorstCaseQuickSelect.hpp"

int main() {
    std::string filepath = "inputs/input9.txt";

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

    std::vector<int> WorstCaseQuickSelect = worstCaseQuickSelect();
    int median = quickSelect(WorstCaseQuickSelect, duration);

    std::cout<<"************************************************************************************************"<<std::endl;
    // Print the results
    std::cout << "Median: " << median << std::endl;
    std::cout << "Duration: " << duration << " milliseconds" << std::endl;

    return 0;
}
