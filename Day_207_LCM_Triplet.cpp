#include<bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of 3n integers, divide it into three contiguous parts of size n each, and minimize the difference between the 
         sum of the smallest n elements in the first two parts and the sum of the largest n elements in the last two parts.
Approach: Use a max-heap to maintain the smallest n elements from the left and a min-heap to maintain the largest n elements
          from the right while iterating through the array to track prefix and suffix sums.

Steps:
1. Initialize a max-heap and compute the sum of the first n elements from the left to simulate the smallest possible values.
2. Store this initial sum in the `leftMins` array at position `k - 1`.
3. Traverse from index `k` to `n - k`, at each step:
   - Replace the maximum in the heap with the current number if the current number is smaller.
   - Update the heap and maintain the smallest n elements' sum in `leftMins`.
4. Similarly, initialize a min-heap from the right end and compute the sum of the last n elements to simulate the largest possible values.
5. Store this initial sum in `rightMaxs[n - k]`.
6. Traverse backward from `n - k - 1` to `k - 1`, at each step:
   - Replace the minimum in the heap with the current number if it's larger.
   - Update the heap and maintain the largest n elements' sum in `rightMaxs`.
7. Iterate from index `k - 1` to `n - k - 1`, and compute the difference between `leftMins[i]` and `rightMaxs[i + 1]`.
8. Track and return the minimum of all such differences.

Time Complexity: O(n log n), for maintaining heaps during two linear traversals.
Space Complexity: O(n), for storing prefix and suffix sums and heap elements.
*/


class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
         int n = nums.size(), k = n / 3;
        vector<long long> leftMins(n, 0), rightMaxs(n, 0);

        priority_queue<int> maxLeft;
        long long leftSum = 0;

        for (int i = 0; i < k; ++i) {
            maxLeft.push(nums[i]);
            leftSum += nums[i];
        }
        leftMins[k - 1] = leftSum;

        for (int i = k; i < n - k; ++i) {
            if (nums[i] < maxLeft.top()) {
                leftSum += nums[i] - maxLeft.top();
                maxLeft.pop();
                maxLeft.push(nums[i]);
            }
            leftMins[i] = leftSum;
        }

        priority_queue<int, vector<int>, greater<int>> minRight;
        long long rightSum = 0;

        for (int i = n - 1; i >= n - k; --i) {
            minRight.push(nums[i]);
            rightSum += nums[i];
        }
        rightMaxs[n - k] = rightSum;

        for (int i = n - k - 1; i >= k - 1; --i) {
            if (nums[i] > minRight.top()) {
                rightSum += nums[i] - minRight.top();
                minRight.pop();
                minRight.push(nums[i]);
            }
            rightMaxs[i] = rightSum;
        }

        long long minDiff = LLONG_MAX;
        for (int i = k - 1; i < n - k; ++i) {
            minDiff = min(minDiff, leftMins[i] - rightMaxs[i + 1]);
        }

        return minDiff;
    
    }
};