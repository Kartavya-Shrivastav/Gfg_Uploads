#include <bits/stdc++.h>
using namespace std;

// Problem: Given a nearly sorted array where each element is at most k positions away from its target position, sort the array.
// Approach: Use a min-heap (priority queue) to efficiently sort the nearly sorted array

// Steps:
// 1. Initialize a min-heap and insert the first k+1 elements of the array.
// 2. For each subsequent element in the array, extract the minimum element from the heap and place it in the correct position in the array, 
//    then insert the next element from the array into the heap.
// 3. After processing all elements, extract the remaining elements from the heap and place them in the array.
// 4. The array is now sorted.

// Time Complexity: O(n log k) where n is the number of elements in the array.
// Space Complexity: O(k) for the min-heap.

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        int n = arr.size();
        int j = 0;
        
        for (int i=0; i <= k; i++) {
            pq.push(arr[i]);
        }
        
        for (int i = k+1; i < n; i++) {
            arr[j++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            arr[j++] = pq.top();
            pq.pop();
        }
    }
};

