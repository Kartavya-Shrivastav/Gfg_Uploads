#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array arr of size n and an integer k, find the maximum for each and every contiguous subarray of size k.    
// Approach: Sliding Window with Tracking Maximum   

// Steps:
// 1. Initialize a pair to keep track of the current maximum value and its index within the window
// 2. Iterate through the array using a single loop 
// 3. For each element, check if the current maximum is still within the bounds of the current window
// 4. If the current maximum is out of bounds, recalculate the maximum for the new window
// 5. Update the current maximum if the new element is greater than the current maximum
// 6. Once the first window is fully traversed, start adding the maximums to the result vector for each window
// 7. Return the result vector containing maximums for all windows of size k

// Time Complexity: O(n*k) in the worst case where n is the size of the array and k is the size of the subarray
// Space Complexity: O(1) since we are using only a fixed amount of extra space

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        pair<int, int> mx = {INT_MIN, 0};
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(i>k-1 && mx.second <= i-k){
                mx = {INT_MIN, 0};
                for(int j=i-k+1;j<i;j++){
                    mx = max(mx, {arr[j], j});
                }
            }
            mx = max(mx, {arr[i], i});
            if(i>=k-1)
                ans.push_back(mx.first);
        }
        return ans;
    }
};