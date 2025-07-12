#include <bits/stdc++.h>
using namespace std;

// Problem: Given a grid representing a gold mine, find the maximum amount of gold that can be collected by moving from the leftmost column to the rightmost column.
// Approach: Use dynamic programming to explore all possible paths and calculate the maximum gold collected.

// Steps:
// 1. Define a recursive function that explores all possible paths from the current cell to the right.
// 2. Use memoization to store results of previously computed states to avoid redundant calculations.
// 3. Iterate through each row in the first column and call the recursive function to find the maximum gold.
// 4. Return the maximum gold collected.

// Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the grid.
// Space Complexity: O(n * m) for the memoization table.

class Solution {
    int n , m ; 
    int f(vector<vector<int>> & grid , vector<vector<int>> & dp , int i , int j){
        if(i >= n || j < 0 || j >= m || i < 0){
            return 0 ; 
        }
        if(dp[i][j] != -1) return dp[i][j] ; 
        return dp[i][j] = grid[i][j] + max({f(grid, dp , i+1 , j+1), f(grid , dp , i , j+1) , f(grid , dp , i-1 , j+1)});
    }
  public:
    int maxGold(vector<vector<int>>& mat) {
        n = mat.size() , m = mat[0].size() ; 
        int res = 0 ; 
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1)) ; 
        for(int i = 0 ; i < n ; i++){
            res = max(res , f(mat ,dp , i , 0)) ; 
        }
        return res; 
    }
};