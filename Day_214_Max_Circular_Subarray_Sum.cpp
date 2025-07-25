#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum sum of a circular subarray in an array of integers.
// Approach: Use Kadane's algorithm to find the maximum subarray sum and the minimum sub array sum.

// Steps:
// 1. Calculate the total sum of the array.
// 2. Use Kadane's algorithm to find the maximum subarray sum.
// 3. Use Kadane's algorithm to find the minimum subarray sum.
// 4. The maximum circular subarray sum can be found by subtracting the minimum subarray sum from the total sum.
// 5. If the minimum subarray sum equals the total sum, return the maximum subarray sum (as it means all elements are negative).
// 6. Return the maximum of the normal subarray sum and the circular subarray sum.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < arr.size(); i++) {
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);
            totalSum = totalSum + arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;
        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};