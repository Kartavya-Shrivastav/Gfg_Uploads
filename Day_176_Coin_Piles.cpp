#include <bits/stdc++.h>
using namespace std;

// Problem: 
// Given an array of integers representing coin piles, find the minimum number of coins needed to make all piles equal to a target value k.
// The target value k is the maximum value that any pile can have after redistribution.
// The function should return the minimum number of coins needed to achieve this.

// Approach:
// 1. Sort the array of coin piles. 
// 2. Use a prefix sum array to calculate the total coins in piles up to each index.
// 3. For each pile, find the upper bound of piles that can be increased to
//    the target value k.
// 4. Calculate the number of coins needed to make all piles equal to k.


class Solution {
    public:
        int minimumCoins(vector<int>& arr, int k) {
                // Get the number of piles
                int n = arr.size();
                // Prefix sum array to store sum up to each index
                vector<int> prefix(n,0);
                // Sort the piles for easier processing
                sort(arr.begin(), arr.end());
                // Compute prefix sums
                partial_sum(arr.begin(), arr.end(), prefix.begin());
                int ans = INT_MAX;
                int prev = 0;
                // Iterate through each pile as a potential base
                for(int i = 0; i < n; i++)
                {
                        // Find the first pile greater than arr[i] + k
                        int index = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
                        // Update prev to sum of coins before i if arr[i] is different from previous
                        if(i > 0 && (arr[i] != arr[i-1]))
                                prev = prefix[i-1];
                        // Calculate coins needed:
                        // prev: coins to remove from piles before i
                        // (prefix[n-1] - prefix[index-1]): coins in piles to be reduced
                        // (n-index) * (arr[i] + k): target coins for piles after index
                        int x = prev + (prefix[n-1] - prefix[index-1]) - (n-index) * (arr[i] + k);
                        // Update answer with minimum coins needed
                        ans = min(ans, x);
                }
                return ans;
        }
};