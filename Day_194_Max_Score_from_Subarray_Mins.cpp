#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum sum of two adjacent elements in an array.
// Approach: Iterate through the array and calculate the sum of each pair of adjacent elements, keeping track of the maximum sum encountered.

// Steps:
// 1. Initialize a variable to keep track of the maximum sum.
// 2. Loop through the array from the first element to the second last element.
// 3. For each element, calculate the sum of the current element and the next element.
// 4. If the calculated sum is greater than the current maximum sum, update the maximum sum.
// 5. Return the maximum sum after the loop ends.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1), as we are using a constant amount of space for the maximum sum variable.

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
            count=max(count,arr[i]+arr[i+1]);
        
        return count;
    }
};