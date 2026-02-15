#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers a and an integer m, where m is less than or equal to the size of the array, find the minimum difference between the maximum and minimum values among any m elements of the array.
// Approach: We can sort the array and then find the minimum difference between the maximum and minimum values among any m elements by iterating through the sorted array and calculating the difference between the element at index i and the element at index i-m+1 for all valid indices i. The minimum of these differences will be the answer.

// Steps:
// 1. Sort the array a.
// 2. Initialize a variable mini to a large value (e.g., 1e9) to store the minimum difference.
// 3. Iterate through the sorted array starting from index m-1 to n-1, and for each index i, calculate the difference between a[i] and a[i-m+1] and update mini if this difference is smaller than the current value of mini.
// 4. Return the value of mini as the result.

// Time Complexity: O(n log n) - due to sorting the array. The iteration through the array takes O(n).
// Space Complexity: O(1) - We are using a constant amount of space for variables

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size();
        sort(a.begin(), a.end());
        
        int mini=1e9;
        
        for(int i=m-1; i<n; i++){
            mini=min(mini, a[i]-a[i-m+1]);
        }
        
        return mini;
    }
};