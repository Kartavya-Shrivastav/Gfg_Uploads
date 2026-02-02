#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Circular Subarray Sum
// Given a circular array, find the maximum sum of a contiguous subarray.
// Approach: Use Kadane's algorithm to find both the maximum subarray sum and the minimum subarray sum. 

// Steps:
// 1. Calculate the maximum subarray sum using Kadane's algorithm.
// 2. Calculate the minimum subarray sum using a modified Kadane's algorithm.
// 3. Compute the total sum of the array.
// 4. The maximum circular subarray sum will be the maximum of the non-circular maximum subarray sum and the total sum minus the minimum subarray sum.
// 5. Handle the edge case where all elements are negative by returning the maximum subarray sum directly.

// Time Complexity: O(n) since we traverse the array a constant number of times.
// Space Complexity: O(1) as we use a constant amount of extra space.

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
         int n = arr.size();
           int mini = INT_MAX, minsum = 0;
           int maxi = INT_MIN, maxsum = 0;
           int total =0;
           for(int i:arr){
                    total+=i;
                    minsum+=i;
                    maxsum+=i;
                    mini = min(mini, minsum);
                    maxi = max(maxi, maxsum);
                    if(minsum>0){
                         minsum=0;
                    }
                    if(maxsum<0){
                          maxsum=0;
                    }
                    
           }
          if(maxi<0) return maxi;
           
           return max(maxi, total-mini);
    }
};