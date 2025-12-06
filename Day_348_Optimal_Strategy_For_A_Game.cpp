#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers representing the values of coins arranged in a line, two players take turns picking a coin from either end of the line. The goal is to determine the maximum amount of money the first player can collect if both players play optimally.
// Approach: Dynamic Programming

// Steps:
// 1. Define a 2D DP table where dp[i][j] represents the maximum amount of money the first player can collect from the subarray arr[i...j].
// 2. Use a gap strategy to fill the DP table, where gap represents the distance between the start and end indices of the subarray.
// 3. For each subarray defined by indices i and j, calculate the maximum amount the first player can collect by considering both choices (picking the leftmost or rightmost coin) and accounting for the optimal responses of the second player.
// 4. Return the value in dp[0][n-1] which represents the maximum amount the first player can collect from the entire array.

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int gap = 0; gap < n; gap++){
            for(int i = 0 ; i+gap < n; i++){
                int j = i+ gap;
                int x = (i + 2 <= j) ? dp[i+ 2][j] : 0;
                int y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                int z = (i <= j - 2) ? dp[i][j - 2] : 0;
            
                dp[i][j] = max(
                    arr[i] + min(x, y),   // pick i
                    arr[j] + min(y, z)    // pick j
                );
            }
            
        }
        return dp[0][n - 1];
    }
};