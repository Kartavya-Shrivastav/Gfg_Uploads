#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given three integers m, n and x, where m is the number of faces on a dice, n is the number of dice thrown and x is the desired sum. The task is to find the number of ways to get the sum x with n dice each having m faces.
Approach: We can use dynamic programming to solve this problem. We create a 2D array dp where dp[i][j] represents the number of ways to get the sum j with i dice. We initialize dp[0][0] = 1, which means there is one way to get a sum of 0 with 0 dice (by not throwing any dice). We then fill the dp array using the relation that for each die, we can choose any face from 1 to m and add it to the sum obtained from the previous dice. Finally, the answer will be in dp[n][x].

Steps:
1. Initialize a 2D vector dp of size (n+1) x (x+1) with all values set to 0.
2. Set dp[0][0] = 1, as there is one way to get a sum of 0 with 0 dice.
3. Use three nested loops to fill the dp array:
   - The outer loop runs from 1 to n (inclusive) for the number of dice.
   - The middle loop runs from 1 to x (inclusive) for the desired sum.
   - The innermost loop runs from 1 to m (inclusive) for the faces of the dice.
   - For each combination of i, j, and k, if j-k is non-negative, we add dp[i-1][j-k] to dp[i][j].
4. Return dp[n][x] as the final answer. 

Time Complexity: O(n * x * m) where n is the number of dice, x is the desired sum and m is the number of faces on the dice.
Space Complexity: O(n * x) for the dp array.

*/

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= x; j++) {
                for(int k = 1; k <= m; k++) {
                    if(j - k >= 0)
                        dp[i][j] += dp[i-1][j-k];
                }
            }
        }

        return dp[n][x];
    }
};