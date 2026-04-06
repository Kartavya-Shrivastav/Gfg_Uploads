#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a grid of size n x m where each cell contains a certain number of chocolates, two players start at the top row of the grid. Player 1 starts at the leftmost column (0) and Player 2 starts at the rightmost column (m-1). Both players can move down to the next row and can also move left, right, or stay in the same column. The goal is to maximize the total number of chocolates collected by both players. The players can collect chocolates from the same cell only once.
Approach: This problem can be solved using dynamic programming. We will use a 2D DP array where dp[c1][c2] represents the maximum chocolates collected when Player 1 is at column c1 and Player 2 is at column c2 in the current row. We will iterate from the bottom row to the top row, updating our DP array based on the possible moves of both players.

Steps:
1. Initialize a 2D DP array of size m x m to store the maximum chocolates collected for each combination of columns for Player 1 and Player 2.
2. Start iterating from the last row to the first row:
    a. For each combination of columns (c1, c2) for Player 1 and Player 2:
        i. Initialize the current DP value to a very small number (e.g., -1e9) to represent an invalid state.
        ii. For each possible move of Player 1 (u = -1, 0, 1) and Player 2 (v = -1, 0, 1):
            - Check if the new positions (c1 + u, c2 + v) are within bounds.
            - If valid, calculate the chocolates collected in the current row for both players and add it to the DP value from the next row (next[c1 + u][c2 + v]).
            - Update the current DP value with the maximum chocolates collected.
3. After processing all rows, the answer will be in dp[0][m-1], which represents both players starting at their initial positions.

Time Complexity: O(n * m^2 * 9) = O(n * m^2) since we are iterating through n rows, m columns for Player 1, m columns for Player 2, and 9 possible moves for both players.
Space Complexity: O(m^2) for the DP array, as we only need to store the current and next row's DP values. We can optimize space by using two 2D arrays and swapping them after each row is processed. Overall, the space complexity is O(m^2).

*/

class Solution {
  public:
    int maxChocolate(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(m, 0)), next(m, vector<int>(m, 0));
        for(int r = n - 1; r >= 0; r--) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = 0; c2 < m; c2++) {
                    curr[c1][c2] = -1e9;
                    for(int u = -1; u <= 1; u++) {
                        for(int v = -1; v <= 1; v++) {
                            if(c1 + u < 0 || c1 + u >= m || c2 + v < 0 || c2 + v >= m) continue;
                            curr[c1][c2] = max(curr[c1][c2], grid[r][c1] + ((c1 == c2) ? 0 : grid[r][c2]) + next[c1 + u][c2 + v]);
                        }
                    }
                }
            }
            next = curr;
        }
        return next[0][m - 1];
    }
};