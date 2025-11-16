#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Common Increasing Subsequence
// Approach: Dynamic Programming

// Steps:
// 1. Use a 1D DP array where dp[j] represents the length of the longest common increasing subsequence ending with b[j].
// 2. Iterate through each element in array a and for each element, iterate through array b.
// 3. For each pair of elements, update the DP array based on the conditions of equality and increasing order.
// 4. Return the maximum value in the DP array as the result.

// Time Complexity: O(n * m) where n and m are the sizes of arrays a and b respectively.
// Space Complexity: O(m) where m is the size of array b.

class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
      int n=a.size(), m=b.size();
      vector<int> dp(m+1, 0);
      
      for(int &x: a){
        int c=0;
        for(int i=0;i<m;i++){
          if(b[i]==x)
            dp[i] = (dp[i], c+1);
          if(b[i] < x)
            c = max(dp[i], c);
        }
      }
      
      
      int ans = 0;
      for(int &x: dp)
        ans = max(ans, x);
      
      return ans;
    }
};