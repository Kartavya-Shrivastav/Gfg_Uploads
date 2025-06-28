#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Largest in a Stream
// Approach: Use a min-heap (priority queue) to keep track of the k largest elements seen so far.

// Steps:
// 1. Initialize a min-heap to store the k largest elements.
// 2. Iterate through each element in the input array.
// 3. Push the current element into the heap.
// 4. If the size of the heap exceeds k, pop the smallest element (the root of the min-heap).
// 5. If the size of the heap is k, the top of the heap is the kth largest element; otherwise, return -1.
// 6. Store the result after each insertion into the heap.

// Time Complexity: O(n log k), where n is the number of elements in the array.
// Space Complexity: O(k), for storing the k largest elements in the heap.

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                res.push_back(pq.top());
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};