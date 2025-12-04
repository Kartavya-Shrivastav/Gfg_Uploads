#include <bits/stdc++.h>
using namespace std;

// Problem: Given a cost matrix for traveling between cities, find the minimum cost to visit all cities and return to the starting city (Travelling Salesman Problem).
// Approach: Use dynamic programming with bitmasking to efficiently explore all possible routes and calculate the minimum cost.

// Steps:
// 1. Define a recursive function that takes the current city index, the cost matrix, the current visited cities bitmask, and a DP table for memoization.
// 2. If all cities have been visited (bitmask is zero), return the cost to return to the starting city.
// 3. If the result for the current state is already computed, return it from the DP table.
// 4. Iterate through all cities, and for each unvisited city, calculate the cost of traveling to that city and recursively call the function for the new state.
// 5. Store the minimum cost found in the DP table and return it.

// Time Complexity: O(n^2 * 2^n), where n is the number of cities, due to the exploration of all subsets of cities and transitions between them.
// Space Complexity: O(n * 2^n) for the DP table storing results for

class Solution {
  public:
    int rec(int ind,vector <vector <int>> &cost,int mask,vector <vector <int>> &dp){
        int n=cost.size();
        mask=mask^(1<<ind);
        if(mask==0) return cost[ind][0];
        
        if(dp[ind][mask]!=-1)   return dp[ind][mask];
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                ans=min(ans,cost[ind][j]+rec(j,cost,mask,dp));
            }
        }
        
        return dp[ind][mask]=ans;
    }
    
    int tsp(vector<vector<int>>cost){
        int n=cost.size();
        int mask=pow(2,n)-1;
        vector <vector<int>> dp(n,vector <int> (mask+1,-1));
        return rec(0,cost,mask,dp);
    }
};