#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


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
    auto start = std::chrono::high_resolution_clock::now(); 

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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    duration = static_cast<int>(difference.count() * 1000);
    // Median is at the root of the remaining heap
    int median = nums[0];
    return median;
}