#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integers n and k, return the number of ways to paint a fence with n posts using k different colors such that no more than two adjacent fence posts have the same color.
Approach: We can use dynamic programming to solve this problem. We can define a recursive function that takes the current index of the fence post, the total number of posts, the number of colors, the color of the previous post, and the count of how many times the previous color has been used consecutively. The base case would be when we have painted all n posts, in which case we return 1 as a valid way to paint the fence. For each post, we can iterate through all k colors and check if we can use that color based on the previous color and count. If we can use it, we recursively call the function for the next post with updated parameters.

Steps:
1. Define a recursive function that takes the current index, total posts, number of colors, previous color, count of consecutive colors, and a memoization table.
2. If the current index is greater than n, return 1 as we have successfully painted all posts.
3. If the result for the current index and count is already computed in the memoization table, return that value.
4. Initialize an answer variable to 0.
5. Iterate through all colors from 1 to k:
   - If the current color is the same as the previous color and the count is 2, skip this color as it would violate the condition of no more than two adjacent posts having the same color.
   - If the current color is the same as the previous color and the count is 1, recursively call the function for the next index with count set to 2.
   - If the current color is different from the previous color, recursively call the function for the next index with count set to 1.
6. Store the computed answer in the memoization table and return it.

Time Complexity: O(n*k) - We are iterating through n posts and for each post, we are iterating through k colors.
Space Complexity: O(n) - We are using a 2D vector for memoization which has a size of n x 3 (for count of consecutive colors).
*/  

class Solution {
  public:
    virtual int fun(int i, int n, int k, int col, int count, vector<vector<int>> &dp){
      if(i>n) return 1;
      if(dp[i][count] != -1) return dp[i][count];
      
      int ans=0;
      for(int j=1; j<=k; j++){
        if(col==j && count==2) continue;  
        if(col==j && count==1) ans+=fun(i+1, n, k, j, 2, dp);
        else ans+=fun(i+1, n, k, j, 1, dp);
      }
      return dp[i][count]=ans;
    }
    
    virtual int countWays(int n, int k){
      vector<vector<int>> dp(n+1, vector<int>(3, -1));
      return fun(1, n, k, 0, 0, dp);
    }
};