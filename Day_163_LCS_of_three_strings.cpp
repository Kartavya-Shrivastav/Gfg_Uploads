#include <bits/stdc++.h>
using namespace std;
// This code defines a Solution class with a method to find the length of the longest common subsequence among three strings.


#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

// Solution class to find the length of the longest common subsequence among three strings
class Solution {
public:
    // Function to compute LCS of three strings
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n = s1.length(), m = s2.length(), o = s3.length();
        
        // Initialize a 3D DP table with dimensions (n+1) x (m+1) x (o+1), filled with 0s
        vvvi dp(n + 1, vvi(m + 1, vi(o + 1, 0)));
        
        // Iterate through all characters of s1, s2, and s3
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= o; ++k) {
                    
                    // If all three characters match, increment the LCS length by 1
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    } 
                    // Otherwise, take the maximum LCS length by excluding one character at a time
                    else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
            }
        }
        
        // The answer is stored in dp[n][m][o]
        return dp[n][m][o];
    }
};