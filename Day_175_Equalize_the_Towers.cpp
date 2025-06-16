#include <bits/stdc++.h>
using namespace std;

// Problem: Equalize the Towers
// Given an array of heights and costs, find the minimum cost to equalize the heights of all towers.

// Approach: Sort the towers by height, then use prefix and suffix sums to calculate the cost of equalizing heights.

class Solution {
    public:
        int minCost(vector<int>& heights, vector<int>& cost) {
                // Number of towers
                int n = heights.size();
                // idx will store indices of towers, to sort by height
                vector<int> idx(n);
                iota(idx.begin(), idx.end(), 0);
                // Sort indices by corresponding heights
                sort(idx.begin(), idx.end(), [&heights](const int &a, const int &b) {
                     return heights[a] < heights[b]; 
                });
                
                // Suffix sums: total cost and total (height * cost) for towers from i to n-1
                long long sufCost = 0, sufProdSum = 0;
                for(int i = 0; i < n; i++) {
                        sufCost += cost[idx[i]];
                        sufProdSum += heights[idx[i]] * cost[idx[i]];
                }
                
                // Prefix sums: total cost and total (height * cost) for towers from 0 to i
                long long preCost = 0, preProdSum = 0;
                long long ans = INT_MAX;
                // Try making all towers equal to each possible height
                for(int i = 0; i < n; i++) {
                        preCost += cost[idx[i]];
                        preProdSum += heights[idx[i]] * cost[idx[i]];
                        sufCost -= cost[idx[i]];
                        sufProdSum -= heights[idx[i]] * cost[idx[i]];
                        // Calculate cost to make all towers equal to heights[idx[i]]
                        long long totalCost = (heights[idx[i]] * preCost - preProdSum)
                                                                        + (sufProdSum - heights[idx[i]] * sufCost);
                        ans = min(ans, totalCost);
                }
                return ans;
        }
};