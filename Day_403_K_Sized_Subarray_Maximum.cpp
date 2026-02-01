#include <bits/stdc++.h>
using namespace std;

// Problem: K-Sized Subarray Maximum
// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
// Approach: Use a deque to maintain indices of useful elements for each window of size k.

// Steps:
// 1. Initialize a deque to store indices of array elements.    
// 2. Iterate through the array, maintaining the deque to ensure it contains indices of elements in decreasing order.
// 3. For each index, remove elements not within the current window and those smaller than the current element.
// 4. The front of the deque will always contain the index of the maximum element for the current window.
// 5. Collect the maximums for each window into a result vector.

// Time Complexity: O(n) since each element is processed at most twice. 
// Space Complexity: O(k) for storing indices in the deque.

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k) 
                dq.pop_front();
            while(!dq.empty() && arr[dq.back()]<=arr[i]) 
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1){
                res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};