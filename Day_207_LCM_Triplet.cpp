#include<bits/stdc++.h>
using namespace std;
// Problem: Find the product of the three largest distinct integers from 1 to n that are not divisible by 2 or 3.
// Approach: The three largest integers that are not divisible by 2 or 3 can be
//           determined based on the value of n. If n is even and divisible by 3, we can directly use n, n-1, and n-2.
//           If n is even but not divisible by 3, we can use n, n

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