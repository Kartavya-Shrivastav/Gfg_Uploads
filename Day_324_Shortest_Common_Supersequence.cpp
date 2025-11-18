#include <bits/stdc++.h>
using namespace std;

// Problem: Shortest Common Supersequence
// Approach: Dynamic Programming

// Steps:
// 1. Create a DP table to find the length of the Longest Common Subsequence (LCS)
// 2. Fill the DP table based on character matches and previous computations
// 3. Calculate the length of the Shortest Common Supersequence (SCS) using the formula:
//    SCS Length = Length of s1 + Length of s2 - Length of LCS
// 4. Return the SCS length
// Time Complexity: O(m*n) where m and n are lengths of s1 and s2
// Space Complexity: O(m*n)


class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s1.size()+s2.size()-dp[s1.size()][s2.size()];
    }
};