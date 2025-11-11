#include <bits/stdc++.h>
using namespace std;

// Problem: Given an n x n matrix 'mat' where each cell contains a certain number of chocolates or -1 (indicating a blocked cell), two players start from the top-left corner (0,0) and move to the bottom-right corner (n-1,n-1). Both players can only move down or right at any point in time. The goal is to maximize the total number of chocolates collected by both players, ensuring that if both players land on the same cell, the chocolates from that cell are only counted once.
// Approach: 

// Steps:
// 1. Use a 3D dynamic programming (DP) array to keep track of the maximum chocolates collected when both players have taken 'k' steps and are at positions (i1, j1) and (i2, j2).
// 2. Iterate through all possible steps 'k' from 0 to 2*(n-1).
// 3. For each step 'k', iterate through all possible positions (i1, j1) and (i2, j2) that the two players can occupy.
// 4. For each position, check all possible previous positions from which the players could have arrived (either from the left or from above).
// 5. Update the DP array with the maximum chocolates collected, ensuring to account for the case where both players land on the same cell.
// 6. The final answer will be found in dp[2*(n-1)][n-1][n-1], which represents both players reaching the bottom-right corner.

// Time complexity is O(n^3) 
// Space complexity is O(n^3).

class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size();
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
            return 0;

        // 3D DP: dp[k][i1][i2] = max chocolates collected when
        // both paths take k steps and are at (i1, j1) and (i2, j2) respectively.
        vector<vector<vector<int>>> dp(2 * n - 1, 
            vector<vector<int>>(n, vector<int>(n, -1e9)));

        dp[0][0][0] = mat[0][0];  // starting cell

        for (int k = 1; k < 2 * n - 1; k++) {
            for (int i1 = 0; i1 < n; i1++) {
                for (int i2 = 0; i2 < n; i2++) {
                    int j1 = k - i1;
                    int j2 = k - i2;

                    // Check valid positions
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) continue;
                    if (mat[i1][j1] == -1 || mat[i2][j2] == -1) continue;

                    // Collect current chocolates
                    int chocolates = mat[i1][j1];
                    if (i1 != i2) chocolates += mat[i2][j2];

                    int bestPrev = -1e9;

                    // 4 possible transitions (both move down or right)
                    if (i1 > 0 && i2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1 - 1][i2 - 1]);
                    if (i1 > 0 && j2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1 - 1][i2]);
                    if (j1 > 0 && i2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1][i2 - 1]);
                    if (j1 > 0 && j2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1][i2]);

                    // Update DP if a valid path exists
                    if (bestPrev != -1e9)
                        dp[k][i1][i2] = bestPrev + chocolates;
                }
            }
        }

        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};