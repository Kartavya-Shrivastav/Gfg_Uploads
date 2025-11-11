#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array where the ith element is the price of a given stock on day i, find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the constraint that after you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Approach: Use recursion with memoization to explore all possible buy/sell actions while respecting the cooldown constraint.

// Steps:
// 1. Define a recursive function that takes the current day, whether you can buy or sell, and the cooldown period.
// 2. If you can buy, you have two choices: buy the stock or skip to the next day.
// 3. If you cannot buy (i.e., you have a stock), you can either sell it and enter a cooldown period or skip to the next day.
// 4. Use a DP table to store results of subproblems to avoid redundant calculations.
// 5. The base case is when the current day exceeds the number of days available.
// 6. The final answer is the maximum profit obtainable starting from day 0 with the ability to buy.

// Time complexity is O(n)
// Space complexity is O(n)

class Solution {
  public:
    int recur(vector<int>& arr, int n, int day, int canBuy, int cool, vector<vector<int>>& dp){
        if(day>=n) return 0;
        if(dp[day][canBuy]!=-1) return dp[day][canBuy];
        int take=0, nott=0;
        if(canBuy){
            take=-arr[day]+recur(arr,n,day+1,!canBuy,cool,dp);
            nott=recur(arr,n,day+1,canBuy,cool,dp);
        } else{
            take=arr[day]+recur(arr,n,day+cool+1,!canBuy,cool,dp);
            nott=recur(arr,n,day+1,canBuy,cool,dp);
        }
        return dp[day][canBuy]=max(take, nott);
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recur(arr,n,0,1,1,dp);
    }
};