#include <bits/stdc++.h>
using namespace std;

/*
This code defines a Solution class with a method to find the number of unique paths in a grid from the top-left corner to the bottom-right corner, avoiding obstacles.
The method uses recursion with memoization to explore all possible paths, counting only those that reach the destination without hitting an obstacle.
*/

class Solution {
    public:
        // Recursive helper function to count unique paths from (i, j) to bottom-right, with memoization
        int solve(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
                // If out of bounds or on an obstacle, no path
                if (i >= n || j >= m || grid[i][j])
                        return 0;
                
                // If reached destination, count as one path
                if (i == n - 1 && j == m - 1)
                        return 1;
                
                // If already computed, return cached result
                if (dp[i][j] != -1)
                        return dp[i][j];
                
                // Move right and down
                int right = solve(n, m, i, j + 1, grid, dp);
                int down = solve(n, m, i + 1, j, grid, dp);
                
                // Store and return total paths from (i, j)
                return dp[i][j] = right + down;
        }

        // Main function to initiate the path count
        int uniquePaths(vector<vector<int>> &grid){
                int n = grid.size();
                int m = grid[0].size();
                // Initialize memoization table with -1
                vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
                // Start from top-left corner
                return solve(n, m, 0, 0, grid, dp);
        }
};