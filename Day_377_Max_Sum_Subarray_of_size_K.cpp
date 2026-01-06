#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, find the maximum sum of a subarray of size k.    
// Approach: Sliding Window

// Steps:
// 1. Calculate the sum of the first 'k' elements
// 2. Use a sliding window approach to maintain a window of size k
// 3. Update the sum by adding the new element and removing the element going out of the window
// 4. Keep track of the maximum sum found so far
// 5. Return the maximum sum found

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = accumulate(arr.begin(),arr.begin()+k,0);
        int maxSum = sum;
        for(int i = k; i < arr.size(); i++){
            sum += arr[i] - arr[i-k];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};