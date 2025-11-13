#include <bits/stdc++.h>
using namespace std;

// Problem: Given three strings s1, s2, and s3, determine if s3 is formed by an interleaving of s1 and s2.
// Approach: Use recursion with memoization to check if s3 can be formed by interleaving s1 and s2.

// Steps:
// 1. Define a recursive function that takes the current indices of s1, s2, and s3.
// 2. If the sum of the lengths of s1 and s2 does not equal the length of s3, return false.
// 3. If both indices of s1 and s2 reach their ends, return true.
// 4. Check if the current character of s3 matches the current character of s1 or s2.
// 5. If it matches s1, recursively check the next character in s1 and s3.
// 6. If it matches s2, recursively check the next character in s2 and s3.
// 7. Use a DP table to store results of subproblems to avoid redundant calculations.
// 8. The final answer is whether s3 can be formed by interleaving s1 and s2 starting from indices 0 of both strings.

// Time complexity is O(m*n)
// Space complexity is O(m*n)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }

private:
    bool dfs(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {
        if (i == s1.size() && j == s2.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        int k = i + j;
        bool ans = false;

        if (i < s1.size() && s1[i] == s3[k])
            ans = dfs(s1, s2, s3, i + 1, j, dp);
        if (!ans && j < s2.size() && s2[j] == s3[k])
            ans = dfs(s1, s2, s3, i, j + 1, dp);

        return dp[i][j] = ans;
    }
};