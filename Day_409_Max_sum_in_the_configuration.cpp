#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the maximum sum of i*arr[i] for all possible rotations of the array.
// Approach: First, calculate the total sum of the array and the initial value of i*arr[i] for the original configuration. Then, for each rotation, update the current sum using the formula: currentSum = currentSum + firstElement * n - totalSum, where firstElement is the element that is moved from the front to the back of the array. Keep track of the maximum sum encountered during this process.

// Steps:
// 1. Calculate the total sum of the array and the initial value of i*arr[i] for the original configuration.
// 2. Initialize maxSum with the initial value of i*arr[i].
// 3. For each rotation from 1 to n-1, update the current sum using the formula and compare it with maxSum to keep track of the maximum value.
// 4. Return the maximum sum found after all rotations.

// Time Complexity: O(n) for calculating the total sum and initial value, and O(n) for iterating through the rotations, resulting in O(n) overall.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the variables.

class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
       
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += i * arr[i];
        }
        
        int maxSum = currentSum;
        for (int i = 0; i < n - 1; i++) {
            int firstElement = arr[i];
            currentSum = currentSum + firstElement * n - totalSum;
            
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};