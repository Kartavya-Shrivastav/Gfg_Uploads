#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the maximum product of a contiguous subarray.
// Approach: We can use two variables, pref and suff, to keep track of the product of the elements from the left and right ends of the array, respectively. We iterate through the array, updating these products and keeping track of the maximum product encountered. If either product becomes zero, we reset it to 1 to start a new subarray.

// Steps:
// 1. Initialize ans to the smallest integer value, and pref and suff to 1.
// 2. Iterate through the array from both ends simultaneously, updating pref and suff with the product of the current elements.
// 3. Update ans with the maximum of ans, pref, and suff.
// 4. If pref or suff becomes zero, reset it to 1 to start a new subarray.
// 5. Return the maximum product found after iterating through the array.

// Time Complexity: O(n) for iterating through the array once.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the variables.

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size() , ans = INT_MIN;
        int pref = 1 , suff = 1;
        for(int i = 0; i < n; i++){
            pref *= arr[i];
            suff *= arr[n - i - 1];
            ans = max({ans , pref , suff});
            if(pref == 0)
                pref = 1;
            if(suff == 0)
                suff = 1;
        }
        return ans;
    }
};