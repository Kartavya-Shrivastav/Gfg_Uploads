#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: You are given an array of stock prices where the i-th element represents the price of a stock on day i, and an integer k representing the transaction fee. You can complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
Approach: We can use dynamic programming to solve this problem. We will maintain two variables, `hold` and `sell`, where `hold` represents the maximum profit we can achieve if we are currently holding a stock, and `sell` represents the maximum profit we can achieve if we are not holding a stock.

Steps:
1. Initialize `hold` to -arr[0] (the cost of buying the stock on the first day) and `sell` to 0 (no profit if we haven't made any transactions).
2. Iterate through the array of stock prices starting from the second day:
   - Update `hold` to be the maximum of the current `hold` and the profit we would get if we sold the stock on the previous day and bought it again today (which is `sell - arr[i]`).
   - Update `sell` to be the maximum of the current `sell` and the profit we would get if we sold the stock today (which is `hold + arr[i] - k`, accounting for the transaction fee).
3. After iterating through all the days, the maximum profit will be in `sell`, since we want to end up not holding any stock.
4. Return the value of `sell` as the result.

Time Complexity: O(n) where n is the number of days (length of the stock prices array).
Space Complexity: O(1) since we are using only a constant amount of space to store the `hold` and `sell` variables.
*/

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        long long hold = -arr[0]; 
        long long sell = 0;

        for (int i = 1; i < n; i++) {
            long long prev_hold = hold;
        
            hold = max(hold, sell - arr[i]);
        
            sell = max(sell, prev_hold + arr[i] - k);
        }
        return (int)sell;
    }
};