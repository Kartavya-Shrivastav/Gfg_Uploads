#include <bits/stdc++.h>
using namespace std;

// Problem: Day 405 Stock Buy and Sell Max one Transaction Allowed
// Approach: We can keep track of the minimum price seen so far and calculate the potential profit at each step. The maximum profit will be the difference between the current price and the minimum price.

// Steps:
// 1. Initialize a variable `mini` to a large value (e.g., 100000) to keep track of the minimum price seen so far.
// 2. Initialize a variable `ans` to 0 to keep track of the maximum profit.
// 3. Iterate through each price in the `prices` vector:
//    a. Update `mini` to be the minimum of `mini` and the current price.
//    b. Update `ans` to be the maximum of `ans` and the difference between the current price and `mini`.
// 4. Return `ans` as the maximum profit.

// Time Complexity: O(n) where n is the number of prices.
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int mini=100000;
        int ans=0;
        for(auto x:prices)
        {
            mini=min(mini,x);
            ans=max(ans,x-mini);
        }
        
        return ans;
    }
};