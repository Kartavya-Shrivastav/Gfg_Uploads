#include <bits/stdc++.h>
using namespace std;

// Problem: Given a cost matrix where costs[i][j] represents the cost of painting the i-th wall with the j-th color, find the minimum cost to paint all walls such that no two adjacent walls have the same color.
// Approach: Dynamic Programming with Optimization

// Steps:
// 1. Initialize a DP array where dp[j] represents the minimum cost to paint up to the current wall with color j.
// 2. For each wall, use a priority queue to efficiently find the two smallest costs from the previous wall's DP array.
// 3. For each color of the current wall, calculate the cost by adding the cost of painting the current wall with that color to the minimum cost from the previous wall, ensuring that the same color is not used for adjacent walls.
// 4. Update the DP array for the current wall and repeat until all walls are processed.
// 5. The answer will be the minimum value in the DP array after processing all walls.

// Time Complexity: O(n * m)
// Space Complexity: O(m)

class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n=costs.size(),m=costs[0].size();
        if(m==1){
            if(n==1)
                return costs[0][0];
            return -1;
        }
        vector<int>dp(m);
        for(int j=0;j<m;j++)
            dp[j]=costs[0][j];
        for(int i=1;i<n;i++){
            priority_queue<int> pq;
            for(auto x:dp){
                pq.push(x);
                if(pq.size()>2)
                    pq.pop();
            }
            int min2=pq.top();pq.pop();
            int min1=pq.top();
            // cout<<min1<<" "<<min2<<endl;
            vector<int> dp2(m);
            for(int j=0;j<m;j++){
                int ans=costs[i][j];
                if(dp[j]==min1)
                    ans+=min2;
                else
                    ans+=min1;
                dp2[j]=ans;
            }
            dp=dp2;
        }
        return *min_element(dp.begin(),dp.end());
    }
};  