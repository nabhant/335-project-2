#include <iostream>
#include <vector>
#include <chrono>

/**
 * @post sorts half of the heap with the median as the root
 * @param array
 * @param duration
 * @return the median of the array
 */
int halfHeapSort ( std::vector<int>& nums, int& duration ){
   auto start = std::chrono::high_resolution_clock::now();
   nums.push_back(nums[0]);
   buildHeap(nums);
   int mid = nums.size()/2;
   for (int i = nums.size()-1; i >=mid; i--){
      std::swap(nums[0], nums[i]);   // Percolate precondition
      nums.pop_back();  // Delete min
      percDown(nums, 0);
   }
   auto end = std::chrono::high_resolution_clock::now();
   auto difference= std::chrono::duration_cast<std::chrono::microseconds>(end - start);
   duration = difference.count();
   return nums[1];   // Median should be the root
}

   // parameter "hole" is the index of the hole.
   // percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
   // percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ){
   int child;
   int tmp;

   for (tmp = std::move(heap[hole]); hole * 2 + 1 < heap.size(); hole = child){
      child = hole * 2 + 1;
      if (child != heap.size() - 1 && heap[child + 1] < heap[child]){
         child++;
      }
      if (heap[child] < tmp){
         heap[hole] = std::move(heap[child]);
      }
      else{
         break;
      }
   }
   heap[hole] = std::move(tmp);
}


void buildHeap ( std::vector<int>& heap){ 
   // Start from the last non-leaf node and perform percDown on each
    for (std::vector<int>::size_type i = heap.size() / 2 - 1; i >= 0; --i) {
        percDown(heap, i);
    }
}

   