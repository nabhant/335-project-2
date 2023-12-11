#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


// /**
//  * @post sorts half of the heap with the median as the root
//  * @param array
//  * @param duration
//  * @return the median of the array
//  */
// int halfHeapSort ( std::vector<int>& nums, int& duration ){
//    auto start = std::chrono::high_resolution_clock::now();
//    nums.push_back(nums[0]);
//    buildHeap(nums);
//    int mid = nums.size()/2;
//    for (int i = nums.size()-1; i >=mid; i--){
//       std::swap(nums[0], nums[i]);   // Percolate precondition
//       nums.pop_back();  // Delete min
//       percDown(nums, 0);
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//    auto difference= std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//    duration = difference.count();
//    return nums[1];   // Median should be the root
// }

//    // parameter "hole" is the index of the hole.
//    // percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
//    // percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
// void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ){
//    int child;
//    int tmp;

//    for (tmp = std::move(heap[hole]); hole * 2 + 1 < heap.size(); hole = child){
//       child = hole * 2 + 1;
//       if (child != heap.size() - 1 && heap[child + 1] < heap[child]){
//          child++;
//       }
//       if (heap[child] < tmp){
//          heap[hole] = std::move(heap[child]);
//       }
//       else{
//          break;
//       }
//    }
//    heap[hole] = std::move(tmp);
// }


// void buildHeap ( std::vector<int>& heap){ 
//    // Start from the last non-leaf node and perform percDown on each
//     for (std::vector<int>::size_type i = heap.size() / 2 - 1; i >= 0; --i) {
//         percDown(heap, i);
//     }
// }

// void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
//     int child;
//     int tmp = std::move(heap[hole]);

//     for (; hole * 2 + 1 < heap.size(); hole = child) {
//         child = hole * 2 + 1;
//         if (child != heap.size() - 1 && heap[child + 1] < heap[child]) {
//             child++;
//         }
//         if (heap[child] < tmp) {
//             heap[hole] = std::move(heap[child]);
//         } else {
//             break;
//         }
//     }
//     heap[hole] = std::move(tmp);
// }

// void buildHeap(std::vector<int>& heap) {
//     // Start from the last non-leaf node and perform percDown on each
//     for (std::vector<int>::size_type i = heap.size() / 2 - 1; i >= 0; --i) {
//         percDown(heap, i);
//     }
// }

// void printHeap(const std::vector<int>& heap) {
//     // Calculate the height of the heap
//     int height = static_cast<int>(std::log2(heap.size() + 1));

//     // Counter for the number of nodes printed
//     int nodesPrinted = 0;

//     // Iterate through each level of the heap
//     for (int level = 0; level <= height; ++level) {
//         // Calculate the number of nodes at the current level
//         int nodesAtLevel = std::pow(2, level);

//         // Print spaces to align nodes
//         int spaces = std::pow(2, height - level) - 1;
//         std::cout << std::string(spaces, ' ');

//         // Print nodes at the current level
//         for (int i = 0; i < nodesAtLevel && nodesPrinted < heap.size(); ++i) {
//             std::cout << heap[nodesPrinted++] << " ";
//         }

//         // Move to the next line
//         std::cout << std::endl;
//     }
// }

// int halfHeapSort(std::vector<int>& nums, int& duration) {
//     auto start = std::chrono::high_resolution_clock::now();

//     // Move the first element to the back of the vector
//     nums.push_back(std::move(nums[0]));

//     // Build the heap
//     buildHeap(nums);

//     // Remove n/2 elements from the heap
//     for (std::vector<int>::size_type i = nums.size() / 2; i < nums.size() - 1; ++i) {
//         std::swap(nums[0], nums[i]);
//         percDown(nums, 0);
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     auto difference = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     duration = difference.count();


//     printHeap(nums);
//     return nums[0];  // Median should be at the root of the remaining heap
// }

void percDown(std::vector<int>& heap, int hole, int size){
    int temp = std::move(heap[hole]);

    // Perc down
    while (hole * 2 + 1 < size)
    {
        // Left child
        int child = hole * 2 + 1;

        // Right child
        if (child != size - 1 && heap[child] > heap[child + 1])
        {
            ++child; // Right child if larger
        }

        // Swap if child is smaller than temp
        if (heap[child] < temp)
        {
            heap[hole] = std::move(heap[child]);
            hole = child;
        }

        else
        {
            break;
        }
    }

    // Insert temp into the hole
    heap[hole] = std::move(temp);
}

void buildHeap(std::vector<int>& heap){
    int size = heap.size();

    // Build the heap
    for (int i = (size - 2) / 2; i >= 0; --i)
    {
        percDown(heap, i, size);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration){
    auto start_time = std::chrono::high_resolution_clock::now(); 

    // Move the first element to the end
    nums.push_back(std::move(nums[0]));
    nums.erase(nums.begin());

    // Perform partial heapsort to get bottom n/2 elements in ascending order
    buildHeap(nums);

    int size = nums.size(); 

    // Delete the bottom n/2 elements
    while (size > (nums.size() / 2 + 1))
    {
        std::swap(nums[0], nums[size - 1]);
        --size;
        percDown(nums, 0, size);
    }

    // Resize the vector to half its original size
    nums.resize(nums.size() / 2 + 1);
    auto end_time = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // Median is at the root of the remaining heap
    int median = nums[0];
    return median;
}