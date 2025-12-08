#include <bits/stdc++.h>
using namespace std;

// Problem: Given a sequence of matrices, find the most efficient way to multiply these matrices together by determining the optimal parenthesization.
// Approach: Dynamic Programming

// Steps:
// 1. Use a DP table where dp[i][j] represents the minimum number of scalar multiplications needed to compute the matrix product from matrix i to matrix j.
// 2. Use a split table to keep track of the index at which the optimal split occurs for matrices i to j.
// 3. Iterate over increasing lengths of matrix chains and compute the minimum cost for each subchain by trying all possible split points.
// 4. After filling the DP and split tables, use a recursive function to construct the optimal parenthesization based on the split points recorded.
// 5. The answer will be the parenthesization string for the full chain from matrix 0 to matrix n-1.

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

class Solution {
    
private:
    string build(int i, int j, vector<vector<int>> &split) {
        if (i == j) return string(1, 'A' + i);
        int k = split[i][j];
        return "(" + build(i, k, split) + build(k + 1, j, split) + ")";
    }
    
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1; 
        vector<vector<long long>> dp(m, vector<long long>(m, 0));
        vector<vector<int>> split(m, vector<int>(m, -1));
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i + len - 1 < m; i++) {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;
                
                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + 1LL * arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }
        
        return build(0, m - 1, split);
    }
};