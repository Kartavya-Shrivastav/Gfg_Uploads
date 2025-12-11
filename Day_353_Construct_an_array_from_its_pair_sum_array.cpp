#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array `arr` of size `n*(n-1)/2` representing the pair sums of an original array of size `n`, reconstruct the original array.
// Approach: Mathematical Derivation

// Steps:
// 1. Calculate the size `n` of the original array using the formula derived from the size of the pair sum array.
// 2. Use the first two pair sums and the last pair sum to derive the first element of the original array.
// 3. Use the first element to calculate the remaining elements of the original array by subtracting it from the corresponding pair sums.
// 4. Return the reconstructed original array.

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int n = (int)(sqrt(arr.size()*2)) + 1;
        vector<int> res(n);
        
        res[0] = (arr[0] + arr[1] - arr[n-1]) / 2;
        
        for(int i=1;i<n;i++)
        res[i] = arr[i-1] - res[0];
        
        return res;
    }
};