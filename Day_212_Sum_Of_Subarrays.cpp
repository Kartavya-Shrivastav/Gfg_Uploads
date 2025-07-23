#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Calculate the sum of all subarray elements in the array `arr`.
// Approach: For each element, calculate its contribution to the total sum based on its position in the array.

// Steps:
// 1. For each element at index `i`, determine how many subarrays it contributes to.
// 2. The number of subarrays that include the element at index `i` is determined by the number of choices for the left and right boundaries.
// 3. The contribution of the element is its value multiplied by the number of subarrays it appears in.
// 4. Sum up the contributions of all elements to get the total sum of all subarrays.

// Time Complexity: O(n) — where `n` is the size of the array `arr`.
// Space Complexity: O(1) — no additional space is used apart from a few variables.

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int ans = 0 ;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-i;
            ans+= (arr[i]*left*right);
        }
        return ans;
    }
};