#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers and a difference value, count the number of ways to partition the array into two subsets such that the difference between the sums of the subsets is equal to the given difference.
Approach: This problem can be transformed into a subset sum problem. We can derive the sum of one subset (s2) from the total sum of the array and the given difference. The problem then reduces to counting the number of subsets that sum up to s2.

Steps:
1. Calculate the total sum of the array.
2. Check if the difference is greater than the total sum or if (sum + diff) is odd. If either condition is true, return 0 as it's not possible to partition the array.
3. Calculate s2 as (sum + diff) / 2.
4. Use dynamic programming to count the number of subsets that sum up to s2:
    a. Create a 2D DP array where dp[i][j] represents the number of subsets of the first i elements that sum up to j.
    b. Initialize dp[i][0] to 1 for all i, as there is one subset (the empty set) that sums to 0.
    c. Fill the DP table using the following logic:
        - If the current element is greater than j, then dp[i][j] = dp[i-1][j].
        - Otherwise, dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]].
5. The answer will be in dp[n][s2], where n is the size of the array.

Time Complexity: O(n * s2) where n is the number of elements in the array and s2 is the target sum for the subset.
Space Complexity: O(n * s2) for the DP array. We can optimize space by using a 1D DP array and iterating backwards to avoid overwriting values that are still needed. Overall, the space complexity can be reduced to O(s2).
*/

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n =  arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++) sum+=arr[i];
        if(diff>sum) return 0;
        if ((sum + diff) % 2 != 0) return 0;

        int s2 = (sum+diff)/2;
        vector<vector<int>> dp(n+1, vector<int>(s2+1));
        for(int i=0; i<=n; i++) dp[i][0]=1;
        //for(int j=  1;j<=s2;j++) dp[0][j]=0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=s2;j++){
                if(arr[i-1]>j) dp[i][j]= dp[i-1][j];
                 else  dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                
            }
        }
            return dp[n][s2];
    }
};