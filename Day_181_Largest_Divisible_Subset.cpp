#include <bits/stdc++.h>
using namespace std;

// Problem: Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies Si % Sj == 0 or Sj % Si == 0.
// Example: Input: arr = [1, 2, 3, 4, 6, 8, 12, 24]
//          Output: [1, 2, 4, 8, 24] or any other valid subset of maximum size.

// Approach: We can use dynamic programming to solve this problem. We will maintain a dp array where dp[i] will store the largest divisible subset that ends with arr[i]. We will iterate through each element and check if it can be added to any of the previous subsets.

// Steps:
// 1. Sort the array.
// 2. Initialize a dp array where each element is a vector containing the element itself.
// 3. For each element, iterate through all previous elements and check if the current element
//   can be added to the subset ending with the previous element.
// 4. If it can be added, update the dp array accordingly.
// 5. Finally, find the largest subset from the dp array.

// Time Complexity: O(n^2), where n is the size of the input array.
// Space Complexity: O(n), for the dp array.

class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        vector<vector<int>> dp(n);
        vector<int> ans;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++){
            dp[i] = {arr[i]};
            for(int j = 0; j < i; j++) {
                if (1 + dp[j].size() >= dp[i].size() and arr[i] % arr[j] == 0) {
                    vector<int> temp = dp[i];
                    temp.pop_back();
                    if (1 + dp[j].size() ==  dp[i].size()) {
                        temp = dp[j];
                        temp.push_back(arr[i]);
                        dp[i] = max(dp[i], temp);
                    } 
                    else {
                        dp[i] = dp[j];
                        dp[i].push_back(arr[i]);
                    }
                }
            }
            mx = max(mx, (int) dp[i].size());
        }
        
        for (int i = 0; i < n; i++){
            if(dp[i].size() == mx) {
                if(ans.empty())
                    ans = dp[i];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};