#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


inline int leftChild(int i) {//access to left child
    return 2 * i;
}
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole){
    int size = heap.size();
    int child;
    int temp = heap[0];

    for (int child = leftChild(hole); child < size; hole = child, child = leftChild(hole)) {
        if (child < size - 1 && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[child] < temp) {
            heap[hole] = heap[child];
        } else {
            break;
        }
    }
    heap[hole] = temp;
}

void buildHeap(std::vector<int>& heap) {
    for (int i = (heap.size() - 1) / 2; i > 0; i--) {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    nums.push_back(nums[0]);
    buildHeap(nums);

    int middle = ((nums.end() - nums.begin()) - 2) / 2;  //gets the middle of the vector by splitting the vector in half
    for(int i = 0; i < middle; i++){
      nums[0] = nums[nums.size() - 1];
      nums.pop_back();
      percDown(nums, 1);
   }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    duration = static_cast<int>(diff.count() * 1000);

    return nums[1];
}
