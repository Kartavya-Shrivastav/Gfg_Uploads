#include <bits/stdc++.h>
using namespace std;

// Problem: Given a matrix where each cell contains a certain number of coins, find the number of unique paths from the top-left corner to the bottom-right corner such that the total number of coins collected along the path equals k. You can only move either down or right at any point in time.
// Approach: Use dynamic programming to keep track of the number of ways to reach each cell with a specific number of coins collected.

// Steps:
// 1. Initialize a 3D DP array where dp[i][j][c] represents the number of ways to reach cell (i, j) with c coins.
// 2. Set the base case dp[0][0][mat[0][0]] = 1.
// 3. Iterate through each cell in the matrix.
// 4. For each cell, update the DP array for the cells directly below and to the right, adding the current cell's coin value.
// 5. The answer will be found in dp[n-1][m-1][k].

// Time Complexity: O(n * m * k) where n and m are the dimensions of the matrix and k is the target number of coins.
// Space Complexity: O(n * m * k) for the DP array.

class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        dp[0][0][mat[0][0]] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int coins = 0; coins <= k; coins++) {
                    if (dp[i][j][coins] > 0) {
                        if (i + 1 < n && coins + mat[i + 1][j] <= k)
                            dp[i + 1][j][coins + mat[i + 1][j]] += dp[i][j][coins];
                        if (j + 1 < m && coins + mat[i][j + 1] <= k)
                            dp[i][j + 1][coins + mat[i][j + 1]] += dp[i][j][coins];
                    }
                }
            }
        }
        
        return dp[n - 1][m - 1][k];
    }
};