#include <bits/stdc++.h>
using namespace std;

// Problem: Given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to the sum of their lengths. We need to connect the ropes with minimum cost.
// Approach: Use a min-heap (priority queue) to always connect the two smallest ropes first, as this will yield the minimum cost.

// Steps:
// 1. Initialize a min-heap and insert all rope lengths into it.
// 2. While there is more than one rope in the heap:
//    - Extract the two smallest ropes from the heap.
//    - Calculate the cost to connect these two ropes.
//    - Add this cost to the total cost.
//    - Insert the combined rope back into the min-heap.
// 3. Return the total cost once all ropes are connected.

// Time Complexity: O(n log n) due to the heap operations for n ropes.
// Space Complexity: O(n) for storing elements in the min-heap.

class Solution {
  public:
   int minCost(vector<int>& arr) {
        int count=0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto it:arr)
        pq.push(it);
        while(pq.size()!=1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int total=first+second;
            pq.push(total);
            count+=total;
        }
        return count;
    }
};