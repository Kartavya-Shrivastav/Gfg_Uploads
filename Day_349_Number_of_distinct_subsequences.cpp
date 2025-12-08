#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string, find the number of distinct subsequences of the string.
// Approach: Dynamic Programming

// Steps:
// 1. Use a DP array where dp[i] represents the number of distinct subsequences that can be formed using the first i characters of the string.
// 2. For each character in the string, double the number of distinct subsequences from the previous character (since each subsequence can either include or exclude the current character).
// 3. If the current character has appeared before, subtract the number of distinct subsequences that were counted before its last occurrence to avoid double counting.
// 4. Use a last occurrence array to keep track of the last index where each character appeared.
// 5. The answer will be the value in dp[n], where n is the length of the string, modulo 10^9 + 7.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int mod = 1000000007;

    int distinctSubseq(string &str) {
        int n = str.size();
        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;

            int ch = str[i - 1] - 'a';
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + mod) % mod;
            }

            last[ch] = i - 1;
        }

        return dp[n];
    }
};