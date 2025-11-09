#include <bits/stdc++.h>
using namespace std;

// Problem: Given a set of jobs where each job has a start time, end time, and profit, find the maximum profit that can be obtained by scheduling non-overlapping jobs.
// Approach: Use dynamic programming with binary search to efficiently find the next non-overlapping job.

// Steps:
// 1. Sort the jobs based on their start times.
// 2. Create an array to store the start times for binary search.
// 3. For each job, use binary search to find the next job that starts after the current job ends.
// 4. Use a DP array where dp[i] represents the maximum profit obtainable from the i-th job to the end.
// 5. Fill the DP array in reverse order, considering two cases for each job:
//   - Exclude the current job: dp[i] = dp[i + 1]
//   - Include the current job: dp[i] = profit of current job + dp[next non-overlapping job]
// 6. The answer will be stored in dp[0].

// Time Complexity: O(n log n) due to sorting and binary search for each job.
// Space Complexity: O(n) for the DP array and auxiliary arrays.

class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
            int n = jobs.size();
        sort(jobs.begin(), jobs.end());
        
        vector<int> start(n);
        for (int i=0; i<n; i++) start[i] = jobs[i][0];
        
        vector<int> next(n);
        for (int i=0; i<n; i++) {
            int et = jobs[i][1];
            auto it = lower_bound(start.begin()+i+1, start.end(), et);
            if (it != start.end()) {
                next[i] = (int)(it-start.begin());
            }
            else next[i] = n;
        }
        
        vector<int> dp(n+1);
        
        dp[n] = 0;      // when no segment is selected
        
        // selecting segment in reverse order
        for (int i=n-1; i>=0; i--) {
            dp[i] = max(dp[i+1], jobs[i][2] + dp[next[i]]);
        }
        
        return dp[0];
    }
};