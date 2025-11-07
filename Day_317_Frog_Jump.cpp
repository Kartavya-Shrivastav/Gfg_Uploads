#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of heights where a frog can jump to the next stone or skip one stone, calculate the minimum cost to reach the last stone. The cost of a jump is the absolute difference in heights between the starting and ending stones.
// Approach: Use dynamic programming to calculate the minimum cost to reach each stone, considering both possible jumps (to the next stone or skipping one).

// Steps:
// 1. Initialize a dp array where dp[i] represents the minimum cost to reach stone i.  
// 2. Iterate from the second last stone to the first stone, calculating the cost for both jump options and storing the minimum in dp[i].
// 3. Return dp[0] which contains the minimum cost to reach the last stone from the first stone.

// Time Complexity: O(N) where N is the number of stones.
// Space Complexity: O(N) for the dp array.

class Solution {
  public:
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), 0);
        
        for(int i = height.size()-2;i>=0;i--){
            int a = abs(height[i]-height[i+1]) + dp[i+1];
            int b = INT_MAX;
            if (i + 2 < height.size())
                b = abs(height[i] - height[i + 2]) + dp[i + 2];
            
            dp[i] = min(a,b);
        }
        
        return dp[0];
    }
};