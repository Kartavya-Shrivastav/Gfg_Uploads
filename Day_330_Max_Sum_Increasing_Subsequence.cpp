#include<bits/stdc++.h>
using namespace std;

// Problem: Max Sum Increasing Subsequence
// Approach: Dynamic Programming

// Steps:
// 1. Use a 1D DP array where dp[i] represents the maximum sum of increasing subsequence ending with arr[i].
// 2. Iterate through each element in the array and for each element, iterate through all previous elements.
// 3. For each pair of elements, update the DP array if the current element is greater than the previous element.
// 4. Return the maximum value in the DP array as the result.

// Time Complexity: O(n^2) where n is the size of the array.
// Space Complexity: O(n) where n is the size of the array.

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int pre_index;
        bool f = true;

        for (int i = 0; i < n; i++) {
            if (f && nums[i] == 1) {
                f = false;
                pre_index = i;
                continue;
            }
            if (nums[i] == 1) {
                if (i - pre_index - 1 >= k)
                    pre_index = i;
                else
                    return false;
            }
        }

        return true;
    }
};