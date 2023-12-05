#include <iostream>
#include <fstream>
#include <sstream>
#include<chrono>
#include <vector>

#include "HalfSelectionSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "StandardSort.hpp"
#include "HalfHeapSort.hpp"

int main() {


    std::string filepath = "inputs/input1.txt";

    std::ifstream inputFile(filepath);

   // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Vector to store the numbers
    std::vector<int> numbers;
    int duration = 0;
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


   halfHeapSort(numbers, duration);

    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    return 0;
}