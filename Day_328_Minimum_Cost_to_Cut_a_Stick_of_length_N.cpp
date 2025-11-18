#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Cost to Cut a Stick of length N
// Approach: Dynamic Programming

// Steps:
// 1. Add the boundaries (0 and N) to the cuts array and sort it
// 2. Use a DP table to store minimum cost for each interval
// 3. Iterate over intervals of increasing length
// 4. Calculate cost for each possible cut within the interval
// 5. Return the minimum cost for the entire stick

// Time Complexity: O(m^3) where m is the number of cuts
// Space Complexity: O(m^2)

class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        
        // Add boundaries 0 and n
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        // DP table
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        // len = length of interval
        for (int len = 2; len < m + 2; len++) {
            for (int i = 0; i + len < m + 2; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][m + 1];
    }
};